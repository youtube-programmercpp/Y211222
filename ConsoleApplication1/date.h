// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <stdio.h>
struct date {
	int year ;
	int month;
	int day  ;
};
bool read_date(FILE* fp, struct date* pVal);
bool write_date(FILE* fp, const struct date* p);
