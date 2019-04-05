#ifndef BFSEARCH_H
#define BFSEARCH_H
#include<queue>
#include<stack>
class bfSearch{
    private:
        int bfArrX;
        int bfArrY;
        int **bfArr;
        int start;
        int end;
        queue<int> open;
        stack<int> closed;
    public:
        bfSearch(int bfArrX, int bfArrY, int **bfArr, int start, int end);
        ~bfSearch();
        string searching();
};
#endif
