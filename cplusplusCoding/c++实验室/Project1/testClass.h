#ifndef TESTCLASS_H
#include <iostream>
using namespace std;

class Test {
public:
	~Test() {
		cout << "����..." << endl;
	}

	Test() {
		x = 0, y = 0; //Ĭ�Ϲ���
	} 
	Test(int x1, int y1):x(x1),y(y1) {} //��ֵ����
	Test(Test& t) {  //��������
		this->x = t.x, this->y = t.y; 
	}
	void operator=(Test& t) { //��ֵ
		this->x = t.x, this->y = t.y;
	}
	void printTest() {
		cout << "x: " << x << " y: " << y << endl; 
	}
	void changeTest(int change_x, int change_y) {
		x += change_x;
		y += change_y;
	}
protected:
private:
	int x;
	int y;
};
#endif // !TESTCLASS_H
