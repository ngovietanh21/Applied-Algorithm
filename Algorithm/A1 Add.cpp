#include <string>
#include <iostream>
 
using namespace std;
 
int stringToNum(char c)
{
    return c - '0';
}
 
char numToString(int n)
{
    return (char)(n+48);
}
 
void chuanHoa(string &a, string &b) // lam 2 xau co do dai bang nhau
{
    int l1 = a.length(), l2 = b.length();
    if (l1 >= l2)
    {
        b.insert(0, l1-l2, '0');
    }
    else
    {
        a.insert(0, l2-l1, '0');
    }
}
 
string sum(string a, string b)
{
    string s = "";
    chuanHoa(a,b);
    int l = a.length();
    
    int temp = 0;
    for (int i=l-1; i>=0; i--)
    {
        temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;
        s.insert(0,1,numToString(temp%10));
        temp = temp/10;
    }
    if (temp>0)
    {
        s.insert(0,1,numToString(temp));
    }
    return s;
}
 
int main(int argc, char **argv)
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    cout << sum(a,b);
    return 0;
}