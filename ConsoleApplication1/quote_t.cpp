// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_t.h"

bool read_quote_t(FILE* fp, struct quote_t* pVal)
{
	return read_date  (fp, &pVal->日付          )
	&&     read_price (fp, &pVal->基準価額      )
	&&     read_change(fp, &pVal->前日差        )
	&&     read_price (fp, &pVal->純資産（百万）)
	;
}
bool write_quote_t(FILE* fp, const struct quote_t* p)
{
	return write_date  (fp, &p->日付          ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->基準価額      ) && fputc(',' , fp)  > 0
	&&     write_change(fp, &p->前日差        ) && fputc(',' , fp)  > 0
	&&     write_price (fp, &p->純資産（百万）) && fputc('\n', fp)  > 0
	;
}
