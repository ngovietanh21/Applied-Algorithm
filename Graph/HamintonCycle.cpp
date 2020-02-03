#include <iostream>
#include <set>
#include <vector>
#define MAX 100003
 
using namespace std;

int n, m;
vector<int>A[MAX];
bool visited[MAX];
int X[MAX];

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
    for (int v =1; v<=n;v++){
        cout << "A[" << v << "] ";
        for (int i = 0; i<A[v].size() ;i++) {
            cout << A[v][i] <<" ";
        }
        cout << endl;
    }
}

bool check(int end, int start){
    for (int i = 0; i<A[start].size(); i++) {
        if (A[start][i] == end) {
            return true;
        }
    }
    return false;
}

void PrintCycle(){
    for (int i =1 ; i<=n; i++){
        cout << X[i] << " ";
    }
    cout << endl;
}


void FindHamilton(int k){
    for (int i = 0; i<A[X[k-1]].size(); i++) {
        int v = A[X[k-1]][i];
        if (!visited[v]) {
            X[k] = v;
            visited[v] = true;
            if (k==n){
                if (check(X[n],X[1])) {
                    PrintCycle();
                }
            }
            else FindHamilton(k+1);
            visited[v] = false;
        }
    }
}

int main(){
    Input();
    PrintGraph();
    X[1] = 1;
    FindHamilton(2);
    return 0;
}
