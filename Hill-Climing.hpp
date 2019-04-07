#ifndef HCLIM_H
#define HCLIM_H

#include <string>
#include <queue>
using namespace std;

class hClim{
    private:
        int hClimArrSize;
        int **hClimArr;
        int start;
        int end;
        queue<queue<int>> open;
        queue<int> closed;
        bool checkClosed(int n);
        int *hArr;
        bool heuristics();
    public:
        hClim(int hClimArrSize, int **hClimArr, int start, int end, int *hArr);
        ~hClim();
        string searching();
};

hClim::hClim(int hClimArrSize, int **hClimArr, int start, int end, int *hArr){
    this->hClimArrSize = hClimArrSize;
    this->hClimArr = hClimArr;
    this->start = start;
    this->end = end;
    this->hArr = hArr;
}

hClim::~hClim(){}

string hClim::searching(){
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
            for(int i = 0;i < hClimArrSize;i++){
                if(hClimArr[tmp.back()][i]!=0&&!checkClosed(i)){
                    open.push(tmp);
                    open.back().push(i);
                }
            }
        }
    }
}

bool hClim::checkClosed(int n){
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

bool heuristics(){}

#endif
