// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "price.h"
#include <ctype.h>
#include <iomanip>

bool read_price(std::istream &stm, price* pVal)
{
	char ch;
	if (stm >> ch) {
		if (isdigit((unsigned char)ch)) {
			pVal->yen = ch - '0';
			for (;;) {
				if (stm.read(&ch, 1)) {
					switch (ch) {
					case ',':
						continue;
					case '.':
						if (stm.read(&ch, 1)) {
							if (isdigit((unsigned char)ch)) {
								pVal->sen = 10 * (ch - '0');
								if (stm.read(&ch, 1)) {
									if (isdigit((unsigned char)ch)) {
										pVal->sen += ch - '0';
										return true;
									}
									else if (isspace((unsigned char)ch))
										return true;
									else
										return false;
								}
								else
									return true;
							}
							else
								return false;
						}
						else
							return false;
					default:
						if (isdigit((unsigned char)ch)) {
							pVal->yen *= 10;
							pVal->yen += ch - '0';
							break;
						}
						else if (isspace((unsigned char)ch)) {
							pVal->sen = 0;
							return true;
						}
						else
							return false;
					}
				}
				else
					return false;
			}
		}
		else
			return false;
	}
	else
		return false;
}
bool write_price(std::ostream &stm, const price* p)
{
	if (p->sen)
		return (stm << p->yen << '.' << std::setfill('0') << std::setw(2) << p->sen << std::setfill(' ')).good();
	else
		return (stm << p->yen).good();
}
