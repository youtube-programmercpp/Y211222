// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "change.h"
#include <ctype.h>

static bool read_digit_sequence(std::istream &stm, char* pch, bool minus, int* pVal)
{
	if (isdigit((unsigned char)*pch)) {
		for (*pVal = *pch - '0';;) {
			if (stm.read(pch, 1)) {
				if (*pch == ',')
					continue;
				else if (isdigit((unsigned char)*pch)) {
					*pVal *= 10;
					*pVal += *pch - '0';
					continue;
				}
				else {
					if (minus)
						*pVal *= -1;
					return true;
				}
			}
			else
				return false;
		}
	}
	else
		return false;
}

bool read_change(std::istream &stm, change* pVal)
{
	char ch;
	if (stm >> ch) {
		switch (ch) {
		case '+':
			return stm.read(&ch, 1) && read_digit_sequence(stm, &ch, false, &pVal->n) && isspace((unsigned char)ch);
		case '-':
			return stm.read(&ch, 1) && read_digit_sequence(stm, &ch, true,  &pVal->n) && isspace((unsigned char)ch);
		case '0':
			if (stm.read(&ch, 1) && isspace((unsigned char)ch)) {
				pVal->n = 0;
				return true;
			}
			else
				return false;
		default:
			return false;
		}
	}
	else
		return false;
}
bool write_change(std::ostream &stm, const change* p)
{
	return (stm << p->n).good();
}
