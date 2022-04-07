#include "workerManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
constexpr auto fileName = "workermanager_data.txt";

WorkerManager::WorkerManager() {//���캯��
	//�ļ������ڵ����
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cerr << "file is not existing" << endl;
		//��ʼ������
		this->worker_array = NULL;
		this->worker_size = 0;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	else {
		char checkIfIsBlank;
		ifs >> checkIfIsBlank;
		if (ifs.eof()) {
			cout << "�����ļ�Ϊ��" << endl;
			this->worker_array = NULL;
			this->worker_size = 0;
			this->fileIsEmpty = true;
			ifs.close();
		}
		else {
			
			int worker_number = this->get_worker_number();
			this->worker_size = worker_number;
			cout << "�����ļ����ڣ��������г���,�У�" <<this->worker_size<<"��Ա��" << endl;
			
			this->initial_Worker();
		}
	}

}

WorkerManager::~WorkerManager() {//��������
	//�������������ݣ��ֶ����٣��ֶ��ͷţ����ɺ�ϰ��
	if (this->worker_array != NULL) {
		delete[] this->worker_array;
		this->worker_array = NULL;
		cout << "�ɹ�����workermanager����" << endl;
	}
}

void WorkerManager::show_Menu() {//��ʾ�˵�
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0.�˳�ְ������ϵͳ" << endl;
	cout << "**1.����ְ����Ϣ**" << endl;
	cout << "**2.��ʾְ����Ϣ**" << endl;
	cout << "**3.ɾ����ְְ��**" << endl;
	cout << "**4.�޸�ְ����Ϣ**" << endl;
	cout << "**5.����ְ����Ϣ**" << endl;
	cout << "6.�����ӡְ����Ϣ" << endl;
	cout << "**7.�����������**" << endl;
	cout << endl;
}

void WorkerManager::exit_Menu() {
	cout << "�ڴ��´�ʹ�ã��ټ�" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addEmployee() {
	cout << "��������Ҫ���ӵ�ְ���ĸ���" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {
		int newSize = addNum + this->worker_size;//�����µģ���Ҫ�ڶ������ٵĿռ�Ĵ�С
		//�����¿ռ�
		 AbstractWorker **new_worker_array = new  AbstractWorker* [newSize+8];
		 if (this->worker_array != NULL) {
			 for (int i = 0; i < this->worker_size;i++) {
				 new_worker_array[i] = worker_array[i];
			 }
		 }
		 for (int j = 0; j < addNum; j++) {
			 int id;
			 string name;
			 int d_id;
			 cout << "������� " << j + 1 << "���û��ı��" << endl;
			 cin >> id;
			 cout << "������� " << j + 1 << "���û�������" << endl;
			 cin >> name;
			 cout << "��ѡ��� " << j + 1 << "���û��ĸ�λ" << endl;
			 cout << "0,boss��1,manager,2,employee" << endl;
			 cin >> d_id;

			 AbstractWorker* worker = NULL;
			 switch (d_id)
			 {
			 case 0:
				 worker = new Boss(name, id, d_id);
				 break;
			 case 1:
				 worker = new Manager(name, id, d_id);
				 break;
			 case 2:
				 worker = new Employee(name, id, d_id);
				 break;
			 default:
				 break;
			 }
			 new_worker_array[this->worker_size + j] = worker;
		 }
		 //�ͷ�ԭ�еĿռ�
		 delete[] this->worker_array;
		 //�����¿ռ��ָ��
		 this->worker_array = new_worker_array;
		 //�����¿ռ�Ĵ�С��ְ��������
		 this->worker_size = newSize;
		 this->save_file();
		 this->fileIsEmpty = false;
		 cout << "�ɹ�����ˣ�" << newSize << "����ְ��������Ա������Ϊ��" << this->worker_size << endl;
	}
	else {
		cout << "������������������������" << endl;

	}
	system("pause");
	system("cls");
}

void WorkerManager::save_file() {
	ofstream ofs;//����������
	//��,�������ģʽ�򿪣���˼����д�ļ�
	ofs.open(fileName, ios::out|ios::trunc);
	//forѭ�����Ѽ�¼�������뵽�ļ���
	for (int i = 0; i < this->worker_size; i++) {
		ofs << this->worker_array[i]->w_person_id << " "
		<< this->worker_array[i]->w_name<<" "
		<< this->worker_array[i]->w_department_id << endl;
	}
	ofs.close();
}	

int WorkerManager::get_worker_number() {
	ifstream ifs;
	ifs.open(fileName, ios::in);
	int id;
	string name;
	int d_id;
	int number = 0;
	while (ifs >> id && ifs >> name && ifs >> d_id) {
		number++;//ͳ������
	}
	return number;
}

void WorkerManager::initial_Worker() {
	ifstream ifs;
	ifs.open(fileName, ios::in);
	this->worker_array = new AbstractWorker * [this->worker_size];//new�������ռ�
	int id, d_id;
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> d_id) {
		AbstractWorker* worker = NULL;
		if (d_id == 2) {
			worker = new Employee(name, id, d_id);
		}
		if (d_id == 0) {
			worker = new Boss(name, id, d_id);
		}
		if (d_id == 1) {
			worker = new Manager(name, id, d_id);
		}
		this->worker_array[index++] = worker;
	}
	ifs.close();
}

