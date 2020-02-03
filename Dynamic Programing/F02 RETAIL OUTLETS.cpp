//A distribution company distribute goods to 𝑀 retail outlets 1,2,…,𝑀. It has 𝑁 branches 1,2,...,𝑁. Each branch 𝑖 has 𝑎𝑖 salesman. The company have to assign 𝑀 retail outlets to 𝑁 branches: each branch is responsible to distribute goods to some retail outlets, each retail outlet is distributed by one branch. In order to balance among salesman, the number of retail outlets assigned to each branch 𝑖 must be positive and divisible by 𝑎𝑖. Compute the total number 𝑄 of ways of such assignment.
//
//Example, 𝑁 = 2, 𝑀 = 20, 𝑎1 = 3, 𝑎2 = 2. There are 3 ways:
//
//Branch 1 is assigned to 6 retail outlets, branch 2 is assigned to 14 retail outlets
//Branch 1 is assigned to 12 retail outlets, branch 2 is assigned to 8 retail outlets
//Branch 1 is assigned to 18 retail outlets, branch 2 is assigned to 2 retail outlets
//
//Input
//Line 1: 𝑁 and 𝑀 (1≤𝑁≤100,1≤𝑀≤500)
//Line 2: 𝑁 positive integers 𝑎1,…,𝑎𝑁 (1≤𝑎𝑖≤10,𝑖=1,…,𝑁)
//
//Output
//Write the value 𝑄 modulo (10^9+7)

#include <iostream>
#define MAXN 102
#define MAXM 502
#define MOD 1000000007
using namespace std;
 
int N, M;
int a[MAXN];
int F[MAXN][MAXM];
 
 
void Solve(){
    //f[n,M] = f[n-1,M-a[n]] + f[n-1 , M-2a[n]]  +  ...
    for (int i = 1; i <= N; i++) {
        F[i][0] = 1;
        for (int j = 1; j <= M; j++) {
        int x = (j - a[i] >= 0) ? F[i][j - a[i]] : 0;
            F[i][j] = (x + F[i - 1][j]) % MOD;
                        //cout<<F[i][j]<<" ";
        }
                //cout<<"\n";
    }
    
    cout << F[N][M];
}
 
void Input(){
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> a[i];
        M -= a[i];
    }
}
 
int main() {
    Input();
    Solve();
    
    return 0;
}
