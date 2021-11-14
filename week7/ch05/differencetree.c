#include<stdio.h>
int numTrees(int n) {
    int G[n + 1];
    memset(G, 0, sizeof(G));   //给数组进行初始化
    G[0] = G[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}
