#include<iostream>
#include"factory.hpp"
#include"abstractFactory.hpp"
using namespace std;

void test_factory() {
	//����ģʽ
	Factory* fac = new ConcreteFactory();
	Product* pro = fac->CreateProduct();
	delete fac;
	delete pro;
	//�������ԣ�����factory��product�������ù��������create��Ʒ�����⣬û�й�ϵ������˳����ء�
	//����ģʽ���������ڣ����칤���࣬Ȼ�����createXXX����(�÷��������װ��new XXX�Ĳ���)����������XXX�Ĳ���������
	//ȱ�����ڣ�����XXX��YYY��Ʒ����Ҫ����һ���µ�XXX����������µ�YYY�����࣬Ȼ��Ҫ������Ҫ��new�ù�����������鷳�ĵ��ˡ�
	//�ؼ���������౬ը��
}

void test_abstract_factory() {
	//���󹤳�ģʽ-factoryģʽʵ��new����factory��Ȼ��factory��������ʵ�ֶ�product��Ķ���Ĵ�������һ��������ۺ϶����Ʒ
	AbstractFactory* ab_fac = nullptr;
	ab_fac = new ChineseFactory;
	AbstractApple *apple =  ab_fac->createApple();
	AbstractBanana* banana = ab_fac->createBanana();

	apple->showName();
	banana->showName();

	delete banana;
	delete apple;
	delete ab_fac;
	//�ŵ㣬������౬ը�����⡣
	//ȱ�㣬����౬ը�ķ�������������չ��Ʒ���ʱ����Ҫ�ڹ�����Ļ��������������ӷ�������չ�ѡ�
}

int main() {
	
	test_abstract_factory();
	
	return 0;
}