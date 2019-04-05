#include <string> //for string
#include <utility> //for pair
#include <stack> //for stack
using namespace std;

#include "Breadth-First_Search.h"

bfSearch::bfSearch(pair<string, int> *pArr, int pArrSize){
    this->pArr = pArr;
    this->pArrSize = pArrSize;
}

bfSearch::~bfSearch(){}

string bfSearch::searching(){
    return pArr[pArrSize-1].first;
}
