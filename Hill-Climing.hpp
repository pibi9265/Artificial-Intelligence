#ifndef HCLIM_H
#define HCLIM_H

#include <string>
#include <queue>
using namespace std;

class hClim{
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
    public:
        hClim(int arrSize, int **arr, int start, int end, int *hArr);
        ~hClim();
        bool searching();
        int getCost();
        string getPath();
};

hClim::hClim(int arrSize, int **arr, int start, int end, int *hArr){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
    this->hArr = hArr;
}

hClim::~hClim(){}

bool hClim::searching(){
    bool firstTry = true;
    int numTmp = -1;
    int costTmp;
    resetQueue(closed);
    resetQueue(path);
    closed.push(queue<int>());
    closed.front().push(start);
    while(true){
        for(int i = 0;i < arrSize;i++){
            if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                if(firstTry){
                    costTmp = cost(closed.back())+arr[closed.back().back()][i]+hArr[i];
                    numTmp = i;
                    firstTry = false;
                }
                else if(costTmp > cost(closed.back())+arr[closed.back().back()][i]+hArr[i]){
                    costTmp = cost(closed.back())+arr[closed.back().back()][i]+hArr[i];
                    numTmp = i;
                }
            }
        }
        if(numTmp == -1){
            return false;
        }
        else if(numTmp == end){
            path = closed.back();
            path.push(numTmp);
            return true;
        }
        else{
            closed.back().push(numTmp);
            firstTry = true;
            numTmp = -1;
        }
    }
}

bool hClim::reVisit(int n){
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

int hClim::cost(queue<int> q){
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

string hClim::qtos(queue<int> q){
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

int hClim::getCost(){
    return cost(path);
}

string hClim::getPath(){
    return qtos(path);
}

void hClim::resetQueue(queue<int> q){
    while(!q.empty()){
        q.pop();
    }
}

void hClim::resetQueue(queue<queue<int>> q){
    while(!q.empty()){
        q.pop();
    }
}

#endif
