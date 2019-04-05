#include <iostream>
#include <utility> //for pair
using namespace std;

#include "Breadth-First_Search.h"

int main(){
    pair<string,int> *pArr = new pair<string,int>[2];
    pArr[0].first = "A";
    pArr[0].second = 1;
    pArr[1].first = "B";
    pArr[1].second = 2;

    int pArrSize = 2;

    bfSearch bf = bfSearch(pArr, pArrSize);

    cout << bf.searching() << endl;

    delete pArr;
    return 0;
}
