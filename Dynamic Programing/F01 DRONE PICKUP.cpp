//
//A Drone is planned to fly from point 1 to point 𝑁 in which it can stop at some points among 1,2,…,𝑁. These points are located on a line, point 𝑖 has coordinate 𝑖. Each point 𝑖 is associated with 𝑐𝑖: amount of good 𝑎𝑖: amount of energy. When the drone stops at point 𝑖 , it takes the amount 𝑐𝑖 of good and the amount 𝑎𝑖 of energy. After that, it can fly farthest to point 𝑖+𝑎𝑖 (it can stops at some point among 𝑖+1,𝑖+2,…,𝑖+𝑎𝑖). Due to technical constraints, the Drone can only stop at at most 𝐾+1 point. Compute the route (sequence of points at which the drone stops to take goods and energy) starting from point 1 and terminating at point 𝑁 such that the total amount of goods is maximal (points 1 and 𝑁 are considered as points that the Drone stop).
//Input
//Line 1: 𝑁 and 𝐾 (1≤𝑁≤3000,1≤𝐾≤100)
//Line 2: 𝑁 positive integers 𝑐1,𝑐2,…,𝑐𝑁 (1≤𝑐𝑖≤20,∀𝑖=1,…,𝑁)
//Line 3: 𝑁 positive integers 𝑎1,𝑎2,…,𝑎𝑁 (1≤𝑎𝑖≤50,∀𝑖=1,…,𝑁)
//
//Output
//Total amount of goods that the Drone takes during the route, or value -1 if no route exists.
//
//Example
//input
//6 3
//3 1 4 2 2 2
//2 3 1 1 3 1
//output
//8

#include <iostream>
#define MAXN 3002
#define MAXK 102
using namespace std;
 
int n, k;
int a[MAXN], c[MAXN];
int L[MAXK][MAXN];
 
 
void Solve(){
    L[1][1] = c[1];
    for(int i = 2; i<=n; i++){
        if ( i <= 1 + a[1])
            L[1][i] = c[1] + c[i];
    }
    
    for(int i =2; i<=k; i++){
        for(int j =2; j<=n; j++){
            
            int max = 0;
            for(int p=1; p<j;p++){
                if (a[p] + p >= j && L[i-1][p] !=0){
                    if (max < L[i-1][p] + c[j]){
                        max = L[i-1][p] + c[j];
                    }
                }
            }
            L[i][j] = max;
        }
    }
    
    /*for(int i =1; i<=k;i++){
        for(int j =1; j<=n;j++){
            cout << L[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << L[k][n];
    
}
 
void Input(){
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        cin >> c[i];
    }
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
}
 
int main() {
    Input();
    Solve();
    
    return 0;
}
