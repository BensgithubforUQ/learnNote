#include "myHead.h"	
#include "circle.h"
/*
c++���������������ԣ���װ���̳У���̬
c++��Ϊ�������ﶼ�Ƕ��󣬶����������Ժ���Ϊ

������ͬ���ʵĶ��󣬿��Ա�����Ϊ ���ࡱ���������ࡣ

��װ��
��װ�������ǣ�
1.�����Ժ���Ϊ��Ϊһ�����壬�����������е����
2.�����Ժ���Ϊ����Ȩ�޿���

��װ������֮һ���������Ժ���Ϊ��Ϊһ�����壬�����������е����
�﷨ class ����{����Ȩ�ޣ�����}
��װ�������������Ȩ�ޣ�
����Ȩ�� public
����Ȩ�� protected
˽��Ȩ�� private
*/
//��װ������1��
//���һ��Բ�࣬��Բ���ܳ�
const double Pi = 3.14;
double Circle::calculatePerimeter() {//��ȡԲ���ܳ�
	return 2 * Pi * r_c;
}
void Circle::setPoint(Point c_p) {
	center = c_p;
}
void Circle::getPoint(int *x,int *y) {
	*x = center.getX();
	*y = center.getY();
}
