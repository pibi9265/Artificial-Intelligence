#ifndef DFSEARCH_H
#define DFSEARCH_H

#include <string>
#include <queue>
#include <stack>
using namespace std;

class dfSearch{
    private:
        int arrSize;
        int **arr;
        int start;
        int end;
        stack<queue<int>> open;
        queue<queue<int>> closed;
        queue<int> path;
        bool reVisit(int n);
        int cost(queue<int> q);
        string qtos(queue<int> q);
        void resetQueue(queue<int> q);
        void resetQueue(queue<queue<int>> q);
        void resetQueue(stack<queue<int>> s);
    public:
        dfSearch(int arrSize, int **arr, int start, int end);
        ~dfSearch();
        bool searching();
        int getCost();
        string getPath();
};

dfSearch::dfSearch(int arrSize, int **arr, int start, int end){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
}

dfSearch::~dfSearch(){}

bool dfSearch::searching(){
    resetQueue(open);
    resetQueue(closed);
    resetQueue(path);
    open.push(queue<int>());
    open.top().push(start);
    while(true){
        if(open.empty()){
            return false;
        }
        else if(open.top().back()==end){
            path = open.top();
            return true;
        }
        else{
            closed.push(open.top());
            open.pop();
            for(int i = arrSize - 1;i >= 0;i--){
                if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                    open.push(closed.back());
                    open.top().push(i);
                }
            }
        }
    }
}

bool dfSearch::reVisit(int n){
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

int dfSearch::cost(queue<int> q){
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

string dfSearch::qtos(queue<int> q){
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

int dfSearch::getCost(){
    return cost(path);
}

string dfSearch::getPath(){
    return qtos(path);
}

void dfSearch::resetQueue(queue<int> q){
    while(!q.empty()){
        q.pop();
    }
}

void dfSearch::resetQueue(queue<queue<int>> q){
    while(!q.empty()){
        q.pop();
    }
}

void dfSearch::resetQueue(stack<queue<int>> s){
    while(!s.empty()){
        s.pop();
    }
}

#endif
