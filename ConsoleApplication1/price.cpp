// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "price.h"
#include <ctype.h>
#include <iomanip>

std::istream& operator>>(std::istream &stm, price& r)
{
	char ch;
	if (stm >> ch) {
		if (isdigit((unsigned char)ch)) {
			r.yen = ch - '0';
			for (;;) {
				if (stm.read(&ch, 1)) {
					switch (ch) {
					case ',':
						continue;
					case '.':
						if (stm.read(&ch, 1)) {
							if (isdigit((unsigned char)ch)) {
								r.sen = 10 * (ch - '0');
								if (stm.read(&ch, 1)) {
									if (isdigit((unsigned char)ch)) {
										r.sen += ch - '0';
										if (stm.read(&ch, 1)) {
											if (isspace((unsigned char)ch))
												return stm;
											else {
												stm.setstate(std::ios_base::failbit);
												return stm;
											}
										}
										else
											return stm;//read error
									}
									else if (isspace((unsigned char)ch))
										return stm;
									else {
										stm.setstate(std::ios_base::failbit);
										return stm;
									}
								}
								else
									return stm;//read error
							}
							else {
								stm.setstate(std::ios_base::failbit);
								return stm;
							}
						}
						else
							return stm;//read error
					default:
						if (isdigit((unsigned char)ch)) {
							r.yen *= 10;
							r.yen += ch - '0';
							continue;
						}
						else if (isspace((unsigned char)ch)) {
							r.sen = 0;
							return stm;
						}
						else {
							stm.setstate(std::ios_base::failbit);
							return stm;
						}
					}
				}
				else
					return stm;//read error
			}
		}
		else {
			stm.setstate(std::ios_base::failbit);
			return stm;
		}
	}
	else
		return stm;//read error
}
std::ostream& operator<<(std::ostream &stm, const price& r)
{
	if (r.sen)
		return stm << r.yen << '.' << std::setfill('0') << std::setw(2) << r.sen << std::setfill(' ');
	else
		return stm << r.yen;
}
