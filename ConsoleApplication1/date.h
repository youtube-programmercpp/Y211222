// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <istream>
#include <ostream>
struct date {
	int year ;
	int month;
	int day  ;
	friend std::istream& operator>>(std::istream& stm,       date& r);
	friend std::ostream& operator<<(std::ostream& stm, const date& r);
};
