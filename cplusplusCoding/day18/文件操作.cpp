#include <iostream>
#include <string>
#include <fstream>//�ļ���д����дfstream
using namespace std;

void output_file() {//�������������ļ�����
	//����������
	ofstream ofs;
	//ָ���򿪵ķ�ʽ
	ofs.open("test.txt", ios::out);//��һ��������·�����ڶ��������Ǵ򿪷�ʽ
	//д����
	ofs << "��������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//�����ļ���ر��ļ�
	ofs.close();
}

int input_file() {//���������ȡ�ļ�
	//����������
	ifstream ifs;
	//���ļ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {//����ɹ����ļ���ifs.is_open����bool���͵�true
		cout << "�ļ���ʧ�ܣ���ǰĿ¼û���ҵ����ļ�" << endl;
		return 1;
	}

	//���ֶ�ȡ����
	//1.whileѭ��+�ַ�����ķ�����ȡ
	char buf1[1024] = {};
	while (ifs >> buf1) {
		cout << buf1 << endl;
	}
	ifs.close();
	//2.�ַ�����+ifs��Ա����getline����
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {//����ɹ����ļ���ifs.is_open����bool���͵�true
		cout << "�ļ���ʧ�ܣ���ǰĿ¼û���ҵ����ļ�" << endl;
		return 1;
	}
	char buf2[1024] = {};
	while (ifs.getline(buf2, sizeof(buf2) / sizeof(buf2[0]))) {
		cout << buf2 << endl;
	}
	ifs.close();
	//3.string
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {//����ɹ����ļ���ifs.is_open����bool���͵�true
		cout << "�ļ���ʧ�ܣ���ǰĿ¼û���ҵ����ļ�" << endl;
		return 1;
	}
	string buf3;
	while (getline(ifs,buf3)) {//һ���ж�ȡ
		cout << buf3 << endl;
	}
	ifs.close();
	//get�ķ�ʽ
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {//����ɹ����ļ���ifs.is_open����bool���͵�true
		cout << "�ļ���ʧ�ܣ���ǰĿ¼û���ҵ����ļ�" << endl;
		return 1;
	}
	char buf4;
	while ((buf4 = ifs.get()) != EOF) {//���Ƽ��õ����֣�һ�����ַ�����Ч�ʵ�
		//EOF,end of file,==eof�Ͷ������ļ�β��
		cout << buf4;
	}
	ifs.close();
	return 0;
}

class person {
public:
	char p_name[1024] = {};
		int p_age;
};

void output_file_binary() {
	//����������
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	//д�ļ�
	person p = { "����",18 };
	ofs.write((const char *)&p,sizeof(person));
}

int input_file_binary() {
	//����������
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	//д�ļ�
	if (!ifs.is_open()) {//����ɹ����ļ���ifs.is_open����bool���͵�true
		cout << "�ļ���ʧ�ܣ���ǰĿ¼û���ҵ����ļ�" << endl;
		return 1;
	}
	person p;
	ifs.read((char*)&p, sizeof(person)); //�������Ҫ��ס�ˡ�read�ӿ�
	cout << p.p_name << endl;
	cout << p.p_age << endl;
	ifs.close();
}
int main() {
	
	//output_file();
	//input_file();
	output_file_binary();
	input_file_binary();
	system("pause");
	return 0;
}