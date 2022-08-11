#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
inline int MAX_inline(int a, int b) {
	return a > b ? a : b;
}
//lambda���ʽ
void sortLambda(vector<int>& v) {
	sort(v.begin(), v.end(), [](int a, int b) {return a < b; });
}

//�����ַ���
ostream& operator<<(ostream& out, vector<int>& v) {
	for (auto i : v) out << i << " ";
	out << endl;
	return out;
}

class A { //���еĳ�Ա������Ĭ����inline����
public:
	//�ؼ��� explicit
	//explicit A(int x) { //��ֹ��ʽת�������ǽ�ֹ�������Լ�����ת����̬
		//val = x;
	//}
	A(int x,int y):const_i(y) { //��ֹ��ʽת�������ǽ�ֹ�������Լ�����ת����̬
		val = x;
 		count++;
	}

	~A() {
		count--;
	}

	static int getCount() { return count; } //static ��̬��Ա�������ܵ��÷Ǿ�̬��Ա�������߷Ǿ�̬��Ա����
	//��Ϊ����û��thisָ��

	int getI() const { //const��Ա����ֻ�ܷ���const���͵ĳ�Ա�������߱���
		//cout << const_i << endl;
		return const_i;
	}
private:
	static int count; //��̬��Ա����������ͬ�����ά����һ����ͬ��ֵ
	int val;
	const int const_i;
};

int A::count = 0;

//�ؼ���static
int fun() {
	static int val = 1; //ֻ�ڵ�һ�ε��øú�����ʱ���ʼ��
	val+=1;
	return val;
}

//int main() {
//	vector<int> v{ 1,4,2,6,3,2,5,7 };
//	cout <<"lambda��������֮ǰ " << v << endl;
//	sortLambda(v);
//	cout <<"lambda��������֮�� " << v << endl;
//
//	cout << "MAX�꣺ " << MAX(v[0], v[1]) << endl;
//	cout << "MAX_inlne������ " <<MAX_inline(v[0], v[1]) << endl;
//
//	//��static��̬��Ա�������࣬����ʹ��ͬ�������̬��Ա������ֵ��ʹ��;�̬��Ա�������
//	A a (10,10);
//	A a1  (10,20);
//	A* a3 = new A(10,30);
//	cout << "�����A��static ���� count��ֵ�� " << A::getCount() << endl;
//	cout << "�����A��const ���� const_i��ֵ�� " << a1.getI() << endl; //20
//	delete a3; //�ͷ�a3����
//	cout << "�����A��static ���� count��ֵ�� " << A::getCount() << endl;
//
//
//	//static�ؼ������εı����ں�����һ�ε��õĳ�ʼ����
//	cout << "fun������ӡ��static�����ں�����һ�α����õ�ʱ���ʼ��" << endl;
//	for (int i = 0; i < 3; i++) cout << fun() << " "; // 2 3 4
//	
//	return 0;
//}