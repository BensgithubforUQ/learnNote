#pragma once
#include "myHead.h"
//#include "Circle.h" ���ﲻ�ܰ������ͷ�ļ�����Ϊcircle���ͷ�ļ��Ǳ���Ҫ��ߵ���
//�������circle��ͷ�ļ���������Դ��ʱ��Ͷ�ȡ�Ǳߣ������Ǳ��ֻ��ȡ��ߣ��Ǳ߲�û�л�ȡ��point
//��������������÷����˹�ߵĵ��ã��ͻᱨ���߼���������
//�е����м��������е�����˼��
using namespace std;

class Point {//���࣬�����ʵ�������ڲ���Բ�͵�Ĺ�ϵ
public:
	void setPointCoordinate(double x, double y); //���õ������
	void relationship(double x, double y, double r_c);
	double getX();
	double getY();
private:
	double x_p_coordinate;
	double y_p_coordinate;
};