#include <iostream>
#include <string>
#include "myHead.h"
using namespace std;

//int main() {
//	int num1 = 1,num2 = 2,num3 =3,num4 = 4;
//	int* p1 = &num1; //ָ�룬���Ըĵ�ַ��p����Ҳ���Ը�ָ���ֵ��*p����
//	const int* p2 = &num2;//����ָ�루�����Ըģ�*p�������Ը�p����ĵ�ַ
//	int* const p3 = &num3;//ָ�볣���������Ը�p����ĵ�ַ�����Ը�pָ���ֵ��
//	const int* const p4 = &num4;
//	
//	
//	//ָ�룬���Ըĵ�ַ��p����Ҳ���Ը�ָ���ֵ��*p����
//	cout << p1 << " " << *p1 << endl;
//	p1 = &num2;
//	*p1 = num1;
//	cout << p1 << " " << *p1 << endl;
//	cout << endl;
//	//����ָ�루�����Ըģ�*p�������Ը�p����ĵ�ַ
//	cout << p2 << " " << *p2 << endl;
//	p2 = &num3;
//	//*p2 = num3;
//	cout << p2 << " " << *p2 << endl;
//	cout << endl;
//	//ָ�볣���������Ը�p����ĵ�ַ�����Ը�pָ���ֵ��
//	cout << p3 << " " << *p3 << endl;
//	*p3 = num4;
//	//p3 = num4;
//	cout << p3 << " " << *p3 << endl;
//	cout << endl;
//
//	//ʲô�����ܸ�
//	cout <<" p1" << p1 << " " << *p1 << endl;
//	cout << " p1" << p2 << " " << *p2 << endl;
//	cout << " p1" << p3 << " " << *p3 << endl;
//	cout << " p1" << p4 << " " << *p4 << endl;
//	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
//	swap(num1, num3);
//	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
//	int temp1 = add(num2, num3);
//	swap(temp1, num1);
//	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
//
//	return 0;
//}