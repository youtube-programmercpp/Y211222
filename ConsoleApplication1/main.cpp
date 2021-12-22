// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "quote_t.h"
#include "quote_i.h"
#include "quote_s.h"

int read_header(FILE* fp)
{
	for (int columns = 1;;) {
		switch (fgetc(fp)) {
		case EOF:
			return 0;
		case '\t':
			++columns;
			continue;
		case '\n':
			return columns;
		}
	}
}
int to_csv_t(const char* filename)
{
	FILE* const fp = fopen(filename, "r");
	if (fp) {
		int rows = 0;
		const int columns = read_header(fp);
		if (columns == 4) {
			for (struct quote_t rec; read_quote_t(fp, &rec); ++rows)
				write_quote_t(stdout, &rec);
		}
		fclose(fp);
		return rows;
	}
	else
		return 0;
}
int to_csv_i(const char* filename)
{
	FILE* const fp = fopen(filename, "r");
	if (fp) {
		int rows = 0;
		const int columns = read_header(fp);
		if (columns == 5) {
			for (struct quote_i rec; read_quote_i(fp, &rec); ++rows)
				write_quote_i(stdout, &rec);
		}
		fclose(fp);
		return rows;
	}
	else
		return 0;
}
int to_csv_s(const char* filename)
{
	FILE* const fp = fopen(filename, "r");
	if (fp) {
		int rows = 0;
		const int columns = read_header(fp);
		if (columns == 7) {
			for (struct quote_s rec; read_quote_s(fp, &rec); ++rows)
				write_quote_s(stdout, &rec);
		}
		fclose(fp);
		return rows;
	}
	else
		return 0;
}
int main()
{
	to_csv_i("..\\998407.txt");
	to_csv_s("..\\8316.txt");
	to_csv_t("..\\01312055.txt");
}
