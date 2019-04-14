#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <iostream> //debug
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
        queue<queue<int>> path;
        queue<int> sPath;
        bool reVisit(int n);
        int cost(queue<int> q);
        string qtos(queue<int> q);
        string qtos(queue<queue<int>> q);
        bool findSP();
    public:
        bfSearch(int arrSize, int **arr, int start, int end);
        ~bfSearch();
        bool searching();
        bool searchingSP();
};

bfSearch::bfSearch(int arrSize, int **arr, int start, int end){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
}

bfSearch::~bfSearch(){}

bool bfSearch::searching(){
    open = queue<queue<int>>();
    closed = queue<queue<int>>();
    path = queue<queue<int>>();
    open.push(queue<int>());
    open.front().push(start);
    while(true){
        if(open.empty()){
            return false;
        }
        else if(open.front().back()==end){
            path.push(open.front());
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

bool bfSearch::searchingSP(){
    int step = 1; //debug
    open = queue<queue<int>>();
    closed = queue<queue<int>>();
    path = queue<queue<int>>();
    sPath = queue<int>();
    open.push(queue<int>());
    open.front().push(start);
    while(true){
        if(open.empty()){
            findSP();
            cout<<"[First Path]\n -Path: "<<qtos(path.front())<<"\n -Cost: "<<cost(path.front())<<endl; //debug
            cout<<"[Shortest Path]\n -Path: "<<qtos(sPath)<<"\n -Cost: "<<cost(sPath)<<"\n"<<endl; //debug
            return true;
        }
        else if(open.front().back()==end){
            path.push(open.front());
        }
        closed.push(open.front());
        open.pop();
        for(int i = 0;i < arrSize;i++){
            if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                open.push(closed.back());
                open.back().push(i);
            }
        }
        cout<<"[Step "<<step<<"]\n -Path: "<<qtos(closed.back())<<"\n -Cost: "<<cost(closed.back())<<endl; //debug
        cout<<" -Open: "<<qtos(open)<<"\n -Closed: "<<qtos(closed)<<endl; //debug
        step++; //debug
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
    string str = "Empty";
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

string bfSearch::qtos(queue<queue<int>> q){
    queue<queue<int>> tmp = q;
    string str = "Empty";
    if(tmp.empty()){
        return str;
    }
    else{
        str = to_string(tmp.front().back());
        tmp.pop();
        while(!tmp.empty()){
            str += " ";
            str += to_string(tmp.front().back());
            tmp.pop();
        }
    }
    return str;
}

bool bfSearch::findSP(){
    queue<queue<int>> tmp = path;
    if(tmp.empty()){
        return false;
    }
    else{
        sPath = tmp.front();
        tmp.pop();
    }
    while(!tmp.empty()){
        if(cost(sPath)>cost(tmp.front())){
            sPath = tmp.front();
            tmp.pop();
        }
    }
    return true;
}

#endif
