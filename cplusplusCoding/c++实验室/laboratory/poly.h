#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int testint = 10;
class Poly {
public:
	Poly() { cout << "����Ĺ���" << endl; };
	virtual ~Poly() { cout << "���������" << endl; };
	virtual void print_po() {};
private:
};

class Poly_son:virtual public Poly {
public:
	Poly_son() {};
	Poly_son(int x) :a(x) { cout << "����Ĺ���" << endl; };
	virtual ~Poly_son() { cout << "���������" << endl; };
	virtual void print_po() { cout << "�����print" << endl; };
	virtual void print_po(int x) { cout << "�����print:" << x<<endl; };
private:
	int a = 1;
};

class Poly_daughter :virtual public Poly {
public:
	Poly_daughter() {};
	Poly_daughter(char x) :b(x) { cout << "����Ĺ���" << endl; };
	virtual ~Poly_daughter() { cout << "���������" << endl; };
	virtual void print_po() { cout << "�����print" << endl; };
	virtual void print_po(int x) { cout << "�����print:" << x << endl; };
private:
	char b = 1;
};

class Poly_grandson :public Poly_son, public Poly_daughter {
public:
	Poly_grandson()  { cout << "����Ĺ���" << endl; };
	~Poly_grandson() { cout << "���������" << endl; };
	virtual void print_po() { cout << "�����print" << endl; };
	virtual void print_po(int x) { cout << "�����print:" << x << endl; };
private:
};