// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "change.h"
#include <ctype.h>

struct digit_sequence {
	char & ch    ;
	bool   minus ;
	int  & value ;

	friend std::istream& operator>>(std::istream &stm, digit_sequence&& r)
	{
		if (stm.read(&r.ch, 1)) {
			if (isdigit((unsigned char)r.ch)) {
				for (r.value = r.ch - '0';;) {
					if (stm.read(&r.ch, 1)) {
						if (r.ch == ',')
							continue;
						else if (isdigit((unsigned char)r.ch)) {
							(r.value *= 10) += r.ch - '0';
							continue;
						}
						else if (isspace((unsigned char)r.ch)) {
							if (r.minus)
								r.value *= -1;
							return stm;
						}
						else {
							//unexpected non-space non-digit character immediately after last digit
							stm.setstate(std::ios_base::failbit);
							return stm;
						}
					}
					else
						return stm;// read error
				}
			}
			else {
				//unexpected non-digit character immediately after sign
				stm.setstate(std::ios_base::failbit);
				return stm;
			}
		}
		else
			return stm;//read error
	}
};

std::istream& operator>>(std::istream &stm, change& r)
{
	char ch;
	if (stm >> ch) {
		switch (ch) {
		case '+': return stm >> digit_sequence{ch, false, r.n};
		case '-': return stm >> digit_sequence{ch, true,  r.n};
		case '0':
			if (stm.read(&ch, 1)) {
				if (isspace((unsigned char)ch))
					r.n = 0;
				else
					stm.setstate(std::ios_base::failbit);
			}
			return stm;
		default:
			stm.setstate(std::ios_base::failbit);
			return stm;
		}
	}
	else
		return stm;
}
std::ostream& operator<<(std::ostream &stm, const change& r)
{
	return stm << r.n;
}
