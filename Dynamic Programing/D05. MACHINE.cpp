//An engineer needs to schedule a machine to run on some given periods 1,…,𝑛 to produce a chemical product . Each period 𝑖 is represented by a starting time point 𝑠𝑖 and terminating time point 𝑡𝑖 (𝑠𝑖<𝑡𝑖). Due to a technical constraint, the machine must run on exactly two periods that are not overlap (two periods 𝑖 and 𝑗 are not overlap if 𝑡𝑖<𝑠𝑗 or 𝑡𝑗<𝑠𝑖). If the machine is runned on the period 𝑖, then the amount of  it will produce is equal to the duration of the period 𝑖 (which is equal to 𝑡𝑖−𝑠𝑖). Help the engineer to select two not-overlap periods to run the machine such that the amount of  produced is maximal.
//
//Input
//Line 1: contains the positive integer 𝑛 (2≤𝑛≤106)
//Line 𝑖+1: contains two positive integer 𝑠𝑖 and 𝑡𝑖 (1≤𝑠𝑖<𝑡𝑖≤106)
//Output
//The output consists of only one single integer which is the amount of product  the machine will produce in the two selected periods. In case there is no solution (there does not exist two periods that are not overlap), the output contains the value -1.
//
//Example
//inputCopy
//5
//8 12
//6 11
//3 9
//2 5
//1 4
//outputCopy
//8

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1<<20;
 
int s[N], t[N], ls[N], lt[N];
 
int main() {
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        lt[t[i]] = max(lt[t[i]], t[i]-s[i]);
        ls[s[i]] = max(ls[s[i]], t[i]-s[i]);
    }
 
    for (int i = 1; i <= (int) 1e6; i++) {
        lt[i] = max(lt[i], lt[i-1]);
    }
 
    for (int i = (int) 1e6; i >= 1; i--) {
        ls[i] = max(ls[i], ls[i+1]);
    }
 
    int res = 0;
 
    for (int i = 1; i <= (int) 1e6; i++) {
        res = max(res, lt[i-1] + ls[i]);
    }
 
    cout << res << endl;
 
    return 0;
}
