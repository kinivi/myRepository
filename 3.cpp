#include <iostream>
#include <math.h>
#include <vector>


using namespace std;
const int ROWS = 5, COLUMNS = 5;//Константи для матриці

double f(int* mass) {
	int sum = 1;//rename to multiply
	for (int i = 0; i < COLUMNS; i++)
	{
		sum *= mass[i];
	}

	if(sum<0) return -1 * pow(abs(sum), 1.0 / COLUMNS);
	else return pow(abs(sum), 1.0 / COLUMNS);
}
void swap(int* a, int* b) {
	int buff = *a;
	*a = *b;
	*b = buff;
}
double F(int** mass) {
	double sumOf_f = 0;

	for (int i = 0; i < ROWS; i++)
	{
		sumOf_f += f(mass[i]);
		cout << "f[" << i << "] = " << f(mass[i]) << endl;
	}

	return sumOf_f / ROWS;
}
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

	int** matrix = new int*[ROWS];//Створюємо масив вказівників на вказівники

	for (int i = 0; i < ROWS; i++)
	{
		matrix[i] = new int[COLUMNS];

		for (int j = 0; j < COLUMNS; j++)
		{
			cin>>matrix[i][j];
		}
	}
	

	bubbleSort(matrix);
	 
	
	cout << endl;

	for (int i = 0; i < ROWS; i++)
	{

		for (int j = 0; j < COLUMNS; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "F(matrix): " << F(matrix);

	return 0;
}




