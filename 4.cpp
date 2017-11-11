#include <iostream>
#include <math.h>


using namespace std;
const int ROWS = 5, COLUMNS = 5;//Константи для матриці

class Matrix {
private:
    double matrix[ROWS][COLUMNS];
public:
    //конструктор який ініціалізує матрицю нулями
    Matrix(void) {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void ReadMatrixFromConsole();
    void PrintMatrixToConsole();
    void InsertionSort();
    void Swap(int fromPosition, int toPosition, int rowWhereToSwap);
    double SumElementsUnderDiagonal(int row);
    double CalculateGeometricMean();
};

void Matrix::ReadMatrixFromConsole()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
void Matrix::PrintMatrixToConsole()
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
void Matrix::InsertionSort() //сортування методом вставки
{
    for (int counterOfRows = 0; counterOfRows < ROWS; counterOfRows++) {
        for (int counterOfColumns = 1; counterOfColumns < COLUMNS; counterOfColumns++)
        {
            int columnNumberOfSelectedItem;//номер колонки вибраного елемента з яким ми порівнюємо

            double itemThatSelected = matrix[counterOfRows][counterOfColumns];//елемент який ми порівнюємо
            columnNumberOfSelectedItem = counterOfColumns - 1;

            while (columnNumberOfSelectedItem >= 0 && matrix[counterOfRows][columnNumberOfSelectedItem] > itemThatSelected) {
                //викликаємо метод обміну поки наш елемент не вставитья на своє місце
                Swap(columnNumberOfSelectedItem, columnNumberOfSelectedItem + 1, counterOfRows);
                columnNumberOfSelectedItem--;
            }
        }
    }

}
void Matrix::Swap(int fromPosition, int toPosition, int rowWhereToSwap)
{
    double buffer = matrix[rowWhereToSwap][fromPosition];
    matrix[rowWhereToSwap][fromPosition] = matrix[rowWhereToSwap][toPosition];
    matrix[rowWhereToSwap][toPosition] = buffer;
}
double Matrix::SumElementsUnderDiagonal(int row)
{
    int column = 0;
    double result = 0;

    //сумуємо всі числа над головною діагоналлю (включно з самою діагоналлю)
    while (column  < (ROWS - row)) {
        result += matrix[row][column];
        column++;
    }

    return result;
}
double Matrix::CalculateGeometricMean()
{
    double result = 1;
    for (int j = 0; j < ROWS; j++)
    {
        result *= SumElementsUnderDiagonal(j);
    }

    // так як в задачі не сказано про від'ємні значення,
    // рахуємо все по модулю

    return pow(abs(result), 1.0 / ROWS);

};


int main() {

    Matrix matrix;
    matrix.ReadMatrixFromConsole();
    matrix.InsertionSort();

    //вивід символів для читаємості
    cout << endl << "-----------------------------------------------------------------" << endl;

    matrix.PrintMatrixToConsole();

    //вивід символів для читаємості
    cout << endl << "-----------------------------------------------------------------" << endl;

    cout <<"Geometric Mean of rows in matrix: " << matrix.CalculateGeometricMean();

    return 0;


}
