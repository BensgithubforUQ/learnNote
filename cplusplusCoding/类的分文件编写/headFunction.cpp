#include "person.h"

void test0() {
	Phone phone_0(45591901, "ŵ����");
	Phone phone_1(phone_0);
	Person p1(18, 150,phone_0);//���вι��캯����ʼ������p1,���Ҹ�ֵ18
	cout << "p1������Ϊ��" << p1.getAge() << "���Ϊ�� " << p1.getHeight() << endl;
	p1.showP();
	Person p2(p1);//���ÿ������캯������һ��p1
	cout << "p2������Ϊ��" << p2.getAge() << "���Ϊ�� " << p2.getHeight() << endl;
	p2.showP();
}

