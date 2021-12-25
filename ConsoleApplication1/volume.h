// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#pragma once
#include <istream>
#include <ostream>
struct volume {
	int n;
};
bool read_volume (std::istream& stm,       volume* pVal);
bool write_volume(std::ostream& stm, const volume* p   );
