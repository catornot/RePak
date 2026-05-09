#pragma once
#include <zstd.h>
#include <compress/zstd_compress_internal.h>
#include <decompress/zstd_decompress_internal.h>

const int ZSTDMT_WORKERS_MAX = 64;

struct ZSTDEncoder_s
{
	ZSTDEncoder_s();
	~ZSTDEncoder_s();

	ZSTD_CCtx cctx;
};

struct ZSTDDecoder_s
{
	ZSTDDecoder_s();
	~ZSTDDecoder_s();

	ZSTD_DCtx dctx;
};
