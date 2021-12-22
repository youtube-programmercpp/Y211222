// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// 当 YouTube チャンネルをご覧いただいている皆さまのための学習用ソースコードです。再頒布と商業利用は許可しません。
#define	_CRT_SECURE_NO_WARNINGS
#include "date.h"
#include "dbc.h"

bool read_date(FILE* fp, struct date* pVal)
{
	union dbc delim_year ;
	union dbc delim_month;
	union dbc delim_day  ;
	return fscanf
	( fp
	, "%d%2c%d%2c%d%2c"
	, &pVal->year , delim_year .s
	, &pVal->month, delim_month.s
	, &pVal->day  , delim_day  .s
	) == 6
	&& delim_year .w == ((const union dbc*)("年"))->w
	&& delim_month.w == ((const union dbc*)("月"))->w
	&& delim_day  .w == ((const union dbc*)("日"))->w
	;
}
bool write_date(FILE* fp, const struct date* p)
{
	return fprintf(fp, "%04d/%02d/%02d", p->year, p->month, p->day) > 0;
}
