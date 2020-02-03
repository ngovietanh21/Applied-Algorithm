//The Kingdom ALPHA has 𝑛 warehouses of golds located on a straight line and are numbered 1,2,...,𝑛. The warehouse i has amount of 𝑎𝑖 (𝑎𝑖 is non-negative integer) and is located at coordinate 𝑖 (𝑖=1,...,𝑛). The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds with respect to the condition that the distance between two selected warehouses must be greater than or equal to 𝐿1 and less than or equal to 𝐿2.
//
//Input
//Line 1 contains 𝑛, 𝐿1 and 𝐿2 (1≤𝑛≤100000,1≤𝐿1≤𝐿2≤𝑛)
//Line 2 contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛
//
//Output
//Contains only one single integer denoting the total amount of golds of selected warehouses.
//
//Example
//input
//6 2 3
//3 5 9 6 7 4
//output
//19


#include <iostream>
#include <algorithm>
#define MAX 100002
 
using namespace std;
int n, l1, l2, maxi;
int A[MAX];
int S[MAX];
 
int main(){
    cin >> n >> l1 >> l2;
    for(int i =0;i<n;i++){
        cin >> A[i];
    }
    
    for(int i=0; i<n;i++){
        maxi = A[i];
        for(int j = i-l2; j<=i-l1;j++){
            if (j>=0){
                maxi = max(S[j] + A[i], maxi);
            }
        }
        S[i] = maxi;
    }
    cout << *max_element(S, S+n);
    return 0;
}
