#include <iostream>
#include <string>
using namespace std;

#include "Breadth-First_Search.hpp"
#include "Depth-First_Search.hpp"
#include "Hill-Climing.hpp"
#include "Best-First_Search.hpp"

/*사용한 변수 List
    arrSize: 탐색할 도시의 갯수
    arr: 각 도시간의 cost을 저장한 int형 2중배열
    start: 시작점
    end: 도착지점
    hArr: 각 도시에서 목적지까지의 직선 거리를 저장한 int형 배열
*/

/*각 클래스 설명
    Breadth-First Search
    bfSearch(도시갯수(int형), 도시간의 cost(int형2중배열 포인터), 시작점(int형), 목적지(int형))
    bfSearch::searchingSP() 모든 트리를 너비 우선 탐색하여 Shortest Path를 찾아 과정과 결과 출력

    Depth-First Search
    dfSearch(도시갯수(int형), 도시간의 cost(int형2중배열 포인터), 시작점(int형), 목적지(int형))
    dfSearch::searchingSP() 모든 트리를 깊이 우선 탐색하여 Shortest Path를 찾아 과정과 결과 출력

    Hill-Climing
    hClim(도시갯수(int형), 도시간의cost(int형2중배열 포인터), 시작점(int형), 목적지(int형), 도시의직선거리(int형배열포인터))
    hClim::searching() Hill-Climing 알고리즘에 따라 극값에 해당하는 path를 찾아 과정과 결과 출력 (Local Maximum일 경우 false값 return)

    Best-First Search
    bFirst(도시갯수(int형), 도시간의cost(int형2중배열 포인터), 시작점(int형), 목적지(int형), 도시의직선거리(int형배열포인터))
    bFirst::searching() Best-First 알고리즘에 따라 path를 찾아 과정과 결과 출력
*/

int main(){
    int arrSize = 20;

    int **arr = new int *[arrSize];
    for(int i = 0;i < arrSize;i++){
        arr[i] = new int[arrSize];
    }
    for(int y = 0; y < arrSize;y++){
        for(int x = 0;x < arrSize;x++){
            arr[y][x] = 0;
        }
    }

    arr[0][14]=140;
    arr[0][15]=118;
    arr[0][19]=75;
    arr[1][18]=211;
    arr[1][5]=90;
    arr[1][12]=101;
    arr[1][16]=85;
    arr[2][3]=120;
    arr[2][12]=138;
    arr[2][13]=146;
    arr[3][9]=75;
    arr[4][6]=86;
    arr[6][16]=98;
    arr[7][10]=87;
    arr[7][17]=92;
    arr[8][9]=70;
    arr[8][15]=111;
    arr[11][19]=71;
    arr[11][14]=151;
    arr[12][13]=97;
    arr[13][14]=80;
    arr[14][18]=99;
    arr[16][17]=142;

    arr[14][0]=140;
    arr[15][0]=118;
    arr[19][0]=75;
    arr[18][1]=211;
    arr[5][1]=90;
    arr[12][1]=101;
    arr[16][1]=85;
    arr[3][2]=120;
    arr[12][2]=138;
    arr[13][2]=146;
    arr[9][3]=75;
    arr[6][4]=86;
    arr[16][6]=98;
    arr[10][7]=87;
    arr[17][7]=92;
    arr[9][8]=70;
    arr[15][8]=111;
    arr[19][11]=71;
    arr[14][11]=151;
    arr[13][12]=97;
    arr[14][13]=80;
    arr[18][14]=99;
    arr[17][16]=142;

    int start = 15;
    int end = 1;

    int *hArr = new int [arrSize];
    for(int i = 0;i < arrSize;i++){
        hArr[i] = 0;
    }

    hArr[0]=366;
    hArr[1]=0;
    hArr[2]=160;
    hArr[3]=242;
    hArr[4]=161;
    hArr[5]=77;
    hArr[6]=151;
    hArr[7]=226;
    hArr[8]=244;
    hArr[9]=241;
    hArr[10]=234;
    hArr[11]=380;
    hArr[12]=98;
    hArr[13]=193;
    hArr[14]=253;
    hArr[15]=329;
    hArr[16]=80;
    hArr[17]=199;
    hArr[18]=178;
    hArr[19]=374;

    cout << "Breadth-First Search" << endl;
    bfSearch bf(arrSize, arr, start, end);
    bf.searchingSP();

    cout << "Depth-First Search" << endl;
    dfSearch df(arrSize, arr, start, end);
    df.searchingSP();

    cout << "Hill-Climing" << endl;
    hClim hillCliming(arrSize, arr, start, end, hArr);
    hillCliming.searching();

    cout << "Best-First Search" << endl;
    bFirst bestFirst(arrSize, arr, start, end, hArr);
    bestFirst.searching();

    for(int i = 0;i < arrSize;i++){
        delete[] arr[i];
    }
    delete[] arr;

    delete[] hArr;

    return 0;
}
