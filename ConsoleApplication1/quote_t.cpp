// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_t.h"

bool read_quote_t(std::istream &stm, quote_t* pVal)
{
	return read_date  (stm, &pVal->日付          )
	&&     read_price (stm, &pVal->基準価額      )
	&&     read_change(stm, &pVal->前日差        )
	&&     read_price (stm, &pVal->純資産（百万）)
	;
}
bool write_quote_t(std::ostream &stm, const quote_t* p)
{
	return write_date  (stm, &p->日付          ) && stm << ',' 
	&&     write_price (stm, &p->基準価額      ) && stm << ',' 
	&&     write_change(stm, &p->前日差        ) && stm << ',' 
	&&     write_price (stm, &p->純資産（百万）) && stm << '\n'
	;
}
