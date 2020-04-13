//Given a undirected connected graph 𝐺=(𝑉,𝐸) where 𝑉={1,…,𝑁}. Each edge (𝑢,𝑣)∈𝐸 has weight 𝑤(𝑢,𝑣). Compute minimum spanning tree of 𝐺.
//
//Input
//Line 1: 𝑁 and 𝑀 (1≤𝑁,𝑀≤105) in which 𝑁 is the number of nodes and 𝑀 is the number of edges.
//Line 𝑖+1 (𝑖=1,…,𝑀): contains 3 positive integers 𝑢, 𝑣, and 𝑤 where 𝑤 is the weight of edge (𝑢,𝑣)
//Output
//Write the weight of the minimum spanning tree found.
//
//Example
//inputCopy
//5 8
//1 2 1
//1 3 4
//1 5 1
//2 4 2
//2 5 1
//3 4 3
//3 5 3
//4 5 2
//outputCopy
//7

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100005
using namespace std;
 
int n,m;
int r[MAX];
pair<long long, pair<int, int>> A[MAX];
 
int Root(int x){
    if (r[x] != x)
        r[x] = Root(r[x]);
    return r[x];
}
 
void Join(int u, int v) {
    u = Root(u);
    v = Root(v);
    r[u] = r[v];
}
 
void Init(){
    for (int i = 1; i<=n; i++) {
        r[i] = i;
    }
}
 
void Input(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        A[i] = make_pair(w, make_pair(u, v));
    }
    sort(A,A+m);
}
 
long long Kruskal(){
    int u,v;
    long long w;
    long long minCost = 0;
    
    for (int i = 0; i<m; i++) {
        u = A[i].second.first;
        v = A[i].second.second;
        w = A[i].first;
        if (Root(u) != Root(v)) {
            minCost += w;
            Join(u, v);
        }
    }
    
    return minCost;
}
 
int main(){
    Input();
    Init();
    cout << Kruskal();
    return 0;
}
