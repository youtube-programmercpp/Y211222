// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "date.h"
#include "price.h"
struct quote_i {
	struct date  日付;
	struct price 始値;
	struct price 高値;
	struct price 安値;
	struct price 終値;
};
bool read_quote_i(FILE* fp, struct quote_i* pVal);
bool write_quote_i(FILE* fp, const struct quote_i* p);
