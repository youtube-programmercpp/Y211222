// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include "date.h"
#include "price.h"
#include "volume.h"
struct quote_s {
	date   日付      ;
	price  始値      ;
	price  高値      ;
	price  安値      ;
	price  終値      ;
	volume 出来高    ;
	price  調整後終値;
	friend std::istream& operator>>(std::istream& stm,       quote_s& r);
	friend std::ostream& operator<<(std::ostream& stm, const quote_s& r);
};
