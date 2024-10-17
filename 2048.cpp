#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 6;
int arr[SIZE][SIZE];
void draw();
void initialize();
void randomBlockGeneration();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
bool canMove();
bool gameOver();

int main() {
    srand(time(0));

    initialize();
    draw();

    char n;
    while (!gameOver()) {
        cout << "Use w(up), a(left), s(down), d(right) to move: ";
        cin >> n;
        switch (n) {
            case 'w':
                moveUp();
                randomBlockGeneration();
                draw();
                break;
            case 'a':
                moveLeft();
                randomBlockGeneration();
                draw();
                break;
            case 's':
                moveDown();
                randomBlockGeneration();
                draw();
                break;
            case 'd':
                moveRight();
                randomBlockGeneration();
                draw();
                break;
            default:
                cout << "Enter valid Input" << endl;
                break;
        }
    }

    cout << "Game Over!" << endl;
    return 0;
}

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            arr[i][j] = 0;
        }
    }

    randomBlockGeneration();
    randomBlockGeneration();
}

void draw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << (arr[i][j] == 0 ? "\t" : to_string(arr[i][j]) + "\t");
        }
        cout << endl << endl;
    }
}

void randomBlockGeneration() {
    int emptyCells = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 0) {
                emptyCells++;
            }
        }
    }

    if (emptyCells == 0) return;

    int randIndex = rand() % emptyCells;
    int newValue = (rand() % 2 + 1) * 2;

    emptyCells = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 0) {
                if (emptyCells == randIndex) {
                    arr[i][j] = newValue;
                    return;
                }
                emptyCells++;
            }
        }
    }
}

void moveUp() {
    for (int j = 0; j < SIZE; j++) 
    {
        int nextEmpty = 0;
        for (int i = 0; i < SIZE; i++) 
        {
            if (arr[i][j] != 0) 
            {
                if (nextEmpty != i) 
                {
                    if (arr[nextEmpty][j] == arr[i][j]) 
                    {
                        arr[nextEmpty][j] *= 2;
                        arr[i][j] = 0;
                        nextEmpty++;
                    } else if (arr[nextEmpty][j] == 0) {
                        arr[nextEmpty][j] = arr[i][j];
                        arr[i][j] = 0;
                    } else {
                        nextEmpty++;
                        if (nextEmpty != i) {
                            arr[nextEmpty][j] = arr[i][j];
                            arr[i][j] = 0;
                        }
                    }
                } else {
                    nextEmpty++;
                }
            }
        }
    }
}
void moveDown() {
    for (int j = 0; j < SIZE; j++) {
        int nextEmpty = SIZE - 1;
        for (int i = SIZE - 1; i >= 0; i--) {
            if (arr[i][j] != 0) {
                if (nextEmpty != i) {
                    if (arr[nextEmpty][j] == arr[i][j]) {
                        arr[nextEmpty][j] *= 2;
                        arr[i][j] = 0;
                        nextEmpty--;
                    } else if (arr[nextEmpty][j] == 0) {
                        arr[nextEmpty][j] = arr[i][j];
                        arr[i][j] = 0;
                    } else {
                        nextEmpty--;
                        if (nextEmpty != i) {
                            arr[nextEmpty][j] = arr[i][j];
                            arr[i][j] = 0;
                        }
                    }
                } else {
                    nextEmpty--;
                }
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < SIZE; i++) {
        int nextEmpty = 0;
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] != 0) {
                if (nextEmpty != j) {
                    if (arr[i][nextEmpty] == arr[i][j]) {
                        arr[i][nextEmpty] *= 2;
                        arr[i][j] = 0;
                        nextEmpty++;
                    } else if (arr[i][nextEmpty] == 0) {
                        arr[i][nextEmpty] = arr[i][j];
                        arr[i][j] = 0;
                    } else {
                        nextEmpty++;
                        if (nextEmpty != j) {
                            arr[i][nextEmpty] = arr[i][j];
                            arr[i][j] = 0;
                        }
                    }
                } else {
                    nextEmpty++;
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < SIZE; i++) {
        int nextEmpty = SIZE - 1;
        for (int j = SIZE - 1; j >= 0; j--) {
            if (arr[i][j] != 0) {
                if (nextEmpty != j) {
                    if (arr[i][nextEmpty] == arr[i][j]) {
                        arr[i][nextEmpty] *= 2;
                        arr[i][j] = 0;
                        nextEmpty--;
                    } else if (arr[i][nextEmpty] == 0) {
                        arr[i][nextEmpty] = arr[i][j];
                        arr[i][j] = 0;
                    } else {
                        nextEmpty--;
                        if (nextEmpty != j) {
                            arr[i][nextEmpty] = arr[i][j];
                            arr[i][j] = 0;
                        }
                    }
                } else {
                    nextEmpty--;
                }
            }
        }
    }
}

bool canMove() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] == 0) return true;
            if (i < SIZE - 1 && arr[i][j] == arr[i + 1][j]) return true;
            if (j < SIZE - 1 && arr[i][j] == arr[i][j + 1]) return true;
        }
    }
    return false;
}

bool gameOver() {
    if (canMove()) return false;
    return true;
}