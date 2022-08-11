#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
//#include "poly.h"
using namespace std;
//c++�нӿڵĸ���
//1������û�ж����κεĳ�Ա����
//2�����еĳ�Ա�������ǹ��е�
//3�����еĳ�Ա�������Ǵ��麯��
//4���ӿ���һ������ĳ�����
//�ṹ���������𣬶�̬���̳У��麯��
struct st1 { //�ṹ��Ĭ�Ϲ��У�c����в��ܺ��г�Ա����
	int a; //4
	char b; //1
	short c; //2
	double d; //8
	union {
		long l; //4
		short s;
	};
	//(4+1+2+"1") + (8) + (4 +"4")
};

class Poly { //��Ĭ��˽�У�c++����п��԰�����Ա����
	friend char getPrivate(const Poly &p);
public:
	Poly() {};
	Poly(const Poly &p) { //�������첻����ֵ���ݣ�������������޵ݹ顣
		this->a = p.a;
	}
	Poly(int x, char y, int *z) :a(x), b(y) ,c(z) {
	} //���캯���������麯������Ϊvtable�ڹ��캯���г�ʼ�����������麯����Ҫ��vtable
	virtual ~Poly() {}; //������̬��ʱ����Ҫ�������������������Ϊ�麯���������޷�ִ����������������
	//�麯��Ҳ�������������������ǾͲ������ڶ�̬�ˣ���Ϊ�麯����̬�Ƕ�̬��̬���ڱ���׶��޷����У���������Ҫ�ڱ���׶��滻��
	virtual void print_po() { cout << "poly~" << endl; }; //vtableҲҪ�������
private:
	int a = 1;
	char b = 'a';
	int* c;
};

char getPrivate(const Poly &p) {
	return p.b;
}
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
		this->a1 = p.a1;
	}
	Poly_son(int x, char y, int* z,string s) :a1(x), b1(y), c1(z) {
		this->str1 = s;
	} //���캯���������麯������Ϊvtable�ڹ��캯���г�ʼ�����������麯����Ҫ��vtable
	~Poly_son() {  }; //������̬��ʱ����Ҫ�������������������Ϊ�麯���������޷�ִ����������������
	void print_po(){ cout << "poly_son~" << endl; } //��̬��
private:
	int a1 = 1;
	char b1 = 'a';
	int* c1;
	string str1;
};
ostream& operator<<(ostream& out, const Poly_son& p) {
	out << p.a1 << " " << p.b1<< " " << *(p.c1) << " " << p.str1 << endl;
	cout << getPrivate(p) << " �����ԣ�" << endl; //����Ϳ��Է��ʸ����˽�б����ˡ�
	return out;
}



//int main() {
//	st1 st_1;
//	cout << " �ṹ��st1��size " << sizeof(st_1) << endl;
//	Poly po;
//	cout << " ���麯������po��size " << sizeof(po) << endl;
//	int n = 0;
//	int* p = &n;
//	int a = 2;
//	char b = 'b';
//	string s = "112";
//	Poly *po_s =  new Poly_son(n,b,p,s);
//	po_s->print_po();
//	cout << "s�Ĵ�С " << sizeof(s) << endl;
//	cout << po_s << endl; //��Ԫ������<<����ӡ���˽�г�Ա������
//	cout << " �������麯��������po_s��size " << sizeof(po_s) << endl;
//
//	return 0;
//}