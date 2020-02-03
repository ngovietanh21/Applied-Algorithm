//  Tính số cây khung của đồ thị 2 x n dạng lưới
//  n <= 10^5
// intput: 2
// ouput: 4

// (1) - (3) - (5) - ... - (2*n-1)
//  |     |     |             |
//  |     |     |             |
// (2) - (4) - (6) - ... -  (2*n)

#include <iostream>
#define MAX_N 200002
#define MAX_M 300002
using namespace std;
 
int N,M;
 
int b[MAX_M];
int e[MAX_M];
int X[MAX_N];
 
int r[MAX_N];
int p[MAX_N];
int dem;

int f[MAX_N/2];
 
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
    cin >> N;
    M = 3*N-2;
    
    for(int i = 1;i<=2*N-2;i++){
        b[i] = i;
        e[i] = i+2;
    }
    
    for (int i = 1; i<=N; i++) {
        b[i+2*N-2] = 2*i-1;
        e[i+2*N-2] = 2*i;
    }
    
    N = 2*N;
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

void printSolution(){
    for (int i = 1; i<=N-1; i++) {
        cout << b[X[i]] << "-" << e[X[i]] << "|";
    }
    cout << endl;
}
 
void TRY(int k){
    for (int v = X[k-1]+1; v <= M; v++){
        if(check(v,k)){
            X[k] = v;
            
            if(k==N-1){
                //printSolution();
                dem = dem + 1;
            }
            else
                TRY(k+1);
        }
    }
}

void dynamic(){
    N = N/2;
    f[1] = 1;
    f[2] = 4;
    for(int i=3;i<=N;i++){
        f[i] = f[i-1] * 4 - f[i-2];
    }
    cout << f[N];
}
 
int main(){
    Input();
    //TRY(1);
    //cout << dem << endl;
    dynamic();
    return 0;
}
