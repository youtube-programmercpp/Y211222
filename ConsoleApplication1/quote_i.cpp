// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_i.h"

bool read_quote_i(FILE* fp, struct quote_i* pVal)
{
	return read_date (fp, &pVal->���t)
	&&     read_price(fp, &pVal->�n�l)
	&&     read_price(fp, &pVal->���l)
	&&     read_price(fp, &pVal->���l)
	&&     read_price(fp, &pVal->�I�l)
	;
}
bool write_quote_i(FILE* fp, const struct quote_i* p)
{
	return write_date (fp, &p->���t) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->�n�l) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->���l) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->���l) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->�I�l) && fputc('\n', fp)  > 0
	;
}
