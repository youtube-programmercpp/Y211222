// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"

struct quote_i;
std::istream& operator>>(std::istream& stm,       quote_i& r);
std::ostream& operator<<(std::ostream& stm, const quote_i& r);


struct quote_i {
	date  ���t;
	price �n�l;
	price ���l;
	price ���l;
	price �I�l;
	friend std::istream& operator>>(std::istream& stm,       quote_i& r);
	friend std::ostream& operator<<(std::ostream& stm, const quote_i& r);
};
