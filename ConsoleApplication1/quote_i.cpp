// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#include "quote_i.h"

std::istream& operator>>(std::istream &stm, quote_i& r)
{
	return stm
		>> r.���t
		>> r.�n�l
		>> r.���l
		>> r.���l
		>> r.�I�l
		;
}
std::ostream& operator<<(std::ostream &stm, const quote_i& r)
{
	return stm
		<< r.���t << ',' 
		<< r.�n�l << ',' 
		<< r.���l << ',' 
		<< r.���l << ',' 
		<< r.�I�l << '\n'
		;
}
