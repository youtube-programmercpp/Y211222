// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#include "quote_t.h"
#include "quote_i.h"
#include "quote_s.h"
#include <iostream>

#ifdef WinINet対応
#include <Windows.h>
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
#include <sstream>
#else
#include <fstream>
#endif

#ifdef WinINet対応
std::string InternetReadFile(_In_ HINTERNET hFile)
{
	std::string buf;
	for (;;) {
		const auto original_size = buf.size();
		buf.resize(original_size + 128 * 1024);
		DWORD cbRead;
		if (InternetReadFile
		( /*_In_                                                                 HINTERNET hFile                */hFile
		, /*_Out_writes_bytes_(dwNumberOfBytesToRead) __out_data_source(NETWORK) LPVOID    lpBuffer             */&buf[original_size]
		, /*_In_                                                                 DWORD     dwNumberOfBytesToRead*/static_cast<DWORD>(buf.size() - original_size)
		, /*_Out_                                                                LPDWORD   lpdwNumberOfBytesRead*/&cbRead
		)) {
			if (cbRead) {
				buf.resize(original_size + cbRead);
				continue;
			}
			else {
				buf.resize(original_size);
				return buf;//eof
			}
		}
		else {
			buf.resize(original_size);
			return buf;//error
		}
	}
}
std::string string_from_utf8(const std::string& s)
{
	if (const auto cbMultiByte = s.length()) {
		std::wstring w;
		w.resize(cbMultiByte);
		if (const auto cchWideChar = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), static_cast<int>(cbMultiByte), &w.front(), static_cast<int>(w.size()))) {
			std::string retval;
			retval.resize(2 * cchWideChar);
			retval.resize(WideCharToMultiByte(CP_ACP, 0, w.c_str(), cchWideChar, &retval.front(), static_cast<int>(retval.size()), nullptr, nullptr));
			return retval;
		}
	}
	return {};
}
template<size_t n>bool extract(const std::string& s, const char (&leading_seq)[n], size_t& offset, std::string& value)
{
	const auto i = s.find(leading_seq, offset);
	if (i == std::string::npos)
		return false;
	else {
		const auto j = i + n - 1;
		const auto k = s.find('<', j);
		if (k == std::string::npos)
			return false;
		else {
			value = s.substr(j, k - j);
			offset = k + 1;
			return true;
		}
	}
}
#endif
template<class T>struct to_csv {
	static const int column_count;
	std::ostream& ostm;
#ifdef WinINet対応

	static bool extract(const std::string& s, size_t& offset, std::ostream& ostm);
	static bool extract(const std::string& s, size_t& offset, T& rec)
	{
		std::stringstream stm;
		return extract(s, offset, stm) && (stm >> rec);
	}
	void operator()(HINTERNET hInternet, LPCSTR code) const
	{
		if (const std::unique_ptr<std::remove_pointer_t<HINTERNET>, decltype(InternetCloseHandle)*> hFile = { InternetOpenUrlA
			( /*_In_                            HINTERNET hInternet      */hInternet
			, /*_In_                            LPCSTR    lpszUrl        */(std::ostringstream() << "https://finance.yahoo.co.jp/quote/" << code << "/history").str().c_str()
			, /*_In_reads_opt_(dwHeadersLength) LPCSTR    lpszHeaders    */nullptr
			, /*_In_                            DWORD     dwHeadersLength*/0
			, /*_In_                            DWORD     dwFlags        */0
			, /*_In_opt_                        DWORD_PTR dwContext      */0
			), InternetCloseHandle }) {
			const auto s = InternetReadFile(hFile.get());
			size_t offset = 0;
			T rec;
			if (extract(s, offset, rec)) {
				do
					ostm << rec;
				while (extract(s, offset, rec));
			}
		}
	}
#else
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
#endif
};
const int to_csv<quote_i>::column_count = 5;
const int to_csv<quote_s>::column_count = 7;
const int to_csv<quote_t>::column_count = 4;

bool to_csv<quote_i>::extract(const std::string& s, size_t& offset, std::ostream& ostm)
{
	std::string 日付;
	if (::extract(s, R"( class="EqUxtc2p">)", offset, 日付)) {
		ostm << string_from_utf8(日付);
		for (int i = 1; i < column_count; ++i) {
			std::string cell;
			if (::extract(s, R"( class="_3bYcwOHa">)", offset, cell))
				ostm << '\t' << cell;
			else
				return false;
		}
		ostm << "\r\n";
		return true;
	}
	else
		return false;
}
bool to_csv<quote_s>::extract(const std::string& s, size_t& offset, std::ostream& ostm)
{
	std::string 日付;
	if (::extract(s, R"( class="UV2ePijJ _1whprju-">)", offset, 日付)) {
		ostm << string_from_utf8(日付);
		for (int i = 1; i < column_count; ++i) {
			std::string cell;
			if (::extract(s, R"( class="_3rXWJKZF">)", offset, cell))
				ostm << '\t' << cell;
			else
				return false;
		}
		ostm << "\r\n";
		return true;
	}
	else
		return false;
}
bool to_csv<quote_t>::extract(const std::string& s, size_t& offset, std::ostream& ostm)
{
	std::string 日付;
	if (::extract(s, R"( class="_5JhkogOn">)", offset, 日付)) {
		ostm << string_from_utf8(日付);
		for (int i = 1; i < column_count; ++i) {
			std::string cell;
			if (::extract(s, R"( class="_3BGK5SVf">)", offset, cell)) {
				ostm << '\t';
				if (i == 2 && cell != "0" && cell.front() != '-')
					ostm << '+';
				ostm << cell;
				
			}
			else
				return false;
		}
		ostm << "\r\n";
		return true;
	}
	else
		return false;
}

int main()
{
#ifdef WinINet対応
	if (const std::unique_ptr<std::remove_pointer_t<HINTERNET>, decltype(InternetCloseHandle)*> hInternet{ InternetOpenA
	( /*_In_opt_ LPCSTR lpszAgent      */"Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)"
	, /*_In_     DWORD  dwAccessType   */INTERNET_OPEN_TYPE_PRECONFIG
	, /*_In_opt_ LPCSTR lpszProxy      */nullptr
	, /*_In_opt_ LPCSTR lpszProxyBypass*/nullptr
	, /*_In_     DWORD  dwFlags        */0
	), InternetCloseHandle }) {
		to_csv<quote_i>{std::cout}(hInternet.get(), "998407.O");
		to_csv<quote_s>{std::cout}(hInternet.get(), "8316.T"  );
		to_csv<quote_t>{std::cout}(hInternet.get(), "01312055");
	}
#else
	std::ifstream("..\\998407.txt"  ) >> to_csv<quote_i>{std::cout};
	std::ifstream("..\\8316.txt"    ) >> to_csv<quote_s>{std::cout};
	std::ifstream("..\\01312055.txt") >> to_csv<quote_t>{std::cout};
#endif
}
