#include "cpModel.h"

namespace ben{
	/*����Person�����Ĺ��캯����*/
	void test_person_construct() {
		Person defaultPrsn;
		Person valuePrsn(2);
		Person copyPrsn(valuePrsn);
		defaultPrsn = copyPrsn;

		std::cout << " Get total person amount: " << Person::getPersonAmount() << std::endl;
	}
	 
	/*����customer���person��Ķ�̬*/
	void test_customer_getConsumeCount() 
	{
		Person* testCstmr = new Customer(2,2);
		std::cout << testCstmr->getPersonAmount()<<std::endl;
		delete testCstmr;
	}

	/*���Բ�Ʒ�ࣨhambuger�������Ĺ��캯����*/
	void test_product_makeHamburger() 
	{
		abstractProduct* hmbrgr = new Hamburger("chicken",21.00,"00000");
		hmbrgr->showAll();
	}

	/*���Ի�����vc++�Ķ��̲߳���*/
}

int main() {


	ben::test_person_construct();

	ben::test_customer_getConsumeCount();
	
	ben::test_product_makeHamburger();

	return 0;
}