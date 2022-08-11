#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <mutex>
using namespace std;
//��ν������ָ�룬����һ����ģ�壬���Դ����������͵�ָ����󣬵�����ʹ����֮�󣬾͵�����������ȥ�ͷ��ڴ�
class test {
public:
	test() { cout << "���졤����" << endl; }
	~test() { cout << "����������" << endl; }

	int getDebug() { return this->debug; }
private:
	int debug = 20;

};
//�Զ���һ������ָ��
template <class T>
class smartptr {
private:
	T* ptr;//ָ�����
public:
	smartptr(T* _ptr): ptr(_ptr) { //�вι���
		cout << "smartptr�Ĺ���" << endl;
	}

	smartptr(smartptr& pre_p) :ptr(pre_p.ptr) { //auto_ptr���Ŀ�������
		pre_p.ptr = nullptr;
	}

	//unique_ptr���� ��������
	//smartptr(smartptr& pre_p) = delete;

	~smartptr() {
		if (ptr != nullptr) {
			cout << "smartptr������" << endl;
			delete ptr;
			ptr = nullptr;
		}
	}

	T& operator*() {
		return *ptr;//����*�����
	}
	T& operator->() {
		return ptr;//����->�����
	}

	T& operator=(smartptr<T>& pre_p) { //auto_ptr���ĸ�ֵ���غ���
		if (ptr != pre_p.ptr) {
			ptr = pre_p.ptr;
			pre_p.ptr = nullptr;
		}
		return ptr;
	}

	//unique_ptr���ĸ�ֵ���غ���
	//T& operator=(smartptr<T>& pre_p) = delete;

	bool operator==(T* p) { //����һ��auto_ptr��������ָ�����Դ����Ȩת�ơ�
		if (ptr == p) return true;
		else return false;
	}
};

//auto_ptr��Ϊ��ʧȥ����Դ�Ĺ���Ȩ�ᵼ�³�������������Ѿ������ã���unique_ptr��ֱ�Ӳ��ܿ������߸�ֵ���졣

//share_ptr

//�����������ʵ��ָ�빲����Դ��

template<class T>
class sh_p {
private:
	T* ptr; //ָ�����
	int* count;//����
	mutex* mt;
public:
	sh_p(T* _ptr):ptr(_ptr) { //Ĭ�Ϲ���
		count = new int(1);
		mt = new mutex;
		cout << "share_ptr��Ĭ�Ϲ���" << endl;
	}
	
	void addCount() {
		mt->lock();
		(*count)++;
		mt->unlock();
	}

	sh_p(sh_p<T>& sh) :ptr(sh.ptr), count(sh.count), mt(sh.mt) { //��������
		cout << "share_ptr�Ŀ�������" << endl;
		addCount();
	}

	void release() { //�ͷŵ�������������Ϊ�գ����ͷ���Դ����������Ӹò�����
		bool flag = false;
		mt->lock();
		cout << "count--������Ϊ" << *count << endl;
		if (--(*count) == 0) { //ע��ÿ��release��--��count;
			delete count;
			delete ptr;
			count = nullptr;
			ptr = nullptr;
			cout << "share_ptr������" << endl;
			flag = true;
		}
		mt->unlock();
		if (flag) {
			delete mt;
			mt = nullptr;
		}
	}

	sh_p<T>& operator=(const sh_p<T>& sh) {
		if (sh.ptr != ptr) {
			release(); //�ͷž���Դ����Ȼ��һ���ͷŵ��ˣ���Ϊ����Դ���ܲ�ֹһ��ָ�������á�
			ptr = sh.ptr;
			count = sh.count;
			mt = sh.mt;
			addCount();
			cout << "share_ptr�ĸ�ֵ����" << endl;
		}
		return *this;
	}

	~sh_p() {
		release();
	}

	int& use_count() {
		return *count;
	}

	T& operator*() {
		return *ptr;//����*�����
	}
	T& operator->() {
		return ptr;//����->�����
	}

};



//int main() {
//	smartptr<int> ptr1(new int(114514));
//	cout << *ptr1 << endl;
//	smartptr<int> ptr2(ptr1);
//	if (ptr1 == nullptr) cout << "ptr1�Ѿ�ʧȥ����Դ�Ĺ���Ȩ" << endl;
//
//	sh_p<int> ptr3(new int(110));
//	cout << *ptr3 << endl;
//	sh_p<int> ptr4(ptr3);
//	cout << ptr3.use_count() << endl;
//
//	//share_ptr���ã�������ȱ�ݣ�������˫�������У����pre��next�ǻ������ã��Ǿͻ����2��ʹ����֮��������Ҳֻ�ܰѼ���-1
//	//���������ڴ�й©�������Ϊѭ�����á���
//	//�����Ҫweak_ptr; weakָ���Ƕ����ڽṹ������ģ�����ָ��share_ptr,���ǲ�����addcount���ͽ������ѭ�����õ����⡣
//	return 0;
//}

//struct node { //ѭ�����÷��� - ��weak���
//	shared_ptr<node> pre; //weak_ptr<node> pre;
//	shared_ptr<node> nex; //weak_ptr<node> nex;
//};
//
//int main() {
//	shared_ptr<node> n1;
//	shared_ptr<node> n2;
//	n1->nex = n2;
//	n2->pre = n1;
//
//	shared_ptr<int> num1(new int(0));
//	return 0;
//}