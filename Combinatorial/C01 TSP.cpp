//A person departs from point 0. He want to visit points 1,2,…,𝑛, once and come back to 0. Given 𝑐(𝑖,𝑗) which is the traveling distance from point 𝑖 to point 𝑗(𝑖,𝑗=0,1,…,𝑛), help that person to compute the shortest route.
//
//Input
//Line 1 contains 𝑛(1≤𝑛≤15)
//Line 𝑖+1(𝑖=1,2,…,𝑛+1) contains the 𝑖𝑡ℎ line of the matrix 𝑐
//
//Output
//Unique line contains the length of the shortest route
//
//Example
//input
//3
//0 5 10 10
//6 0 2 9
//5 9 0 6
//1 7 4 0
//output
//14




#include <iostream>
#define MAX 100
int n, d, dmin, cmin;
int c[MAX][MAX];
int x[MAX];
bool visited[MAX];
 
using namespace std;
 
void TRY(int k){
    for (int v=1; v<=n; v++) {
        if(!visited[v]){
            x[k] = v;
            visited[v] = true;
            d += c[x[k-1]][x[k]];
            if (k == n){
                if (d + c[x[k]][0] < dmin)
                    dmin = d + c[x[k]][0];
            }
            else {
                if( d + cmin *(n-k+1) < dmin)
                    TRY(k+1);
            }
            d -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}
int main(){
    dmin = 100000;
    cmin = 100000;
    cin >> n;
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<n+1; j++) {
            cin >> c[i][j];
            if (i!=j && cmin > c[i][j])
                cmin = c[i][j];
        }
    }
    TRY(1);
    cout << dmin;
    return 0;
}
