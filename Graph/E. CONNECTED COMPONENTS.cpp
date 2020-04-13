//Given a undirected graph 𝐺=(𝑉,𝐸) where 𝑉={1,…,𝑁} is the number of nodes and the set 𝐸 has 𝑀 edges. Compute number of connected components of 𝐺.
//
//Input
//Line 1: two positive integers 𝑁 and 𝑀 (1≤𝑁≤105,1≤𝑀≤105)
//Lline 𝑖+1 (𝑖=1,…,𝑀): contains two positive integers 𝑢 and 𝑣 which are endpoints of 𝑖𝑡ℎ edge
//Output
//Write the number of connected components of 𝐺.
//
//Example
//inputCopy
//8 8
//1 2
//1 7
//1 8
//2 7
//4 5
//4 6
//5 6
//7 8
//outputCopy
//3

#include <iostream>
#include <vector>
#define MAX 100003 //MAX so dinh, la n
 
using namespace std;
 
int n, m; // n đỉnh và m cạnh
vector<int> A[MAX]; // A[v] là đỉnh kề với v
 
//data structures for DFS
int p[MAX]; // đỉnh trước đỉnh u
bool visited[MAX];
 
int dem;
 
void DFS(int u){
    visited[u] = true;
    for(int i = 0; i<A[u].size();i++){
        int v = A[u][i];
        if (!visited[v]){
            DFS(v);
        }
    }
}
 
void DFS(){
    dem = 0;
    for(int v=1;v<=n;v++){
        if (!visited[v]){
            dem = dem + 1;
            DFS(v);
        }
    }
}
 
void input(){
    cin >> n >> m;
    for(int i =1; i<=m;i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
 
 
int main(){
    input();
    DFS();
    cout << dem;
    return 0;
}
