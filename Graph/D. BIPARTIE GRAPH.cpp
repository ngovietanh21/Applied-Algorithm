//Given a undirected graph 𝐺=(𝑉,𝐸) in which 𝑉={1,…,𝑁} is the set of nodes and |𝐸|=𝑀. You are required to write a program to check if 𝐺 is a bipartie graph.
//
//Input
//Line 1 𝑁 and 𝑀 (1≤𝑁,𝑀≤105)
//Line 𝑖+1 (𝑖=1,…,𝑀): 𝑢 and 𝑣 which are endpoints of the 𝑖𝑡ℎ edge
//Output
//Write 1 if 𝐺 is a bipartie graph and 0, otherwise.
//
//Example
//inputCopy
//6 6
//1 2
//1 3
//2 5
//2 6
//4 5
//4 6
//outputCopy
//1

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100003
 
using namespace std;
 
vector<int> A[MAX];
int d[MAX];
int n,m;
 
void Input(){
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
        
    }
}
 
void PrintGraph(){
    for(int i = 1; i<=n; i++){
        cout << "A[" << i << "] ";
        for(int j = 0; j<A[i].size(); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
 
void Init(){
    for (int i = 1; i<=n; i++) {
        d[i] = -1;
    }
}
 
void BFS(int u){
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for(int x  : A[v]){
            if (d[x] == -1) {
                d[x] = d[v] + 1;
                Q.push(x);
            }
            else {
                if (d[x]%2 == d[v]%2){
                    cout << 0;
                    return;
                }
            }
        }
    }
    cout << 1;
}
 
 
int main(){
    Input();
    Init();
    BFS(1);
    return 0;
}
