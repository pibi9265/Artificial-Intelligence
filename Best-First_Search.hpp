#ifndef BFIRST_H
#define BFIRST_H

#include <string>
#include <queue>
using namespace std;

class bFirst{
    private:
        int arrSize;
        int **arr;
        int start;
        int end;
        int *hArr;
        queue<queue<int>> open;
        queue<queue<int>> closed;
        queue<int> path;
        bool reVisit(int n);
        int cost(queue<int> q);
        string qtos(queue<int> q);
        void resetQueue(queue<int> q);
        void resetQueue(queue<queue<int>> q);
        queue<int> bestofAllChild();
        void popOpen(queue<int> q);
    public:
        bFirst(int arrSize, int **arr, int start, int end, int *hArr);
        ~bFirst();
        bool searching();
        int getCost();
        string getPath();
};

bFirst::bFirst(int arrSize, int **arr, int start, int end, int *hArr){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
    this->hArr = hArr;
}

bFirst::~bFirst(){}

bool bFirst::searching(){
    queue<int> tmp;
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
            tmp = bestofAllChild();
            popOpen(tmp);
            closed.push(tmp);
            for(int i = 0;i < arrSize;i++){
                if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                    open.push(closed.back());
                    open.back().push(i);
                }
            }
        }
    }
}

bool bFirst::reVisit(int n){
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

int bFirst::cost(queue<int> q){
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

string bFirst::qtos(queue<int> q){
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

int bFirst::getCost(){
    return cost(path);
}

string bFirst::getPath(){
    return qtos(path);
}

void bFirst::resetQueue(queue<int> q){
    while(!q.empty()){
        q.pop();
    }
}

void bFirst::resetQueue(queue<queue<int>> q){
    while(!q.empty()){
        q.pop();
    }
}

queue<int> bFirst::bestofAllChild(){
    queue<queue<int>> q = open;
    queue<int> result;
    if(q.empty()){
        return result;
    }
    else{
        result = q.front();
        q.pop();
        while(!q.empty()){
            if(cost(result)>cost(q.front())){
                result = q.front();
            }
            q.pop();
        }
    }
    return result;
}

void bFirst::popOpen(queue<int> q){
    stack<queue<int>> tmp;
    while(!open.empty()){
        if(open.front() == q){
            open.pop();
            break;
        }
        else{
            tmp.push(open.front());
            open.pop();
        }
    }
    while(!tmp.empty()){
        open.push(tmp.top());
        tmp.pop();
    }
}

#endif
