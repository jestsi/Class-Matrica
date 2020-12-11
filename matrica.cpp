#include "matrica.h"


Matrica::Matrica(int height, int width) {
    if (height <= 1 || width <= 1) {
        throw std::invalid_argument( "Height and width must not be less than 1 and < 0");
    }
    matrica = init(height, width);
//        std::cout << "Конструктор!\n";
    srand(time(NULL));
}
Matrica::Matrica(const Matrica &other) {
    _delete();
    matrica = init(other.height, other.width);
//        std::cout << "Конструктор COPY!\n";
}
Matrica::~Matrica() {
    _delete();
//        std::cout << "DEКонструктор!\n";
}

Matrica& Matrica::operator = (const Matrica &other) {
    _delete();
    this->height = other.height;
    this->width = other.width;

    matrica = init(height, width);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrica[i][j] = other.matrica[i][j];
        }
    }

    return *this;
}
bool Matrica::operator == (const Matrica &other) {
    if (height == other.height && width == other.width) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrica[i][j] != other.matrica[i][j]) return 0;
                return 1;
            }
        }
    } else return 0;
}
bool Matrica::operator != (const Matrica &other) {
    if (height == other.height && width == other.width) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrica[i][j] != other.matrica[i][j]) return 1;
                return 0;
            }
        }
    } else return 1;
}

bool Matrica::operator > (const Matrica &other) {
    if (height > other.height && width > other.width) return 1; else return 0;
}
bool Matrica::operator < (const Matrica &other) {
    if (height > other.height && width > other.width) return 0; else return 1;
}

Matrica Matrica::operator +(const Matrica &other) {
    int **tempMatrica = copyIn();
    _delete();
    height += other.height;
    width += other.height;
    matrica = init(height, width);
    for (int i = 0; i < (height-other.height); i++) {
        for (int j = 0; j < (width-other.width); j++) {
            matrica[i][j] = tempMatrica[i][j];
        }
    }

    for (int i = 0; i < (height-other.height); i++) {
        delete [] tempMatrica[i];
    }
    delete [] tempMatrica;}
Matrica Matrica::operator -(const Matrica &other) {
    int **tempMatrica = copyIn();
    _delete();
    height -= other.height;
    width -= other.height;
    matrica = init(height, width);
    for (int i = 0; i < (height); i++) {
        for (int j = 0; j < (width); j++) {
            matrica[i][j] = tempMatrica[i][j];
        }
    }

    for (int i = 0; i < (height); i++) {
        delete [] tempMatrica[i];
    }
    delete [] tempMatrica;
}

Matrica& Matrica::operator++() {
    int **tempMatrica = copyIn();
    _delete();

    height++;
    width++;

    matrica = init(height, width);

    for (int i = 0; i < height-1; i++) {
        for (int j = 0; j < width-1; j++) {
            matrica[i][j] = tempMatrica[i][j];
        }
    }

    for (int i = 0; i < height-1; i++) {
        delete [] tempMatrica[i];
    }
    delete [] tempMatrica;
    return *this;}
Matrica& Matrica::operator--() {
    int **tempMatrica = copyIn();
    _delete();

    height--;
    width--;

    matrica = init(height, width);

    for (int i = 0; i < height+1; i++) {
        for (int j = 0; j < width+1; j++) {
            matrica[i][j] = tempMatrica[i][j];
        }
    }
    //delete tempMatrica
    for (int i = 0; i < height+1; i++) {
        delete [] tempMatrica[i];
    }
    delete [] tempMatrica;
    return *this;
}

int **Matrica::init(int height, int width) {
    int **temp_matrx;
    if (height > 0 && width > 0) {
        this->height = height;
        this->width = width;

        temp_matrx = new int*[height];

        for (int i = 0; i < height; i++) {
            temp_matrx[i] = new int[width];
        }
        return temp_matrx;

    } else {
        throw std::invalid_argument("Height not must be 0 and width!");
    }
    return temp_matrx;
}


