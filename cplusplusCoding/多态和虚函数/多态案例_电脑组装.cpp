#include <iostream>
#include <string>
using namespace std;

//����������������ɲ���Ϊ cpu�����ܼ��㣩���Կ���������ʾ�����ڴ��������ܴ��棩
//��ÿ�������װ�ɳ�����࣬�����ṩ��ͬ�ĳ���������ͬ�����������intel��Lenovo
//���������࣬�ṩ�õ����๤���ĺ��������ҵ�����������Ľӿ�
//������װ��̨��ͬ�ĵ�����������
class Cpu {//intel ,AMD
public:
	//����
	virtual void calculate_cpu() = 0;
};

class GraphicsCard {//NVIDIA,AMD
public:
	//��ʾ
	virtual void send_graphic_info() = 0;
};

class RAM {//kingston ,samsung
public:
	//����
	virtual void memory() = 0;
};

class intelCpu : public Cpu {
public:
	void calculate_cpu() {
		cout << "intel cpu begins to calculate" << endl;
	}
};

class AMDCpu : public Cpu {
public:
	void calculate_cpu() {
		cout << "AMD cpu begins to calculate" << endl;
	}
};

class NVIDIAVideoCard : public GraphicsCard {
public:
	void send_graphic_info() {
		cout << "NVIDIA video card begins to work" << endl;
	}
};	

class AMDVideoCard : public GraphicsCard {
public:
	void send_graphic_info() {
		cout << "AMD video card begins to work" << endl;
	}
};

class KingstonRAM : public RAM {
public:
	void memory() {
		cout << "Kingston RAM Stores info" << endl;
	}
};

class SamsungRAM : public RAM {
public:
	void memory() {
		cout << "Samsung RAM Stores info" << endl;
	}
};

class Computer {
public:
	Computer(Cpu* c, GraphicsCard* g, RAM* m) {//�ô���Ķ���ָ�������������
		cpu = c;
		GC = g;
		mem = m;
	}
	void work() {//���ýӿڣ��������������
		cpu->calculate_cpu();
		GC->send_graphic_info();
		mem->memory();
	}

	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (GC != NULL) {
			delete cpu;
			GC = NULL;
		}
		if (mem != NULL) {
			delete cpu;
			mem = NULL;
		}
		cout << "����computer��" << endl;
	}
private:
	Cpu* cpu;//������ĳ�Ա������һЩ�������ָ��
	GraphicsCard* GC;
	RAM* mem;
};

void test_assemble_a_computer() {
	Computer *c1 = new Computer(new intelCpu,new NVIDIAVideoCard,new KingstonRAM);
	Computer *c2 = new Computer(new AMDCpu, new AMDVideoCard, new KingstonRAM);
	Computer *c3 = new Computer(new intelCpu, new AMDVideoCard, new SamsungRAM);
	cout << "the first computer works" << endl;
	c1->work();
	delete c1;
	cout << endl;
	cout << "the second computer works" << endl;
	c2->work();
	delete c2;
	cout << endl;
	cout << "the third computer works" << endl;
	c3->work();
	cout << endl;
	delete c3;
}

int main() {
	test_assemble_a_computer();
	return 0;
}