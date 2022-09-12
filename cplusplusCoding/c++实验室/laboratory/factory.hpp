#ifndef FACTORY_HPP
#define FACTORY_HPP
#include <iostream>
using namespace std;

//���崴������Ľӿڣ���װ����Ĵ���
//���ǰѾ��廯�������������ࣩ�Ĺ����ӳٵ������С�

class Product { //product�Ļ��࣬������
public:
	virtual ~Product() = 0 { cout << "~Product deconstruct..." << endl; }; //���࣬���麯��,ʵ��Ҳû�õ�
protected:
	Product(){ cout << "Product construct..." << endl; }
private:
	
};

class ConcreteProduct :public Product { //public�̳�
public:
	~ConcreteProduct() { cout << "~concreteProduct deconstruct..."<<endl; }
	ConcreteProduct() { cout << "concreteProduct construct..." << endl; }
protected:
private:
};

class Factory {
public:
	virtual ~Factory() = 0 { cout << "~factory deconstruction..." << endl; };
	virtual Product* CreateProduct() = 0 {};
protected:
	Factory() { cout << "factory construction..." << endl; }
private:
};

class ConcreteFactory : public Factory {
public:
	~ConcreteFactory(){ cout << "~concreteFactory deconstruct..." << endl; }
	ConcreteFactory() { cout << "ConcreteFactory construction..." << endl; }
	Product* CreateProduct() { return new ConcreteProduct(); }
};

#endif // 

