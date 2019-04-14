#ifndef DFSEARCH_H
#define DFSEARCH_H

#include <iostream> //debug
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
        queue<queue<int>> path;
        queue<int> sPath;
        bool reVisit(int n);
        int cost(queue<int> q);
        string qtos(queue<int> q);
        string qtos(queue<queue<int>> q);
        string stos(stack<queue<int>> s);
        bool findSP();
    public:
        dfSearch(int arrSize, int **arr, int start, int end);
        ~dfSearch();
        bool searching();
        bool searchingSP();
};

dfSearch::dfSearch(int arrSize, int **arr, int start, int end){
    this->arrSize = arrSize;
    this->arr = arr;
    this->start = start;
    this->end = end;
}

dfSearch::~dfSearch(){}

bool dfSearch::searching(){
    open = stack<queue<int>>();
    closed = queue<queue<int>>();
    path = queue<queue<int>>();
    open.push(queue<int>());
    open.top().push(start);
    while(true){
        if(open.empty()){
            return false;
        }
        else if(open.top().back()==end){
            path.push(open.top());
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

bool dfSearch::searchingSP(){
    int step = 1; //debug
    open = stack<queue<int>>();
    closed = queue<queue<int>>();
    path = queue<queue<int>>();
    sPath = queue<int>();
    open.push(queue<int>());
    open.top().push(start);
    while(true){
        if(open.empty()){
            findSP();
            cout<<"[First Path]\n -Path: "<<qtos(path.front())<<"\n -Cost: "<<cost(path.front())<<endl; //debug
            cout<<"[Shortest Path]\n -Path: "<<qtos(sPath)<<"\n -Cost: "<<cost(sPath)<<"\n"<<endl; //debug
            return true;
        }
        else if(open.top().back()==end){
            path.push(open.top());
        }
        closed.push(open.top());
        open.pop();
        for(int i = arrSize - 1;i >= 0;i--){
            if(arr[closed.back().back()][i]!=0&&!reVisit(i)){
                open.push(closed.back());
                open.top().push(i);
            }
        }
        cout<<"[Step "<<step<<"]\n -Path: "<<qtos(closed.back())<<"\n -Cost: "<<cost(closed.back())<<endl; //debug
        cout<<" -Open: "<<stos(open)<<"\n -Closed: "<<qtos(closed)<<endl; //debug
        step++; //debug
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

string dfSearch::qtos(queue<queue<int>> q){
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

string dfSearch::stos(stack<queue<int>> s){
    stack<queue<int>> tmp;
    string str = "Empty";
    while(!s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    if(tmp.empty()){
        return str;
    }
    else{
        str = to_string(tmp.top().back());
        tmp.pop();
        while(!tmp.empty()){
            str += " ";
            str += to_string(tmp.top().back());
            tmp.pop();
        }
    }
    return str;
}

bool dfSearch::findSP(){
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
