#include <iostream>
#include <vector>
#include <string>
#include <ostream>


template<class keyType, class valueType >
class myOwnPair {
public:
	static int statPairCount;
	friend std::ostream& operator << (std::ostream& output, myOwnPair<keyType, valueType>& _targetPair)
	{
		return output << "(" << _targetPair._key << "��" << _targetPair._value << ")";
	}

public:
	myOwnPair() // Ĭ�Ϲ���
	{
		std::cout << "add a own type pair object(no value)." << std::endl;
		++statPairCount;
	}

	myOwnPair(keyType key, valueType value) : _key(key), _value(value) // ��ʼ���б�
	{
		std::cout << "add a own type pair object(initialized list)." << std::endl;
		++statPairCount;
	}

	myOwnPair(const myOwnPair<keyType, valueType>& inputPair) //����
	{
		this->_key = inputPair._key;
		this->_value = inputPair._value;
		std::cout << "add a own type pair object(with copy)." << std::endl;
		++statPairCount;
	}


	bool operator = (const myOwnPair<keyType, valueType>& inputPair);
	bool operator < (const myOwnPair<keyType, valueType>& inputPair) const;

	
	~myOwnPair()
	{
		std::cout << "dalete a own type pair object" << std::endl;
		--statPairCount;
	}

	static int getOwnPairAmount()
	{
		return statPairCount;
	}
protected:

private:
	keyType _key; // ģ��pair�����key ֵ
	valueType _value; // ģ��pair�����value ֵ
};

//��̬��Ա��������¼myOwnPair�������
template<class keyType, class valueType >
int myOwnPair<keyType, valueType>::statPairCount = 0;

//"<"�ȽϷ� 
template<class keyType, class valueType >
bool myOwnPair<keyType, valueType>::operator < (const myOwnPair<keyType, valueType>& _inputPair) const
{
	if (this->_key == _inputPair._key)
	{
		return this->_value < _inputPair._value;
	}

	return this->_key < _inputPair._key;
}

//"=" 
template<class keyType, class valueType >
bool myOwnPair<keyType, valueType>::operator = (const myOwnPair<keyType, valueType>& _inputPair)
{
	this->_key = _inputPair._key;
	this->_value = _inputPair._value;
	return this->_key == _inputPair._key && this->_value == _inputPair._value;
}

