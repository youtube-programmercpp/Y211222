// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_t.h"
#include "quote_i.h"
#include "quote_s.h"
#include <fstream>
#include <iostream>

template<class T>struct to_csv {
	std::ostream& ostm;

	static const int column_count;
	friend std::istream& operator>>(std::istream& istm, to_csv&& r)
	{
		if (istm) {
			const int columns = [&istm]()->int
			{
				for (int retval = 1;;) {
					switch (istm.get()) {
					case EOF:
						return 0;
					case '\t':
						++retval;
						continue;
					case '\n':
						return retval;
					}
				}
			}();
			if (columns == column_count) {
				for (T rec; istm >> rec;)
					r.ostm << rec;
			}
		}
		return istm;
	}
};
const int to_csv<quote_i>::column_count = 5;
const int to_csv<quote_s>::column_count = 7;
const int to_csv<quote_t>::column_count = 4;
int main()
{
	std::ifstream("..\\998407.txt"  ) >> to_csv<quote_i>{std::cout};
	std::ifstream("..\\8316.txt"    ) >> to_csv<quote_s>{std::cout};
	std::ifstream("..\\01312055.txt") >> to_csv<quote_t>{std::cout};
}
