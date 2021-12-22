// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_i.h"

bool read_quote_i(FILE* fp, struct quote_i* pVal)
{
	return read_date (fp, &pVal->日付)
	&&     read_price(fp, &pVal->始値)
	&&     read_price(fp, &pVal->高値)
	&&     read_price(fp, &pVal->安値)
	&&     read_price(fp, &pVal->終値)
	;
}
bool write_quote_i(FILE* fp, const struct quote_i* p)
{
	return write_date (fp, &p->日付) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->始値) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->高値) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->安値) && fputc(',' , fp)  > 0
	&&     write_price(fp, &p->終値) && fputc('\n', fp)  > 0
	;
}
