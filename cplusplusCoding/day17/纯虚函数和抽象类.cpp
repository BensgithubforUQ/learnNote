#include <iostream>
#include <string>
using namespace std;
//���麯���ͳ�����
class Base {//ֻҪһ������һ�����麯�����Ǿ��ǳ�����
	/*�������ص�
	1.�������޷�ʵ��������
	2.����������࣬������д�����еĴ��麯��������Ҳ���ڳ�����*/
public:
	virtual void func() = 0;//���麯��
};

class Son : public Base {//�̳и���base��base�ǳ����࣬����son����û��д���麯��
	//���Ҳ�ǳ�����
public:
};
class Son_x :public Base {//��д�˸����е��麯��
public:
	void func() {
		cout << "func�ĵ��ã�son_x)" << endl;
	}
};
//int main() {
//	//Base b_test;
//	//Son s_test;
//	Base* s_x = new Son_x;
//	s_x->func();
//	return 0;
//}