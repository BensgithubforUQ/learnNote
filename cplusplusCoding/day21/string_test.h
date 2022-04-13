#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//string��c++�����ַ�������������string��һ����
//char * ��һ��ָ��
//string���࣬���ڲ���װ��char* ����������ַ�������һ��char*�͵�����

//string�������װ��find��copy��delete��replace��insert�ȳ�Ա����
//ͬʱstring���õ��ĸ���Խ���ȡֵԽ������⣬������char*��������ڴ�

void test_string0() {//���Թ��캯��
	/*��������֪���ˣ�stringʵ������һ����װ��char*���࣬�����Ĺ��캯������*/
	string s1;//Ĭ�Ϲ��죬����ʼ��
	s1 = "bye";//��ֵ����
	const char* str = "hello world";//����һ��char*���͵��ַ���
	string s2(str);//��Ϊstring�Ƿ�װ��char*���࣬���������������вι����ʹ�÷�ʽ����c_stringת��Ϊstring
	string s3(s2);//��������
	string s4(10, 'h');//һ�����ص�������вι��죬��n�����Ƶ��ַ���ʼ��
	cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
}

void test_string1() {
	/*sting�����кܶ��ָ�ֵ����
	* string& operator=(const char* s); //��char* ���͵��ַ���	��ֵ ����ǰ�ַ���
	string& operator=(const string& s); //��string���͵Ķ��󣬸�ֵ�� ��ǰ�ַ���
	string& operator=(char c); // ���ַ�c����ֵ ����ǰ�ַ���
	string& assign(const char* s); // ���ַ���s��ֵ����ǰ�ַ���
	string& assign(const char* s,int n); //���ַ���s��ǰn���ַ�����ֵ����ǰ�ַ���
	string& assign(const string & s);//���ַ���s��ֵ����ǰ�ַ���
	string& assign(int n,,const char c);//��n���ַ�c��ֵ���ַ���
	*/
	string str1,str2;//Ĭ�ϳ�ʼ��
	str1 = "hello";
	str2 = "world";
	cout << str1 << " ";
	str1 =  str2 ;
	cout << str1 << " ";
	char c1 = 'a';
	str1 = c1;
	cout << str1 << endl;
	str1.assign(str2);
	cout << str1 << " ";
	str1.assign("hello world", 3);
	cout << str1 << " ";
	str1.assign("you are welcome");
	cout << str1 << " ";
	str1.assign(5, c1);
	cout << str1 << endl;
}

void test_string2() {
	/*string��ƴ��*/
	/*��Ҫ�����ص�+=��append��ʵ��ƴ�ӣ�����ƴ��char*��string��char*/
	string s1 = "hello s1";
	string s2 = "world s2";
	char c1 = 'c';
	const char* c2 = "c2 is a char*";
	s1 += s2;
	cout << s1 << endl;
	s1 += ':';
	cout << s1 << endl;
	s1 += c1;
	cout << s1 << endl;
	s1 += c2;
	cout << s1 << endl;
	//append
	cout << "append" << endl;
	string s3 = "i";
	s3.append(s1);
	cout << s3 << endl;
	s3.append(s1, 5);
	cout << s3 << endl;
	s3.append("love you",4);
	cout << s3 << endl;
	//����append
	string s4("never");
	s4.append("i have a dream that came true", 2, 25);
	cout << s4 << endl;
}

void test_string3() {
	//����
	string s1 = "abcdefghde";
	//��Ҫ����s1���Ƿ����Ӵ���de"
	//int find(const string & str, int pos = 0)const;
	//pos����ʼλ�ã���ΪĬ��Ϊ0�����Կ��Բ�����
	string target_s1 = "de";
	int target_postion = s1.find(target_s1);
	cout << "de��λ���ǣ�" << target_postion << endl;//���ڸ�ֵ��ʱ��
	target_s1 = "ed";
	target_postion = s1.find(target_s1);
	cout << "de��λ���ǣ�" << target_postion << endl;//�����ڸ�ֵ��ʱ�����-1
	//���������������ж�
	target_postion = s1.rfind("de");
	cout << "de��λ���ǣ�rfind����" << target_postion << endl;
	//rfind�Ǵ��������
}

void test_string4() {
	//�滻 replace
	string s1 = "abcdefgh";
	s1.replace(1, 3, "1111");
	cout << "�滻1-3���ַ�Ϊ1111��" << s1 << endl;//��1��λ�ÿ�ʼ������3��λ�ã��滻Ϊ1111��ע����ֱ���滻
	//����ν�滻�ɼ����ַ���
}