// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
#include "change.h"
struct quote_t {
	date   ���t          ;
	price  ����z      ;
	change �O����        ;
	price  �����Y�i�S���j;
	friend std::istream& operator>>(std::istream& stm,       quote_t& r);
	friend std::ostream& operator<<(std::ostream& stm, const quote_t& r);
};
