#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
using namespace std;

vector<double> data_arr;
struct Parameter {
	int begin;
	int count; //size / 4;
	double sum;
}Para;

void getSum(Parameter *para) {
	int begin = para->begin;
	int count = para->count + begin;
	double sum = 0;
	int arr_size = data_arr.size();
	//cout << begin << endl;
	for (int i = begin; i < count && i< arr_size; i++) sum += data_arr[i];
	para->sum = sum;
	cout <<"����sum:" << sum << endl;
}

int test1() {
	fstream ifile;
	ifile.open("data1.txt"); //open file
	

	if (!ifile) { //open failed
		cout << "error" << endl;
		return 0;
	}

	double num = 0.0;
	while (ifile >> num) { //read file with " ";
		data_arr.push_back(num);
		//cout << num << endl;
	}

	int size = data_arr.size(); //get size

	cout << size << endl;

	const int thread_num = 22; //set thread num
	thread calculate_thread[thread_num]; //�߳�����
	Parameter part[thread_num]; //����ֿ�
	// 0 - size/4?

	for (int i = 0; i < thread_num; i++) {
		//��ʼ���ṹ�壬���Ρ�
		if (i != thread_num - 1) {
			part[i].begin = (size / thread_num) * i;
			part[i].count = size / thread_num;
			part[i].sum = 0.0;
		}
		else {//���һ����������������� 9 / 4 ���һ���������һ����
			part[i].begin = (size / thread_num) * i;
			part[i].count = size;
			part[i].sum = 0.0;
		}
		

		//��ʼ�����
		calculate_thread[i] = thread(getSum, &part[i]); //�߳�����
	}
	double part_sum = 0.0;
	for (int i = 0; i < thread_num; i++) calculate_thread[i].join(); //�����߳�
	for (int i = 0; i < thread_num; i++) part_sum += part[i].sum; //���κ�

	cout << part_sum / size << endl; //���߳����sum / size �������ƽ��ֵ��
	//-0.077937 answer?
	return 0;
}