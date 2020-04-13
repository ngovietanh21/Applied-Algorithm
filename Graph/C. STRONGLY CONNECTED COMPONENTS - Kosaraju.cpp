//Given a directed graph 𝐺=(𝑉,𝐸) where 𝑉={1,…,𝑁} is the number of nodes and the set 𝐸 has 𝑀 arcs. Compute number of strongly connected components of 𝐺
//Input
//Line 1: two positive integers 𝑁 and 𝑀 (1≤𝑁≤105,1≤𝑀≤106)
//Lline 𝑖+1 (𝑖=1,…,𝑀): contains two positive integers 𝑢 and 𝑣 which are endpoints of 𝑖𝑡ℎ arc
//Output
//Write the number of strongly connected components of 𝐺
//Example
//inputCopy
//8 13
//1 2
//1 8
//2 3
//2 6
//3 6
//4 3
//4 6
//5 4
//6 5
//7 1
//7 2
//7 6
//8 7
//outputCopy
//3

#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000003

using namespace std;

vector<int> G[MAX], rG[MAX];
stack<int> S;
bool visited[MAX];
int n,m,scc;

void Input(){
    scc = 0;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
        
    }
}

void Init(){
    for(int i = 1; i<=n; i++){
        visited[i] = false;
    }
}

void SecondDFS(int u){
    visited[u] = true;
    for(int i = 0; i<rG[u].size();i++){
        if (!visited[rG[u][i]])
            SecondDFS(rG[u][i]);
    }
}

void FirstDFS(int u){
    visited[u] = true;
    for(int i = 0; i<G[u].size();i++){
        if (!visited[G[u][i]])
            FirstDFS(G[u][i]);
    }
    S.push(u);
}

void Solve(){
    Init();
    for(int i = 1; i<=n; i++){
        if(!visited[i])
            FirstDFS(i);
    }
    
    Init();
    
    while (!S.empty()) {
        int u = S.top();
        S.pop();
        if (!visited[u]) {
            scc +=1;
            SecondDFS(u);
        }
    }
    cout << scc;
}


int main(){
    Input();
    Solve();
    return 0;
}
