#include <iostream>
#include <string.h>
#include "Sales_data.h"
using namespace std;
//
//int main() {
//	int val = 1;
//	int *p = &val;
//	//int* q = 2;��Ҳ�Ǵ�ġ�
//	int* q = 0; //�������ǿ��Եġ�
//	//��ͬ�ڣ�
//	//int* q = nullptr;
//	cout << p<<" "<<*p<<" "<<val<<endl;
//	*p = 2;
//	cout << p << " " << *p << " " << val << endl;
//	//��ʵ����֤��һ����ʵ����p����ָ��val�ĵ�ַ��p��val��ָ�롣
//	//����޸�*p��ֵ����ͬ���޸�pָ��Ķ����ֵ��
//	//���޸�*p��ֵ������ı�p�洢��ֵ����val�ĵ�ַ��
//	return 0;
//}

//int main() {
//	int i = 42;
//	int* p1 = &i;
//	*p1 = *p1 * *p1;
//	cout << *p1 << " " << p1 << " " << i;
//	return 0;
//}

//int main() {
//	int i = 10;
//	//double *dp = &i;
//	int* p = &i;
//	//int *p = i;
//	int *q = nullptr;
//	//q = i;
//	if (p) cout << "yes" << endl;
//	if (*p) cout << "no" << endl; //���p�洢�ĵ�ַָ��Ķ����ֵΪ0������������������
//	return 0;
//}

//int main() {
//	int i = 42; //�������岢�ҳ�ʼ��iΪһ��int���͵ı�����ֵΪ42
//	int* p; //����һ��ָ��p
//	int*& r = p; //r��p�����á�
//
//	//�����*&r����˼��r��ָ��p�����á����ұ�����߶������*&r�����ã���*֤����r������������ָ�롣
//	r = &i; //��i�ĵ�ַ��ֵ������r�����Ǹ�ֵ��ָ��p
//	*r = 0; //������r����ָ��p�ĵ�ַ��ָ�룬�͵õ���p�ĵ�ַ��ָ��ı���i��*r��*p��i����ʱ��ͬ��ʡ�
//	cout << i << " " << r << " " << *r << " " << p << " " << *p << endl;
//	//��ˣ�i��ֵ�ͱ���ֵΪ0��Ȼ��*r����*p��ָ��õ���ֵ��Ҳ��0.
//}

//int main() {
//	int i = 45;
//	int& r1 = i;
//	const int& r2 = i;
//	cout << i << " " << r1 << " " << r2<<endl;
//	r1 = 42;
//	//r2 = 41;
//	cout << i << " " << r1 << " " << r2;
//	return 0;
//}

//int main() {
//	int i = 42;
//	const int* p = nullptr;
//	p = &i;
//	//*p = 45;��Ϊ*pָ�����i��������ָ������ָ�벻���޸ģ���˲���ͨ����ָ���޸�ָ��Ķ����ֵ��
//	cout << p << " " << *p;
//	return 0;
//}

//int main() {
//	//ע�⣬ָ������ָ��ͳ���ָ�벢��һ����
//	int i = 3, h = i;
//	const int j = i, & r = i,*p0 = &i;
//	cout << j << " " << r <<" "<<*p0<< endl;
//	int* const p = &i;
//	int *p1 = &i;
//	p1 = &h;
//	const int* const p2 = &i;
//	const int& const r1 = 0;
//	cout << i << " " << p1 << " " << r1 << " " << p2 << endl;
//	*p = 4;
//	
//	int* q = nullptr;
//	//p = q;//����ͱ��ֳ����ˣ�p�����ǳ�������һ������ָ�룬��˲��������ұߵĵĿ�ָ��������и�ֵ��
//	p1 = q;//���Ƿǳ���ָ��Ϳ��Ա���ֵ���ı�洢�ĵ�ַ��
//	cout << i <<" " << p1 <<" " <<r1<<" "<<p2<< endl;
//	return 0;
//	//�������Ҫע����ǣ���const int *p���� int *const p��
//	//int *const p�ĺ�����p�������ָ�벻�ɱ䣬������ָ��Ķ���ɱ䡢
//	//const int *p��int *p���ָ��ָ����ǳ���������ͨ����ָ���޸�ָ��ĳ�����
//}

//�ȿ�ָ�����Ĳ��֣����ʽ��������ָ���������ұ߱����ǿ���ת��Ϊָ�����ģ����߱����ǳ�����
//�ٿ����ʽ����Ƿ��ǳ���ָ�룬����������ڳ�ʼ�����������£����ܳ����ڱ��ʽ��ߡ�
//int main() {
//	int i = 0; //�������Ҷ��岢�ҳ�ʼ����int���͵�i��ֵΪ0��
//	int* const p1 = &i;//�������Ҷ��岢�ҳ�ʼ����int���͵ģ�����ָ��p1.ָ��int���͵�i��
//	const int ci = 42;//����const int���͵�ci��
//	const int* p2 = &ci;//����ָ������int���͵�ָ�룬p2��ָ����c1���ײ�const
//	const int* const p3 = p2;//����ָ������int���͵ĳ���ָ��p3����ָ������int���͵�ָ��p2��ʼ������
//	//��ʱ����ߵ�const�ǵײ�const���ұߵ�const�Ƕ���const��
//	//�ڿ�����ʱ�򣬶���const����ν����Ϊ��������ı䱻���������ֵ��
//	//�����뿼�ǵײ�const�����ߵĶ����������ͬ�ĵײ��ʸ�
//	const int& r = ci;//�������õ�const���ǵײ�const
//
//	i = ci; // i��int���͵ı�����ci��const int ���͵ĳ�������������ת��Ϊ���������ԺϷ���
//	p2 = p3;//p2��ָ������int���͵�ָ�룬p3��ָ������int���͵ĳ���ָ�룬�ײ�const����ָ�������ʸ�һ�¡�
//	//���ұߵ�p3�ĳ���ָ������β����в��ᱻ�ı䣬��˺Ϸ���
//	//���������ʱ����һ��
//	//p3 = p2;//��ͻ�����⣬��Ϊ��Ȼ�ײ�const�ʸ�һ�£�����p3�ǳ���ָ�룬��˲��ܳ����ڱ��ʽ��ߡ�
//	
//	//int* p = p3; //����Ҳ������⣬��Ϊp3�ĵײ��ʸ�������const����int *pû�У���˷Ƿ���
//	p2 = p3;//ͬ�ϣ��Ϸ���
//	p2 = &i;//p2��ָ������int���͵�ָ�룬��int*���Ϳ���ת����const int*���ͣ���˺Ϸ���
//	//int& r = ci; // ��Ϊc1��const int���͵ĳ���������ͨ��int& ���ܰ󶨵������ϡ�
//	const int& r2 = i;
//	system("puase");
//	return 0;
//}

