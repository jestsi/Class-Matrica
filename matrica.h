#ifndef MATRICA_H
#define MATRICA_H

#pragma once
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <ostream>

class Matrica
{
public:
    Matrica(int height, int width);
    Matrica(const Matrica &other);

    Matrica &operator = (const Matrica &other);

    bool operator == (const Matrica &other);
    bool operator != (const Matrica &other);

    bool operator > (const Matrica &other);
    bool operator < (const Matrica &other);


    Matrica operator +(const Matrica &other);
    Matrica operator -(const Matrica &other);

    Matrica &operator++();
    Matrica &operator--();

    void fillColumn(int indexColumm);
    void fillRow(int indexRow);

    int getPos(int pos_h, int pos_w);

    void fillRand();
    void showAndUpdate();

    void setNull();

    void drawRect(int posY, int posX, int size, int numDraw = 8);
    void drawCircle(int posY, int posX, int radius, int numDraw = 8);
    friend std::ostream & operator<<(std::ostream& os, const Matrica& matrix);
//    friend std::istream & operator>>(std::istream& is, Matrica& matrix);

    ~Matrica();
private:
    int **copyIn(); // копирует эту матрицу в другую Возврощает двухмерный массив
    void _delete(); // чистит память двухмерного массива
    void _delete(Matrica &matrica); // чистит ...
    int **init(int height, int width); // создает двухмерный массив Возвращает двухмерный массив заполненый нулями

    int **matrica; // сам двухмерный массив матрицы
    int height, width; // высота и ширина матрицы
};



#endif // MATRICA_H
