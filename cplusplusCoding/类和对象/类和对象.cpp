#include <iostream>
#include <string>
using namespace std;


/*������
��Ա�������const�����Ǿͳ�֮Ϊ������
�������ڲ������޸ĳ�Ա����
��Ա����������ʱ��������˹ؼ���mutable���Ϳ����ڳ��������޸���
*/

/*������
����ǰ��const���ǳ�����
������ֻ�ܵ��ó�����
*/
class Person {
public:
	void showPerson() const{
		//this->m_a = 10;
		//thisָ��ı�����һ��ָ�볣�� �� const ��* this���ټӸ�const
		//���� const ��* const ��
		//�����Ͳ����޸���
		cout << "m_a = " << m_a << endl;
		this->m_b = 10;//���ǼӸ�mutable�Ϳ����޸���
	}

	void funcNoConst() {

	}

	int m_a;
	mutable int  m_b;
};

int main() {
	//��ϰһ��ָ�볣���ͳ���ָ��
	int i = 1,j = 10;
	int* const a = &i;//����ָ��
	cout << "a�ĵ�ַ��" << (int)&a << " ����ĵ�ַ�� " << (int)a << " ָ���ֵ�� " << *a << endl;
	//a = 1;//ָ��a���ɸ�
	//a = &j;
	int* A = &i;
	A = &j;
	*a = 2;//����ָ��ָ��ı������Ըġ�
	cout << "a�ĵ�ַ��" << (int)&a << " ����ĵ�ַ�� " << (int)a << " ָ���ֵ�� " << *a << endl;
	cout << i << endl;
	const int* b = a;//ָ�볣��������ͨ�����ָ���޸�ָ��ı��������ǿ���ͨ�����������ģ����Ҹ���֮��
	//�ⳣ��ָ��ָ��ĵ�ַ�����ܷ��֣���ָ��ı��������ˡ�
	cout << "b�ĵ�ַ��" << (int)&b << " ����ĵ�ַ�� " << (int)b << " ָ���ֵ�� " << *b << endl;
	//*b = *a; //���ָ��ָ��ı������ܸģ�
	int c = 3;
	int *d = &c;
	b = d; //����ָ�뱾����Ը�
	cout << "b�ĵ�ַ��" << (int)&b << " ����ĵ�ַ�� " << (int)b << " ָ���ֵ�� " << *b << endl;

	//������
	const Person p_const;
	//p_const.m_a = 10; //������ֻ�ܵ��ó������������޸ı�����
	p_const.m_b = 10; //m_b����mutable���������ǿ��Է����޸ĵġ�
	p_const.showPerson();
	//p_const.funcNoConst();//�������ܵ��ó���������ĺ�������Ϊ����ĺ����п��ܷ������ԡ�

	//double *arr = new double[2000000*12*12];
	//double*** array_3d = new double** [2000000];
	//for (int i = 0; i < 2000000; ++i) {
	//	array_3d[i] = new double* [12];
	//	for (int j = 0; j < 12; ++j) {
	//		array_3d[i][j] = new double[12];
	//		for (int k = 0; k < 12; ++k) {
	//			array_3d[i][j][k] = 1;
	//		}
	//	}
	//}
	system("pause");
	return 0;
}