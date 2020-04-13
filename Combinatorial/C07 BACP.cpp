//
//The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced . There are 𝑁 courses 1,2,…,𝑁 that must be assigned to 𝑀 periods 1,2,…,𝑀. Each courses 𝑖 has credit 𝑐𝑖 and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period. The prerequisites information is represented by a matrix 𝐴𝑁×𝑁 in which 𝐴𝑖,𝑗 = 1 indicates that courses 𝑖 must be assigned to a period before the period to which the course 𝑗 is assigned. Compute the assignment such that the maximum load for all periods is minimal.
//
//Input
//Line 1 contains 𝑁 and 𝑀 (2≤𝑁≤16,2≤𝑀≤5)
//Line 2 contains 𝑐1,𝑐2,…,𝑐𝑁
//Line 𝑖+2(𝑖=1,…,𝑁) contains the 𝑖𝑡ℎ line of the matrix 𝐴
//
//Output
//Unique line contains that maximum load for all periods of the solution found
//
//Example
//input
// 6 2
// 4 4 4 4 2 4
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 1 0 0 0
// 0 0 1 0 0 0
// 1 0 0 0 0 0
//output
//12


#include <iostream>
#define MAX_N 20
#define MAX_M 8
 
// input data
int n, m;
int c[MAX_N];
int A[MAX_N][MAX_N];
 
//variables
int x[MAX_N]; //kì mà môn i phải học
int load[MAX_M]; // tải của kì i;
int f_best;
 
using namespace std;
 
int check(int v, int k){
    for(int i =1; i<=k-1;i++){
        if (A[i][k]==1){
            if (x[i] >= v) return 0;
        } else if (A[k][i] == 1){
            if (v >= x[i]) return 0;
        }
    }
    return 1;
}
 
void solution(){
    int max =0;
    for(int i =1; i<=m;i++){
        if (max < load[i]) max = load[i];
    }
    if (max < f_best)
        f_best = max;
}
 
 
void TRY(int k){
    for(int v=1;v<=m;v++){
        if(check(v,k)){
            x[k] = v;
            load[v] += c[k];
            if(k==n) solution();
            else TRY(k+1);
            load[v] -=c[k];
        }
    }
}
 
void Input(){
    cin >> n >> m;
    
    for(int i =1; i<=n;i++){
        cin >> c[i];
    }
    
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }
}
 
void Solve(){
    f_best = 1000000;
    TRY(1);
    cout << f_best;
}
 
int main(){
    Input();
    Solve();
    return 0;
}
