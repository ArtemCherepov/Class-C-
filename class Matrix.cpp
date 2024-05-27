#include <iostream>

using namespace std;

class Matrix {
public:
    int count_row, count_column;
    int** matrix;


    //Конструктор. Создание матрицы
    Matrix(int row = 0, int column = 0) {
        count_row = row;
        count_column = column;
        matrix = new int* [count_row];
        for (int i = 0; i < count_row; i++) {
            matrix[i] = new int[count_column];
        }
    }


    //Пользователь заполняет матрицу своими значениями
    void SetMatrixValue() {
        for (int i = 0; i < count_row; i++) {
            for (int j = 0; j < count_column; j++) {
                cout << "Введите элемент матрицы в строке " << i + 1 << " столбце " << j + 1 << "\t";
                cin >> matrix[i][j];
            }
        }
    }


    //Заполняет матрицу рандомными значениями
    void SetMatrixRandomValue() {
        for (int i = 0; i < count_row; i++) {
            for (int j = 0; j < count_column; j++) {
                matrix[i][j] = rand();
            }
        }
    }


    //Создание Разреженной матрицы диагонального формата (Diagonal Sparse Matrix Format)
    void SetDSMRandomValue() {
        for (int i = 0; i < count_row; i++) {
            for (int j = 0; j < count_column; j++) {
                if (i == j)
                    matrix[i][j] = rand();
                else
                    matrix[i][j] = 0;
            }
        }
    }


    //Копия значений матрицы 1 в матрицу 2
    void Copy_Matrix(Matrix& ob) {
        ob.count_row = this->count_row;
        ob.count_column = this->count_column;
        ob.matrix = new int* [ob.count_row];
        for (int i = 0; i < ob.count_row; i++) {
            ob.matrix[i] = new int[ob.count_column];
        }
        for (int i = 0; i < this->count_row; i++) {
            for (int j = 0; j < this->count_column; j++)
                ob.matrix[i][j] = this->matrix[i][j];
        }
    }


    //Перемножение матриц
    void operator*(Matrix& second) {
        if (this->count_row != second.count_column) {
            cout << "Матрицы не могут быть перемножены. Количество строк первой матрицы должно быть равно количеству столбцов второй матрицы" << endl;
            return;
        }
        Matrix result_matrix(second.count_column, this->count_row);
        for (int i = 0; i < this->count_row; i++) {
            for (int j = 0; j < second.count_column; j++) {
                int result_number = 0;
                for (int y = 0; y < second.count_column; y++) {
                    result_number = result_number + this->matrix[y][j] * second.matrix[i][y];
                }
                result_matrix.matrix[i][j] = result_number;
            }
        }
        cout << "Полученна матрица:\n";
        result_matrix.Info();
    }


    //Сумма разреженной диагональной матицы
    void SumDMatrix() {
        int Sum = 0;
        for (int i = 0; i < count_row; i++) {
            for (int j = 0; j < count_column; j++) {
                if ((i + j) % 2 == 0)
                    Sum += matrix[i][j];
            }
        }
        cout << "Sum DMatrix: " << Sum;
    }


    //Вывод матрицы
    void Info() {
        for (int i = 0; i < count_row; i++) {
            cout << '|';
            for (int j = 0; j < count_column; j++) {

                cout << matrix[i][j];
                if (j != count_column - 1) {
                    cout << "\t";
                }
            }
            cout << '|' << endl;
        }
        cout << endl << endl;
    }


    //Очистка памяти
    ~Matrix() {
        for (int i = 0; i < count_row; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};