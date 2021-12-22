// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "change.h"
#include <ctype.h>

static bool read_digit_sequence(FILE* fp, char* pch, bool minus, int* pVal)
{
	if (isdigit((unsigned char)*pch)) {
		for (*pVal = *pch - '0';;) {
			if (fscanf(fp, "%c", pch) == 1) {
				if (*pch == ',')
					continue;
				else if (isdigit((unsigned char)*pch)) {
					*pVal *= 10;
					*pVal += *pch - '0';
					continue;
				}
				else {
					if (minus)
						*pVal *= -1;
					return true;
				}
			}
			else
				return false;
		}
	}
	else
		return false;
}

bool read_change(FILE* fp, struct change* pVal)
{
	char ch;
	if (fscanf(fp, " %c", &ch) == 1) {
		switch (ch) {
		case '+':
			return fscanf(fp, "%c", &ch) == 1 && read_digit_sequence(fp, &ch, false, &pVal->n) && isspace((unsigned char)ch);
		case '-':
			return fscanf(fp, "%c", &ch) == 1 && read_digit_sequence(fp, &ch, true,  &pVal->n) && isspace((unsigned char)ch);
		case '0':
			if (fscanf(fp, "%c", &ch) == 1 && isspace((unsigned char)ch)) {
				pVal->n = 0;
				return true;
			}
			else
				return false;
		default:
			return false;
		}
	}
	else
		return false;
}
bool write_change(FILE* fp, const struct change* p)
{
	return fprintf(fp, "%d", p->n) > 0;
}
