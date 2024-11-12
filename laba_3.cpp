//12 var
#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
using namespace std;

void swapy(double& a, double& b) {		//Функция, меняющая два числа местами
	double c = a;
	a = b;
	b = c;	
}
void swapy(long long& a, long long& b) {		//Перегрузка swap
	long long c = a;
	a = b;
	b = c;		
}
void shellsort(vector<double>& data) {		//Сортировка Шелла
	for (long long step = data.size() / 2; step >= 1; step /= 2) {		//Выбор шага
		for (long long right = step; right < data.size(); ++right) {	//Элемент, начиная с шага, а не с начала
			for (long long element = right - step; element >= 0 && data[element + step] < data[element]; element -= step) {		//Сравнение элементов на расстоянии шага, пока не встанет на своё место
				swapy(data[element + step], data[element]);		//Поменять два элемента местами, если большее слева
			}
		}
	}
}
void printres(vector<double> data) {
	cout << "[ ";
	int flag = 0;
	for (int i = 0; i < data.size(); ++i) {
		if (!(i > 20 && i < data.size() - 20)) {
			cout << data[i] << ' ';
			flag = 1;
		}
		else if (flag == 1) {
			cout << "... ";
			++flag;
		}
	}
	cout << "]\n";
}

int main()
{
	srand(time(0));
	
	long long size;

	char flag;
	do {
		cout << "Enter number of elements - ";
		cin >> size;		//Ввод количества случайных данных
		while (cin.fail()) {		//Проверка на ввод
			cin.clear();
			cin.ignore(1e+4, '\n');
			cout << "Enter valid data - ";
			cin >> size;
		}
		vector<double> data(size);		//Объявление
		for (int i = 0; i < size; i++) {	//Заполнение случайными данными
			data[i] = rand() % 100 + 1;
		}
		printres(data);
		shellsort(data);	//Сортировка данных
		printres(data);
		cout << '\n';
		cout << "Continue?(y/n) - ";
		cin >> flag;	//Хочет ли пользователь продолжить
		while (!(flag == 'y' || flag == 'Y' || flag == 'n' || flag == 'N')) {
			cout << "Enter y or n!" << '\n';
			cin >> flag;    //Проверка на неккоректный ввод
		}
	} while (flag == 'Y' || flag == 'y');	//Зацикливание программы
	
}
