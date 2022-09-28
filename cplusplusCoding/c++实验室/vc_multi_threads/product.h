#pragma once
#include <iostream>
#include <string>
#include <algorithm>


/******************
* class : abstractProduct ��Ʒ�����
* value :
private:
*	std::string  _strProductName; // ��Ʒ��
*	double  _doubleProductPrice; //��Ʒ�۸�
*	std::string  _strProductId; //��Ʒid
******************/
class abstractProduct 
{
public:
	virtual ~abstractProduct() = 0 
	{
		
	}

	std::string set_strProductName(std::string _name)
	{
		return _strProductName =  _name ;
	}

	double set_strProductPrice(double _price)
	{
		return _doubleProductPrice =  _price ;
	}

	std::string set_strProductId(std::string id)
	{
		return _strProductId = id ;
	}

	void showAll()
	{
		std::cout << _strProductName << " "
			<< _doubleProductPrice << " "
			<< _strProductId << " " << std::endl;
	}
protected:
private:
	std::string  _strProductName; // {}
	double  _doubleProductPrice; //[]
	std::string  _strProductId; //()
};

/******************
* class : Hamburger �����Ʒ��
* value :
private:
*	std::string  _strProductName; // ��Ʒ�����̳У�
*	double  _doubleProductPrice; //��Ʒ�۸񣨼̳У�
*	std::string  _strProductId; //��Ʒid���̳У�
******************/
class Hamburger : public abstractProduct
{
public:
	virtual ~Hamburger()
	{

	}

	Hamburger()
	{
		set_strProductName("");
		set_strProductPrice(0.00);
		set_strProductId("h000000");
	}

	Hamburger(std::string _name, double _price, std::string _id)
	{
		set_strProductName(_name);
		set_strProductPrice(_price);
		set_strProductId(_id);
	}
private:

};