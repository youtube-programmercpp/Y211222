// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <stdio.h>
struct price {
	int yen;
	int sen;
};
bool read_price(FILE* fp, struct price* pVal);
bool write_price(FILE* fp, const struct price* p);