//constexpr int weekday = 5;
//#define weekend 2;
//int main() {
//	const int v2 = 0;
//	int v1 = v2;
//	int* p1 = &v1;
//	int& r1 = v1;
//	const int* p2 = &v2, *const p3 = p2,&r2 = v2;
//	r1 = v2;
//	//p1 = p2; //�ײ�const�ʸ�һ�������ܸ�ֵ
//	p2 = p1; //�ײ�const�����ʸ���Ȼ��һ��������int*����ת��const int *��
//	//p1 = p3; //ͬ��
//	p2 = p3;
//	system("pause");
//	return 0;
//}

//int main() {
//	int i = 0, & r = i;
//	auto a = r; //int a = r;
//	//auto ����Զ���const���ǻᱣ���ײ�const
//	const int ci = i, & cr = ci;
//	auto b = ci; // int b = ci;
//	auto c = cr; // int c = ci;
//	auto d = &i; //int *d = &i;
//	auto e = &ci;//&ci��ci���������������&ci��ָ������������ָ�룬���ָ�������������ǵײ�const��
//	//�����const int* e = &ci;
//	const auto f = ci;//const int f = ci�������Ҫǿ�Ʊ�������const������Ҫ�Լ���const��
//	auto& g = ci;//ci��������������������const int &g = ci;
//	//auto& h = 42;����Ǵ�ģ�����Ϊ42�����������Ƕ���const�����ò��ɰ�����ֵ��
//	//int& g1 = 42; �ο������
//	const int& g2 = 42;
//	const auto& j = 42;
//
//	auto k = ci, & l = i;//k = ci,���Զ���const��int k = i��int &l = i��������ȷ�ġ�
//	auto& m = ci, * p = &ci;//ci�Ƕ���const�����������������const int &m = ci,const int *p = &ci;��������������m��ָ������������ָ��p��
//	//auto& n = i, * p2 = &ci; ���ﱨ������Ϊ��i�����Σ����auto��int��int &n = i����n����int i��int *p2 =&ci�����Ϸ���
//	//��Ϊ&ci��ָ������������ָ�룬��const int*���ǵײ�const���������int *���ײ�const��һ�������ܳ�ʼ����
//	a = 42;//��int���͵ı���a��ֵ42���Ϸ���
//	b = 42;//ͬ��
//	c = 42;//ͬ��
//	//d = 42;//d��int * ���͵ģ�����ֱ�Ӹ�ָ����󸳳���
//	//e��ָ������ָ��
//	//e = 42;ͬ��Ҳ�ǲ���ֱ�Ӹ�ָ�븳����
//	//g = 42;g��const�����ɱ䡣
//	int& n = i;
//	n = 42;
//	return 0;
//}

//int main() {
//	const int i = 42;
//	auto j = i; //�мǣ��ڲ���ǰ��������const������£�auto����Զ���const�����������int j = i.j��int���Ͷ�����const int��
//	const auto& k = i;
//	auto* p = &i;
//	const auto j2 = i, & k2 = i;
//	return 0;
//}

//int main() {
//	const int a = 3;
//	int b = 4;
//	decltype(a) a1 = a; //�����a1 �� const int���͵�
//	auto a2 = a;//a2��int ���͵ģ���Ϊa��const�Ƕ���const��auto�����ˡ�
//	decltype(b) b1 = b;//b1��int���͵�
//	auto b2 = b;//b2��int���͵�
//	//�������չʾ��ͬһӦ���龳�£�decltype��auto������
//}


//struct Sales_data {
//	string bookNo;
//	unsigned units_sold = 0;
//	double revenue = 0.0;
//};
Sales_data accum, trans, * salesptr;
int main() {
	Sales_data data1, data2, data3;
	double price = 0;
	cout << "please input book number,units_sold and price:" << endl;
	cin >> data1.bookNo >> data1.units_sold>> price;
	data1.revenue = data1.units_sold * price;
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;
	if (data1.bookNo == data2.bookNo) {
		auto totalCnt = data1.units_sold + data2.units_sold;
		auto totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0) {
			cout << totalRevenue / totalCnt << endl;
		}
		else cout << " no sales" << endl;
		return 0;
	}
	else {
		cerr << "data must refer to the same ISBN" << endl;
		return -1;
	}
}