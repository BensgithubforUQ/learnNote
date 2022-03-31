#include "myHead.h"

void printStructStudent(struct student stu) {
	cout << "�ṹ���ж��������" << stu.name << "����" << stu.age << "�ɼ�" << stu.age << endl;
}
//�������е��βθ�Ϊָ�룬���Խ����ڴ�ռ����ģ����ҿ��Բ���ÿ�ζ�����һ������ĸ�������һ��ָ��ֻռ�ĸ��ڴ�ռ䡣
//��Ϊֵ���ݽ���������������һ��������������ԭ������в�������ô�ṹ���ж�󣬸������ж�󣬼�����������ڴ�ռ䡣
void printStructStudent2(struct student *stu) {
	cout << "�ṹ���ж��������" << stu->name << "����" << stu->age << "�ɼ�" << stu->age << endl;
}

//��ӡteacher����
void printStructTeacher(struct teacher* t,int len) {
	for (int i = 0; i < len; i++) {
		cout << (t + i)->name << " ���� " << (t + i)->age << endl;
		auto beg = (t + i)->stu.begin();
		while (beg != (t + i)->stu.end()) {
			cout << beg->name << " ���� " << beg->age << " �ɼ� " << beg->grade << endl;
			beg++;
		}
	}
}

//��"teacher"��������ӡ�student��������
void inputStructStudent(struct teacher* t) {
	string name;
	int age;
	float grade;
	cin >> name >> age >> grade;
	t->stu.push_back({ name,age,grade });
}

void inputStructStudent2(struct teacher* t, struct student *s,int len) {
	for (int i = 0; i < len; i++) {
		t->stu.push_back({ (s+i)->name,(s + i)->age,(s + i)->grade });
	}
}