// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <stdio.h>
struct change {
	int n;
};
bool read_change(FILE* fp, struct change* pVal);
bool write_change(FILE* fp, const struct change* p);
