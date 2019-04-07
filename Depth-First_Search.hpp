#ifndef DFSEARCH_H
#define DFSEARCH_H

#include <string>
#include <queue>
#include <stack>
using namespace std;

class dfSearch{
    private:
        int dfArrSize;
        int **dfArr;
        int start;
        int end;
        stack<queue<int>> open;
        int *closed;
    public:
        dfSearch(int dfArrSize, int **dfArr, int start, int end);
        ~dfSearch();
        string searching();
};

dfSearch::dfSearch(int dfArrSize, int **dfArr, int start, int end){
    this->dfArrSize = dfArrSize;
    this->dfArr = dfArr;
    this->start = start;
    this->end = end;
    closed = new int[dfArrSize];
    for(int i = 0;i < dfArrSize;i++){
        closed[i] = 0;
    }
}

dfSearch::~dfSearch(){
    delete[] closed;
}

string dfSearch::searching(){
    string result;
    open.push(queue<int>());
    open.top().push(start);
    while(true){
        if(open.empty()){
            result = "Fail";
            return result;
        }
        else if(open.top().back()==end){
            result = "Start: ";
            while(true){
                result += to_string(open.top().front());
                open.top().pop();
                if(open.top().empty()){
                    return result;
                }else{
                    result += " -> ";
                }
            }
        }
        else{
            queue<int> tmp = open.top();
            open.pop();
            closed[tmp.back()] = 1;
            for(int i = 0;i < dfArrSize;i++){
                if(dfArr[tmp.back()][i]!=0&&closed[i]==0){
                    open.push(tmp);
                    open.top().push(i);
                }
            }
        }
    }
}

#endif
