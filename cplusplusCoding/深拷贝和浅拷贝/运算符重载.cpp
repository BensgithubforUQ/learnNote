#include <iostream>
#include <string>
using namespace std;

//������������� = ��ֵ����� 
class Person {
	friend void test01();
public:
	//���캯��

	Person() {//Ĭ�ϵĹ��캯��

	}

	Person(int a,int b) {
		m_A = new int(a);//��ָ��m_Aά��������a��ֵ��������Ϊǳ������ԭ�򣬻ᵼ�¶����ڴ��ظ��ͷš�
		m_B = b;
	}

	~Person() {
		delete m_A;
		m_A = NULL;
		cout << "�ͷ�m_Aά���Ķ�������" << endl;//�����漰����������ǳ�������ڸ�ֵ����֮��
		//�ͻ����������������ֵ�����ʱ��ͬʱdelete�˱���ֵ�Ķ���ָ��Ķ����ڴ棬�ͻᱨ��
		//�����ڴ��ظ��ͷš�
	}

	Person& operator=(Person &p) {//��������
		//�������ṩ����ǳ����m_A = p.m_A;//ָ����ȣ������Ǵ��ݵ�ַ
		//Ӧ�����жϣ��Ƿ���������ݣ���������ͷţ�Ȼ�����
		if (m_A != NULL) {
			delete m_A;
			m_A = NULL;
		}
		//���
		m_A = new int(*p.m_A);//m_A�ǵ�ַ��*p.m_A��ֵ��new int�ǵ�ַ����˼���ڶ�������һ����ַ�����ֵ��Ȼ��ѵ�ַ��ֵ��m_A;
		//���ڷ����ú�ָ���ֵ����ǳ����������
		m_B = p.m_B;
		return *this;//this�������������þ����õ������������
	}

	//����==
	bool operator==(Person &p) {//!=����������Ҳ����һ����
		if ((*this->m_A == *p.m_A) && (this->m_B == p.m_B)) {
			return true;
		}
		else return false;
	}
private:
	int* m_A;
	int m_B;
};

void test01() {
	Person p1(1,1);
	Person p2,p3;
	p3 = p2 = p1;
	cout << *p3.m_A << endl;
	cout << p3.m_B << endl;
}

void test02() {
	Person p1(1, 1);
	Person p2(2, 1);
	if (p1 == p2) {
		cout << "yes" << endl;
	}
	else cout << "No" << endl;
}

int main() {
	//test01();
	test02();
	return 0;
}