// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
struct quote_i {
	date  ���t;
	price �n�l;
	price ���l;
	price ���l;
	price �I�l;
};
bool read_quote_i (std::istream& stm,       quote_i* pVal);
bool write_quote_i(std::ostream& stm, const quote_i* p   );
