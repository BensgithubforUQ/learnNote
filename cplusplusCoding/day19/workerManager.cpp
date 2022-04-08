#include "workerManager.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <vector>
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
		//ɾ��������ÿ��ְ������Ȼ����Ҫɾ��������������ָ�롢
		for (int i = 0; i < this->worker_size; i++) {
			delete this->worker_array[i];
			this->worker_array[i] = NULL;
		}
		//ɾ������ָ��
		delete[] this->worker_array;
		this->worker_array = NULL;
		this->worker_size = 0;
		this->fileIsEmpty = true;
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

int WorkerManager::check_same_id(int id) {
	for (int i = 0; i < this->worker_size; i++) {
		if (id == this->worker_array[i]->w_person_id) {
			cout << "id�ظ�������������" << endl;
			return 1;
		}
	}
	return 0;
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
			 do
			 {
				 cin >> id;
			 } while (check_same_id(id));
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
				 cout << "���棬��ʼ������Ϊ��ͨԱ��" << endl;
				 worker = new Employee(name, id, d_id);
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
	ofs.open(fileName, ios::out);
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
int WorkerManager::isExist(string name, vector<int> id_vector) {
	bool flag = false;
	int id;
	for (int i = 0; i < this->worker_size; i++) {
		if (this->worker_array[i]->w_name == name) {
			cout << "���ڸ�ְ��" << endl;
			flag = true;
			id_vector.push_back(i);
			cout << "���ţ�" << this->worker_array[i]->w_person_id << " "
				<< "������ " << this->worker_array[i]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[i]->w_department_id << endl;
			id = i;
		}
	}
	if (flag) {
		return id;
	}
	else {
		cout << "ְ��������" << endl;
		return -1;
	}
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

int WorkerManager::search_Worker_withName(vector<int> id_vector) {
	cout << "����������" << endl;
	string name;
	cin >> name;
	int id = this->isExist(name, id_vector);
	if (id != -1) {
		for (int i : id_vector) {
			cout << "ְ����ϢΪ��" << endl;
			cout << "���ţ�" << this->worker_array[i]->w_person_id << " "
				<< "������ " << this->worker_array[i]->w_name << " "
				<< "���ű�ţ� " << this->worker_array[i]->w_department_id << endl;
		}

	}
	return id;
}

int WorkerManager::search_Worker_withId() {
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
	return id;
}

void WorkerManager::search_Worker() {
	cout << "��ѡ����Ҫ��β�ѯְ��" << endl
		<< "1.�������ֲ�ѯ" << endl
		<< "2.����id��ѯ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		search_Worker_withId();
	}
	else if (choice == 2) {
		vector<int> id_vector;
		search_Worker_withName(id_vector);
	}
	system("pause");


	system("cls");
}
void WorkerManager::confirm_delete(int id) {
	cout << "���Ҫɾ����ְ������Ϣ��?��������Y/y������ȡ��" << endl;
	char make_Sure;
	cin >> make_Sure;
	if (make_Sure == 'Y'|| make_Sure == 'y') {
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
		<< "1.����id��ѯ" << endl
		<< "2.�������ֲ�ѯ" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		int id = search_Worker_withId();
		if (id != -1) {
			this->confirm_delete(id);
		}
	}
	else if (choice == 2) {
		vector<int> id_vector;
		int id = search_Worker_withName(id_vector);
		if (id != -1) {
			this->confirm_delete(id);
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::change_worker_info() {
	cout << "��ѡ����Ҫ��β�ѯְ��" << endl
		<< "1.����id��ѯ" << endl
		<< "2.�������ֲ�ѯ" << endl;
	int choice;
	cin >> choice;
	vector<int> id_vector;
	int id = 0;
	if (choice == 1) {
		id = search_Worker_withId();
	}
	else if (choice == 2) {
		
		id = search_Worker_withName(id_vector);
	}
	if (id != -1) {
			cout << "�������޸ĺ��Ա��������" << endl;
			getchar();//ֹͣһ�£���ΪҪ����һ���س�
			getline(cin, this->worker_array[id]->w_name);
			cout << "�������޸ĺ��Ա�����ű�ţ�" << endl;
			int d_id;
			cin >> d_id;
			this->worker_array[id]->w_department_id = d_id;

		
		this->save_file();
		cout << "�޸ĳɹ�......" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Worker() {
	if (this->fileIsEmpty) {
		cout << "���ļ�" << endl;
	}
	else {
		for (int i = 0; i < this->worker_size; i++) {
			for (int j = i + 1; j < this->worker_size; j++) {
				if (this->worker_array[i]->w_person_id > this->worker_array[j]->w_person_id) {
					int temp_id;
					int temp_d_id;
					string temp_name;
					temp_id = this->worker_array[i]->w_person_id;
					temp_d_id = this->worker_array[i]->w_department_id;
					temp_name = this->worker_array[i]->w_name;
					this->worker_array[i]->w_person_id = this->worker_array[j]->w_person_id;
					this->worker_array[i]->w_department_id = this->worker_array[j]->w_department_id;
					this->worker_array[i]->w_name = this->worker_array[j]->w_name;
					this->worker_array[j]->w_person_id = temp_id;
					this->worker_array[j]->w_department_id = temp_d_id;
					this->worker_array[j]->w_name = temp_name;

				}
			}
		}
	}
	this->save_file();
	cout << "�������" << endl;
	system("pause");
	system("cls");
}

void WorkerManager::delete_all_data() {
	cout << "ȷ��ɾ��������Y/y������ȡ��" << endl;
	char confirm;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y') {
		ofstream ofs(fileName,ios::trunc);//�Ȱ��ļ�ɾ�����½����յ�
		ofs.close();
		if (this->worker_array != NULL) {
			//�൱����������
			for (int i = 0; i < this->worker_size; i++) {
				delete this->worker_array[i];
				this->worker_array[i] = NULL;
			}
			//ɾ������ָ��
			delete[] this->worker_array;
			this->worker_array = NULL;
			this->worker_size = 0;
			this->fileIsEmpty = true;
			cout << "�����Ѿ�ȫ��ɾ�����" << endl;
		}
		else {
			cout << "�ļ�Ϊ�գ�����ɾ��" << endl;
		}
	}
	system("pause");
	system("cls");
}