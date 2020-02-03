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
