#ifndef PRODUCER_H
#define PRODUCER_H
#include "person.h"

/******************
* class : person������ hamburgerMaker
* value :
*	_stat_int_PersonAmount�� �������
*	_int_handleCount�� ����ÿ���ܹ�������ר�Ŷ���ĸ�����
******************/
class hamburgerMaker : Person {
public:
	~hamburgerMaker()
	{

	}

	hamburgerMaker(int handleCount) 
	{
		this->set_int_handleCount(handleCount);
	}

protected:
private:

};

#endif // !PRODUCER_H
