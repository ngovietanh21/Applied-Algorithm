#include <iostream>
#define MAX 10000
 
using namespace std;
 
int n, A[MAX];
 
void Solution(){
    for (int i=0;i<n;i++){
        if (i== n-1) cout << A[i];
        else cout << A[i] << " ";
    }
}
 
void TimHoanViKeTiep(){
    int i = n-1;
    int k = n-1;
    
    while(A[i] < A[i-1]) {
        i--;
        if (i==0){
            cout << "-1";
            return;
        }
    }
    
    while(A[i-1] > A[k]){
        k--;
    }
    swap(A[i-1], A[k]);
    
    k = n-1;
    while(i<k){
        swap(A[i], A[k]);
        i++;k--;
    }
    Solution();
    
}
 
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    TimHoanViKeTiep();
    
    return 0;
}