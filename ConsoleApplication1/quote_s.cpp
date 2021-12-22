// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_s.h"

bool read_quote_s(FILE* fp, struct quote_s* pVal)
{
	return read_date  (fp, &pVal->���t      )
	&&     read_price (fp, &pVal->�n�l      )
	&&     read_price (fp, &pVal->���l      )
	&&     read_price (fp, &pVal->���l      )
	&&     read_price (fp, &pVal->�I�l      )
	&&     read_volume(fp, &pVal->�o����    )
	&&     read_price (fp, &pVal->������I�l)
	;
}
bool write_quote_s(FILE* fp, const struct quote_s* p)
{
	return write_date  (fp, &p->���t      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->�n�l      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->���l      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->���l      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->�I�l      ) && fputc(',' , fp)  > 0
	&&     write_volume(fp, &p->�o����    ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->������I�l) && fputc('\n', fp)  > 0
	;
}
