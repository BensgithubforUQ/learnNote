#include <iostream>
#include <string>
using namespace std;
//�������ʹ�������
/*��������������Կ����˶����ڴ棬�Ǹ���ָ�����ͷŵ�ʱ���޷����õ�������������룬
�����Ҫ�ڸ�����д�������ʹ�������*/
//�ö�̬��ʱ��������Ҫ�ڶ��������ڴ棬�ڸ���ָ���ͷŵ�ʱ����޷�ֱ�ӵ����������������
//��ʱ���Ҫ�Ѹ������������д���������������ߴ��������������������ܵ����������������
//��������������Ǹ��໹���ܿ���ʵ����
//���ʹ�ô����������Ǹ���Ҳ����˳����࣬����ʵ�����������ࣺ�д��麯�����ࡣ����ʵ������
class Animal1 {
public:
	Animal1() {
		cout << "animal1�Ĺ���" << endl;
	}
	virtual void speak() = 0;
	
	//virtual ~Animal1() {//������
	//	cout << "animal1������" << endl;
	//}
	virtual ~Animal1() = 0;//��������Ҳ���Խ��������⣬���Ǳ����к�����ʵ�֣�д�ڳ�������
	//�������˴�������֮�󣬸���Ҳ���ǳ������ˣ��޷�ʵ��������
};
Animal1::~Animal1() {//���������ĺ���ʵ��
	cout << "animal1�Ĵ�������" << endl;
}

class Cat1 :public Animal1{
public:
	Cat1(string name) {
		cout << "����cat" << endl;
		c_name = new string(name);
	}
	void speak() {
		cout << "cat "<<*c_name<<" speaks" << endl;
	}
	~Cat1() {
		if (c_name != NULL) {
			cout << "����cat" << endl;
			delete c_name;
			c_name = NULL;
		}
	}

private:
	string* c_name;
};

void test10() {
	Animal1* a = new Cat1("tom");//����ָ����������ʱ�򣬲�������������������
	//����������������ڶ��������ԣ��ͻ��޷��������ᵼ���ڴ�й©
	//��������ǰ������ĳ�������
	a->speak();
	delete a;
}
//
//int main() {
//	test10();
//	return 0;
//}