#pragma once
#include <map>
#include <iostream>
using namespace std;

/*map�ǹ��������������е�Ԫ�ض���pair����һ��ֵΪkey��ֵ���ڶ���Ԫ��Ϊvalueʵֵ
����Ԫ�ض������key��ֵ�Զ�����
�ײ�ṹ�Ƕ�����

�ŵ㣺���Ը���keyֵ�����ҵ�valueֵ������set���߱��ģ�setֻ�ܸ���ֵ�ҵ�����λ��
*/


void test_map0() {
	map<int, int>m0;
	m0.insert(pair<int, int>(1, 10))//pair<int, int>(1, 10)��һ��������pari����

}