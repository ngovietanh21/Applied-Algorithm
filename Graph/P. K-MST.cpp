//Given a undirected graph 𝐺=(𝑉,𝐸), in which 𝑉={1,…,𝑁} is the set of nodes and 𝐺 has 𝑀 edges, 𝑤(𝑒) is the weight of the edge 𝑒 (𝑒∈𝐸). Given a positive integer 𝐾, find the subgraph of 𝐺 which is a tree containing exactly 𝐾 edges having minimal weight.
//
//Input
//Line 1 contains 𝑁, 𝑀, and 𝐾 (1≤𝑁≤20,1≤𝑀≤30,1≤𝐾≤15)
//Line 𝑖+1 (𝑖=1,…,𝑀) contains 𝑢, 𝑣, and 𝑤 in which 𝑤 is the weight of the edge (𝑢,𝑣)
//Output
//Write the weight of the tree found, or write -1 if no such tree exists.
//
//Example
//inputCopy
//5 7 3
//1 2 4
//1 3 3
//1 4 1
//2 3 2
//2 5 6
//3 4 5
//3 5 5
//outputCopy
//6

#include <iostream>
#define MAX_N 25
#define MAX_M 35
using namespace std;
 
int N,M,K;
 
int b[MAX_M];
int e[MAX_M];
int w[MAX_M];
int X[MAX_N];
 
int r[MAX_N]; //rank of node i
int p[MAX_N]; //parent of node i
int d , dmin;
 
void makeSet() {
    for (int i=1; i<=N; i++) {
        p[i] = i;
        r[i] = 0;
    }
}
 
int Root(int x){
    if (p[x] != x)
        p[x] = Root(p[x]);
    return p[x];
}
 
void Join(int u, int v) {
    u = Root(u);
    v = Root(v);
    if (u == v) return;
    if (r[u] == r[v]) r[u]++;
    if (r[u] < r[v]) p[u] = v;
    else p[v] = u;
}
 
void Input(){
    d = 0;
    dmin = INT_MAX;
    cin >> N >> M >> K;
    for(int i = 1;i<=M;i++){
        int u,v,we;
        cin >> u >> v >> we;
        b[i] = u;
        e[i] = v;
        w[i] = we;
    }
}
bool check(int val, int k){
    //check if set edge inculde a cycle
    makeSet();
    for (int i = 1; i<k; i++) {
        int u = b[X[i]];
        int v = e[X[i]];
        int ru = Root(u);
        int rv = Root(v);
        if (ru == rv) return false; // u and v belong to the same Set -> creating the cycle
        Join(ru, rv);
    }
    if (Root(b[val]) == Root(e[val])) {
        return false;
    }
    return true;
}
 
void solution(){
    d =0;
    for (int i = 1; i<=K; i++) {
        d += w[X[i]];
    }
    if (d<dmin) {
        dmin = d;
    }
}
 
void TRY(int k){
    for (int v = X[k-1]+1; v <= M; v++){
        if(check(v,k)){
            X[k] = v;
            d += w[v];
            if(k==K)
                solution();
            else{
                TRY(k+1);
            }
        }
    }
}
 
int main(){
    Input();
    TRY(1);
    cout << dmin;
    return 0;
}
