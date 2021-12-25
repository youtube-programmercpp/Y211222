// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "date.h"
#include "price.h"
#include "change.h"
struct quote_t {
	date   日付          ;
	price  基準価額      ;
	change 前日差        ;
	price  純資産（百万）;
};
bool read_quote_t (std::istream& stm,       quote_t* pVal);
bool write_quote_t(std::ostream& stm, const quote_t* p   );
