// Copyright(C) 2021 https://www.youtube.com/c/ProgrammerCpp
// �� YouTube �`�����l�����������������Ă���F���܂̂��߂̊w�K�p�\�[�X�R�[�h�ł��B�ĔЕz�Ə��Ɨ��p�͋����܂���B
#pragma once
#include <istream>
#include <ostream>
struct price {
	int yen;
	int sen;
	friend std::istream& operator>>(std::istream& stm,       price& r);
	friend std::ostream& operator<<(std::ostream& stm, const price& r);
};
