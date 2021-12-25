// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_t.h"

std::istream& operator>>(std::istream &stm, quote_t& r)
{
	return stm
		>> r.日付          
		>> r.基準価額      
		>> r.前日差        
		>> r.純資産（百万）
		;
}
std::ostream& operator<<(std::ostream &stm, const quote_t& r)
{
	return stm
		<< r.日付           << ',' 
		<< r.基準価額       << ',' 
		<< r.前日差         << ',' 
		<< r.純資産（百万） << '\n'
		;
}
