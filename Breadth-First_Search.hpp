#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <string>
#include <queue>
using namespace std;

class bfSearch{
    private:
        int bfArrSize;
        int **bfArr;
        int start;
        int end;
        queue<queue<int>> open;
        queue<int> closed;
        bool checkClosed(int n);
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
}

bfSearch::~bfSearch(){}

string bfSearch::searching(){
    string result;
    open.push(queue<int>());
    open.front().push(start);
    while(true){
        if(open.empty()){
            result = "Fail";
            return result;
        }
        else if(open.front().back()==end){
            result = "Success: ";
            while(true){
                result += to_string(open.front().front());
                open.front().pop();
                if(open.front().empty()){
                    return result;
                }else{
                    result += " -> ";
                }
            }
        }
        else{
            queue<int> tmp = open.front();
            open.pop();
            closed.push(tmp.back());
            for(int i = 0;i < bfArrSize;i++){
                if(bfArr[tmp.back()][i]!=0&&!checkClosed(i)){
                    open.push(tmp);
                    open.back().push(i);
                }
            }
        }
    }
}

bool bfSearch::checkClosed(int n){
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
