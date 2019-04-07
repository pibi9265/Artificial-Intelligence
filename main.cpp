#include <iostream>
#include <string>
using namespace std;

#include "Breadth-First_Search.hpp"
#include "Depth-First_Search.hpp"

int main(){
    int bfArrSize = 5;

    int **bfArr = new int *[bfArrSize];
    for(int i = 0;i < bfArrSize;i++){
        bfArr[i] = new int[bfArrSize];
    }
    for(int y = 0; y < bfArrSize;y++){
        for(int x = 0;x < bfArrSize;x++){
            bfArr[y][x] = 0;
        }
    }

    bfArr[0][1] = 1;
    bfArr[0][3] = 1;
    bfArr[0][4] = 1;
    bfArr[1][0] = 1;
    bfArr[2][3] = 1;
    bfArr[3][0] = 1;
    bfArr[3][2] = 1;
    bfArr[4][0] = 1;

    int start = 0;
    int end = 2;

    bfSearch bf(bfArrSize, bfArr, start, end);
    cout << bf.searching() << endl;
    dfSearch df(bfArrSize, bfArr, start, end);
    cout << df.searching() << endl;

    for(int i = 0;i < bfArrSize;i++){
        delete[] bfArr[i];
    }
    delete[] bfArr;

    return 0;
}
