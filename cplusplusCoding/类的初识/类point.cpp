#include "myHead.h"	
#include "point.h"
/*
* ʵ��5���жϵ��Բ�Ĺ�ϵ
* ��Ҫһ��point���ͺ�һ��circle����
* �������������ԣ�Բ���а뾶���ԣ��˴��ظ����ð���һ�ж�����ࡣ
*/

	void Point::setPointCoordinate(double x, double y) {//���õ������
		x_p_coordinate = x;
		y_p_coordinate = y;
	}
	void Point::relationship(double x1,double y1,double r_c) {
		double x = x1;
		double y = y1;
		double distance = (x_p_coordinate - x) * (x_p_coordinate - x) + (y_p_coordinate - y) * (y_p_coordinate - y);
		double rSquare = r_c * r_c;
		cout << "x: " << x << " y:" << y << endl;
		cout << "x_p: " << x_p_coordinate << " y_p:" << y_p_coordinate << endl;
		cout << "distance: " << distance << " r^2: " << rSquare << endl;
		if (distance == rSquare) {
			cout << "����Բ��" << endl;
		}
		else if (distance > rSquare) {
			cout << "����Բ��" << endl;
		}
		else if (distance < rSquare) {
			cout << "����Բ��" << endl;
		}
	}
	double Point::getX() {
		return x_p_coordinate;
	}
	double Point::getY() {
		return y_p_coordinate;
	}

