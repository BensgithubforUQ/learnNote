#include <iostream>
#include <string>
#include "stl_class.h"
#include "predicate.h"
#include "arithmetic_functor.h"
#include "relation_functor.h"
#include "logic_functor.h"
using namespace std;

/*stl��������
���ز��ݵ��ò��������࣬�����Ǹ��࣬������Ϊ��������
����ʹ�õ�ʱ������������Խзº���*/
/*
1.�����в����������з���ֵ��
2.������ͨ�����ĸ������ӵ���Լ���״̬
3.�������������Ϊ�������д���
*/

/*��������Ϊbool�ķº�����Ϊν��
operator()����һ��������ΪһԪν��
operator()��������������Ϊ��Ԫν��*/

/*�ڽ���������
�����º���
��ϵ�º���
�߼��º���

��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>*/

int main() {
	/*test0();
	test1();
	test2();
	predicate0();*/
	//predicate1();
	//test_negate(); //�ڽ��������������º�����һԪ���㣬negate��ȡ��
	//test_plus();//�ڽ��������������º�������Ԫ���㣬plus��ȡ��
	//��ϵ�º���
	//test_greater();
	test_logical_not();
;	return 0;
}