#include <iostream>
using namespace std;

class father { //����
public:
	father() {}
	virtual void print() = 0;
	virtual ~father() {}
};
//�̳�һ��
class son : public father { //����
public:
	son() {}; //�޲ι��� 
	son(int _a, char _b, char *_str) :a(_a), b(_b) { 
		str = new char(*_str); //���
	} //�вι��캯��
	son(const son& s) { //���صĿ�������
		this->a = s.a;
		this->b = s.b;
		this->str = new char(*s.str); //���
	}

	son& operator=(son& s) { //���صĸ�ֵ����
		if (str != NULL) {
			delete str;
			str = NULL;
		}
		str = new char(*s.str); //���
		this->a = s.a;
		this->b = s.b;
		return *this;
	}

	~son(){
		delete str;
		str = NULL;
		cout << "�ͷ���strָ��ά���Ķ�������" << endl;
	}

	void print() { //��дfather���е�print����
		cout << a << " " << b << " " << *str << endl;
	}

	void print(int x) { //����father���е�print������ͬʱ�Ǳ�����print������
		cout << a << " " << b << " " << str << " ���� " << endl;
	}
private:
	int  a;
	char b;
	char* str;
};

//int main() {
//	char str[] = "abcdedf";
//	int a = 1;
//	son s(a, 'b', str);
//	cout << sizeof(s) << endl;
//	son s1 = s;
//	s1.print(1);
//	return 0;
//}