// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_s.h"

std::istream& operator>>(std::istream &stm, quote_s& r)
{
	return stm
		>> r.日付      
		>> r.始値      
		>> r.高値      
		>> r.安値      
		>> r.終値      
		>> r.出来高    
		>> r.調整後終値
		;
}
std::ostream& operator<<(std::ostream &stm, const quote_s& r)
{
	return stm
		<< r.日付       << ',' 
		<< r.始値       << ',' 
		<< r.高値       << ',' 
		<< r.安値       << ',' 
		<< r.終値       << ',' 
		<< r.出来高     << ',' 
		<< r.調整後終値 << '\n'
	;
}
