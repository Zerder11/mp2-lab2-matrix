// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц
#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------
void create_random_matrix(TDynamicMatrix<double>& M, int ran)
{
    srand(ran);
    for (size_t i = 0; i < M.size(); i++)
        for (size_t j = 0; j < M.size(); j++)
        {
            M[i][j] = 100 + (rand() % 10000) / 10.0;
        }
}
void choice_test(const int& select, TDynamicMatrix<double>& M1, TDynamicMatrix<double>& M2)
{
    if (select == 1)
    {
        cout << M1 * M2 << endl;
    }
    else if (select == 2)
    {
        cout << M1 + M2 << endl;
    }
    else if (select == 3)
    {
        cout << M1 - M2 << endl;
    }
}
void choice_matrix(const int& ch, TDynamicMatrix<double>& M, int ran)
{
    if (ch == 1)
    {
        cout << "\nразмер матрицы:\n";
        cin >> M;
    }
    else if (ch == 2)
    {
        create_random_matrix(M, ran);
    }
}
void main()
{
    int ch1, ch2, select, n, size;
    setlocale(LC_ALL, "Russian");
    cout << "Размер Матриц:\n\n1)ввести\n2)рандом\n";
    cin >> n;
    if (n == 1)
    {
        cout << "\nввод данных ";
        cin >> size;
    }
    else if (n == 2)
    {
        srand(204);
        size = 3 + rand() % 98;
    }
    TDynamicMatrix<double> M1(size), M2(size);
    cout << "Выбор матрица1:\n\n1)ввести\n2)рандом\n\n";
    cin >> ch1;
    choice_matrix(ch1, M1, 5326);
    cout << "Выбор матрица2:\n\n1)ввести\n2)рандом\n\n";
    cin >> ch2;
    choice_matrix(ch2, M2, 9083);
    cout << "выбор метода:\n\n1)Матрица A*B\n2)Матрица A+B\n3)Матрица A-B\n\n";
    cin >> select;
    if (select > 3 || select < 1 || ch1 < 1 || ch1 > 2 || ch2 < 1 || ch2 > 2)
    {
        cout << "\nERROR: Invalid operation number" << endl;
        exit(1);
    }
    cout << "\nРешение:\n\n";
    choice_test(select, M1, M2);
}
//---------------------------------------------------------------------------