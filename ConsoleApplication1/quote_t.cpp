// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_t.h"

bool read_quote_t(FILE* fp, struct quote_t* pVal)
{
	return read_date  (fp, &pVal->���t          )
	&&     read_price (fp, &pVal->����z      )
	&&     read_change(fp, &pVal->�O����        )
	&&     read_price (fp, &pVal->�����Y�i�S���j)
	;
}
bool write_quote_t(FILE* fp, const struct quote_t* p)
{
	return write_date  (fp, &p->���t          ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->����z      ) && fputc(',' , fp)  > 0
	&&     write_change(fp, &p->�O����        ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->�����Y�i�S���j) && fputc('\n', fp)  > 0
	;
}
