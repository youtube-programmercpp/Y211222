// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
#include "change.h"
struct quote_t {
	struct date   ���t          ;
	struct price  ����z      ;
	struct change �O����        ;
	struct price  �����Y�i�S���j;
};
bool read_quote_t(FILE* fp, struct quote_t* pVal);
bool write_quote_t(FILE* fp, const struct quote_t* p);
