//Vinh works for an ATM machine manufacturing company. The basic functionality of an ATM machine is cash withdrawal. When a user requests a cash withdrawal of 𝑊 VND (Vietnamese Dong), the ATM has to dispense 𝑁 money notes such that they sum up to 𝑊. For the next generation of ATM machines, Vinh is working on an algorithm to minimize the number of 𝑁 of money notes for each cash withdrawal transaction.
//
//Your task is to help Vinh to do his job given that the money notes come in the values of 1000,2000,3000,5000,1000⋅101,2000⋅101,3000⋅101,5000⋅101,…,1000⋅10𝑐,2000⋅10𝑐,3000⋅10𝑐,5000⋅10𝑐 where 𝑐 is a positive integer and Vinh has unlimited supply of money notes for each value.
//
//Input
//The input file consists of several datasets. The first line of the input file contains the number of datasets which is a positive integer and is not greater than 1000. The following lines describe the datasets.
//
//The first line consists of one positive integer W (𝑊≤1018);
//
//The second line consists of one positive integer 𝑐 (𝑐≤15).
//
//Output
//For each dataset, write in one line two space-separated integers 𝑁 and 𝑆 where 𝑆 is the number of ways to dispense the fewest number 𝑁 of money notes. In case there is no way to serve the cash withdrawal request, write out 0 in one line instead.
//
//Example
//inputCopy
//2
//1000
//1
//7000
//1
//outputCopy
//1 1
//2 1

#include<iostream>
#include <algorithm>
 
using namespace std;
 
void atm(long long w, int c) {
    if(w % 1000 != 0) {
        cout<<0<<"\n";
        return;
    } else {
        w /= 1000;
    }
    int so_cach[]= {1,1,1,1,2,1,2,1,1,3};
    int so_to[]= {0,1,1,1,2,1,2,2,2,3};
 
    long long cach=1,to=0;
    int d;
    while (c > 0 && w > 0) {
        c--;
        d = w%10;
        w /= 10;
        to += so_to[d];
        cach *= so_cach[d];
    }
 
    switch(w%5) {
        case 0:
            to += w/5;
            break;
        case 1:
            to += w/5 + 1;
            if (w != 1)
                cach *= 2;
            break;
        case 2:
            to += w/5 +1;
            break;
        case 3:
            to += w/5 +1;
            break;
        case 4:
            to += w/5 +2;
            if (w != 4)
                cach*= 3;
            else
                cach*= 2;
            break;
    }
 
    cout << to << " " << cach << endl;
}
 
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        long long w;
        int c;
        cin>>w>>c;
        atm(w,c);
    }
 
    return 0;
}
