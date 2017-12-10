#include <iostream>
#include <math.h>
#include <vector>


using namespace std;
const int ROWS = 5, COLUMNS = 5;//Константи для матриці

class Matrix {
private:
    double matrix[ROWS][COLUMNS];
public:
    //constructor that initialize matrix with nulls
    Matrix(void) {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void inputMatrix();
    void outputMatrix();
    void sort();
    void swap(int i, int j, int row);
    double f(int row);
    double F();
};

void Matrix::inputMatrix()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void Matrix::outputMatrix()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}
void Matrix::sort() //insertSort
{
    for (int countOfRows = 0; countOfRows < ROWS; countOfRows++) {


        for (int counter = 1; counter < COLUMNS; counter++)
        {
            int numberOfItem;//номер вибраного елемента з яким ми порівнюємо

            double itemThatSelected = matrix[countOfRows][counter];//елемент який ми порівнюємо
            numberOfItem = counter - 1;

            while (numberOfItem >= 0 && matrix[countOfRows][numberOfItem] > itemThatSelected) {
                swap(numberOfItem, numberOfItem + 1, countOfRows);//викликаємо метод вставки(обміну)
                numberOfItem--;
            }
        }
    }

}
void Matrix::swap(int i, int j, int row)
{
    double buff = matrix[row][i];
    matrix[row][i] = matrix[row][j];
    matrix[row][j] = buff;
}
double Matrix::f(int column)
{
    int row = 0;
    double result = 0;
    while (row <= column) {
        result += matrix[row][column];
        row++;
    }
    return result;
}
double Matrix::F()
{
    double result = 1;
    for (int j = 0; j < ROWS; j++)
    {
        result *= f(j);
    }

    return pow(abs(result), 1.0 / ROWS);
};


int main() {

    Matrix matrix;
    matrix.inputMatrix();
    matrix.sort();

    cout << endl << "-----------------------------------------------------------------" << endl;

    matrix.outputMatrix();

    cout << endl << "-----------------------------------------------------------------" << endl;

    cout <<"F(matrix): " << matrix.F();

    return 0;


}


