#include <iostream>
#include <string>
using namespace std;

class Person;

class Person {
	friend ostream& operator<< (ostream& cout, const Person& p);
	friend Person operator+(Person& p1, Person& p2);
	friend Person operator+(const Person& p1, int a);
	friend Person operator-(Person& p1, Person& p2);
	friend Person operator-(const Person& p1, int a);
public:
	//��Ա��������+�������
	//Person operator+ (Person &p1) {
	//	Person temp;
	//	temp.m_A = this->m_A + p1.m_A;
	//	temp.m_B = this->m_B + p1.m_B;
	//	return temp;
	//}
	Person(int a, int b) :m_A(a), m_B(b) {
	}
	Person() {//���{}һ��Ҫд����Ȼ�ͻ��޷����ɾ���ĺ���ģ�壬����Ҫ���ù��캯����ʱ��ͻᱨ��
		//�޷��������ⲿ����

	}
	void getValue();
	Person& operator++();
	const Person& operator++(int); //���õ����ã�int����ռλ����


private:
	int m_A;
	int m_B;
	int* m_C;
};

void Person::getValue() {
	cout << "m_A = " << m_A << endl;
	cout << "m_B = " << m_B << endl;
}

Person operator+(Person& p1, Person& p2) {//ȫ�ֺ������ؼӷ������
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

Person operator+(const Person& p1, int a) {//ȫ�ֺ������ؼӷ������ 	
									//���������Ҳ���Է�����������
	Person temp;
	temp.m_A = p1.m_A + a;
	temp.m_B = p1.m_B + a;
	return temp;
}

Person operator-(Person& p1, Person& p2) {//ȫ�ֺ������ؼ��������
	Person temp;
	temp.m_A = p1.m_A - p2.m_A;
	temp.m_B = p1.m_B - p2.m_B;
	return temp;
}

Person operator-(const Person& p1, int a) {//ȫ�ֺ������ؼ�������� 	
									//���������Ҳ���Է�����������
	Person temp;
	temp.m_A = p1.m_A - a;
	temp.m_B = p1.m_B - a;
	return temp;
}

ostream& operator<< (ostream &cout,const Person &p) {
	//ȫ�ֺ����������������
	//cout��ostream���͵Ķ�����ֻ��һ�������Բ��ܴ����µģ�ֱ�Ӵ����ַ������
	//һ�㲻�ó�Ա�������������������
	//��Ϊ�����Ա������д��Ϊ ostream& operator<<(ostream&cout��
	//����д�����յõ�����p << cout�����������ص�����
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}



Person& Person::operator++() {//���ص�ַ��ԭ������Ϊ��
	/*++p�Ǽ�¼����֮���ֵ��ֱ�ӷ��ؽ��ֵ����Ϊ��ʵ��++��++p�����ֹ���
	���뱣֤ÿ��++�Ķ�����ԭ���Ǹ�����ֻ���õ�ַ���ݲ���ʵ����һ������
	ֵ���ݻᵼ�µڶ��β�û���õ���ʼ���Ǹ�����*/
	this->m_A++;
	this->m_B++;
	return *this;
}

 const Person& Person::operator++(int ) {//���ܷ��ص�ַ��ԭ������Ϊ��
	//���õ��������ȼ�¼��ǰ�����Ȼ��++��Ȼ�󷵻ؼ�¼�Ľ��
	/*����cout<<p++;���Ǵ�ӡ����p++֮ǰ��ֵ��������p+1��ֵ
	����ζ�����Ƿ��ص���p��ֵ������Ҫʵ��++���������õ�ַ++��Ȼ�󷵻�ԭ����ֵ*/
	Person const *temp = this;//��һ������ָ���¼��ǰ�����ֵ
	this->m_A++;
    this->m_B++;//����thisָ��ָ��ĵ�ǰ��������ԣ��޸ĵ�ǰ�����ֵ��
	return  (*temp) - 1;//���ؼ�¼��ֵ
}
 
void test_add_operator() {
	Person p_1(10, 10);
	Person p_2(1, 1);
	Person p_3 = p_1 + p_2;//�Ѿ������˵ļӺ���������򻯰棬���ʵ��þ����������ú�����
	Person p_4 = p_1 + 10;
	p_3.getValue();
	p_4.getValue();
}
void test_leftMove_operator() {
	Person p_1(10, 11);
	cout << p_1<<endl; //ȫ�ֺ����������������,��֤
}

void test_upward_operator() {
	Person p_1(10, 11);
	Person p_2(10, 11);
	cout << (++p_1)++ << endl; //ȫ�ֺ�������ǰ��++,��֤��Ԥ���ӡ
	//cout << (p_2++)++ << endl; //ȫ�ֺ������غ���++,��������
	cout << (p_2++)<< endl; //ȫ�ֺ������غ���++,
	cout << p_2 << endl; //ȫ�ֺ������غ���++,��֤
}
int main() {
	test_add_operator();

	test_leftMove_operator();
	cout << "++h,h++" << endl;
	test_upward_operator();
	

	//����һ��++������
	int a = 1;
	//cout << (a++)++ << endl;//(a++)++�ǲ�����ģ���Ϊc++��a++���ص���һ������
	cout << a++ << endl;;
	cout << (++a)++ << endl; //�������
	//cout << ++(a++) << endl; //����ֲ�����
	cout << a << endl;
	system("pause");
	return 0;
}