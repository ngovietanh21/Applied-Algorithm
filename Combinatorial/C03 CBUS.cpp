//There are 𝑛 passengers 1,2,…,𝑛. The passenger 𝑖 want to travel from point 𝑖 to point 𝑖+𝑛(𝑖=1,2,…,𝑛). There is a bus located at point 0 and has 𝑘 places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which 𝑐(𝑖,𝑗) is the traveling distance from point 𝑖 to point 𝑗(𝑖,𝑗=0,1,…,2𝑛) . Compute the shortest route for the bus, serving 𝑛 passengers and coming back to point 0 without visiting any point more than once (except for the point 0).
//
//Input
//Line 1 contains 𝑛 and 𝑘(1≤𝑛≤11,1≤𝑘≤10).
//Line 𝑖+1(𝑖=1,2,…,2𝑛+1)contains the (𝑖−1)𝑡ℎ line of the matrix 𝑐 (rows and columns are indexed from 0,1,2,..,2𝑛)
//
//Output
//Unique line contains the length of the shortest route.
//
//Example
//input
//3 2
//0 8 5 1 10 5 9
//9 0 5 6 6 2 8
//2 2 0 3 8 7 2
//5 3 4 0 3 2 7
//9 6 8 7 0 9 10
//3 8 10 6 5 0 2
//3 4 4 5 2 2 0
//output
//25


#include <iostream>
#define MAX 100
int n, d, dmin, cmin;
int cap; // số lượng người cao nhất có thể chở
int load; // biến để lưu số lượng chở người
int c[2*MAX+1][2*MAX+1];
int x[MAX];
bool visited[MAX];
 
using namespace std;
 
int check(int v, int k){
    if (visited[v]) return 0;
    
    if (v>n){
        if (!visited[v-n]) return 0;
    }else{
        if (load + 1 > cap) return 0;
    }
    return 1;
}
 
void solution(){
    if (d + c[x[2*n]][0] < dmin){
        dmin = d + c[x[2*n]][0];
    }
}
 
void TRY(int k){
    for(int v = 1; v<=2*n; v++){
        if (check(v,k)){
            x[k] = v;
            d += c[x[k-1]][x[k]];
            if (v<=n) load++; else load--;
            visited[v] = true;
            if (k == 2*n) solution();
            else{
                if (d + cmin * (2*n-k+1) < dmin)
                    TRY(k+1);
            }
            d -= c[x[k-1]][x[k]];
            if (v<=n) load--; else load++;
            visited[v] = false;
        }
    }
}
 
int main(){
    dmin = 100000;
    cmin = 100000;
    cin >> n >> cap;
    for (int i=0; i<2*n+1; i++) {
        for (int j=0; j<2*n+1; j++) {
            cin >> c[i][j];
            if (i!=j && cmin > c[i][j])
                cmin = c[i][j];
        }
    }
    TRY(1);
    cout << dmin;
    return 0;
}
