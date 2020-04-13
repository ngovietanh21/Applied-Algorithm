//Cho 1 một xâu nhị phân 𝑆 độ dài 𝑛. Tìm xâu nhị phân kế tiếp của xâu 𝑆 trong thứ tự từ điển.
//
//Input
//Dòng đầu 1 số nguyên dương 𝑛≤104.
//
//Dòng thứ 2 ghi 𝑛 số 0 hoặc 1 liên tiếp nhau.
//
//Example
//inputCopy
//5
//00100
//outputCopy
//00101

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
