// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <stdio.h>
struct change {
	int n;
};
bool read_change(FILE* fp, struct change* pVal);
bool write_change(FILE* fp, const struct change* p);
