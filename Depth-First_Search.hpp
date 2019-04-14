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
        string ntoc(int n); //debug
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
            closed.push(open.top());
            open.pop();
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
        str = ntoc(tmp.front()); //debug //str = to_string(tmp.front());
        tmp.pop();
        while(!tmp.empty()){
            str += " -> ";
            str += ntoc(tmp.front()); //debug //str += to_string(tmp.front());
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
        str = ntoc(tmp.front().back()); //debug //str = to_string(tmp.front().back());
        tmp.pop();
        while(!tmp.empty()){
            str += " ";
            str += ntoc(tmp.front().back()); //debug //str += to_string(tmp.front().back());
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
        str = ntoc(tmp.top().back()); //debug //str = to_string(tmp.top().back());
        tmp.pop();
        while(!tmp.empty()){
            str += " ";
            str += ntoc(tmp.top().back()); //debug //str += to_string(tmp.top().back());
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
        }
        tmp.pop();
    }
    return true;
}

string dfSearch::ntoc(int n){ //debug
    if(n == 0) return "Arad";
    else if(n == 1) return "Bucharest";
    else if(n == 2) return "Craiova";
    else if(n == 3) return "Dobreta";
    else if(n == 4) return "Eforie";
    else if(n == 5) return "Giurgiu";
    else if(n == 6) return "Hirsova";
    else if(n == 7) return "Iasi";
    else if(n == 8) return "Lugoj";
    else if(n == 9) return "Mehadia";
    else if(n == 10) return "Neamt";
    else if(n == 11) return "Oradea";
    else if(n == 12) return "Pitesti";
    else if(n == 13) return "Rimnicu_Vilcea";
    else if(n == 14) return "Sibiu";
    else if(n == 15) return "Timisoara";
    else if(n == 16) return "Urziceni";
    else if(n == 17) return "Vaslui";
    else if(n == 18) return "Yagaras";
    else if(n == 19) return "Zerind";
}

#endif
