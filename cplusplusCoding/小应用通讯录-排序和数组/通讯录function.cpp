#include "myHead.h"

//struct address {
//	string name;
//	int age;
//	string gender;
//	vector<int> number;
//	string address;
//	bool starContacts;
//};

//struct address {
//	vector<struct person> people;
//	const int max = 10;
//};

//��
void menu() {
	cout << "**********" << "1.�����ϵ��" << "**********" << endl;
	cout << "**********" << "2.������ϵ��" << "**********" << endl;
	cout << "**********" << "3.�޸���ϵ��" << "**********" << endl;
	cout << "**********" << "4.ɾ����ϵ��" << "**********" << endl;
	cout << "**********" << "5.ɾ��ͨѶ¼" << "**********" << endl;
	cout << "**********" << "6.��ӡͨѶ¼" << "**********" << endl;
	cout << "**********" << "0.�˳�ͨѶ¼" << "**********" << endl;
	cout << "����Ӧ���ּ�����" << endl;
}
int addAddress(struct address* ab,struct person *a) {
	cout << "�Ƿ���������ϵ�ˣ���������y����������" << endl;
	getchar();
	if (getchar() != 'y') {
		cout << "����������" << endl;
		string name;
		cin >> name;
		auto beg = ab->people.begin(), end = ab->people.end();
		int flag = 0;//���ڱ���Ƿ��Ǻϲ�Ϊͬһ�û����Ǿ͸�Ϊ1.
		while (beg != end) {
			if (name == beg->addrName) {
				cout << "��⵽ͬ���û����Ƿ�ֱ������û������ĺ��룿�ǣ�������y" << endl;
				getchar();
				if (getchar() == 'y') {
					cout << "��������룺" << endl;
					int newNumber = 0;
					cin >> newNumber;
					beg->addrNumber.push_back(newNumber);
					flag = 1;
				}
				else {
					cout << "ȡ������ͬһ����ϵ�ˣ���ʼ�����µ���ϵ�ˣ�" <<name<< endl;
					a->addrName = name;
				}
			}
			beg++;
		}	
		if (flag == 0) {
			a->addrName = name;
			cout << "�������Ա�" << endl;
			cin >> a->addrGender;
			cout << "����������" << endl;
			cin >> a->addrAge;
			cout << "�������ַ" << endl;
			cin >> a->addrAddress;
			cout << "������绰����" << endl;
			int num = 0;
			cin >> num;
			a->addrNumber.push_back(num);
			cout << "��ѡ���Ƿ����Ǽ���ϵ�ˣ�����ǣ�������y" << endl;
			getchar();
			if (getchar() == 'y') {
				a->addrStarContacts = true;
			}
			else {
				a->addrStarContacts = false;
			}
			ab->people.push_back(*a);
		}
		return 1;
	}
	else {
		cout << "ȡ��������ϵ����Ϣ" << endl;
		return 0;
	}
}
//ɾ
int delAddress(struct address *ab) {
	auto beg = ab->people.begin(), end = ab->people.end();
	cout << "����������" << endl;
	string name;
	cin >> name;
	int flag = 0;//���ڱ���Ƿ��Ǻϲ�Ϊͬһ�û����Ǿ͸�Ϊ1.
	while (beg != end) {
		if (name == beg->addrName) {
			cout << "��⵽ͬ���û����Ƿ�ֱ��ɾ������yֹͣ����������" << endl;
			int size = (ab->people.size());
			getchar();
			
			if (getchar() != 'y') {
				ab->people.erase(beg);
				cout << "ɾ���ɹ�" << endl;
				break;
			}
			else {
				cout << "ȡ������ɾ��" << name << endl;
			}
		}
		beg++;
	}
	return 1;
}
//��
int searchAddress(struct address *a) {
	auto beg = a->people.begin(), end = a->people.end();
	string target;
	getchar();
	//getline(cin, target);
	cin >> target;
	while (beg != end) {
		int flag = 1, amount = 0;
		auto targetSize = target.size();
		for (int i = 0; i < targetSize; i++) {
			if (beg->addrName[i] != target[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printAddress(*beg);
			amount++;
		}
		beg++;
		if (beg == end&& amount==0) {
			cout << "û���ҵ�Ŀ����ϵ��ʽ" << endl;
		}
		else {
			cout << "�������" << endl;
		}
	}
	return 1;
}
//��
int changeAddress(struct address * a) {
	cout << "��������Ҫ�޸ĵ���ϵ�˵�����" << endl;
	auto beg = a->people.begin(), end = a->people.end();
	string target;
	getchar();
	//getline(cin, target);
	cin >> target;
	while (beg != end) {
		int flag = 1, amount = 0;
		auto targetSize = target.size();
		for (int i = 0; i < targetSize; i++) {
			if (beg->addrName[i] != target[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printAddress(*beg);
			getchar();
			cout << "ȷ���Ƿ��޸Ĵ���ϵ����Ϣ,��yȡ��������������" << endl;
			char approval;
			cin >> approval;
			if (approval != 'y') {
				cout << "����������" << endl;
				cin >> beg->addrName;
				cout << "�������Ա�" << endl;
				cin >> beg->addrGender;
				cout << "����������" << endl;
				cin >> beg->addrAge;
				cout << "�������ַ" << endl;
				cin >> beg->addrAddress;

				vector<long long> newNum;

				cout << "������绰����" << endl;
				int num = 0;
				cin >> num;
				newNum.push_back(num);
				beg->addrNumber = newNum;
				cout << "��ѡ���Ƿ����Ǽ���ϵ�ˣ�����ǣ�������y" << endl;
				getchar();
				if (getchar() == 'y') {
					beg->addrStarContacts = true;
				}
				else {
					beg->addrStarContacts = false;
				}
			}
			else {
				cout << "ȡ���޸Ĵ���ϵ����Ϣ" << endl;
			}
			amount++;
		}
		beg++;
		if (beg == end && amount == 0) {
			cout << "û���ҵ�Ŀ����ϵ��ʽ" << endl;
		}
		else {
			cout << "�������" << endl;
		}
	}
	return 1;
}
//ӡ
void printAddress(struct person a) {
	cout << "������" << a.addrName << endl;	
	cout << "���䣺" << a.addrAge << endl;
	cout << "�Ա�" << a.addrGender << endl;
	cout << "��ַ��" << a.addrAddress << endl;
	for (auto addv = a.addrNumber.begin(); addv != a.addrNumber.end(); addv++) {
		cout << "�绰����: " << (long long) * addv << endl;
	}
	if (a.addrStarContacts) {
		cout << "�Ǽ���ϵ�� " << endl;
	}
	else {
		cout << "��ͨ��ϵ�� " << endl;
	}
}
//��ӡȫ��
void printAddressList(struct address a) {
	if (a.people.size()!=0) {
		auto beg = a.people.begin(),end = a.people.end();
		while (beg != end) {
			printAddress(*beg);
			beg++;
		}
	}
	else {
		cout << "ͨѶ¼�ǿյġ�" << endl;
	}
}
//ȫɾ
int delAddressList(struct address *a) {
	//int size = a->people.size();
	//while (size) {
	//	a->people.pop_back();
	//	size--;
	//}
	vector<struct person> peoNull;
	a->people = peoNull;
	cout << "ͨѶ¼�Ѿ����" << endl;
	return 1;
}
//��
void exitAddressList() {
	cout << "���Ҫ�˳��𣿼���������y�������˳�" << endl;
	getchar();
	if (getchar() != 'y') {
		exit(0);
	}
	else {
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}
}