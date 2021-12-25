// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "volume.h"
#include <ctype.h>

bool read_volume(std::istream& stm, volume* pVal)
{
	char ch;
	if (stm >> ch) {
		if (isdigit((unsigned char)ch)) {
			pVal->n = ch - '0';
			for (;;) {
				if (stm.read(&ch, 1)) {
					switch (ch) {
					case ',':
						continue;
					default:
						if (isdigit((unsigned char)ch)) {
							pVal->n *= 10;
							pVal->n += ch - '0';
							break;
						}
						else if (isspace((unsigned char)ch))
							return true;
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
bool write_volume(std::ostream &stm, const volume* p)
{
	return (stm << p->n).good();
}
