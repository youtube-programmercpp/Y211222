// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <stdio.h>
struct volume {
	int n;
};
bool read_volume(FILE* fp, struct volume* pVal);
bool write_volume(FILE* fp, const struct volume* p);
