#include "myHead.h"
#include "circle.h"
#include "Fruit.h"
//#include "point.h"���Ҳ���Բ�д����Ϊcircle.h�Ѿ�����point.h



//ʵ��2��ѧ���࣬Ҫ����������ѧ�ţ����ҿ��Դ�ӡ����ֵ��
class Student {
	//����Ȩ��
	//����Ȩ��
public:
	//���е����Ժ���Ϊ����������ĳ�Ա
	/*s���ԣ�Ҳ������Ա���ԣ��ͳ�Ա����
	���� string
	ѧ�� long long
	*/
	string name_s;
	long long id_s;
	//��Ϊ��Ҳ������Ա���������߳�Ա������
	//��ӡ
	void printrInfo_s() {
		cout << "����: " << name_s << " id: " << id_s << endl;
	}
	void set_name_s(string *name) {
		name_s = *name;
	}
	void set_id_s(long long *id) {
		id_s = *id;
	}
};
//��װ�������������Ȩ�ޣ�����Ȩ��public������Ȩ��protected��˽��Ȩ��private
/*
* public����Ա���ڿ��Է��ʣ�����Ҳ���Է���
* protected����Ա���ڿ��Է��ʣ����ⲻ�ɷ��ʣ�������Է���
* private, ��Ա���ڿ��Է��ʣ����᲻���Է��ʣ����಻�ɷ���
* protected��private���������ڣ��̳е�ʱ��������Է��ʸ���ı���Ȩ�ޣ����ǲ����Է��ʸ����˽��Ȩ�ޡ�
* ��Ա���ó�˽����Ҫ������ô���
* 1.���Կ��ƶ�д��Ȩ�ޣ���Ϊ���ⲻ�ܷ��ʣ����ֻ������ĳ�Ա���������ʡ�
* 2.���ڡ�д�����������Լ�����ݵ���Ч�ԡ�
*/
class Person {//ʵ��3
	//����Ȩ��
public:
	string p_Name;
	//����Ȩ��
protected:
	string p_Car;
	//˽��Ȩ��
private:
	int p_Password;
	//��Ա��������Ϊ
public:
	void func() {
		p_Name = "����";
		p_Car = "������";
		p_Password = 45591901;
	}

	void printrInfo_p() {
		cout << "����: " << p_Name << " ��: " << p_Car<< " ����: " << p_Password << endl;
	}
};
/*
* ��c++��structĬ�ϵķ���Ȩ��Ϊpublic;
* ��class��Ĭ�Ϸ���Ȩ����private��
*/



/*����4
* ��ϰ��������һ���������࣬������������������
���ҷֱ�����ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
* ����Ȩ�ޣ�����Ȩ��������һЩ�ӿڣ��������úͻ�ȡ���������Ϣ����˽������������������������ԡ�
*/
class Cubic {
	//����Ȩ��
public:
	void setAttribute(double l, double w, double h) {//���������������
		if (l > 0 && w > 0 && h > 0) {
			length = l;
			weight = w;
			height = h;
		}
		else {
			cerr << "����ߵ����Բ����ϱ�׼�����������0�ĳ����" << endl;
		}
	}

	double getAttributeLWH(int a) {//��ȡ�����
		switch(a) {
		case 1:
			return length;
			break;
		case 2:
			return weight;
			break;
		case 3:
			return height;
			break;
		default:
			cout << "���� " << length << "�� " << weight << "�ߣ� " << height << endl;
			return 0;
			break;
		}
		cout << "���� " << length << "�� " << weight << "�ߣ� " << height << endl;
	}

	void getVolume() {//��ȡ���
		cout << "����� " << height*weight*length << endl;
	}

	void getSurfaceArea() {//��ȡ���
		cout << "����� " << 2* height * weight + 2 * length * weight + 2 * height *  length << endl;
	}

	void isCubicSame_classfunc(Cubic c) {
		if (c.getAttributeLWH(1) == length && c.getAttributeLWH(2) == weight && c.getAttributeLWH(3) == height) {
			cout << "��ͬ����Ա�����жϽ����" << endl;
		}
		else {
			cout << "��ͬ����Ա�����жϽ����" << endl;
		}
	}

private:
	double length;
	double weight;
	double height;

};

