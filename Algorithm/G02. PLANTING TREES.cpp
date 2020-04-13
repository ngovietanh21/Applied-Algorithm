//Farmer Jon has recently bought 𝑛 tree seedlings that he wants to plant in his yard. It takes 1 day for Jon to plant a seedling: {Jon isn't particularly hardworking.}, and for each tree Jon knows exactly in how many days after planting it grows to full maturity. Jon would also like to throw a party for his farmer friends, but in order to impress them he would like to organize the party only after all the trees have grown. More precisely, the party can be organized at earliest on the next day after the last tree has grown up.
//
//Help Jon to find out when is the earliest day when the party can take place. Jon can choose the order of planting the trees as he likes, so he wants to plant the trees in such a way that the party will be as soon as possible.
//
//Input
//The input consists of two lines. The first line contains a single integer 𝑁 (1≤𝑁≤100000) denoting the number of seedlings. Then a line with 𝑁 integers 𝑡𝑖 follows (1≤𝑡𝑖≤1000000), where 𝑡𝑖 denotes the number of days it takes for the 𝑖th tree to grow.
//
//Output
//You program should output exactly one line containing one integer, denoting the earliest day when the party can be organized. The days are numbered 1,2,3,… beginning from the current moment.
//
//Example
//inputCopy
//1
//1
//outputCopy
//3

#include <iostream>
#include <algorithm>
#define MAX 1000002
using namespace std;
 
int n, A[MAX], party;
 
bool TangDan(int i,int j){
    return (i>j);
    
}
 
int main()
{
    party = 0;
    cin >> n;
    for(int i =1; i<=n;i++){
        cin >> A[i];
    }
    sort(A+1, A+n+1, TangDan);
    
    for(int i =1; i<=n;i++){
        if (party <= A[i] + i + 1)
            party = A[i] + i +1;
    }
    cout << party;
    
    return 0;
}
