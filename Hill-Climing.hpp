#ifndef HCLIM_H
#define HCLIM_H

#include <iostream> //debug
#include <string>
#include <queue>
using namespace std;

class hClim{
    private:
        int arrSize; //탐색할 도시의 갯수
        int **arr; //각 도시간의 cost을 저장한 int형 2중배열
        int start; //시작점
        int end; //도착점
        int *hArr; //각 도시의 직선거리를 저장한 int형 배열
        queue<int> pathTmp; //searching()도중에 생기는 path를 임시로 저장할 큐
        queue<int> path; //찾아낸 path를 저장할 큐
        bool reVisit(int n); //인자로 받은 도시가 과거에 방문했던 도시인지 검사 (재방문일 경우 true값 return)
        int cost(queue<int> q); //인자로 받은 Path(큐)의 총 Cost를 return
        string qtos(queue<int> q); //인자로 받은 Path(큐)를 String형으로 변환해서 return
        string ntoc(int n); //debug //0부터 19까지의 int형 값을 알맞은 도시의 이름(string)으로 변환해서 return
    public:
        hClim(int arrSize, int **arr, int start, int end, int *hArr);
        ~hClim();
        bool searching(); //Hill-Climing 알고리즘에 따라 극값에 해당하는 path를 찾는 함수 (path에 값을 입력, Local Maximum일 경우 false값 return)
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
    int step = 1; //debug
    bool firstTry = true;
    int numTmp = -1;
    int costTmp;
    pathTmp = queue<int>();
    path = queue<int>();
    pathTmp.push(start);
    cout<<"[Step "<<step<<"]\n -Path: "<<qtos(pathTmp)<<"\n -Cost: "<<cost(pathTmp)<<endl; //debug
    step++; //debug
    while(true){
        for(int i = 0;i < arrSize;i++){
            if(arr[pathTmp.back()][i]!=0&&!reVisit(i)){
                if(firstTry){
                    costTmp = cost(pathTmp)+arr[pathTmp.back()][i]+hArr[i];
                    numTmp = i;
                    firstTry = false;
                }
                else if(costTmp > cost(pathTmp)+arr[pathTmp.back()][i]+hArr[i]){
                    costTmp = cost(pathTmp)+arr[pathTmp.back()][i]+hArr[i];
                    numTmp = i;
                }
            }
        }
        if(numTmp == -1){
            cout<<"[Error]\n -Local Maximum"<<endl; //debug
            return false;
        }
        else if(numTmp == end){
            path = pathTmp;
            path.push(numTmp);
            cout<<"[Last Step "<<step<<"]\n -Path: "<<qtos(path)<<"\n -Cost: "<<cost(path)<<"\n"<<endl; //debug
            return true;
        }
        else{
            pathTmp.push(numTmp);
            cout<<"[Step "<<step<<"]\n -Path: "<<qtos(pathTmp)<<"\n -Cost: "<<cost(pathTmp)<<endl; //debug
            firstTry = true;
            numTmp = -1;
        }
        step++; //debug
    }
}

bool hClim::reVisit(int n){
    queue<int> tmp = pathTmp;
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

string hClim::ntoc(int n){ //debug
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