void WorkerManager::show_WorkerInfo() {
	if (this->fileIsEmpty == false) {
		cout << "һ����" << this->worker_size << "��ְ��" << endl;
		for (int i = 0; i < this->worker_size; i++) {
			cout << "���ţ�" << this->worker_array[i]->w_person_id << " "
				<< "������ " << this->worker_array[i]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[i]->w_department_id << endl;
		}
	}
	else {
		cout << "�ļ������ڣ������ļ�Ϊ��" << endl;
	}
	system("pause");
	system("cls");
}
int WorkerManager::isExist(string name) {
	for (int i = 0; i < this->worker_size; i++) {
		if (this->worker_array[i]->w_name == name) {
			cout << "���ڸ�ְ��" << endl;
			return i;
		}
	}
	cout << "ְ��������" << endl;
	return -1;
}
int WorkerManager::isExist(int id) {
	for (int i = 0; i < this->worker_size; i++) {
		if (this->worker_array[i]->w_person_id == id) {
			cout << "���ڸ�ְ����Ŷ�Ӧ��ְ��" << endl;
			return i;
		}
	}
	cout << "ְ��������" << endl;
	return -1;
}
void WorkerManager::search_Worker() {
	cout << "��ѡ����Ҫ��β�ѯְ��" << endl
		<< "1.�������ֲ�ѯ" << endl
		<< "2.����id��ѯ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "����������" << endl;
		string name;
		cin >> name;
		int id = this->isExist(name);
		if (id != -1) {
			cout << "ְ����ϢΪ��" << endl;
			cout << "���ţ�" << this->worker_array[id]->w_person_id << " "
				<< "������ " << this->worker_array[id]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[id]->w_department_id << endl;
		}
	}
	else if (choice == 2) {
		cout << "��������" << endl;
		int search_id;
		cin >> search_id;
		int id = this->isExist(search_id);
		if (id != -1) {
			cout << "ְ����ϢΪ��" << endl;
			cout << "���ţ�" << this->worker_array[id]->w_person_id << " "
				<< "������ " << this->worker_array[id]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[id]->w_department_id << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::confirm_delete(int id) {
	cout << "���Ҫɾ����ְ������Ϣ��?��������Y������ȡ��" << endl;
	char make_Sure;
	cin >> make_Sure;
	if (make_Sure == 'Y') {
		this->worker_array[id] = this->worker_array[this->worker_size - 1];
		this->worker_array[this->worker_size - 1] = NULL;
		--this->worker_size;
		this->save_file();
	}
	else {
		cout << "ȡ��ɾ��";
		return;
	}
}
void WorkerManager::delete_Worker() {
	cout << "��ѡ����Ҫ��β�ѯְ��" << endl
		<< "1.�������ֲ�ѯ" << endl
		<< "2.����id��ѯ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cout << "����������" << endl;
		string name;
		cin >> name;
		int id = this->isExist(name);
		if (id != -1) {
			cout << "ְ����ϢΪ��" << endl;
			cout << "���ţ�" << this->worker_array[id]->w_person_id << " "
				<< "������ " << this->worker_array[id]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[id]->w_department_id << endl;
		}
		this->confirm_delete(id);
	}
	else if (choice == 2) {
		cout << "��������" << endl;
		int search_id;
		cin >> search_id;
		int id = this->isExist(search_id);
		if (id != -1) {
			cout << "ְ����ϢΪ��" << endl;
			cout << "���ţ�" << this->worker_array[id]->w_person_id << " "
				<< "������ " << this->worker_array[id]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[id]->w_department_id << endl;
		}
		this->confirm_delete(id);
	}
	system("pause");
	system("cls");
}
