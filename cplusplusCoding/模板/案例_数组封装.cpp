#include <iostream>
#include <string>
#include "goldenFingerArray.hpp"
using namespace std;

/*����
1.���Դ��������������͵Ķ�����Զ����������͵Ķ���
2.�������е����ݴ�ŵ�����
3.���캯���п��Դ������������
4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=�����ط�ֹǳ����
5.�ṩβ�巨��βɾ�����������ӻ���ɾ�������е�����
6.����ͨ���±����
7.���Ի�ȡ�����е�ǰԪ�صĸ���������*/
class cat {//�Զ����������ͣ����ڲ���
public:
	cat() {

	}
	cat(string n, int a);
	//cat(string n, int a) {
	//	this->name = n;
	//	this->age = a;
	//}
	string name;
	int age;
};

cat::cat(string n, int a) :name(n), age(a) {
	cout << "��ʼ���б��ʼ��cat�����" << endl;
}

void test_goldenFingerArr_0() {
	goldenFingerArray<int>arr1(5);//�����вι���
	goldenFingerArray<int>arr2(arr1);//���Կ�������
	cout << endl;	goldenFingerArray<int>arr3(100);
	arr3 = arr2;//�������صĲ�����"="
}

void test_goldenFingerArr_1() {
	goldenFingerArray<int>arr1(5);//�����вι���
	for (int i = 0; i < 6; i++) {
		arr1.Push_Back(i);//����β�巨�������ݣ����Ҳ��Գ������������
	}
	cout << "arr1��ӡΪ" << endl;
	arr1.showArrInfo();

	arr1.Pop_Back();
	arr1.Push_Back(6);

	arr1.showArrInfo();
	cout << "���±���ʣ�" << arr1[4] << endl;
}

void test_goldenFingerArr_2() {
	//�����Զ������������
	cat kitty("kitty", 10);
	cat tom("tom", 20);
	goldenFingerArray<cat>arr1(5);
	arr1.Push_Back(kitty);
	arr1.Push_Back(tom);
	cout << "������" << arr1.getCapacity() << " ���ȣ� " << arr1.getSize() << endl
		<<arr1[1].name<<endl;
	//arr1.showArrInfo();
}
int main() {
	//test_goldenFingerArr_0();
	//test_goldenFingerArr_1();
	test_goldenFingerArr_2();
	system("pause");
	return 0;
}