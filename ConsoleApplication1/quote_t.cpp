// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "quote_t.h"

std::istream& operator>>(std::istream &stm, quote_t& r)
{
	return stm
		>> r.���t          
		>> r.����z      
		>> r.�O����        
		>> r.�����Y�i�S���j
		;
}
std::ostream& operator<<(std::ostream &stm, const quote_t& r)
{
	return stm
		<< r.���t           << ',' 
		<< r.����z       << ',' 
		<< r.�O����         << ',' 
		<< r.�����Y�i�S���j << '\n'
		;
}
