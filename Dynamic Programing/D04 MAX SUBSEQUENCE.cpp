//
//Given an integers sequence 𝑎=(𝑎1,𝑎2,…,𝑎𝑛). A subsequence of 𝑎 is defined to be 𝑎𝑖,𝑎𝑖+1,…,𝑎𝑗. The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
//
//Input
//Line 1 contains 𝑛 (1≤𝑛≤106)
//Line 2 contains 𝑎1,…,𝑎𝑛 (−500≤𝑎𝑖≤500)
//
//Output
//Write the weight of the highest subsequence found.
//
//Example
//input
//10
//3 -1 -3 5 2 5 0 -1 5 4
//output
//20

#include <iostream>
#define MAX 1000002
 
using namespace std;
int n, S,Sbest;
int A[MAX];
 
int main(){
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> A[i];
    }
    S = A[0];
    Sbest = S;
    for(int i =1;i<n;i++){
        S += A[i];
        if (S < A[i]) S= A[i];
        if (Sbest < S) Sbest = S;
    }
    cout << Sbest;
    return 0;
}
