#pragma once
#include <functional>
#include <iostream>
using namespace std;

//�����º���
/*
template <class T> T plus<T> //�ӷ��º���
template <class T> T minus<T> //�����º���
template <class T> T multiples<T> //�˷��º���
template <class T> T divides<T> //�����º���
template <class T> T modulus<T> //ȡģ�º���
template <class T> T negate<T> //ȡ���º���
*/

void test_negate() {
	//negate һԪ���� ȡ��
	negate<int>negate_int;
	int num = 10;
	num = negate_int(num);
	cout << "negate_int(num):" << num << endl;
}

void test_plus() {
	//add ��Ԫ���� ��
	plus<int>plus_int;
	int num1 = 1, num2 = 2;
	int sum = plus_int(num1, num2);
	cout << "plus_int(num1, num2):" << sum << endl;
}