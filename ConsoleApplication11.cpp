#include <iostream>
using namespace std;

int** create_arr(int SIZE_x, int SIZE_y) {
    int** A = new int* [SIZE_x];
    for (int i = 0; i < SIZE_x; i++) {
        A[i] = new int[SIZE_y];
    }
    return A;
}

void init_arr(int** arr, int SIZE_x,int SIZE_y) {
    for (int i = 0; i < SIZE_x; i++) {
        for (int j = 0; j < SIZE_y; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void print_arr(int** arr, int SIZE_x, int SIZE_y) {
    for (int i = 0; i < SIZE_x; i++) {
        for (int j = 0; j < SIZE_y; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int** add_line(int** arr, int& SIZE_x, int SIZE_y, int pos) {
    int** new_arr = new int* [SIZE_x + 1];
    for (int i = 0; i < SIZE_x + 1; i++) {
        new_arr[i] = new int[SIZE_y];
    }

    for (int i = 0; i < pos; i++)
        for (int j = 0; j < SIZE_y; j++)
            new_arr[i][j] = arr[i][j];

    for (int j = 0; j < SIZE_y; j++)
        new_arr[pos][j] = rand() % 100;

    for (int i = pos; i < SIZE_x; i++)
        for (int j = 0; j < SIZE_y; j++)
            new_arr[i + 1][j] = arr[i][j];

    for (int i = 0; i < SIZE_x; i++)
        delete[] arr[i];
    delete[] arr;

    SIZE_x++;
    return new_arr;
}
int** delete_line(int** arr, int& SIZE_x, int SIZE_y, int pos) {
    int** new_arr = new int* [SIZE_x - 1];
    for (int i = 0; i < SIZE_x - 1; i++)
        new_arr[i] = new int[SIZE_y];

    for (int i = 0; i < pos; i++)
        for (int j = 0; j < SIZE_y; j++)
            new_arr[i][j] = arr[i][j];

    for (int i = pos + 1; i < SIZE_x; i++)
        for (int j = 0; j < SIZE_y; j++)
            new_arr[i - 1][j] = arr[i][j];

    for (int i = 0; i < SIZE_x; i++)
        delete[] arr[i];
    delete[] arr;

    SIZE_x--;
    return new_arr;
}

void delete_arr(int** arr, int SIZE_x) {
    for (int i = 0; i < SIZE_x; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
int** shift(int** arr, int& SIZE_x, int SIZE_y, int num, int dir) {
        int** new_arr = new int* [SIZE_x];
    if (dir == 1) {
        for (int i = 0; i < SIZE_x; i++)
        {
            int pos = i - num;
            if (pos < 0)
                pos += SIZE_x;
            new_arr[pos] = arr[i];
        }
    }
    else if (dir == 4) {
        for (int i = 0; i < SIZE_x; i++)
        {
            int pos = i + num;
            if (pos >= SIZE_x)
                pos -= SIZE_x;
            new_arr[pos] = arr[i];
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < SIZE_x; i++)
        {
            for (int j = 0; j < SIZE_y; j++)
            {
                int pos = j + num;
                if (pos >= SIZE_y)
                    pos -= SIZE_y;
                new_arr[i][pos] = arr[i][j];
            }
        }
    }
    else if (dir == 3) {
        for (int i = 0; i < SIZE_x; i++)
        {
            for (int j = 0; j < SIZE_y; j++)
            {
                int pos = j - num;
                if (pos < 0)
                    pos += SIZE_y;
                new_arr[i][pos] = arr[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE_x; i++)
        delete[] arr[i];
    delete[] arr;
    return new_arr;
}
int main()
{
    int SIZE_x = 5, SIZE_y = 5;
    int** arr = create_arr(SIZE_x, SIZE_y);
    init_arr(arr, SIZE_x, SIZE_y);

    cout << "basic:" << "\n";
    print_arr(arr, SIZE_x, SIZE_y);
    //1
    arr = add_line(arr, SIZE_x, SIZE_y, 2);
    cout << "\nadded 2:" << "\n";
    print_arr(arr, SIZE_x, SIZE_y);
    //2
    arr = delete_line(arr, SIZE_x, SIZE_y, 3);
    cout << "\ndeleted 3:" << "\n";
    print_arr(arr, SIZE_x, SIZE_y);

    delete_arr(arr, SIZE_x);
    //3
    shift(arr, SIZE_x, SIZE_y, 2, 3);
    print_arr(shift(arr, SIZE_x, SIZE_y, 2, 3), SIZE_x, SIZE_y);
}
