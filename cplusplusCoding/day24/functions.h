#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Employee.h"
#include <map>
using namespace std;

#define planningDep 0
#define developDep 1
#define artDep 2

void addElement(vector<Employee> &v); //��vector���������Ԫ��
void assignTask(vector<Employee>& v,multimap<int, Employee>&m); //��vector���������Ա����������
void showTaskGroup(const vector<Employee>& v);
void showTaskGroup( multimap<int,Employee> &m);
void department(multimap<int, Employee>& m, int i);//�����Ŵ�ӡ��int�����������keyֵ
void showMapByTask(multimap<int, Employee>& m);//��ͳ��show������