#ifndef SINGLETON_HPP
#define SINGLETON_HPP
#include<iostream>
#include<mutex>
using namespace std;
mutex my_mutex;
//�̲߳���ȫ��-����ģʽ-��-�̰߳�ȫ��
class SingletonLazy {
public:
	static SingletonLazy* getInstance() {
		if (pSingleton == nullptr) { //˫�У���ֹ���̲߳���ȫ
			mutex_t.lock(); 
			if (pSingleton == nullptr) { //˫�У���ֹ���̲߳���ȫ
				pSingleton = new SingletonLazy();
				count++;
				cout << "����ģʽ��new��һ������..." << endl;
			}
			else {
				cout << "˫�еڶ��� false " << endl;
			}
			mutex_t.unlock();
		}
		else {
			cout << "˫�е�һ�� false " << endl;
		}
		return pSingleton;
	}
	static bool getCount() {
		if (count == 1) return true;
		return false;
	}

	class innerCG {
	public:
		~innerCG(){
			delete SingletonLazy::pSingleton;
			pSingleton = nullptr;
			cout << "�ڲ����Զ��ͷ�,�� "<<SingletonLazy::count<<"��ʵ����ͬʱdelete pSingleton" << endl;
			count--;
		}
	};
	/*����C++ջ���������ǻ��Զ����յ��ص㣬���Զ����շ����ڶ��ϵĵ�������
		����ͨ�����ַ�������Ԫ�ࡢ�ڲ��� + ��̬���ݳ�Ա��atexit()������pthread_once() + atexit()��ʵ��*/

private:
	static SingletonLazy* pSingleton;
	static mutex mutex_t;
	static innerCG gc;
	static int count;
	//�����췽��ȫ��˽�л�
	SingletonLazy() {}; //˽�л����캯��
	SingletonLazy(const SingletonLazy&) = delete;
	SingletonLazy& operator=(SingletonLazy&) = delete;
};
SingletonLazy* SingletonLazy::pSingleton = nullptr; //��̬��Ա���������ڶ��壬�����ʼ����
mutex SingletonLazy::mutex_t;
SingletonLazy::innerCG SingletonLazy::gc;
int SingletonLazy::count = 0;


//�̰߳�ȫ��-����ģʽ
class SingletonHungry {
public:
	static SingletonHungry* getinstance() {
		if (pSingleton != nullptr) cout << "use getinstance..." << endl;
		else cout << "seems the object had been deleted..." << endl;
		return pSingleton;
	}

	static void freeSpace() {
		if (pSingleton != nullptr) {
			delete pSingleton; 
			pSingleton = nullptr;
			cout << "freeSpace..." << endl;
		}
		else {
			cout << "nothing to delete..." << endl;
		}
	}
private:
	static SingletonHungry* pSingleton;
	SingletonHungry() {}
};
SingletonHungry* SingletonHungry::pSingleton = new SingletonHungry; //�Ƕ����ܷ��ʣ��������಻�ܷ���
#endif // !SINGLETON_HPP
