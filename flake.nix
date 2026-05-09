{
  inputs = {
    utils.url = "github:numtide/flake-utils";
  };
  outputs =
    {
      self,
      nixpkgs,
      utils,
    }:
    utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        formatter = pkgs.nixfmt-tree;

        devShell =
          pkgs.mkShell.override
            {
              stdenv = pkgs.clangStdenv;
            }
            {
              packages = with pkgs; [
                meson
                ninja
                clang-tools
                lldb
                (if system == "x86_64-darwin" || system == "aarch64-darwin" then null else valgrind)
                include-what-you-use
                ccache
                pkg-config
                cmake
              ];

              buildInputs = [
                pkgs.rapidjson
                pkgs.zstd.dev
                pkgs.rapidcsv
                pkgs.dxvk.lib
              ];

              shellHook = ''
                export CC="ccache clang"
                export CXX="ccache clang++"
              '';
            };
      }
    );
}
