// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <stdio.h>
struct volume {
	int n;
};
bool read_volume(FILE* fp, struct volume* pVal);
bool write_volume(FILE* fp, const struct volume* p);
