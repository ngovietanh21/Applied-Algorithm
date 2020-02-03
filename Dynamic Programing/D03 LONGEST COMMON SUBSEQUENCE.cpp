//A subsequence of a given sequence 𝑠=𝑠1,…,𝑠𝑛 is obtained by removing some elements from 𝑠. Given two sequence of integers 𝑋=(𝑋1,…,𝑋𝑛) and 𝑌=(𝑌1,…,𝑌𝑚). Find the longest common subsequence of 𝑋 and 𝑌.
//
//Input
//Line 1 contains 𝑛 and 𝑚 (1≤𝑛,𝑚≤104)
//Line 2 contains 𝑋1,…,𝑋𝑛
//Line 3 contains 𝑌1,…,𝑌𝑚
//
//Output
//Write the length of the longest subsequence of the given sequences
//
//Example
//input
//7 10
//3 7 2 5 1 4 9
//4 3 2 3 6 1 5 4 9 7
//output
//5


#include <iostream>
#define MAX 10002
 
using namespace std;
 
int X[MAX], Y[MAX], n,m;
int L[MAX][MAX];
 
int LCS(int a, int b){
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[a][b];
}
 
int main(){
    cin >> n >> m;
    for(int i =0; i<n;i++){
        cin >> X[i];
    }
    for(int i =0; i<m;i++){
        cin >> Y[i];
    }
    cout << LCS(n,m);
    return 0;
}
