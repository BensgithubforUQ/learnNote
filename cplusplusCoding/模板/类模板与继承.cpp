#include <iostream>
#include <string>
using namespace std;
/*������̳еĸ�����һ����ģ���ʱ��
����������ʱ����Ҫָ��������T������
���򣬱������޷�����������ڴ�
�����Ҫ����ָ��������T�����ͣ�����ҲӦ����һ����ģ��*/
template<class T>
class Base {
public:
	T m;
};

class Son :public Base<int> {//����������ʱ����Ҫָ��������T������
	//���򣬱������޷�����������ڴ�
};
template<class T1,class T2, class T3>
class Son_template :public Base<T2> {//�����Ҫ����ָ��������T�����ͣ�����ҲӦ����һ����ģ��
public:
	T1 n;
	Son_template(T1 x, T2 y, T3 z);
	//��ģ���г�Ա����������ʵ��
	void showMember();
private:
	T3 l;
};
template<class T1, class T2, class T3>
void Son_template<T1,T2,T3>::showMember() {
	cout << this->n << " " << this->m << " " << this->l << endl;
}
//��ģ��Ĺ��캯��������ʵ��
template<class T1, class T2, class T3>
Son_template<T1, T2, T3>::Son_template(T1 x, T2 y, T3 z) {
	this->n = x;
	this->m = y;
	this->l = z;
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;
	cout << typeid(T3).name() << endl;

}



//
//int main() {
//	Son s1;
//	s1.m = 10;
//	cout << typeid(s1.m).name() << endl;
//	cout << s1.m << endl;
//
//	Son_template<int, char, int> s2('Y', 90 ,20);
//
//	s2.showMember();//��Ϊָ����T1��int����T1��n�����ͣ�������ﴫ��Y���ͷ�����ʽ����ת��
//	//��˴�ӡn��ֵ����������ASCII��89��ͬ���ӡm����������90��Ӧ��ֵ����Z
//
//    return 0;
//}