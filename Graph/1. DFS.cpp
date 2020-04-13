#include <iostream>
#include <vector>
#define MAX 10000 //MAX so dinh, la n
 
using namespace std;

int n, m; // n đỉnh và m cạnh
vector<int> A[MAX]; // A[v] là đỉnh kề với v

//data structures for DFS
int d[MAX];// khoảng thời gian bắt đầu duyệt đỉnh u
int f[MAX]; // khoảng thời gian duyệt xong đỉnh u
int p[MAX]; // đỉnh trước đỉnh u
char color[MAX];
int t;

void DFS(int u){
    t = t + 1;
    d[u] = t;
    color[u] = 'G';
    for(int i = 0; i<A[u].size();i++){
        int v= A[u][i];
        if (color[v] == 'W'){
            p[v] = u;
            DFS(v);
        }
    }
    t = t +1;
    f[u] = t;
    color[u] = 'B';
}

void DFS(){
    for (int v = 1; v<=n;v++){
        color[v] = 'W';
    }
    t=0;
    for(int v=1;v<=n;v++){
        if (color[v] == 'W'){
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
    }
}

void printGraph(){
    for(int v=1; v<=n;v++){
        cout << "A[" << v << "] = ";
        for(int i = 0; i<A[v].size();i++){
            cout << A[v][i] << " ";
        }
        cout << endl;
    }
}

void printArray(int A[], int n){
    for(int i =1 ; i<=n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    input();
    printGraph();
    DFS();
    printArray(d, n);
    printArray(f, n);
    printArray(p, n);
    return 0;
}
