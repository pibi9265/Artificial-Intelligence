#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <string>
#include <queue>
#include <stack>
using namespace std;

class bfSearch{
    private:
        int bfArrSize;
        int **bfArr;
        int start;
        int end;
        queue<queue<int>> open;
        int *closed;
    public:
        bfSearch(int bfArrSize, int **bfArr, int start, int end);
        ~bfSearch();
        string searching();
};

bfSearch::bfSearch(int bfArrSize, int **bfArr, int start, int end){
    this->bfArrSize = bfArrSize;
    this->bfArr = bfArr;
    this->start = start;
    this->end = end;
    closed = new int[bfArrSize];
    for(int i = 0;i < bfArrSize;i++){
        closed[i] = 0;
    }
}

bfSearch::~bfSearch(){
    delete[] closed;
}

string bfSearch::searching(){
    string result;
    open.push(queue<int>());
    open.front().push(start);
    while(true){
        if(open.front().back()==end){
            while(true){
                result += to_string(open.front().front());
                open.front().pop();
                if(open.front().empty()){
                    break;
                }else{
                    result += "->";
                }
            }
            return result;
        }
        else{
            for(int i = 0;i < bfArrSize;i++){
                if(bfArr[open.front().back()][i]!=0&&closed[i]==0){
                    open.push(open.front());
                    open.back().push(i);
                }
            }
            closed[open.front().back()] = 1;
            open.pop();
        }
    }
}

#endif
