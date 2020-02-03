//A truck is planned to arrive at some stations among 𝑁 stations 1,2,...,𝑁 located on a line. Station 𝑖 (𝑖=1,…,𝑁) has coordinate 𝑖 and has following information
// 𝑎𝑖: amount of goods
// 𝑡𝑖: pickup time duration for taking goods
//The route of the truck is a sequence of stations 𝑥1<𝑥2<...<𝑥𝑘 (1≤𝑥𝑗≤𝑁,𝑗=1,…,𝑘). Due to technical constraints, the distance between two consecutive stations that the truck arrives 𝑥𝑖 and 𝑥𝑖+1 is less than or equal to 𝐷 and the total pickup time duration cannot exceed 𝑇. Find a route for the truck such that total amount of goods picked up is maximal.
//
//Input
//Line 1: 𝑁,𝑇,𝐷 (1≤𝑁≤1000,1≤𝑇≤100,1≤𝐷≤10)
//Line 2: 𝑎1,…,𝑎𝑁(1≤𝑎𝑖≤10)
//Line 3: 𝑡1,…,𝑡𝑁(1≤𝑡𝑖≤10)
//
//Output
//Write the total amount of goods that the truck picks up in the route.
//
//Example
//input
//6 6 2
//6 8 5 10 11 6
//1 2 2 3 3 2
//output
//24

#include <iostream>
#define MAXN 1002
#define MAXT 102
using namespace std;
 
int N, T, D;
int a[MAXN], t[MAXN];
int W[MAXT][MAXN];
 
 
void Solve(){
    
    for(int i =1; i<=T; i++){
        for(int j =1; j<=N; j++){
            int p = i - t[j];
            if (p>=0) {
                int max = 0;
                for (int k = 1; k<=D; k++) {
                    if (j-k>0 && max < W[p][j-k]) {
                        max = W[p][j-k];
                    }
                }
                W[i][j] = max + a[j];
            } else {
                W[i][j] = 0;
            }
        }
    }
    
//    for(int i =1; i<=T;i++){
//        for(int j =1; j<=N;j++){
//            cout << W[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (max < W[T][i]) {
            max = W[T][i];
        }
    }
    cout << max;
    
}
 
void Input(){
    cin >> N >> T >> D;
    for(int i = 1; i<=N; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=N; i++){
        cin >> t[i];
    }
}
 
int main() {
    Input();
    Solve();
    
    return 0;
}
