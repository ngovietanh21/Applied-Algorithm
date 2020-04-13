//Given an undirected graph 𝐺=(𝑉,𝐸). A graph 𝐺′=(𝑉′,𝐸′) is called a subgraph of 𝐺 if 𝑉′⊆𝑉 and 𝐸′⊆𝐸. Find the subgraph 𝐶 of 𝐺 which is a complete graph and has maximal number of nodes.
//
//Input
//Line 1 𝑁 and 𝑀 (1≤𝑁≤12,1≤𝑀≤60)
//Line 𝑖+1 (𝑖=1,…,𝑀): 𝑢 and 𝑣 which are endpoints of the 𝑖𝑡ℎ edge
//Output
//Write the number of nodes of the complete subgraph 𝐶 found.
//
//Example
//inputCopy
//5 8
//1 2
//1 3
//2 3
//2 4
//2 5
//3 4
//3 5
//4 5
//outputCopy
//4

#include<iostream>
#include <algorithm>
int graph[16][16];
int res = 0;
 
using namespace std;
 
int check(int k,int start) {
    for(int i=start; i<=k+start-1; i++) {
        for(int j=i+1; j<=k+start-1; j++) {
            if(!graph[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
 
int counting(int n) {
    for(int k=n; k>=1; k--) {
        for(int start=1; start<=n-k+1; start++) {
            if(check(k,start)) {
                return k;
            }
        }
    }
}
int visit[16];
int x[16];
int checkAdd(int v,int n) {
    for(int i=0; i<n; i++) {
        if(!graph[v][x[i]]) {
            return 0;
        }
    }
    return 1;
}
 
void DFS(int n,int k,int v) {
    res = max(res, k);
    for(int i=1; i<=n; i++) {
        if(!visit[i] && checkAdd(i,k)) {
            x[k] = i;
            visit[i] = 1;
            DFS(n,k+1,i);
            visit[i] = 0;
        }
    }
}
 
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    //handle
    DFS(n,0,0);
    //show output
    cout<<res;
 
    return 0;
}
