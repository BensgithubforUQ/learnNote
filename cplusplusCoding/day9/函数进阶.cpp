#include <iostream>
#include <string>
using namespace std;

int func(int a, int b, int c) {
	int sum = a + b + c;
	return sum;
}

//ע��������ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ�����󣬴����ң���������Ĭ��ֵ��
//int func0(int a, int b = 10, int c ) {
//	int sum = a + b + c;
//	return sum;
//}
int func1(int a, int b = 10, int c = 100) {
	int sum = a + b + c;
	return sum;
}
//ע��������������������Ĭ��ֵ��������ʵ�־Ͳ�����Ĭ��ֵ��ֻ��������һ����Ĭ�ϲ�������Ȼ�ͻ��������ֵ��
int func2(int a=10, int b = 20);

//int func2(int a = 10, int b = 20) {
//	int sum = a + b;
//	return sum;
//}

//�������أ�

int func2(int a, int b) {
	int sum = a + b;
	return sum;
}

int func2(int a) {
	int sum = a + 10;
	return sum;
}

int func2() {
	int sum = 10 + 10;
	return sum;
}

double func2(double a,double b) {
	double sum = a + b;
	return sum;
}

//������Ϊ���ص�Ĭ������
void func3(int& a) {//�ֲ��������ڴ�����
	cout << "func3(int&a)����" << endl;
}
void func3(const int& a) {//ȫ�ֱ�������ȫ����
	cout << "func3(const int&a)����" << endl;
}
//const int &a��int&a���Ͳ�ͬ�����ؿ���ʵ��

//2.������������Ĭ�ϲ������п��ܳ������壬Ӧ�þ������⣩
void func4(int a,int b) {
	cout << "func��int a,int b = 10���ĵ���" << endl;
}

void func4(int a) {
	cout << "func��int a���ĵ���" << endl;
}
//��������ͻ���ֶ����ԣ��ᵼ�±���



int main() {
	int a = 1, b = 2, c = 3;
	int sum = func(a, b, c);//�β�û�г�ʼ��������£���������ȫ���ββ����������ú�����
	int sum1 = func1(a, 1010);
	cout << "sum = " << sum << endl;//�β��г�ʼ��������£�����ʹ�ô�����βε�ֵ�����û�У����ó�ʼ����ֵ��
	cout << "sum1 = " << sum1 << endl;
	int sum2 = func2(a, 1010);
	cout << "sum2 = " << sum2 << endl;
	double a_d = 3.14, b_d = 3.14;
	cout << "sum2_d= " << func2(a_d, b_d);
	//func4();
	return 0;
}