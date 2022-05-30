#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int ptint_int(){
	int res;
	do
	{
		try
		{
			string numStr;
			cout << "������� �����: ";
			getline(cin, numStr);
			res = stoi(numStr);
			return res;
		}
		catch (const exception& ex)
		{
			cout << "������: " << ex.what() << ".\n";
		}
	} while (true);
}

double division(double a, double b) {
	if (b == 0)
		throw logic_error("division by zero");
	return a / b;
}

// ����� �������
template <typename T>void showArr(T arr[], int size){
	if (size <= 0)
		throw underflow_error("����� �������� ������ ���� �������������");
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// ���������� �������
template <typename T>void fillArr(T arr[], int size, int min, int max){
	if (size <= 0)
		throw underflow_error("����� �������� ������ ���� �������������");
	if (max <= min)
		throw invalid_argument("����� ���������  ������ ���� ������, ��� ������");
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ����� �� �������� ��������
	/*
	try
	{
		cout << "������� ����� �� 1 �� 10: ";
		cin >> n;
		if (n < 1)
			throw 0;
		if (n > 10)
			throw "�������� ����� ������ ���������� ���������.";
		cout << "����� ������� ���������\n";
	}
	catch (const int ex) {
		if (ex == 0)
			cout << "O�����! �������� ����� ������ ���������� ���������\n";
	}
	catch (const char ex[]) {
		cout << "O�����! " << ex << endl;
	}*/
	// ������ �� ����
	/*
	n = ptint_int();
	cout << "������� " << n << endl;*/

	// �������
	/*
	try
	{
		cout << "������� ��� �����: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const logic_error& ex)
	{
		cout << "������: " << ex.what() << endl;
	}*/

	string path = "file.txt";

	// �������� ������� �����
	/*
	ofstream out;
	out.exceptions(ios::badbit | ios::failbit | ios::eofbit); // ��������� ������� ������ ������� ����������

	try {
		out.open(path);

		string str;
		cout << "������� ������:\n";
		getline(cin, str);
		out << str + "\n";
		cout << "������ �������� � ����:\n";

		out.close();
	}
	catch (const ios::failure& ex) {
		cout << "������: " << ex.what() << endl;
		cout << "��� �����: " << ex.code() << endl;
	}*/

	cout << "������� ����� �������: ";
	cin >> n;
	try{
		cout << "����������� ������: ";
		int* arr = new int[n] {};
		showArr(arr, n);
		fillArr(arr, n, 10, 31);
		cout << "�������� ������: ";
		showArr(arr, n);
	}
	catch(const underflow_error& ex){
		cout << "������: " << ex.what() << endl;
	}
	catch (const bad_array_new_length& ex) {
		cout << "������ �������� �������: " << ex.what() << endl;
	}
	catch (const invalid_argument& ex){
		cout << "������ ���������: " << ex.what() << endl;
	}

	return 0;
}