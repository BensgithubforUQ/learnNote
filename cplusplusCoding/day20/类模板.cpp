#include <iostream>
#include <string>
using namespace std;

//��ģ��
template<class nameType, class AgeType = int>//��ģ����ģ������б��п�����Ĭ�ϲ���������ģ���в�����
class People {
public:
	nameType m_name;
	AgeType m_age;
	//��ģ���еĳ�Ա�����Ĵ���ʱ��
	//����ͨ���У���Ա����������һ��ʼ�ʹ���
	//����ģ���У���Ա�����ڱ����õ�ʱ��Ŵ���,��ס������	
	void showPerson() {
		cout << this->m_name << " " << this->m_age << endl;
	}

	People(nameType name, AgeType age) {
		this->m_name = name;
		this->m_age = age;
	}
};
/*��ģ���������������*/
//1.ָ����������-ֱ����ʾ�������������*******����Ҫ����ã���ֱ�ӡ�
void printPerson1(People<string>& p) {//��ģ����ģ������б��п�����Ĭ�ϲ���������ģ���в�����,���Բ�дint
	p.showPerson();
}
//2.����ģ�廯-�������еĲ�����Ϊģ����д���
template<class nameType, class AgeType>//�ṩģ��
void printPerson2(People<nameType, AgeType>& p) {//����ģ�廯
	p.showPerson();
	cout << typeid(nameType).name() << endl;//����ͨ�����ַ�ʽ֪����ģ�����Զ��Ƶ���ʲô���͡�
	cout << typeid(AgeType).name() << endl;
}
//3.������ģ�廯-�������������ģ�廯���д���
template<class T>//�ṩģ��
void printPerson3(T &p) {
	p.showPerson();
	cout << typeid(T).name() << endl;
	//class People<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,int>
	//�õ�����������������Կ�����һ��class <string,int> ����
}
//��ģ��ͺ���ģ�������
/*
1.��ģ�壬û���Զ������Ƶ��ķ�ʽ����Ҫָ��
2.��ģ����ģ������б��п�����Ĭ�ϲ���
*/
//int main() {
//	People <string, int> p1("����", 30);//��ģ�壬û���Զ������Ƶ��ķ�ʽ����Ҫ��ʾָ������<string, int>
//	//p1.showPerson();
//	//People <string> p2("����", 30);//��ģ����ģ������б��п�����Ĭ�ϲ������Ѿ�������int���������ط�����������
//	//p2.showPerson();
//	printPerson1(p1);
//	printPerson2(p1);
//	printPerson3(p1);
//	return 0;
//}