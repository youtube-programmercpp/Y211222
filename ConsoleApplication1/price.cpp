// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "price.h"
#include <ctype.h>

bool read_price(FILE* fp, struct price* pVal)
{
	char ch;
	if (fscanf(fp, " %c", &ch) == 1) {
		if (isdigit((unsigned char)ch)) {
			pVal->yen = ch - '0';
			for (;;) {
				if (fscanf(fp, "%c", &ch) == 1) {
					switch (ch) {
					case ',':
						continue;
					case '.':
						if (fscanf(fp, "%c", &ch) == 1) {
							if (isdigit((unsigned char)ch)) {
								pVal->sen = 10 * (ch - '0');
								if (fscanf(fp, "%c", &ch) == 1) {
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
bool write_price(FILE* fp, const struct price* p)
{
	if (p->sen)
		return fprintf(fp, "%d.%02d", p->yen, p->sen) > 0;
	else
		return fprintf(fp, "%d", p->yen) > 0;
}
