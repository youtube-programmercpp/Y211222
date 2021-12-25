// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "quote_i.h"

bool read_quote_i(std::istream &stm, quote_i* pVal)
{
	return read_date (stm, &pVal->���t)
	&&     read_price(stm, &pVal->�n�l)
	&&     read_price(stm, &pVal->���l)
	&&     read_price(stm, &pVal->���l)
	&&     read_price(stm, &pVal->�I�l)
	;
}
bool write_quote_i(std::ostream &stm, const quote_i* p)
{
	return write_date (stm, &p->���t) && stm << ',' 
	&&     write_price(stm, &p->�n�l) && stm << ',' 
	&&     write_price(stm, &p->���l) && stm << ',' 
	&&     write_price(stm, &p->���l) && stm << ',' 
	&&     write_price(stm, &p->�I�l) && stm << '\n'
	;
}
