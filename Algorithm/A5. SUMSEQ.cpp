//Given a sequence 𝑎1,𝑎2,…,𝑎𝑛. Compute 𝑆=𝑎1+𝑎2+…+𝑎𝑛.
//
//𝑛≤106,0≤𝑎𝑖≤109
//Input
//Line 1: number 𝑛 of elements
//Line 2: 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛
//Output
//Unique value 𝑆 mod (109+7)
//
//Example
//inputCopy
//3
//18663 2391 9035
//outputCopy
//30089

#include <iostream>
#define MAX 100
using namespace std;
const unsigned int M = 1000000007;
 
int main() {
    int n;
    cin >> n;
    unsigned long long A[n];
    unsigned long long Sum=0;
    for (int i=0; i<n; i++) {
        cin >> A[i];
        Sum +=A[i] % M;
    }
    cout << Sum%M;
    
    
    
    return 0;
}
