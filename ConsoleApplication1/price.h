// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <istream>
#include <ostream>
struct price {
	int yen;
	int sen;
};
bool read_price (std::istream& stm,       price* pVal);
bool write_price(std::ostream& stm, const price* p   );
