// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#define	_CRT_SECURE_NO_WARNINGS
#include "volume.h"
#include <ctype.h>

bool read_volume(FILE* fp, struct volume* pVal)
{
	char ch;
	if (fscanf(fp, " %c", &ch) == 1) {
		if (isdigit((unsigned char)ch)) {
			pVal->n = ch - '0';
			for (;;) {
				if (fscanf(fp, "%c", &ch) == 1) {
					switch (ch) {
					case ',':
						continue;
					default:
						if (isdigit((unsigned char)ch)) {
							pVal->n *= 10;
							pVal->n += ch - '0';
							break;
						}
						else if (isspace((unsigned char)ch))
							return true;
						else
							return false;
					}
				}
				else
					return false;
			}
		}
		else
			return false;
	}
	else
		return false;
}
bool write_volume(FILE* fp, const struct volume* p)
{
	return fprintf(fp, "%d", p->n) > 0;
}
