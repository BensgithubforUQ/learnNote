#include "stack_test.h"
#include "queue_test.h"
#include "list_test.h"
#include "Person.h"
#include <time.h>
#include <string>

/*list���Զ�������Person �������
������������������У����������ͬ��������߽��н�������*/

void p_array_show(Person* p, int size) {
	if (size) {
		for (int i = 0; i < size; i++) {
			p[i].showInfo();
		}
	}
	else {
		cout << "blank array" << endl;
	}
}

void p_array_show(list<Person> l) {//����һ������汾��
	if (!l.empty()) {
		for (list<Person>::iterator it = l.begin(); it != l.end(); it++) {
			//(*it).showInfo();
			it->showInfo();
		}
	}
	else {
		cout << "blank array" << endl;
	}
}

//���ûص�����дsort���������
bool comparePerson(Person &p1, Person &p2) {//��������꾫�����ݡ�
	//������������
	if (p2.getAge() == p1.getAge()) return p1.getheight() > p2.getheight();//�߼������ʵ�ַ���
	return p2.getAge() > p1.getAge();//��������
}


//int main() {
//	//stack_test0();
//	//queue_test0();
//	//list_test0();
//	srand((unsigned int)time(NULL));
//	int size = 20;
//	Person* p_array = new Person[size];
//	list<Person> p_list;
//	for (int i = 0; i < size; i++) {
//		char name_temp = (i + 65);
//		string name{ name_temp };
//		int age = rand() % 25 + 20;
//		float height = (rand() % 30 + 160) + (rand() / double(RAND_MAX));
//		Person p_temp(name, age, height);
//		p_array[i] = p_temp;//����汾
//		p_list.push_back(p_temp);//list�汾
//	}
//	//p_array_show(p_array, 5);
//	p_array_show(p_list);
//	//����
//	cout << "//����:" << endl;
//	p_list.sort(comparePerson);
//	p_array_show(p_list);
//	delete[] p_array;//�ͷŶ����ڴ�
//	p_array = NULL;
//	return 0;
//}