//����ȫ�ֺ����ж������������Ƿ����
bool isCubicSame(Cubic c1, Cubic c2) {
	if (c1.getAttributeLWH(1) == c2.getAttributeLWH(1) && c1.getAttributeLWH(2) == c2.getAttributeLWH(2) && c1.getAttributeLWH(3) == c2.getAttributeLWH(3)) {
		cout << "��ͬ��ȫ�ֺ����жϽ����" << endl;
		return true;
	}
	else {
		cout << "��ͬ��ȫ�ֺ����жϽ����" << endl;
		return false;
	}
}



int main() {
	//ͨ��Բ�ഴ������Ķ���һ��Բ��
	Circle circle1; //ͨ��һ���ഴ��һ������Ĺ��̣�����Ϊ��ʵ������
	circle1.r_c = 10.0;
	cout << "Բ�����circle1���ܳ�Ϊ�� " << circle1.calculatePerimeter() << endl;

	//ʵ����һ��ѧ����Ķ���
	Student stu1;
	long long id = 45591901;
	string name = { "������" };
	stu1.set_name_s(&name); //���ó�Ա����������Ա������ֵ
	stu1.set_id_s(&id);//���ó�Ա����������Ա������ֵ
	stu1.printrInfo_s();//���ó�Ա��������ӡ��Ա������
	
	//ʵ������Ȩ�����⣺
	//��ʵ����һ��������
	Person zhangsan;
	zhangsan.p_Name = "�����ı���";
	//ֻ����һ����Ա������������������ʡ�
	zhangsan.func();
	zhangsan.printrInfo_p();
	zhangsan.p_Name = "�����ı���";
	zhangsan.printrInfo_p();
	//���ǿ���ͨ���������ڵĳ�Ա����������ķ��ʣ���ӡ��

	//ʵ��4���������࣬��������������Զ�ȡ���ж����������Ƿ���ͬ��
	Cubic c_1, c_2, c_3;
	c_1.setAttribute(10.0, 10.0, 10.0);
	c_1.getAttributeLWH(4);
	c_1.getSurfaceArea();
	c_1.getVolume();
	//���ù���Ȩ���е�һϵ�нӿڣ���Ա��������ȡһϵ�е�c_1��˽�����ԡ�
	c_2.setAttribute(10.0, 10.0, 10.0);
	c_3.setAttribute(10.0, 10.0, 11.0);
	isCubicSame(c_1, c_2);
	isCubicSame(c_1, c_3);
	//����ȫ�ֺ����ж��������Ƿ���ͬ
	c_1.isCubicSame_classfunc(c_2);
	c_1.isCubicSame_classfunc(c_3);
	//�������еĳ�Ա�����ж��������Ƿ���ͬ


	//�����壬�жϵ��Բ�Ĺ�ϵ
	//������Ҫ��ʼ����������
	Point p_1,p_2,p_3,c_p;
	Circle circle2;
	int x1 = 0, y1 = 0;
	p_1.setPointCoordinate(0.0, 1.0);
	p_2.setPointCoordinate(0.5, 0.5);
	p_3.setPointCoordinate(0, 0);
	c_p.setPointCoordinate(1, 1);
	circle2.setPoint(c_p);
	circle2.r_c = 1;
	circle2.getPoint(&x1, &y1);
	p_1.relationship(x1,y1,circle2.r_c);
	p_2.relationship(x1, y1, circle2.r_c);
	p_3.relationship(x1, y1, circle2.r_c);


	/*����ĳ�ʼ��������*/
	//�������صĹ��캯��
	//���ŷ�
	Fruit apple;
	Fruit banana("yellow");
	Fruit banana1(banana);
	//ע���������Ĭ�Ϲ��캯����ʱ�򣬲�Ҫ��С���ţ�
	banana.getColor();
	banana1.getColor();
	//��ʾ��
	Fruit purple;
	Fruit watermelon = Fruit("green and black");
	//Fruit("green and black")���ֶ��󵥶��ó�������������
	//��ǰ�н�����ϵͳ�������Զ����������������
	//���Ⱥ���ֵ��watermelon����������������ֱ����ʾ��������
	Fruit("green and black");
	//���Է������Ͼͻ��Զ��������������������������������
	//ע������2�������ÿ������캯������ʼ����������
	//Fruit(watermelon);//�ᱨ���ض���
	Fruit watermelon1 = Fruit(watermelon);

	watermelon.getColor();
	watermelon1.getColor();
	//��ʽת����
	Fruit orange = watermelon;
	//���ӡ�������͹��캯���������Ϣ������д�˴�ӡ
	system("pause");
	return 0;
}