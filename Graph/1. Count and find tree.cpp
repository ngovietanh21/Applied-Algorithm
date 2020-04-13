#include <iostream>
#include <vector>
#define MAX_N 20
#define MAX_M 30
using namespace std;
 
int N,M,K;
pair<pair<int,int>, int> G[MAX_M];
vector<int> A[MAX_N];
int X[MAX_N];
 
int r[MAX_N]; //rank
int p[MAX_N]; //parent
 
bool visited[MAX_N];
int curD, maxD, U;

 
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
 
void DFS(int s, int d){
    visited[s] = true;
    for (int v : A[s]){
        if (!visited[v]){
            curD = d + 1;
            if (maxD < curD) {
                maxD = curD;
                U = v;
                cout << " " << U ;
            }
            DFS(v, curD);
        }
        curD = 0;
    }
}

void makeTree(){
    
    for (int i = 1; i<=N; i++) {
        visited[i] = false;
    }
    
    for (int i = 1 ; i<=N-1; i++) {
        int u = G[X[i]].first.first;
        int v = G[X[i]].first.second;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

int calDiameter(){
    makeTree();
    
    curD = 0;
    maxD = INT_MIN;
    for (int i = 1; i<=N; i++) {
        if (!visited[i]) {
            DFS(i,0);
        }
    }
    
    cout << " | ";
    for (int i = 1; i<=N; i++) {
        visited[i] = false;
    }
    curD = 0;
    maxD = INT_MIN;
    DFS(U, 0);

    
    return maxD;
}

void makeSet() {
    for (int i=1; i<=N; i++) {
        p[i] = i;
        r[i] = 0;
    }
}

 
void Input(){
    cin >> N >> M >> K;
    for (int i = 1; i<=M; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        G[i] = make_pair(make_pair(u, v), w);
    }
}

bool check(int val, int k){
    makeSet();
    for (int i = 1; i<k; i++) {
        int u = G[X[i]].first.first;
        int v = G[X[i]].first.second;
        int ru = Root(u);
        int rv = Root(v);
        if (ru == rv) {
            return false;
        }
        Join(ru, rv);
    }
    if (Root(G[val].first.first) == Root(G[val].first.second)) {
        return false;
    }
    return true;
}

 
void TRY(int k){
    for (int v = X[k-1]+1; v <= M; v++){
        if(check(v,k)){
            X[k] = v;
            
            if(k==N-1){
                int w = 0;
                for (int i = 1; i<=N-1; i++) {
                    w += G[X[i]].second;
                    cout << "[ " << G[X[i]].first.first << " , " << G[X[i]].first.second<< " ] " ;
                }
               
                int wTree = calDiameter();
                cout << " w:" << wTree << " ";

                    cout << w;

                cout << endl;

//                if (wTree <=K) {
//                    cout << wTree;
//                    return;
//                }
            }
                
            else
                TRY(k+1);
        }
    }
}



int main(){
    Input();
    TRY(1);
    return 0;
}
