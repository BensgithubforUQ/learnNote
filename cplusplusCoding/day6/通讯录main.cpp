#include <iostream>
#include <string>
#include "myHead.h"
#include <vector>
using namespace std;

//��������
//struct address {
//	string addrName;
//	int addrAge;
//	string addrGender;
//	vector<long long> addrNumber;
//	string addrAddress;
//	bool addrStarContacts;
//};

int main() {
	struct person addr;
	addr.addrName = "������";
	addr.addrAge = 26;
	addr.addrGender = "��";
	addr.addrNumber = { 
		13034470589 
	};
	addr.addrAddress = "����ʡ�Ƹ����ˮ��",
	addr.addrStarContacts = true;
	struct address abs;
	abs.people.push_back(addr);
	//��ʼ��һ��Ƕ�׵Ľṹ�壬address����person��������һ��person�����ʼ��address�е�vector����

	while (true) {
		struct person addrNew;
		int flag = 0;
		cout << "�������ˢ�½��棬����ͨѶ¼ϵͳ" << endl;
		//cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		menu();
		switch (getchar())
		{
		case '1':
			flag = addAddress(&abs,&addrNew);
			if (flag == 1) cout << "�ɹ����" << endl;
			else cout << "��ֹ���" << endl;
			break;//�����ϵ��

		case '2':
			cout << "��������ϵ������:" << endl;
			flag = searchAddress(&abs);
			break;//������ϵ��
		case '3':
			flag = changeAddress(&abs);
			break;//�޸���ϵ��
		case '4':
			delAddress(&abs);
			break;//ɾ����ϵ��
		case '5':
			delAddressList(&abs);
			break;//ɾ��ͨѶ¼

		case '6':printAddressList(abs);//printAddress(addr); 
			break;//��ӡͨѶ¼

		case '0':
			exitAddressList();
			break;//�˳�ͨѶ¼
		}
		std::system("pause");
		std::system("cls");

	}
	return 0;
}