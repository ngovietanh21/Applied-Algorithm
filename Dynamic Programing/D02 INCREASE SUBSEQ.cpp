//Given a sequence of integers 𝑎1,…,𝑎𝑛. Compute the longest subsequence (elements are not necessarily continous) in which elements are in an increasing orders.
//
//Example
//input
//10
//7 2 3 7 5 4 2 1 9 6
//output
//4

#include <iostream>
#include<bits/stdc++.h> 
#define MAX 10003
 
using namespace std;
int n,k,kbest, m;
int A[MAX];
 
 
int main(){
    cin >> n;
    k =0;
    kbest =0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int lis[n];
    
    lis[0] = 1;
    
    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( A[i] > A[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    cout << *max_element(lis, lis+n);
    return 0;
}
