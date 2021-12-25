// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_i.h"

bool read_quote_i(std::istream &stm, quote_i* pVal)
{
	return read_date (stm, &pVal->日付)
	&&     read_price(stm, &pVal->始値)
	&&     read_price(stm, &pVal->高値)
	&&     read_price(stm, &pVal->安値)
	&&     read_price(stm, &pVal->終値)
	;
}
bool write_quote_i(std::ostream &stm, const quote_i* p)
{
	return write_date (stm, &p->日付) && stm << ',' 
	&&     write_price(stm, &p->始値) && stm << ',' 
	&&     write_price(stm, &p->高値) && stm << ',' 
	&&     write_price(stm, &p->安値) && stm << ',' 
	&&     write_price(stm, &p->終値) && stm << '\n'
	;
}
