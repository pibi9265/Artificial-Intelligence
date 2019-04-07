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
        queue<int> closed;
        bool checkClosed(int n);
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
}

dfSearch::~dfSearch(){}

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
            result = "Success: ";
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
            closed.push(tmp.back());
            for(int i = dfArrSize - 1;i >= 0;i--){
                if(dfArr[tmp.back()][i]!=0&&!checkClosed(i)){
                    open.push(tmp);
                    open.top().push(i);
                }
            }
        }
    }
}

bool dfSearch::checkClosed(int n){
    queue<int> tmp = closed;
    while(!tmp.empty()){
        if(tmp.front() == n){
            return true;
        }
        else{
            tmp.pop();
        }
    }
    return false;
}

#endif
