// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "date.h"
#include "dbc.h"
#include <iomanip>

bool read_date(std::istream &stm, date* pVal)
{
	dbc delim_year ;
	dbc delim_month;
	dbc delim_day  ;
	return stm && stm >> pVal->year  && stm.read(delim_year .s, sizeof delim_year .s)
	           && stm >> pVal->month && stm.read(delim_month.s, sizeof delim_month.s)
	           && stm >> pVal->day   && stm.read(delim_day  .s, sizeof delim_day  .s)
	           && delim_month.w == reinterpret_cast<const dbc*>("��")->w
	           && delim_day  .w == reinterpret_cast<const dbc*>("��")->w
	;
}
bool write_date(std::ostream &stm, const date* p)
{
	return (stm 
		<< std::setfill('0')
		<<        std::setw(4) << p->year 
		<< '/' << std::setw(2) << p->month
		<< '/' << std::setw(2) << p->day  
		<< std::setfill(' ')
		).good();
}
