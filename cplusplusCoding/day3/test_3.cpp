#include<iostream>
#include<string>

using namespace std;

//int main() {
//	int typedef weight;
//	int size = 0;
//	cout << "please input pig amount" << endl;
//	cin >> size;
//	weight *pig = new int[size];
//	int i = 0,heaviestPig = 0;
//	cout << "please input pig weight(ctrl+z to pause in advance)" << endl;
//	while (cin >> pig[i] && i<size) {
//		if (i > 0) {
//			if (pig[i] > pig[heaviestPig]) {
//				heaviestPig = i;
//			}
//		}
//		i++;
//		if (i >= size) {
//			break;
//		}
//	}
//	cout << "the heaviest pig is the" << heaviestPig + 1<< endl;
//	return 0;
//}

//����Ŀ�������д��������,����������ص����ء�
//int main() {
//	int typedef weight;
//	int size = 0;
//	cout << "please input pig amount" << endl;
//	cin >> size;
//	weight* pig = new weight[size];
//	int i = 0, heaviestPig = i;
//	cout << "please input pigs' weight" << endl;
//	while (cin >> pig[i] && i < size) {
//		if (i > 0) {
//			heaviestPig = pig[i - 1] ? pig[i] : pig[i] > pig[i - 1];
//		}
//		i++;
//	}
//	cout << "the heaviest pig is " << heaviestPig<<"kg";
//	return 0;
//}

//switch �÷���switch���if���ṹ��������Ч�ʸ��ߣ�����ֻ���������ͻ����ַ��ͱ�����
//int main() {
//	int score = 0;
//	
//	cout << "please evaluate the film" << endl;
//	cin >> score;
//	switch (score)
//	{
//	case 10 :
//		cout << "it is a fantastic film" << endl;
//		break;
//	case 9:
//		cout << "it is a fantastic film" << endl;
//		break;
//	case 8:
//		cout << "it is a pretty good film" << endl;
//		break;
//	case 7:
//		cout << "it is a good film" << endl;
//		break;
//	case 6:
//		cout << "it is a normal film" << endl;
//		break;
//	case 5:
//		cout << "it is not a bad film" << endl;
//		break;
//	default:
//		cout << "this film is no good" << endl;
//		break;
//	}
//	return 0;
//}

//string�����ԣ��м䲻�ܴ��ո�
//int main() {
//	string str;
//	cin >> str;//�Ӽ��̶���str�������ո��ͣ�ˡ�
//	//fflush(stdin);
//	cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
//	//���д����������cin�������е����ݡ�
//	cout <<"str is "<< str << endl;
//	string str1 = "132456wbm 132";//������ʼ��
//	cout << "str1 is " << str1 << endl;
//
//	string str2;
//	cin >> str >> str2;
//	//fflush(stdin);
//	cout << "str2 is " << str << str2 << endl;
//	string str3("value");//ֱ�ӳ�ʼ��
//	string str4(10, 'c');//ֱ�ӳ�ʼ��
//	cout << "str3 is " << str3 << endl;
//	cout << "str4 is " << str4 << endl;
//	//�������string��ȡ�����ո��һ���У���getline()
//	string line,line1;
//	int i = 0;
//	while (getline(cin, line)) {
//		if (!line.empty() && line.size() > 5) { //line.size()>5����˼���������5����
//			cout << "line is " << line << endl;
//		}
//		if (i == 0) {
//			line1 = line;
//		}
//		else {
//			if (line > line1) {
//				line1 = line;
//				cout << "the bigger line is:" << line1 << endl;
//			}
//			else if (line == line1) {
//				cout << " the two line is same" << endl;
//			}
//			else {
//				cout << "the bigger line is:" << line1 << endl;
//			}
//		}
//		i++;
//	}
//	string finalStr = str + str1 + str2 + str3 + str4 + line + line1;
//	cout << "the final string is :" << finalStr << endl;
//	return 0;
//}

//��������Ϸ��while�����á�
//#include <ctime>
//int main() {
//	int number = 0,i = 5,target = 0;
//	
//	srand((unsigned int)time(NULL));
//	target = rand() % 100 + 1;
//	//�������������c++�������д��
//
//	cout << "�뿪ʼ�����֣�һ������λ���" << endl;
//	while (i && cin >> number) {
//		if (number > target) {
//			
//			i--;
//			cout << "�´���,����" <<i<<"�λ���" << endl;
//		}
//		else if (number < target) {
//			i--;
//			cout << "��С��,����" << i << "�λ���" << endl;
//		}
//		else {
//			cout << "�¶��ˣ�һ������" <<5-i+1<<"�λ���" << endl;
//		}
//		if (i == 0) {
//			cout << "���������ˣ�ʧ����,��ȷ����" <<target<< endl;
//		}
//
//	}
//	return 0;
//}

//int main() {
//	//���0 - 9 
//	//do while����������ִ��һ�Σ����ж���������while����������while�������Ⱦ��ж�һ��������
//	//����numֱ�ӵ���10��ʱ��Ҳ��ִ��һ�Σ���ӡ10��
//	int num = 10;
//	do {
//		cout << num++ << endl;
//	} while (num < 10);
//	system("pause");
//	return 0;
//}

//ˮ�ɻ���

//int main() {
//	int num = 100;
//	int b, t, h;
//	while (num < 1000) {
//		h = num / 100;
//		t = (num - h * 100) / 10;
//		b = num % 10;
//		if(b*b*b + t*t*t + h*h*h == num){
//			cout << num << " is a ˮ�ɻ� ��" << endl;
//		}
//		num++;
//	}
//}

//����ַ����еı�����
//int main() {
//	string s;
//	
//	cout << "please input string:" << endl;
//	
//	decltype(s.size()) cnt = 0;
//	while(getline(cin, s)){
//		for (auto c : s) {
//			if (ispunct(c)) {
//				cnt++;
//			}
//		}
//		cout << cnt << " punctuation characters in " << s << endl;
//	}
//	return 0;
//}


//���ַ��������е�Сд��ĸ��ɴ�д��ĸ
//int main() {
//	string s;
//	cout << "please input string:" << endl;
//	decltype(s.size()) cnt = 0;
//	while (getline(cin, s)) {
//		for (auto& c : s) {
//			if (isalpha(c)) {
//				c = toupper(c);
//			}
//		}
//		cout <<"the upper string is " << s << endl;
//	}
//	return 0;
//}



//��������Ϸ
//int main() {
//	for (int i = 0; i <= 100;i++) {
//		if (i == 7 || i % 10 == 7 || i / 10 == 7 || i%7 == 0) {
//			cout << i << " ������" << endl;
//		}
//		else cout << i << " ";
//	}
//	return 0;
//}

//int main() {
//	string s = "abcasdasdaw!!!!!";
//	cout << s << endl;
//	for (auto &c : s) {
//		c = 'x';
//	}
//	cout << s << endl;
//	const string s1 = "keep out!";
//	for (auto& c : s1) {
//
//	}
//	cout << s1 << endl;
//	string s2("something is strange");
//	if (!s2.empty()) {
//		s2[0] = toupper(s2[0]);
//	}
//	for (decltype(s2.size()) index = 0; index != s2.size() && !isspace(s2[index]); ++index) {
//		s2[index] = toupper(s2[index]);
//	}
//	cout << s2 << endl;
//	return 0;
//}