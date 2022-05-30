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
			cout << "Введите число: ";
			getline(cin, numStr);
			res = stoi(numStr);
			return res;
		}
		catch (const exception& ex)
		{
			cout << "Ошибка: " << ex.what() << ".\n";
		}
	} while (true);
}

double division(double a, double b) {
	if (b == 0)
		throw logic_error("division by zero");
	return a / b;
}

// Вывод массива
template <typename T>void showArr(T arr[], int size){
	if (size <= 0)
		throw underflow_error("Длина макссива должна быть положительной");
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// Заполнение массива
template <typename T>void fillArr(T arr[], int size, int min, int max){
	if (size <= 0)
		throw underflow_error("Длина макссива должна быть положительной");
	if (max <= min)
		throw invalid_argument("конец диапазона  должен быть больше, чеь начало");
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Выход за числовой диапазон
	/*
	try
	{
		cout << "вВЕДИТЕ ЧИСЛО ОТ 1 ДО 10: ";
		cin >> n;
		if (n < 1)
			throw 0;
		if (n > 10)
			throw "Введеное число больше указанного диапазона.";
		cout << "Число введено корректно\n";
	}
	catch (const int ex) {
		if (ex == 0)
			cout << "Oшибка! Введеное число меньше указанного диапазона\n";
	}
	catch (const char ex[]) {
		cout << "Oшибка! " << ex << endl;
	}*/
	// защита от нуба
	/*
	n = ptint_int();
	cout << "Введено " << n << endl;*/

	// Деление
	/*
	try
	{
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const logic_error& ex)
	{
		cout << "Ошибка: " << ex.what() << endl;
	}*/

	string path = "file.txt";

	// Проверка откритя файла
	/*
	ofstream out;
	out.exceptions(ios::badbit | ios::failbit | ios::eofbit); // Разрешаем объекту класса бросать исключения

	try {
		out.open(path);

		string str;
		cout << "Введите строку:\n";
		getline(cin, str);
		out << str + "\n";
		cout << "Запись помещена в файл:\n";

		out.close();
	}
	catch (const ios::failure& ex) {
		cout << "Ошибка: " << ex.what() << endl;
		cout << "Код шибки: " << ex.code() << endl;
	}*/

	cout << "Введите длину массива: ";
	cin >> n;
	try{
		cout << "Изначальный массив: ";
		int* arr = new int[n] {};
		showArr(arr, n);
		fillArr(arr, n, 10, 31);
		cout << "Итоговый массив: ";
		showArr(arr, n);
	}
	catch(const underflow_error& ex){
		cout << "Ошибка: " << ex.what() << endl;
	}
	catch (const bad_array_new_length& ex) {
		cout << "Ошибка создания массива: " << ex.what() << endl;
	}
	catch (const invalid_argument& ex){
		cout << "Ошибка диапазона: " << ex.what() << endl;
	}

	return 0;
}