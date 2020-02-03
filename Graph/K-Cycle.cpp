#include <iostream>
#include <vector>
#define MAXN 35
#define MAXK 20
 
using namespace std;
 
vector<int> A[MAXN];
bool visited[MAXN];
int n,m,k;
 
int dem;
int X[MAXK];
 
void Input(){
    cin >> n >> m >> k;
    for(int i = 0; i<m;i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
 
bool Solution(int u, int v){
    for(int i : A[u]){
        if (i==v) return true;
    }
    return false;
}
 
void Try(int i){
    for(int v : A[X[i-1]]){
        if (!visited[v] && v > X[1]){
            X[i] = v;
            visited[v] = true;
            if (i==k){
                if(Solution(X[k],X[1]))
                   dem = dem + 1;
            }
            else Try(i+1);
            visited[v] = false;
            
        }
    }
}
 
void Solve(){
    dem = 0;
    for (int i = 1; i<=n-k+1; i++) {
        X[1] = i;
        visited[i] = true;
        Try(2);
        visited[i] = false;
    }
    //Chia cho 2 boi vi do thi vo huong, 1 2 3 4 1 va 1 4 3 2 1 la mot nen se chia 2
    cout << dem/2;
}

int main(){
    Input();
    Solve();
    return 0;
}
