// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "date.h"
#include "price.h"
#include "change.h"
struct quote_t {
	struct date   日付          ;
	struct price  基準価額      ;
	struct change 前日差        ;
	struct price  純資産（百万）;
};
bool read_quote_t(FILE* fp, struct quote_t* pVal);
bool write_quote_t(FILE* fp, const struct quote_t* p);
