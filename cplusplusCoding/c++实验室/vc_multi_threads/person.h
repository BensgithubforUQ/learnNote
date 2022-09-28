#pragma once

#include <iostream>

/******************
* class : person ������������ģ�ͻ���
* value :
*	_stat_int_PersonAmount�� �������
*	_int_handleCount�� ����ÿ���ܹ�������ר�Ŷ���ĸ�����
******************/
class Person {
	friend int getHandleCount(Person& _p)
	{
		return _p._int_handleCount;
	}
public:
	virtual ~Person()
	{
		//
		--_stat_int_PersonAmount;
	}

	/*default _int_handleCount = 1*/
	Person()
	{
		_int_handleCount = 1;
		++_stat_int_PersonAmount;
	}

	Person(int handleCount) : _int_handleCount(handleCount) {
		++_stat_int_PersonAmount;
	}

	Person(Person& _p)
	{
		this->_int_handleCount = _p._int_handleCount;
		++_stat_int_PersonAmount;
	}

	Person& operator =(Person& _p) {
		this->_int_handleCount = _p._int_handleCount;
		return *this;
	}


	void set_int_handleCount(int handleCount)
	{
		_int_handleCount = handleCount;
	}

	int get_int_handleCount() 
	{
		return _int_handleCount;
	}

	static int getPersonAmount()
	{
		return _stat_int_PersonAmount;
	}

	
protected:

private:
	static int _stat_int_PersonAmount;
	int _int_handleCount;
};

/*��ʼ��person���static int����*/
int Person::_stat_int_PersonAmount = 0;

enum PRODUCT_TYPE
{
	hamburger = 1, lamian = 2, cookie = 3
};