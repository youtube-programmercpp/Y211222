// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
#include "volume.h"
struct quote_s {
	date   ���t      ;
	price  �n�l      ;
	price  ���l      ;
	price  ���l      ;
	price  �I�l      ;
	volume �o����    ;
	price  ������I�l;
	friend std::istream& operator>>(std::istream& stm,       quote_s& r);
	friend std::ostream& operator<<(std::ostream& stm, const quote_s& r);
};
