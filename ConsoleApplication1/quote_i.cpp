// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_i.h"

std::istream& operator>>(std::istream &stm, quote_i& r)
{
	return stm
		>> r.日付
		>> r.始値
		>> r.高値
		>> r.安値
		>> r.終値
		;
}
std::ostream& operator<<(std::ostream &stm, const quote_i& r)
{
	return stm
		<< r.日付 << ',' 
		<< r.始値 << ',' 
		<< r.高値 << ',' 
		<< r.安値 << ',' 
		<< r.終値 << '\n'
		;
}
