#include <iostream>
#include <math.h>
#include <vector>


using namespace std;
const int ROWS = 5, COLUMNS = 5;//Константи для матриці

/**
 * Реалізація функції f(x) згідно з завдання:
 *  середнє геометричне значення елементів у кожному рядку матриці;
 *
 * @param mass
 * @return результат роботи функціїї f(x)
 */
double f(int* mass) {
	int multiply = 1;
	for (int i = 0; i < COLUMNS; i++)
	{
		multiply *= mass[i];
	}

	if(multiply<0) return -1 * pow(abs(multiply), 1.0 / COLUMNS);
	else return pow(abs(multiply), 1.0 / COLUMNS);
}

/**
 * Функція міняє місцями "a" та "b" за допомогою вказівників
 * @param a
 * @param b
 */
void swap(int* a, int* b) {
	int buff = *a;
	*a = *b;
	*b = buff;
}

/**
 * Реалізація функції F(x) згідно з завдання:
 *  середнє арифметичне значення f(х) і-того рядка
 * @param mass
 * @return
 */
double F(int** mass) {
	double sumOf_f = 0;

	for (int i = 0; i < ROWS; i++)
	{
		sumOf_f += f(mass[i]);
		cout << "f[" << i << "] = " << f(mass[i]) << endl;
	}

	return sumOf_f / ROWS;
}

/**
 * Реалізація бульбашкового сортування (метод обміну)
 * @param mass - двовимірний масив матриці 5 на 5
 */
void bubbleSort(int** mass) {
	for (int countOfRows = 0; countOfRows < ROWS; countOfRows++) {

		for (int i = 0; i < COLUMNS - 1; i++)
		{
			for (int j = i + 1; j < COLUMNS; j++)
			{
				if (mass[i][countOfRows] > mass[j][countOfRows]) {
					swap(&mass[i][countOfRows], &mass[j][countOfRows]);
				}

			}
		}
	}

}



int main() {

	int** matrix = new int*[ROWS];//Створюємо масив вказівників на вказівники для передачі матриці сторонній функції

	//Ініціалізація масиву "matrix" для матриці
	for (int i = 0; i < ROWS; i++)
	{
		matrix[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
		{
			cin>>matrix[i][j]; //зчитуємо данній для ячейки з консолі
		}
	}


	bubbleSort(matrix);


	cout << endl;//Виводиму пусту строку в консоль для читаємості

	for (int i = 0; i < ROWS; i++)
	{

		for (int j = 0; j < COLUMNS; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;//Виводиму пусту строку в консоль для читаємості

	cout << "F(matrix): " << F(matrix);//Виводить в консоль результат роботи головної функції - F(x)

	return 0;
}




