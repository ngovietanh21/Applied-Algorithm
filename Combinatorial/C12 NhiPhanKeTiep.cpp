#include <iostream>
#define MAX 10002
 
using namespace std;
int n;
char S[MAX];
 
int main(){
    cin >> n >> S;
    int k = n-1;
    while( S[k] != '0'){
        S[k] = '0';
        k--;
        if (k== -1){
            cout << "-1";
            return 0;
        }
    }
    S[k] = '1';
    cout << S;
    return 0;
}