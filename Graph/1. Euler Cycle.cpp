#include <iostream>
#include <set>
#include <stack>
#define MAX 100003
 
using namespace std;

int n, m;
set<int> A[MAX];

void Input(){
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        A[u].insert(v);
        A[v].insert(u);
    }
}

void PrintGraph(){
    for (int v =1; v<=n;v++){
        cout << "A[" << v << "] ";
        for (set<int>::iterator it = A[v].begin(); it!=A[v].end(); it++) {
            cout << *it <<" ";
        }
        cout << endl;
    }
}

void FindEulerCycle(){
    stack<int> S;
    stack<int> CE;
    
    S.push(1);
    while (!S.empty()) {
        int x = S.top();
        if (!A[x].empty()) {
            int y = *A[x].begin();
            S.push(y);
            A[x].erase(y);
            A[y].erase(x);
        }
        else {
            S.pop();
            CE.push(x);
        }
    }
    
    cout << "Euler Path" << endl;
    while (!CE.empty()) {
        int x = CE.top();
        CE.pop();
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    Input();
    PrintGraph();
    FindEulerCycle();
    
    return 0;
}
