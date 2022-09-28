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
		abstractProduct* hmbrgr = new Hamburger("chicken",21.00,0000);
		hmbrgr->showAll();
	}

	/*���Ի�����vc++�Ķ��̲߳���*/
	void test_thread_mutex_condition()
	{

		std::thread testThread[15];
		for (int i = 0; i < 15; i++)
		{
			int tar = (i >> 1) & 1;
			if (tar)
			{
				Person* tmpP = new hamburgerMaker(i + 1);
				testThread[i] = std::thread(produce, tmpP);
			}
			else
			{
				Person* tmpP = new Customer(i + 1, i + 1);
				testThread[i] = std::thread(consum, tmpP);
			}
		}

		for (int i = 0; i < 15; i++)
		{
			testThread[i].join();
			
		}
	}
}

int main() {


	//ben::test_person_construct();

	//ben::test_customer_getConsumeCount();
	
	//ben::test_product_makeHamburger();

	ben::test_thread_mutex_condition();

	return 0;
}