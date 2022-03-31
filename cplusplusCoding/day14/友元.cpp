#include <iostream>
#include <string>
using namespace std;

class Mate;
class Building;

class Mate {
public:
	void visit();
	Building* building;
	void visitFriend();
	Mate();
private:
};

class Building {//��������
	friend void mate(Building* building);//ȫ�ֺ�����building����Ԫ�����Է���building��˽�г�Ա
	friend class Mate;
	friend void Mate::visitFriend();
public:
	Building();
	Building(string s, string b) :m_settingRoom(s), m_bedRoom(b) {

	}
public:
	string m_settingRoom; //����
private:
	string m_bedRoom;//����
};

Building::Building() {//��Ϊ�������mate�����ö���ָ�����˸�����ָ�룬û�ж�����ʵ����
	//���������ﲻ���޲εĹ��캯����һ����ʼ���Ļ����Ƿ������Ծͻᱨ����Ϊ�����ڡ�
	m_settingRoom = "��ʼ������";
	m_bedRoom = "��ʼ������";
}
/*��Ԫ������ĺ�����������������ʵ����ڵ�private˽�г�Ա*/
//1.ȫ�ֺ�������Ԫ
void mate(Building* building) {
	cout << " ȫ�ֺ���mate����publicȨ�޵ģ�" << building->m_settingRoom << endl;

	cout << " ��Ԫȫ�ֺ���mate����privateȨ�޵ģ�" << building->m_bedRoom << endl;
}
//2.������Ԫ

void Mate::visit() {
	cout << "��Mate����ͨ����Ԫ������Building��˽������m_bedRoom: " <<building->m_bedRoom<< endl;
}
Mate::Mate() {
	//����һ�����������
	 building = new Building;
}
//3.��Ա��������Ԫ
void Mate::visitFriend() {
	cout << "��Mate�еĳ�Ա��������ͨ����Ԫ������Building��˽������m_bedRoom: " << building->m_bedRoom << endl;
}


int main() {
	Building b_global_friend_test("����", "����");
	mate(&b_global_friend_test);
	Mate m_class_friend_test;
	m_class_friend_test.visit();
	m_class_friend_test.visitFriend();
	return 0;
}