#ifndef PRODUCER_H
#define PRODUCER_H
#include "person.h"

/******************
* class : person������ hamburgerMaker
* value :
* private:
*	_stat_int_PersonAmount�� �������(�̳�)
*	_int_handleCount�� ����ÿ���ܹ�������ר�Ŷ���ĸ�����(�̳�)
******************/
class hamburgerMaker : public Person {
public:
	~hamburgerMaker()
	{

	}

	hamburgerMaker(int handleCount) 
	{
		this->set_int_handleCount(handleCount);
		this->personType = m_hamburgerMaker;
	}

protected:
private:
	
};

#endif // !PRODUCER_H
