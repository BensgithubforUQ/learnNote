#include "virtual_son_template.hpp"
//��Ϊ��ģ��ĳ�Ա�����ڵ��õ�ʱ��Ŵ�����
/*��ˣ�������ļ�д�Ļ����ᵼ���ڲ�ѯ.h�ļ���ʱ���޷����ӵ��ú���
���Ի����ģ�����������ģ��ĳ�Ա��������д��һ��ͷ�ļ�������ļ���׺��hpp*/



void test_vitural_fatherToSon_classTemplate() {//�����ø������õ��ö�̬����Ȼ������ֻʵ���˵�һ���������
	abstractFather<string, int, int>* aF =
		new son_template_father<string, int, int, string>("����", 10, 30, "�������");
	aF->showInfo();
	delete aF;
}
void test_vitural_fatherToSon_classTemplate2() {//���������е���Ԫȫ�ֺ�������ӡson�������
	son_template_father<string, int, int, string> sF("����", 10, 30, "С������");
	printThisClassInfo(sF);
}
//int main() {
//	test_vitural_fatherToSon_classTemplate();
//	cout << "*****************" << endl;
//	test_vitural_fatherToSon_classTemplate2();
//	system("pause");
//	return 0;
//}