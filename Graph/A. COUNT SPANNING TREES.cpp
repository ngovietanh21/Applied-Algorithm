//Given a undirected connected graph 𝐺=(𝑉,𝐸) in which 𝑉={1,…,𝑁} is the set of nodes and 𝐸 is the set of 𝑀 edges. Count the number of spanning trees of 𝐺.
//
//Input
//Line 1: contains positive integers 𝑁 and 𝑀 (1≤𝑁≤20,1≤𝑀≤25)
//Line 𝑖+1 (𝑖=1,…,𝑀): contains 𝑢 and 𝑣 which are endpoints of the 𝑖𝑡ℎ edge of 𝐺
//Output
//Write the number of spanning trees of G
//
//Example
//inputCopy
//4 5
//1 2
//1 3
//1 4
//2 3
//3 4
//outputCopy
//8

#include <iostream>
#define MAX_N 25
#define MAX_M 30
using namespace std;
 
int N,M;
 
int b[MAX_M];
int e[MAX_M];
int X[MAX_N];
 
int r[MAX_N];
int p[MAX_N];
int dem;
 
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
    dem = 0;
    cin >> N >> M;
    for(int i = 1;i<=M;i++){
        int u,v;
        cin >> u >> v;
        b[i] = u;
        e[i] = v;
    }
}
bool check(int val, int k){
    makeSet();
    for (int i = 1; i<k; i++) {
        int u = b[X[i]];
        int v = e[X[i]];
        int ru = Root(u);
        int rv = Root(v);
        if (ru == rv) {
            return false;
        }
        Join(ru, rv);
    }
    if (Root(b[val]) == Root(e[val])) {
        return false;
    }
    return true;
}
 
void TRY(int k){
    for (int v = X[k-1]+1; v <= M; v++){
        if(check(v,k)){
            X[k] = v;
            
            if(k==N-1){
                dem = dem + 1;
            }
                
            
            else
                TRY(k+1);
        }
    }
}
 
int main(){
    Input();
    TRY(1);
    cout << dem;
    return 0;
}
