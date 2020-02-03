#include <iostream>
#define MAX 10002
 
using namespace std;
int n, m;
int A[MAX];
 
 
int main(){
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    int k = m-1;
    while(A[k] == n-m+k+1) k--;
    if (k==-1){
        cout << "-1";
        return 0;
    }
    A[k]++;
    for(int i=k+1;i<m;i++){
        A[i]=A[i-1] +1;
        
    }
    for (int i=0;i<m;i++)
        cout << A[i] << " ";
    return 0;
}