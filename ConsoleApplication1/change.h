// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <istream>
#include <ostream>
struct change {
	int n;
	friend std::istream& operator>>(std::istream& stm,       change& r);
	friend std::ostream& operator<<(std::ostream& stm, const change& r);
};
