#pragma once
#include "myHead.h"
#include "Point.h"
using namespace std;

class Circle {
	//Perimeter = 2*PI*r;
	//����Ȩ��
	//����Ȩ��
public:
	//���е����Ժ���Ϊ����������ĳ�Ա
	//����
	double r_c;//�뾶
	//��Ϊ	
	double calculatePerimeter();//��ȡԲ���ܳ�
	void setPoint(Point c_p);
	void getPoint(int* x, int* y);
	//double getX() {
	//	return x_c_coordinate;
	//}
	//double getY() {
	//	return y_c_coordinate;
	//}
	//void setXY(double x, double y) {
	//	x_c_coordinate = x;
	//	y_c_coordinate = y;
	//}
private:
	Point center;
};
