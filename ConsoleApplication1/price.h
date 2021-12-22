// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <stdio.h>
struct price {
	int yen;
	int sen;
};
bool read_price(FILE* fp, struct price* pVal);
bool write_price(FILE* fp, const struct price* p);
