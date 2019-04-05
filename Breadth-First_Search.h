#ifndef BFSEARCH_H
#define BFSEARCH_H
class bfSearch{
    private:
        int bfArrX;
        int bfArrY;
        int **bfArr;
        int start;
        int end;
    public:
        bfSearch(int bfArrX, int bfArrY, int **bfArr, int start, int end);
        ~bfSearch();
        string searching();
};
#endif
