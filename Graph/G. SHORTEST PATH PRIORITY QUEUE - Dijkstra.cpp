//Given a directed graph 𝐺=(𝑉,𝐴) where 𝑉={1,…,𝑛} is the set of nodes. Each arc (𝑢,𝑣)∈𝐴 has weight 𝑤(𝑢,𝑣). Given 𝑠,𝑡∈𝑉, compute the shortest path from 𝑠 to 𝑡.
//
//Input
//Line 1: 𝑛 and 𝑚 (1≤𝑛≤105,1≤𝑚≤106)
//Line 𝑖+1 (𝑖=1,…,𝑚): positive integers 𝑢, 𝑣, and 𝑤 in which 𝑤 is the weight of arc (𝑢,𝑣)
//Line m+2: 𝑠, 𝑡
//Output
//Write the weight of the shortest path found or -1 if no path from 𝑠 to 𝑡 exists.
//
//Example
//inputCopy
//5 7
//2 5 87
//1 2 97
//4 5 78
//3 1 72
//1 4 19
//2 3 63
//5 1 18
//1 5
//outputCopy
//97

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100003
 
using namespace std;
 
vector<pair<int, int>> A[MAX];
int d[MAX];
int p[MAX];
bool visited[MAX];
int n,m,s,t;
int dmax;
 
struct pri
{
    int operator() (const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
};
 
void Input(){
    cin >> n >>m;
    for(int i =0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(make_pair(v, w));
    }
    cin >> s >> t;
}
 
void Init(){
    for(int i = 1; i<=n; i++){
        d[i] = INT_MAX;
        visited[i]=false;
    }
}
 
void Dijkstra(int start){
    priority_queue<pair<int, int>,vector<pair<int, int>>,pri> Q;
    d[start] = 0;
    Q.push(make_pair(start, 0));
    
    while (!Q.empty()) {
        
        int u = Q.top().first;
        int du = Q.top().second;
        Q.pop();
        
        if (visited[u])
            continue;
        visited[u] = true;
        
        for(pair<int,int> i : A[u]){
            int v = i.first;
            int w = i.second;
            if (d[v] > du + w) {
                d[v] = du + w;
                p[v] = u;
                Q.push(make_pair(v, d[v]));
            }
        }
    }
    if (d[t] == INT_MAX)
        cout << "-1";
    else
        cout << d[t];
  
}
 
 
int main(){
    Input();
    Init();
    Dijkstra(s);
    return 0;
}
