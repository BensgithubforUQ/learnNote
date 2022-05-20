#include <iostream>
#include <string>
using namespace std;

class animal_nonPolymorphism {
public:
	void speak() {
		cout << "animal speak" << endl;
	}
};

class animal_Polymorphism {
public:
	virtual void speak() {
		cout << "animal speak" << endl;
	}
};

class cat: public animal_nonPolymorphism {
public:
	void speak() {
		cout << "cat speak" << endl;
	}
};
class dog : public animal_Polymorphism {
public:
	void speak() {
		cout << "dog speak" << endl;
	}
};

void test_sizeof() {
	animal_nonPolymorphism a_n0;
	animal_Polymorphism a_0;
	cat c_n0;
	dog d_0;
	cout << "animal_nonPolymorphism memory size:" << sizeof(a_n0) << endl;
	cout << "animal_Polymorphism memory size:" << sizeof(a_0) << endl;
	cout << "cat memory size:" << sizeof(c_n0) << endl;//��x64�����У�һ��vfptrָ��ռ8���ֽڡ�
	cout << "dog memory size:" << sizeof(d_0) << endl;
}
//int main() {
//	//Polymorphism��̬��
//	test_sizeof();
//	system("pause");
//	return 0;
//}