// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <istream>
#include <ostream>
struct change {
	int n;
};
bool read_change (std::istream& stm,       change* p   );
bool write_change(std::ostream& stm, const change* pVal);
