#include <iostream>
using namespace std;

//����ģ��
//��ͨ�������ÿ��Է�����ʽ����ת����������԰�char��ת����int�������м��㣩��
// ����ģ��	 ���Զ������Ƶ������ɷ�����ʽ����ת������Ϊû���滻��һ�µ����ͣ������ж����ԣ�
// ����ģ��  ����ʾָ�����ͣ����Է�����ʽ����ת������ȷ����ת�������ͣ����ܼ��㣬û�����壩
//������������������


void swapInt(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//��������������������
void swapDouble(double& a, double& b) {
	double temp;
	temp = a;
	a = b;
	b = temp;
}

//��������function�ǳ����ƣ��߼�һֱ��ֻ�ǲ������Ͳ�һ��
//���������ģ��������

template<class T>//����һ��ģ�壬���߱����������������T������T��һ��ͨ�õ���������
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
//�����һ������ģ�壬����ģ��+�����ŵĶ����һ��������ʹ�á�
template<class T>
void SortArray(T arr[], int len) {
	if (len > 1) {
		for (int i = 0; i < len; i++) {
			//cout << arr[i] << endl;

			for (int j = i + 1; j < len; j++) {
				//cout << arr[i] <<" "<<arr[j] << endl;

				if (arr[i] < arr[j]) {
					mySwap(arr[i], arr[j]);
 				}
			}
		}
	}
	else {
		cout << "���ݲ���" << endl;
	}
}
template<class T>
void array_print(T arr[],int len) {
	for (int i = 0; i < len;i++) {
		cout << arr[i] << " ";
	}
}
/*
��ͨ�����ͺ���ģ��ĵ��ù���
1.�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
2.����ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
3.����ģ��Ҳ��������
4.�������ģ����Բ������õ�ƥ�䣬�����ȵ��ú���ģ��*/
void myPrint(int a, int b) {
	cout << "��ͨ���� a: " << a << " b: " << b << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "����ģ�� a: " << a << " b: " << b << endl;
}
template<class T>
void myPrint(T a, T b, T c) {
	cout << "����ģ��,���ص�ģ�� a: " << a << " b: " << b << " c: " << c << endl;
}

//int main() {
//	/*�����ַ���ʹ�ú���ģ��*/
//	//1.�Զ������Ƶ�������Ҫ�Ƶ���һ�µ��������Ͳ�����
//	int a = 10, b = 20;
//	mySwap(a, b);
//	cout << a << " " << b << endl;
//
//	/*��ͨ�����ͺ���ģ����ò���*/
//	myPrint(a, b);//������ͨ���������ϵ�һ���ù���,������ͨ����ֻ��������Ҳ������ͨ������Ȼ�󱨴�
//	//�ڶ�����ͨ����ģ������б�����ǿ�Ƶ��ú���ģ��
//	myPrint<>(a, b);//��ģ������б�
//	//����ģ�������
//	myPrint(a, b,100);
//	//�������ģ����Բ������õ�ƥ�䣬�����ȵ��ú���ģ��
//	myPrint('A', 'B');//��ʵ�β�Ϊint����ͨ����Ҳ���Գɹ����ã�������Ҫ������ʽ����ת��
//	//�������������£�����ģ���Ǹ��������ƥ�䣬�����ȵ��ú���ģ�塣
//	
//
//	//2.��ʾָ������
//	mySwap<int>(a, b);//ָ��Ϊint������ָ���˲�����
//	cout << a << " " << b << endl;
//	int arr[3] = { 3,1,2 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	SortArray(arr,len);
//	array_print(arr,len);
//
//	cout << endl;
//
//	char arr_s[] = "abcdefghijklmnopqrstuvwxyz";//������stringŶ,string���ַ������������顣��char���͵����顣
//	int len_s = sizeof(arr_s) / sizeof(arr_s[0]);
//	SortArray(arr_s, len_s);
//	array_print(arr_s, len_s);
//	system("pause");
//	return 0;
//}