// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include "date.h"
#include "price.h"
#include "volume.h"
struct quote_s {
	struct date   ���t      ;
	struct price  �n�l      ;
	struct price  ���l      ;
	struct price  ���l      ;
	struct price  �I�l      ;
	struct volume �o����    ;
	struct price  ������I�l;
};
bool read_quote_s(FILE* fp, struct quote_s* pVal);
bool write_quote_s(FILE* fp, const struct quote_s* p);
