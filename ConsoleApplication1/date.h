// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <stdio.h>
struct date {
	int year ;
	int month;
	int day  ;
};
bool read_date(FILE* fp, struct date* pVal);
bool write_date(FILE* fp, const struct date* p);
