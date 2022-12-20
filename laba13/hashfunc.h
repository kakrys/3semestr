
#ifndef __HASHFUNC_H__
#define __HASHFUNC_H__
#include <iostream>

const int N = 18;
const int n = 15;

namespace hash
{
    int Hashfunc(int a);
    void HashTable(int mas[N][N], int a);
    void out(int mas[N][N]);
    int foundN(int y);
    void foundNubmers(int mas[N][N], int k);
}
#endif
