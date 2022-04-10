#pragma once
#include <iostream>
#include <string>
using namespace std;

/*����
1.���Դ��������������͵Ķ�����Զ����������͵Ķ���
2.�������е����ݴ�ŵ�����
3.���캯���п��Դ������������
4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=�����ط�ֹǳ����
5.�ṩβ�巨��βɾ�����������ӻ���ɾ�������е�����
6.����ͨ���±����
7.���Ի�ȡ�����е�ǰԪ�صĸ���������*/

template <class T>
class goldenFingerArray {
public:
	void Push_Back(const T& value);//β�巨����Ԫ��
	void Pop_Back();//βɾ��
	goldenFingerArray(int capacity);//���캯��
	goldenFingerArray(const goldenFingerArray& arr);//Ϊ�˷�ֹǳ���������⣬��Ҫ����һ���������캯��
	~goldenFingerArray();//��������
	goldenFingerArray& operator=(const goldenFingerArray& arr);//Ϊ�˷�ֹǳ����������,��Ҫ����һ����ֵ�������
	T& operator[](int index);//����[]��ʵ��a[i]���ܣ����±����
	int getCapacity();//��ȡ���������
	int getSize();
	void showArrInfo();//��ȡ����ȫ����Ϣ��
private://˽�г�Ա
	T* m_elementAddress; //�����е�Ԫ�أ�ָ��ָ������ڶ������ٵ�����
	int m_Capacity; //���������
	int m_size; //����Ĵ�С
};

template <class T>
goldenFingerArray<T>::goldenFingerArray(int capacity) {//�вι���
	this->m_Capacity = capacity;
	this->m_size = 0;
	this->m_elementAddress = new T[this->m_Capacity];
	cout << "�вι������" << endl;
}

template <class T>
goldenFingerArray<T>::goldenFingerArray(const goldenFingerArray& arr) {
	this->m_Capacity = arr.m_Capacity;
	this->m_size = arr.m_size;
	this->m_elementAddress = new T[this->m_Capacity];//��ֹǳ��������Ҫ�Լ����¿����µĶ����ռ�
	//�������

	//��arr�е����ݶ���������
	if (arr.m_Capacity != 0) {
		for (int i = 0; i < arr.m_size;i++) {
			this->m_elementAddress[i] = arr.m_elementAddress[i];
		}
		cout << "�����������" << endl;
	}
}
template <class T>
goldenFingerArray<T> & goldenFingerArray<T>::operator=(const goldenFingerArray<T>& arr) {
	//��Ϊ=Ҫʵ��һ�����ȵ���ʽ���˼�룬���ÿ��=���˶�Ҫ����һ����ǰ����ĵ�ַ
	//���ж�ԭ�������Ƿ������ݣ�����У���Ҫ�ͷ�
	if (this->m_elementAddress != NULL) {
		delete[] this->m_elementAddress;
		this->m_elementAddress = NULL;
		this->m_size = 0;
		this->m_Capacity = 0;
	}
	//Ȼ���������
	this->m_Capacity = arr.m_Capacity;
	this->m_size = arr.m_size;
	this->m_elementAddress = new T[this->m_Capacity];//��ֹǳ��������Ҫ�Լ����¿����µĶ����ռ�
	//�������

	//��arr�е����ݶ���������
	if (arr.m_Capacity != 0) {
		for (int i = 0; i < arr.m_size; i++) {
			this->m_elementAddress[i] = arr.m_elementAddress[i];
		}
		cout << "=�����У������������" << endl;
	}

	//�����Ҫ���ر�����
	return *this; //this��ָ�룬*this���صľ���ָ��ָ��Ķ���
}


template <class T>
goldenFingerArray<T>::~goldenFingerArray() {
	if (this->m_Capacity != NULL) {
		delete[] this->m_elementAddress;
		this->m_Capacity = NULL;
		cout << "������������������������" << endl;
	}
}

template <class T>
void goldenFingerArray<T>::Push_Back(const T& value) {
	if (this->m_Capacity == this->m_size) {
		cout << "���������Ѿ����ˣ����ɼ�������Ԫ��" << endl;
		return;
	}
	else {
		this->m_elementAddress[this->m_size] = value; //β��
		this->m_size++;//����++
	}
}

template <class T>
void goldenFingerArray<T>::Pop_Back() {
	if (this->m_size == 0) {
		cout << "�����������ˣ����ɼ���ɾ��Ԫ��" << endl;
		return;
	}
	else {
		this->m_size--;//����--
	}
}

template <class T>
T& goldenFingerArray<T>::operator[](int index) {//����[]��ʵ��a[i]���ܣ����±����
	return this->m_elementAddress[index];
	//���ص���&��������Ϊ��ֵ��
}

template <class T>
int goldenFingerArray<T>::getCapacity() {
	return this->m_Capacity;
}

template <class T>
int goldenFingerArray<T>::getSize() {
	return this->m_size;
}


template <class T>
void goldenFingerArray<T>::showArrInfo() {
	cout << "���������� " << this->m_Capacity << endl;
	cout << "���鳤�ȣ� " << this->m_size << endl;
	for (int i = 0; i < this->m_size;i++) {
		cout << this->m_elementAddress[i] << endl;
	}
}