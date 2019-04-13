#include <iostream>
#include <string>
using namespace std;

#include "Breadth-First_Search.hpp"
#include "Depth-First_Search.hpp"
#include "Hill-Climing.hpp"
#include "Best-First_Search.hpp"

int main(){
    int arrSize = 5;

    int **arr = new int *[arrSize];
    for(int i = 0;i < arrSize;i++){
        arr[i] = new int[arrSize];
    }
    for(int y = 0; y < arrSize;y++){
        for(int x = 0;x < arrSize;x++){
            arr[y][x] = 0;
        }
    }

    arr[0][1] = 1;    arr[0][3] = 1;    arr[0][4] = 1;
    arr[1][0] = 1;
    arr[2][3] = 1;
    arr[3][0] = 1;    arr[3][2] = 1;
    arr[4][0] = 1;

    int start = 0;
    int end = 2;

    int *hArr = new int [arrSize];
    for(int i = 0;i < arrSize;i++){
        hArr[i] = 0;
    }

    hArr[0] = 8;
    hArr[1] = 7;
    hArr[2] = 0;
    hArr[3] = 5;
    hArr[4] = 6;

    cout << "Breadth-First Search" << endl;
    bfSearch bf(arrSize, arr, start, end);
    bf.searchingSP();

    cout << "Depth-First Search" << endl;
    dfSearch df(arrSize, arr, start, end);
    df.searchingSP();

    cout << "Hill-Climing" << endl;
    hClim hillCliming(arrSize, arr, start, end, hArr);
    hillCliming.searching();

    cout << "Best-First Search" << endl;
    bFirst bestFirst(arrSize, arr, start, end, hArr);
    bestFirst.searching();

    for(int i = 0;i < arrSize;i++){
        delete[] arr[i];
    }
    delete[] arr;

    delete[] hArr;

    return 0;
}
