#include <iostream>
#include <string>
using namespace std;

//father class 1
class Animal { //��̳е������
public:
	int m_Age;
};
//sheep
class Sheep :virtual public Animal { //��virtual����̳��������������⣨����̳���������ͬ���͵����ݣ��������Դ�˷ѣ�
public:
	//������̳�֮��sheep���animal��̳е�m_age��һ��vbptr����һ��virtual base pointer
	//��������ָ��ָ�����һ��virtual base table������������¼����һ��ƫ������ͨ����ƫ������
	//�����������ҵ�Ψһ��һ����ַ����¼�����μ̳��еڶ�������̳е�����
private:

};
//Camelus
class Camelus :virtual public Animal {
public:

private:

};

//son class
class Alpaca :public Sheep, public Camelus {

};

//���μ̳У�alpacaͬʱ�̳���sheep��camelus�ĳ�Ա�ͳ�Ա����
void test01() {
	Alpaca a1;
	a1.Sheep::m_Age = 28;
	a1.Camelus::m_Age = 18;
	cout << "���䣨sheep��" << a1.Alpaca::Sheep::Animal::m_Age << endl;
	cout << "���䣨camelus��" << a1.Alpaca::Camelus::Animal::m_Age << endl;
	cout << "���䣨Alpaca��" << a1.m_Age << endl;
	//cout << "���䣨camelus��" << a1.Alpaca::Camelus::Animal::m_Age << endl;
}

//
//int main() {
//	test01();
//	return 0;
//}