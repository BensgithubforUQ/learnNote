#pragma once
#include <iostream>
#include <string>
#include "myHead.h"
#include <vector>
using namespace std;


struct student {
	string name;
	int age;
	float grade;
};

struct teacher {
	string name;
	int age;
	vector<struct student> stu;
};

struct person {
	string addrName;
	int addrAge;
	string addrGender;
	vector<long long> addrNumber;
	string addrAddress;
	bool addrStarContacts;
};

struct address {
	vector<struct person> people;
	const int max = 10;
};

int add(int num1, int num2);
void swap(int* num1, int* num2);
void printArray(int* arr, int len);
int  getSizeOfArr(int* arr);
void popArr(int* arr, int len);

//�ṹ�庯��
void printStructStudent(struct student stu);
void printStructStudent2(struct student* stu);
void inputStructStudent(struct teacher* t);
void printStructTeacher(struct teacher* t, int len);
void inputStructStudent2(struct teacher* t, struct student* s, int len);

//ͨѶ¼��ɾ���ӡ
int addAddress(struct address* ab, struct person* a);
//ɾ
int delAddress(struct address* ab);
//��
int searchAddress(struct address* a);
//��
int changeAddress(struct address* abs);
//ӡ
void printAddress(struct person a);
void printAddressList(struct address a);
//ȫɾ
int delAddressList(struct address* a);
//��
void exitAddressList();
void menu();

