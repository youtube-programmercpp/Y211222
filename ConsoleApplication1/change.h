// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <istream>
#include <ostream>
struct change {
	int n;
};
bool read_change (std::istream& stm,       change* p   );
bool write_change(std::ostream& stm, const change* pVal);
