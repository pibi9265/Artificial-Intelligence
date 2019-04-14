#ifndef BFSEARCH_H
#define BFSEARCH_H

#include <iostream> //debug
#include <string>
#include <queue>
using namespace std;

class bfSearch{
    private:
        int arrSize; //탐색할 도시의 갯수
        int **arr; //각 도시간의 cost을 저장한 int형 2중배열
        int start; //시작점
        int end; //도착점
        queue<queue<int>> open; //다음 방문할 자식 노드를 저장할 큐
        queue<queue<int>> closed; //방문한 노드를 저장할 큐
        queue<queue<int>> path; //찾아낸 모든 path를 저장할 큐
        queue<int> sPath; //Shortest Path를 저장할 큐
        bool reVisit(int n); //인자로 받은 도시가 과거에 방문했던 도시인지 검사 (재방문일 경우 true값 return)
        int cost(queue<int> q); //인자로 받은 Path(큐)의 총 Cost를 return
        string qtos(queue<int> q); //인자로 받은 Path(큐)를 String형으로 변환해서 return
        string qtos(queue<queue<int>> q); //인자로 받은 Path(큐)를 String형으로 변환해서 return
        bool findSP(); //변수 path에서 Shortest Path를 찾아내어 sPath변수에 값을 입력함 (path가 비어있을경우 false값 return)
        string ntoc(int n); //debug //0부터 19까지의 int형 값을 알맞은 도시의 이름(string)으로 변환해서 return
    public:
        bfSearch(int arrSize, int **arr, int start, int end);
        ~bfSearch();
        bool searching(); //첫번째 path를 찾을때까지 탐색하는 함수 (path에 값을 입력)
        bool searchingSP(); //모든 트리를 탐색하여 Shortest Path를 찾는 함수 (path, sPath에 값을 입력)
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
            closed.push(open.front());
            open.pop();
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

string bfSearch::qtos(queue<queue<int>> q){
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
        }
        tmp.pop();
    }
    return true;
}

string bfSearch::ntoc(int n){ //debug
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
