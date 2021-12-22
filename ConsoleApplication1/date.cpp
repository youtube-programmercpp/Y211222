// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
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
	&& delim_year .w == ((const union dbc*)("�N"))->w
	&& delim_month.w == ((const union dbc*)("��"))->w
	&& delim_day  .w == ((const union dbc*)("��"))->w
	;
}
bool write_date(FILE* fp, const struct date* p)
{
	return fprintf(fp, "%04d/%02d/%02d", p->year, p->month, p->day) > 0;
}
