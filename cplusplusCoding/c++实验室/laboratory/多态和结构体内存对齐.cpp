#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
//#include "poly.h"
using namespace std;
//�ṹ���������𣬶�̬���̳У��麯��
struct st1 { //�ṹ��Ĭ�Ϲ��У�c����в��ܺ��г�Ա����
	int a; //4
	char b; //1
	short c; //2
	double d; //8
	long l; //4
	//(4+1+2+"1") + (8) + (4 +"4")
};

class Poly { //��Ĭ��˽�У�c++����п��԰�����Ա����
public:
	Poly() {};
	Poly(const Poly &p) { //�������첻����ֵ���ݣ�������������޵ݹ顣
		this->a = p.a;
	}
	Poly(int x, char y, int *z) :a(x), b(y) ,c(z) {
	} //���캯���������麯������Ϊvtable�ڹ��캯���г�ʼ�����������麯����Ҫ��vtable
	virtual ~Poly() {}; //������̬��ʱ����Ҫ�������������������Ϊ�麯���������޷�ִ����������������
	//�麯��Ҳ�������������������ǾͲ������ڶ�̬�ˣ���Ϊ�麯����̬�Ƕ�̬��̬���ڱ���׶��޷����У���������Ҫ�ڱ���׶��滻��
	virtual void print_po() {}; //vtableҲҪ�������
private:
	int a = 1;
	char b = 'a';
	int* c;
};
//char ��1���ֽ�
//short int : 2���ֽ�
//int�� 4���ֽ�
//unsigned int : 4���ֽ�
//float : 4���ֽ�
//double : 8���ֽ�
//long : 4���ֽ�
//long long : 8���ֽ�
//unsigned long : 4���ֽ�

class Poly_son :public Poly {
	friend ostream& operator<<(ostream &out,const Poly_son &p); //vtableҲҪ�������
public:
	Poly_son() {};
	Poly_son(const Poly_son& p) { //�������첻����ֵ���ݣ�������������޵ݹ顣
		this->a = p.a;
	}
	Poly_son(int x, char y, int* z,string s) :a(x), b(y), c(z) {
		this->str = s;
	} //���캯���������麯������Ϊvtable�ڹ��캯���г�ʼ�����������麯����Ҫ��vtable
	~Poly_son() {}; //������̬��ʱ����Ҫ�������������������Ϊ�麯���������޷�ִ����������������
	
private:
	int a = 1;
	char b = 'a';
	int* c;
	string str;
};
ostream& operator<<(ostream& out, const Poly_son& p) {
	out << p.a << " " << p.b << " " << *(p.c) << " " << p.str << endl;
	return out;
}

int main() {
	st1 st_1;
	cout << " �ṹ��st1��size " << sizeof(st_1) << endl;
	Poly po;
	cout << " ���麯������po��size " << sizeof(po) << endl;
	int n = 0;
	int* p = &n;
	int a = 2;
	char b = 'b';
	string s = "112";
	Poly_son po_s(n,b,p,s);
	cout << po_s << endl; //��Ԫ������<<����ӡ���˽�г�Ա������
	cout << " �������麯��������po_s��size " << sizeof(po_s) << endl;
	return 0;
}