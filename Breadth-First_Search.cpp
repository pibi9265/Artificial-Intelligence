#include <string>
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

string bfSearch::searching(){
    string result = to_string(start);
    result += "->";
    while(!open.empty()){
        open.pop();
    }
    while(!closed.empty()){
        result += to_string(closed.top());
        result += "->";
        closed.pop();
    }
    return result;
}
