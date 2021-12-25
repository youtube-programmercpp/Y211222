// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_t.h"
#include "quote_i.h"
#include "quote_s.h"
#include <fstream>
#include <iostream>

int read_header(std::istream &stm)
{
	for (int columns = 1;;) {
		switch (stm.get()) {
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
	auto stm = std::ifstream(filename);
	if (stm) {
		int rows = 0;
		const int columns = read_header(stm);
		if (columns == 4) {
			for (quote_t rec; read_quote_t(stm, &rec); ++rows)
				write_quote_t(std::cout, &rec);
		}
		return rows;
	}
	else
		return 0;
}
int to_csv_i(const char* filename)
{
	auto stm = std::ifstream(filename);
	if (stm) {
		int rows = 0;
		const int columns = read_header(stm);
		if (columns == 5) {
			for (quote_i rec; read_quote_i(stm, &rec); ++rows)
				write_quote_i(std::cout, &rec);
		}
		return rows;
	}
	else
		return 0;
}
int to_csv_s(const char* filename)
{
	auto stm = std::ifstream(filename);
	if (stm) {
		int rows = 0;
		const int columns = read_header(stm);
		if (columns == 7) {
			for (quote_s rec; read_quote_s(stm, &rec); ++rows)
				write_quote_s(std::cout, &rec);
		}
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
