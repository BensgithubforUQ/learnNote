#include "Phone.h"

Phone::Phone(const Phone& p) {
	number = p.number;
	type = p.type;
	cout << "�ÿ������캯����ʼ�� ���룺 " << number << " ����: " << type << endl;
}

Phone::Phone() {
	cout << "���޲ι��캯����ʼ��phone����" << endl;
}


Phone::Phone(int n, string t) :number(n), type(t) {
	//�ó�ʼ���б��ʼ��phone����
	cout << " phone?"  << endl;
}

int Phone::getNum() {
	return number;
}
string Phone::getStr(){
	return type;
}
void Phone::showPhone() {
	cout << "����� ���룺 " << number << " ����: " << type << endl;
}
Phone::~Phone() {
	cout << "����������������phone���͵Ķ���" << endl;
}