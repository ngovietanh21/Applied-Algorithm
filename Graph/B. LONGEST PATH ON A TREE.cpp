//Given a undirected tree 𝐺=(𝑉,𝐸) in which 𝑉={1,…,𝑁} is the set of nodes. Each edge (𝑢,𝑣)∈𝐸 has weight 𝑤(𝑢,𝑣). The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on 𝐺.
//
//Input
//Line 1: positive integer 𝑁 (1≤𝑁≤105)
//Line 𝑖+1 (𝑖=1,…,𝑁−1): positive integers 𝑢,𝑣,𝑤 in which 𝑤 is the weight of edge (𝑢,𝑣) (1 ≤ w ≤ 100)
//Output
//The weight of the longest path on the given tree
//
//Example
//inputCopy
//6
//1 3 3
//1 6 2
//2 6 5
//4 5 2
//4 6 1
//outputCopy
//10

#include <iostream>
#include <vector>
#define MAX 100003

using namespace std;

vector<pair<int, int>> A[MAX];
bool visited[MAX];
int n;
int curD, maxD, U;

void DFS(int s, int d){
    visited[s] = true;
    for (int i = 0; i<A[s].size(); i++){
        int v = A[s][i].first;
        if (!visited[v]){
            curD = d + A[s][i].second;
            if (maxD < curD) {
                maxD = curD;
                U = v;
            }
            DFS(v, curD);
        }
        curD = 0;
    }
}

void DFS(){
    for (int i = 1; i<=n; i++) {
        if (!visited[i]) {
            DFS(i,0);
        }
    }
    for (int i = 1; i<=n; i++) {
        visited[i] = false;
    }
    curD = 0;
    maxD = 0;
    DFS(U, 0);
}

void Input(){
    curD = 0;
    maxD = INT_MIN;
    cin >> n;
    for (int i = 1 ; i<=n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(make_pair(v, w));
        A[v].push_back(make_pair(u, w));
    }

}

void PrintGraph(){
    for (int i = 1; i<=n; i++) {
        cout << "A[" << i << "] ";
        for (int j = 0; j<A[i].size(); j++) {
            cout << A[i][j].first << "-" << A[i][j].second << " ";
        }
        cout << endl;
    }
}

int main(){
    Input();
    DFS();
    cout << maxD;
    return 0;
}


