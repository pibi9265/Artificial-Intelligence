#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <string>
#include <queue>
using namespace std;

class bfSearch{
    private:
        int arrSize;
        int **arr;
        int start;
        int end;
        queue<queue<int>> open;
        queue<queue<int>> closed;
        queue<int> path;
        bool reVisit(int n);
        int cost(queue<int> q);
        string qtos(queue<int> q);
        void resetQueue(queue<int> q);
        void resetQueue(queue<queue<int>> q);
    public:
        bfSearch(int arrSize, int **arr, int start, int end);
        ~bfSearch();
        bool searching();
        int getCost();
        string getPath();
};

bfSearch::bfSearch(int arrSize, int **arr, int start, int end){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
}

bfSearch::~bfSearch(){}

bool bfSearch::searching(){
    resetQueue(open);
    resetQueue(closed);
    resetQueue(path);
    open.push(queue<int>());
    open.front().push(start);
    while(true){
        if(open.empty()){
            return false;
        }
        else if(open.front().back()==end){
            path = open.front();
            return true;
        }
        else{
            closed.push(open.front());
            open.pop();
            for(int i = 0;i < arrSize;i++){
                if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                    open.push(closed.back());
                    open.back().push(i);
                }
            }
        }
    }
}

bool bfSearch::reVisit(int n){
    queue<int> tmp = closed.back();
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

int bfSearch::cost(queue<int> q){
    queue<int> tmp = q;
    int total = 0;
    int n = 0;
    if(tmp.empty()){
        return total;
    }
    else{
        while(true){
            n = tmp.front();
            tmp.pop();
            if(!tmp.empty()){
                total += arr[n][tmp.front()];
                n = 0;
            }
            else{
                return total;
            }
        }
    }
}

string bfSearch::qtos(queue<int> q){
    queue<int> tmp = q;
    string str = "Fail";
    if(tmp.empty()){
        return str;
    }
    str = to_string(tmp.front());
    tmp.pop();
    str += " -> ";
    while(true){
        str += to_string(tmp.front());
        tmp.pop();
        if(tmp.empty()){
            return str;
        }
        else{
            str += " -> ";
        }
    }
}

int bfSearch::getCost(){
    return cost(path);
}

string bfSearch::getPath(){
    return qtos(path);
}

void bfSearch::resetQueue(queue<int> q){
    while(!q.empty()){
        q.pop();
    }
}

void bfSearch::resetQueue(queue<queue<int>> q){
    while(!q.empty()){
        q.pop();
    }
}

#endif
