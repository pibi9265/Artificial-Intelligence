#include <iostream>
using namespace std;

#include "Breadth-First_Search.h"

int main(){
    int bfArrX = 20;
    int bfArrY = 20;

    int start = 17;
    int end = 2;

    //bfSearch(bfArrX, bfArrY, **bfArr, start, end);

    string str = "Hello";
    str = str + " world!! ";
    str = str + to_string(100);
    cout << str << endl;

    return 0;
}


//bfSearch클래스의 searching부분 완성해야됨
//open이랑 closed를 각각 큐랑 스택으로 구현하는거 까지 함
