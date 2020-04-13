//Minh go shopping at the SS shop. The shop has currency denominations: 1$, 5$, 10$, 50$, 100$, 500$. Minh takes some items at the shop and pay an amount of 1000$. Your task to devise a method to pay back amount to customer using fewest number of money notes.
//
//Input
//The input consists of only one single integer 𝑁 (1≤𝑁≤999) denoting the total value of the taken items.
//
//Output
//The output consists of only one single integer denoting the number of money notes.
//
//Examples
//inputCopy
//1
//outputCopy
//15
//inputCopy
//3
//outputCopy
//13

#include <iostream>
using namespace std;
 
int n, dem, value;
int A[] = {500,100,50,10,5,1};
 
int main()
{
    cin >> n;
    dem = 0;
    value = 0;
    for(int i =0; i<6;i++){
        while(value + A[i] <= 1000-n){
            value +=A[i];
            dem++;
        }
    }
    cout << dem;
    
    
    return 0;
}
