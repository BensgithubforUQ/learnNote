#include <iostream>
#include <string>
using namespace std;
//���������Ƕ�̬
class Calculator {//����������������
public:
	int m_1;
	int m_2;
	int getResult(char oper) {//ʹ�÷Ƕ�̬��д���Ļ��������Ҫ��չ�µĹ��ܣ�����Ҫ�޸�Դ��
		//������ʵ�Ŀ����У��ᳫ����ԭ�򣺶���չ���п��������޸Ľ��йرա�
		switch(oper) {
			case '+':
				return m_2 +m_1;
				break;
			case '-':
				return m_2 - m_1;
				break;
			case '*':
				return m_2 * m_1;
				break;
			deafult:
				break;
		}
		return 0;
	}
};

void test_Calculator_normal() {//���ԷǶ�̬�ļ�������ļ�����������
	Calculator c;
	c.m_1 = 2;
	c.m_2 = 3;
	cout << "+ :" << c.getResult('+') << endl;
	cout << "- :" << c.getResult('-') << endl;
	cout << "* :" << c.getResult('*') << endl;
}
//���ö�̬ʵ�ּ�����
//��ʵ��һ��������ĳ����࣬���ࡣ
class abstractCalculator {//Ϊ�����ö�̬����Ҫ�и���
public:
	int m_1;
	int m_2;
	virtual int getResult() {//Ϊ�����ö�̬����Ҫ�ṩһ���麯�������Ӻ���ȥ��д
		return 0;
	};
};

//�ӷ��������࣬�̳и���
class AddCalculator : public abstractCalculator {
public:
	int getResult() {//Ϊ�����ö�̬������������д������麯��
		return m_1 + m_2;
	}
};
//�������������࣬�̳и���
class MinusCalculator : public abstractCalculator {
public:
	int getResult() {//Ϊ�����ö�̬������������д������麯��
		return m_1 - m_2;
	}
};
//�˷��������࣬�̳и���
class MultiplyCalculator : public abstractCalculator {
public:
	int getResult() {//Ϊ�����ö�̬������������д������麯��
		return m_1 * m_2;
	}
};
//�������������࣬�̳и���
class DivideCalculator : public abstractCalculator {
public:
	int getResult() {//Ϊ�����ö�̬������������д������麯��
		if (m_2 != 0) return m_1 / m_2;
		else {
			cerr << "error m_2 = 0" << endl; 
			return 0;
		}
	}
};

class SurplusCalculator: public abstractCalculator {
public:
	int getResult() {//Ϊ�����ö�̬������������д������麯��
		return m_1 % m_2;
	}
};

//�ɴ˿�����̬������
/*
1.��֯�ṹ����
2.�ɶ���ǿ
3.����ǰ�ںͺ��ڵ���չ��ά���Ը�
����ڿ���֮ǰ����Ҫ�࿼���Ƿ����ö�̬��ʵ�֣������Ϳ��԰ѿ�����ø��Ӽ򵥺�����*/
void test_Calculator_polymorphism() {//���Զ�̬�ļ�������ļ�����������
	abstractCalculator *abc0 = new AddCalculator;//������̬,�ڶ�������һ�������ָ��
	abc0->m_1 = 3;
	abc0->m_2 = 2;
	cout << "+ :" << abc0->getResult() << endl;
	delete abc0;
	abstractCalculator* abc1 = new MinusCalculator;//������̬,�ڶ�������һ�������ָ��
	abc1->m_1 = 3;
	abc1->m_2 = 2;
	cout << "- :" << abc1->getResult() << endl;
	delete abc1;
	abstractCalculator* abc2 = new MultiplyCalculator;//������̬,�ڶ�������һ�������ָ��
	abc2->m_1 = 3;
	abc2->m_2 = 2;
	cout << "* :" << abc2->getResult() << endl;
	delete abc2;
	abstractCalculator* abc3 = new DivideCalculator;//������̬,�ڶ�������һ�������ָ��
	abc3->m_1 = 3;
	abc3->m_2 = 2;
	cout << "/ :" << abc3->getResult() << endl;
	delete abc3;
	abstractCalculator* abc4 = new SurplusCalculator;//������̬,�ڶ�������һ�������ָ��
	abc4->m_1 = 3;
	abc4->m_2 = 2;
	cout << "% :" << abc4->getResult() << endl;
	delete abc4;
}

//int main() {
//	test_Calculator_normal();
//	test_Calculator_polymorphism();
//	return 0;
//}