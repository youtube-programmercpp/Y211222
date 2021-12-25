// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "date.h"
#include <iomanip>

template<size_t length_including_null>inline std::istream& operator>>(std::istream& istm, const char(&r)[length_including_null])
{
	char buf[length_including_null - 1];
	if (istm.read(buf, length_including_null - 1)) {
		if (memcmp(buf, r, length_including_null - 1))
			istm.setstate(std::ios_base::failbit);
	}
	return istm;
}

std::istream& operator>>(std::istream &stm, date& r)
{
	return stm
		>> r.year  >> "年"
		>> r.month >> "月"
		>> r.day   >> "日"
		;
}
std::ostream& operator<<(std::ostream &stm, const date& r)
{
	return stm 
		<< std::setfill('0')
		<<        std::setw(4) << r.year 
		<< '/' << std::setw(2) << r.month
		<< '/' << std::setw(2) << r.day  
		<< std::setfill(' ');
}
