#include<iostream>
using namespace std;

//�ڴ����ƪ
//new �� malloc
//malloc free��c��׼��ĺ���
//new delete ��c++�������

int test() {
	return 0;
}

class A {
protected:
	A() {}
	~A() {}
public:
	static A* create() { //��create�����ض�����A
		return new A();
	}

	void destroy() {
		delete this;
	}
};

class B {
private:
	void* operator new(size_t t) {} //����new��delete��Ȼ��ŵ�private���棬������ֹ�ڶ�����������
	void operator delete(void* ptr) {}
public:
	B() {}
	~B(){}
};

class C {
public:
	C() {};
	virtual ~C() {};
private:
	char a;
};

int a1;
//int main() {
//	const int *b = &a1;
//	static int a;
//	int* num = (int*)malloc(sizeof(int) * 10); //����
//	int* p = new int(256);
//	int* arr = new int[5](); //�������治��д����
//	for (int i = 0; i < 10; i++) *(num+i) = i;
//	cout << "static int a:" << a << " ��ַ" << (int)&a<<endl;
//	cout << "int a1:" << a1 << " ��ַ" << (int)&a1 << endl;
//	cout << "const int *b  :" << *b << " ��ַ" << (int)b << endl;
//	cout<<"num[9]:" << num[9] << " ��ַ" << (int)num<<endl;
//	cout << "int *p" << *p << " ��ַ " << (int)p << endl;
//	cout << "abcde" << " ��ַ " << (int)&("abcde") << endl;
//	free(num); 
//	delete p;
//
//	for (int i = 0; i < 5; i++) cout << arr[i] << " ";
//	delete[] arr;
//
//	C c;
//	cout << "sizeof c " << sizeof(c) << endl;//�麯���������ڴ����
//	return 0;
//}