#include "Person.h"


Person::Person() {
	cout << "���޲ι��캯����ʼ������" << endl;
}
//Person::Person(int a,int h) {//�вι��캯�������ó�ʼ���б�֮��Ͳ���������
//	age = a;
//	m_height = new int(h);//��������д�������
//
//	cout << "���вι��캯����ʼ������" << endl;
//}
Person::Person(const Person& p) {//ǳ�������������Դ��Ŀ������캯��Ҳ��ǳ���� ��
	//�������������ݵ�ʱ�����ʹ��������������������ͷŶ����ڴ�
	age = p.age;//�����Ϊջ���Ƚ������ԭ�������ͷ��˱���ʼ���Ķ���Ķ����ڴ�
	//m_height = p.m_height;//����ǳ��������������ֽڵĿ���������ں��ͷ����ڳ�ʼ����Ķ����ԭ�����ʱ��
	//�ᷢ���ظ���������ԭ����Ķ����ڴ��Ѿ����ͷ��ˣ��������ٴ��ͷţ������һ�ַǷ�������
	//Ϊ�˽��������⣬����Ҫ�õ������
	//��ν����������ڳ�ʼ����ʱ����������һ�������ڴ��ô������¶�������ݡ�
	//�����Ͳ������ͷŵ�ʱ�����ظ��ͽ�������ͷš�
	m_height = new int(*p.m_height);
	//���������new int���¿�����һ������ڴ棬Ȼ���p��*���ַ�����ҰѸö����������Դ��뵽�¿��ٵĶ����ڴ�����
	//�����Ϳ��԰���������Ķ����ڴ�ֿ��������ǹ���ͬһ����
	//��������
	p_Phone = p.p_Phone;
	cout << "�ÿ������캯����ʼ������" << endl;
}
Person::~Person() {//����������ͨ�����ڽ��������ٵ������ͷš�
	if (*m_height != NULL) {
		delete m_height;
		m_height = NULL;
	}
	cout << "�����������������" << endl;
}

int Person::getAge() {
	return age;
}

int Person::getHeight() {
	return *m_height;
}

Person::Person(int a, int h,Phone p_0) :age(a), m_height(new int(h)), p_Phone(p_0) {
	cout << "person��" << endl;
}
void Person::showP() {
	p_Phone.showPhone();
}
	//private:
//	int age;
//int* m_height;//��ߣ���ָ������Ϊ��Ҫ�ڶ��������������

