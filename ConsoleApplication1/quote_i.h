// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
struct quote_i {
	struct date  ���t;
	struct price �n�l;
	struct price ���l;
	struct price ���l;
	struct price �I�l;
};
bool read_quote_i(FILE* fp, struct quote_i* pVal);
bool write_quote_i(FILE* fp, const struct quote_i* p);
