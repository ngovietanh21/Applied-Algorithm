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