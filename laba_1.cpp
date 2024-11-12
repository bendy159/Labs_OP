#include <iostream>
using namespace std;														//Облегчение ввода

int main()
{	
	int flag = 1;
	while (flag == 1) {
		cout << "Enter the sequence elements one at a time by pressing 'Enter' after each individual sequence element" << "\n";
		float entering_number = 1;											//Вводимое число
		float strongiest = 10e-9;										//Наибольшее число
		long long weakiest = 9 * (10e+9);									//Наименьшее число
		int count = 0;														//Количество чисел
		float sum = 0;														//Сумма чисел
		while (entering_number != 0) {										//работает, пока не 0
			cin >> entering_number;
			while (cin.fail()) {											//Проверка на букву
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid data, please enter number" << "\n";
				cin >> entering_number;
			}
			count++;														// Количество + 1
			sum = sum + entering_number;									//сумма + вводимое число
			if (strongiest < entering_number) {								//если больше максимального, то максимальное - вводимое
				strongiest = entering_number;
			}
			if (entering_number <= weakiest and entering_number != 0) {		//если меньше минимального, то минимальное - вводимое
				weakiest = entering_number;
			}
		}
		cout << "Max number - " << strongiest << "\nMin number - " << weakiest << "\nCount of numbers - " << count - 1 << "\nMiddle number -   " << sum / (count - 1) << "\n";
		cout << "Do you want to continue?" << "\n" << "1)Yes" << "\n" << "2)No" << "\n";
		cin >> flag;														//флаг для зацикливания программы
	}
}