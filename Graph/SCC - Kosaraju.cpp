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
