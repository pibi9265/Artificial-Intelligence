#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <string>
#include <queue>
#include <stack>
using namespace std;

class bfSearch{
    private:
        int bfArrX;
        int bfArrY;
        int **bfArr;
        int start;
        int end;
        queue<int> open;
        stack<int> closed;
    public:
        bfSearch(int bfArrX, int bfArrY, int **bfArr, int start, int end);
        ~bfSearch();
        string searching();
};

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

#endif
