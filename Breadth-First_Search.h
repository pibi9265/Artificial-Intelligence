#ifndef BFSEARCH_H
#define BFSEARCH_H
class bfSearch{
    private:
        pair<string, int> *pArr;
        int pArrSize;
    public:
        bfSearch(pair<string, int> *pArr, int pArrSize);
        ~bfSearch();
        string searching();
};
#endif