void Matrica::fillRand() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrica[i][j] = rand()%10;
        }
    }
}

void Matrica::_delete() {
    if (matrica != nullptr) {
        for (int i = 0; i < height; i++) {
            delete [] this->matrica[i];
        }
        delete [] this->matrica;
    }
    matrica = nullptr;
}
void Matrica::_delete(Matrica &matrica) {
    if (matrica.matrica != nullptr) {
        for (int i = 0; i < matrica.height; i++) {
            delete [] matrica.matrica[i];
        }
        delete [] matrica.matrica;
    }
    matrica.matrica = nullptr;
}

int Matrica::getPos(int pos_h, int pos_w) {
    if (pos_h < 0 || pos_w < 0) {
        throw std::invalid_argument("Not finded");
    }
    return Matrica::matrica[pos_h][pos_w];
}

int **Matrica::copyIn() {

    int **tempMatrica = init(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tempMatrica[i][j] = matrica[i][j];
        }
    }
    return tempMatrica;
}

void Matrica::fillColumn(int indexColumm) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == indexColumm)
                matrica[i][j] = rand()%10;
        }
    }
}
void Matrica::fillRow(int indexRow) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == indexRow)
                matrica[i][j] = rand()%10;
        }
    }
}

void Matrica::showAndUpdate() {
    while (true) {
        system("clear");
        fillRand();
        std::cout << *this;
    }
}
void Matrica::drawRect(int posY, int posX, int size, int numDraw) {
    if (posY < 0 || posX < 0 || size < 1) {
        throw std::invalid_argument("Minimum position is 0 and size min 2");
    }
    if (numDraw < 0 || numDraw > 9) {
        throw std::invalid_argument("numDraw is 0 1 2 3 4 ... 9");
    }

    for (int i = posY; i < (posY+size); i++) {
        for (int j = posX; j < (posX+size); j++) {
            matrica[i][j] = numDraw;
        }
    }
}

void Matrica::drawCircle(int posY, int posX, int size, int numDraw ) {
    if (posY < 0 || posX < 0 || size < 1) {
        throw std::invalid_argument("Minimum position is 0 and size min 2");
    }
    if (numDraw < 0 || numDraw > 9) {
        throw std::invalid_argument("numDraw is 0 1 2 3 4 ... 9");
    }


    for (int i = posY; i < (posY+size); i++) {
        for (int j = posX; j < (posX+size); j++) {
            matrica[i][j] = numDraw;
        }
    }
    // левый верхний угол
    matrica[posY][posX] = 0;
    matrica[posY][posX+1] = 0;
    matrica[posY+1][posX] = 0;
    // правый верхний угол
    matrica[posY][posX+size-1] = 0;
    matrica[posY+1][posX+size-1] = 0;
    matrica[posY][posX+size-2] = 0;
    //правый нижний угол
    matrica[posY+size-1][posX+size-2] = 0;
    matrica[posY+size-2][posX+size-1] = 0;
    matrica[posY+size-1][posX+size-1] = 0;

    // левый нижний угол
    matrica[posY+size-1][posX] = 0;
    matrica[posY+size-1][posX+1] = 0;
    matrica[posY+size-2][posX] = 0;
}

void Matrica::setNull() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrica[i][j] = 0;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrica & matrix) {
    for (int i = 0; i < matrix.height; i++) {
        for (int j = 0; j < matrix.width; j++) {
            os <<  ' ' <<"\033[35m" + std::to_string( matrix.matrica[i][j]) + "\033[0m";
//            os << matrix.matrica[i][j];
        }
        os << std::endl;
    }
    return os;
}

//std::istream& operator>>(std::istream& is, Matrica & matrix) {
//    std::string temp_line;
//    for (int i = 0; i < matrix.height; i++) {
//        for (int j = 0; j < matrix.width; j++) {
//            is >>matrix.matrica[i][j];
//        }
//    }
//    return is;
//}
