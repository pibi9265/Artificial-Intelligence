#include <string> //for string
#include <stack> //for stack
using namespace std;

#include "Breadth-First_Search.h"

bfSearch::bfSearch(int bfArrX, int bfArrY, int **bfArr, int start, int end){
    this->bfArrX = bfArrX;
    this->bfArrY = bfArrY;
    this->bfArr = bfArr;
    this->start = start;
    this->end = end;
}

bfSearch::~bfSearch(){}

string bfSearch::searching(){}
