// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "volume.h"
#include <ctype.h>

std::istream& operator>>(std::istream& stm, volume& r)
{
	char ch;
	if (stm >> ch) {
		if (isdigit((unsigned char)ch)) {
			r.n = ch - '0';
			for (;;) {
				if (stm.read(&ch, 1)) {
					if (ch == ',')
						continue;
					else if (isdigit((unsigned char)ch)) {
						(r.n *= 10) += ch - '0';
						continue;
					}
					else if (isspace((unsigned char)ch))
						return stm;
					else {
						stm.setstate(std::ios_base::failbit);
						return stm;
					}
				}
				else
					return stm;
			}
		}
		else {
			stm.setstate(std::ios_base::failbit);
			return stm;
		}
	}
	else
		return stm;
}
std::ostream& operator<<(std::ostream &stm, const volume& r)
{
	return stm << r.n;
}
