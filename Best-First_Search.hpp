#ifndef BFIRST_H
#define BFIRST_H

#include <iostream> //debug
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
        queue<int> bestOpen();
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
    int step = 1; //debug
    queue<int> tmp;
    open = queue<queue<int>>();
    closed = queue<queue<int>>();
    path = queue<int>();
    open.push(queue<int>());
    open.front().push(start);
    tmp = open.front();
    while(!open.empty()){
        if(tmp.back()==end){
            cout<<"[Last Step "<<step<<"]\n -Path: "<<qtos(tmp)<<"\n -Cost: "<<cost(tmp)<<"\n"<<endl; //debug
            path = open.front();
            return true;
        }
        else{
            cout<<"[Step "<<step<<"]\n -Path: "<<qtos(tmp)<<"\n -Cost: "<<cost(tmp)<<endl; //debug
            closed.push(tmp);
            popOpen(tmp);
            for(int i = 0;i < arrSize;i++){
                if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                    open.push(closed.back());
                    open.back().push(i);
                }
            }
            tmp = bestOpen();
        }
        step++; //debug
    }
    cout<<"[Error]"<<endl; //debug
    return false;
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
    else{
        str = to_string(tmp.front());
        tmp.pop();
        while(!tmp.empty()){
            str += " -> ";
            str += to_string(tmp.front());
            tmp.pop();
        }
    }
    return str;
}

int bFirst::getCost(){
    return cost(path);
}

string bFirst::getPath(){
    return qtos(path);
}

queue<int> bFirst::bestOpen(){
    queue<queue<int>> q = open;
    queue<int> result;
    if(!q.empty()){
        result = q.front();
        q.pop();
        while(!q.empty()){
            if((cost(result)+hArr[result.back()])>(cost(q.front())+hArr[q.front().back()])){
                result = q.front();
            }
            q.pop();
        }
    }
    return result;
}

void bFirst::popOpen(queue<int> q){
    queue<queue<int>> tmp;
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
    while(!open.empty()){
        tmp.push(open.front());
        open.pop();
    }
    open = tmp;
}

#endif
