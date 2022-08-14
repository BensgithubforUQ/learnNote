#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP
#include <iostream>
using namespace std;

//ƻ����Ʒ
class AbstractApple {
public:
	virtual ~AbstractApple() = 0 { cout << "~ƻ����������..." << endl; };
	virtual void showName() = 0;
	AbstractApple() { cout << "ƻ�����๹��..." << endl; }
private:
};

class ChineseApple :public AbstractApple { //����
public:
	virtual ~ChineseApple() { cout << "~�й�ƻ������..." << endl; };
	void showName() { cout << "�й�ƻ��!!!" << endl; }
	ChineseApple() { cout << "�й�ƻ������..." << endl; }
private:
};

class AmericanApple :public AbstractApple { //����
public:
	virtual ~AmericanApple() { cout << "~����ƻ������..." << endl; };
	void showName() { cout << "����ƻ��!!!" << endl; }
	AmericanApple() { cout << "����ƻ������..." << endl; }
private:
};

//�㽶��Ʒ
class AbstractBanana {
public:
	virtual ~AbstractBanana() = 0 { cout << "~�㽶��������..." << endl; };
	virtual void showName() = 0;
	AbstractBanana() { cout << "�㽶���๹��..." << endl; }
private:
};

class ChineseBanana :public AbstractBanana { //����
public:
	virtual ~ChineseBanana() { cout << "~�й��㽶����..." << endl; };
	void showName() { cout << "�й��㽶������" << endl; }
	ChineseBanana() { cout << "�й��㽶����..." << endl; }
private:
};

class AmericanBanana :public AbstractBanana { //����
public:
	virtual ~AmericanBanana() { cout << "~�����㽶����..." << endl; };
	void showName() { cout << "�����㽶������" << endl; }
	AmericanBanana() { cout << "�����㽶����..." << endl; }
private:
};

//���󹤳� ��Բ�Ʒ��
class AbstractFactory {
public:
	virtual AbstractApple* createApple() = 0;
	virtual AbstractBanana* createBanana() = 0;
protected:
private:
};

class ChineseFactory:public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new ChineseApple;
	}
	virtual AbstractBanana* createBanana() {
		return new ChineseBanana;
	}
private:
};

class AmericanFactory :public AbstractFactory {
public:
	virtual AbstractApple* createApple() {
		return new AmericanApple;
	}
	virtual AbstractBanana* createBanana() {
		return new AmericanBanana;
	}
private:
};
#endif // !ABSTRACTFACTORY_HPP

