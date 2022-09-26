#include "myOwnPair.hpp"

/*********************
Function:     testConstructAnd
Description:  �����Զ����������͵Ĺ��죬��ֵ��������������<<
Calls:        <<���أ�=����
Called By:    main
*********************/
void testConstructAnd()
{
	/*һ���Զ����������ݣ�����pair����vector�������޲ι���*/
	std::vector<myOwnPair<char, int>> vecOwnPair(10, myOwnPair<char, int>());

	/*���Ը�ֵ�������вι���Ϳ���*/
	for (int i = 0; i < vecOwnPair.size(); ++i)
	{
		vecOwnPair[i] = myOwnPair<char, int>('a' + i, i);
		std::cout << vecOwnPair[i] << " " << myOwnPair<char, int>::getOwnPairAmount() << std::endl;
	}

	/*����resize��������*/
	vecOwnPair.resize(1);
	std::cout << myOwnPair<char, int>::getOwnPairAmount() << std::endl;
}

/*********************
Function:     testCmp
Description:  ���ԱȽϷ�<
Calls:        <����
Called By:    main
*********************/
void testCmp()
{
	myOwnPair<char, int> cmpLeftPair('1', 1);
	myOwnPair<char, int> cmpRightPair('0', 2);

	/*���� < �ȽϷ�*/
	if (cmpLeftPair < cmpRightPair)
	{
		std::cout << "yes,left is smaller." << std::endl;
	}
	else
	{
		std::cout << "No,left is bigger." << std::endl;
	}
}


int main() {
	testConstructAnd();
	testCmp();

	return 0;
}