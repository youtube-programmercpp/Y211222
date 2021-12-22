// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "date.h"
#include "price.h"
#include "volume.h"
struct quote_s {
	struct date   日付      ;
	struct price  始値      ;
	struct price  高値      ;
	struct price  安値      ;
	struct price  終値      ;
	struct volume 出来高    ;
	struct price  調整後終値;
};
bool read_quote_s(FILE* fp, struct quote_s* pVal);
bool write_quote_s(FILE* fp, const struct quote_s* p);
