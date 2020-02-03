//There are 𝑛 passengers 1,2,…,𝑛. The passenger 𝑖 want to travel from point 𝑖 to point 𝑖+𝑛(𝑖=1,2,…,𝑛). There is a taxi located at point 0 for transporting the passengers. Given the distance matrix 𝑐(2𝑛+1)∗(2𝑛+1) in which 𝑐(𝑖,𝑗) is the traveling distance from point 𝑖 to point 𝑗(𝑖,𝑗=0,1,…,2𝑛) Compute the shortest route for the taxi, serving 𝑛 passengers and coming back to point 0 such that at any moment, there are no more than one passenger in the taxi, and no point is visited more than once (except for point 0 , which can be visited up to twice).
//
//Input
//Line 1 contains 𝑛(1≤𝑛≤11).
//Line 𝑖+1(𝑖=1,2,…,2𝑛+1) contains the 𝑖𝑡ℎ line of the matrix 𝑐.
//
//Output
//Unique line contains the length of the shortest route.
//
//Example
//input
//2
//0 8 5 1 10
//5 0 9 3 5
//6 6 0 8 2
//2 6 3 0 7
//2 5 3 4 0
//output
//17

#include <iostream>
#define MAX 100
int n, d, dmin, cmin;
int c[MAX][MAX];
int x[MAX];
bool visited[MAX];
 
using namespace std;
 
void TRY(int k){
    for (int v=1; v<=n; v++) {
        if (!visited[v]) {
            x[k] = v;
            x[k+1] = v+n;
            visited[v] = true;
            visited[v+n] = true;
            d = d + c[x[k-1]][x[k]] + c[x[k]][x[k] + n];
            if (k==2*n-1) {
                if (d + c[x[k+1]][0] < dmin) {
                    dmin = d + c[x[k+1]][0];
                }
            }
            else{
                if( d + cmin *(n-k+1) < dmin)
                    TRY(k+2);
            }
            visited[v] = false;
            visited[v+n] = false;
            d = d - c[x[k-1]][x[k]] - c[x[k]][x[k] + n];
            
        }
    }
}
 
int main(){
    dmin = 100000;
    cmin = 100000;
    cin >> n;
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
