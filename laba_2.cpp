#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

void printres(double n, double a, double s, double an) {                //Функция вывода промежуточного результата
    cout << "n = " << n << " ";
    cout << "a" << n << " = " << a << " ";
    cout << "S" << n << " = " << s << " ";
    cout << "ac = " << abs(an/(2*s)) << "\n";
}

int main()
{
    char flag;  //Флаг для зацикливания программы

    do {
        double a;
        double x;
        cout << "Enter x number from -1 inclusive to 1 not inclusive - "; cin >> x;     //Ввод х
        while (!(x >= -1 && x < 1) || cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter x number from -1 inclusive to 1 not inclusive - "; cin >> x;		//Проверка на букву
        }
        cin.clear();
        cin.ignore(1e+4, '\n');
        cout << "Enter number a - ";
        cin >> a;       //Ввод альфа
        while (cin.fail()) {		                //Проверка на букву
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "a must be a number - "; cin >> a;
        }
        long double summForanPlusOne;   //Вспомогательный подсчёт для альфа от n+1
        long double anPlusOne;       //а от n+1
        double Sn = 0;      //Сумма элементов последовательности от n
        double an = 1;      //а от n

        if (round(a) == a) {    //Если а целое число
            for (int n = 1; n <= a; n++) {              //Вычисление суммы до а элемента
                long float first_el = 0;
                for (float t = 1; t <= n; t++) {          //Суммирование дробей от 1/1 до 1/n
                    first_el += 1.0 / t;
                }
                an = first_el * (pow(x, (n + 1)) / (n + 1));    //Вычисление элемента последовательности
                Sn += an;
                summForanPlusOne = first_el + 1.0 / (n + 1);    //Суммирование дробей для а от n+1
                anPlusOne = summForanPlusOne * (pow(x, n + 2)) / (n + 2);     //Вычисление элемента последовательности а от n+1
                printres(n, an, Sn, anPlusOne);
            }
        }
        else {          //Если а дробное число
            while (!(a > 0 && a <= 1) || cin.fail()) {                                   //Ещё одна проверка на букву
                cout << "If the number is a float, then the value must be from zero to one";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> a;
            }
            float n = 0;
            while (n == 0 || abs(anPlusOne) >= a * 2 * abs(Sn)) {    //Вычисление суммы с погрешностью a
                n++;
                double first_el = 0;
                for (float t = 1; t <= n; t++) {      //Суммирование дробей от 1/1 до 1/n
                    first_el += 1.0 / t;
                }
                an = first_el * (pow(x, n + 1) / (n + 1));      //Вычисление элемента последовательности
                Sn += an;
                summForanPlusOne = first_el + 1.0 / (n + 1);    //Суммирование дробей для а от n+1
                anPlusOne = summForanPlusOne * ((pow(x, n + 2)) / (n + 2));   //Вычисление элемента последовательности а от n+1
                printres(n, an, Sn, anPlusOne);
            }
        }
        cout << "Do you want to continue?\n" << "y)Continue\n" << "Anything symbol)End\n";
        cin >> flag;

    } while (flag == 'y' || flag == 'Y');
}