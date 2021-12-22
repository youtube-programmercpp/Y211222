// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_s.h"

bool read_quote_s(FILE* fp, struct quote_s* pVal)
{
	return read_date  (fp, &pVal->日付      )
	&&     read_price (fp, &pVal->始値      )
	&&     read_price (fp, &pVal->高値      )
	&&     read_price (fp, &pVal->安値      )
	&&     read_price (fp, &pVal->終値      )
	&&     read_volume(fp, &pVal->出来高    )
	&&     read_price (fp, &pVal->調整後終値)
	;
}
bool write_quote_s(FILE* fp, const struct quote_s* p)
{
	return write_date  (fp, &p->日付      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->始値      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->高値      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->安値      ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->終値      ) && fputc(',' , fp)  > 0
	&&     write_volume(fp, &p->出来高    ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->調整後終値) && fputc('\n', fp)  > 0
	;
}
