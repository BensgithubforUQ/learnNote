#include "myHead.h"

void printArray(int* arr, int len) {
	cout << "���int���͵����飺";
	for (int i = 0; i < len;i++) {
		cout << *(arr + i) << " ";
	}
	cout << endl;
}