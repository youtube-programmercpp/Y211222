// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "quote_t.h"

bool read_quote_t(std::istream &stm, quote_t* pVal)
{
	return read_date  (stm, &pVal->���t          )
	&&     read_price (stm, &pVal->����z      )
	&&     read_change(stm, &pVal->�O����        )
	&&     read_price (stm, &pVal->�����Y�i�S���j)
	;
}
bool write_quote_t(std::ostream &stm, const quote_t* p)
{
	return write_date  (stm, &p->���t          ) && stm << ',' 
	&&     write_price (stm, &p->����z      ) && stm << ',' 
	&&     write_change(stm, &p->�O����        ) && stm << ',' 
	&&     write_price (stm, &p->�����Y�i�S���j) && stm << '\n'
	;
}
