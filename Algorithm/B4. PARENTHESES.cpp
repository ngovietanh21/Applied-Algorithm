//Input
//The input file consists of several datasets. The first line of the input file contains the number of datasets which is a positive integer 𝑇 and is not greater than 1000. Each of 𝑇 following lines describes a parentheses expression including: '(',')','[',']','{','}'.
//
//Output
//For each dataset, write in one line 1 or 0 if the expression is correct or not respectively.
//
//Example
//inputCopy
//2
//([]())
//()()()[}
//outputCopy
//1
//0

#include <iostream>
using namespace std;
char stack[1000];
int ssize;
 
void push(char c){
    ssize ++;
    stack[ssize-1] = c;
}
 
void pop(){
    ssize--;
}
 
char top(){
    return stack[ssize-1];
}
 
int check(string s)
{
    ssize = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            push(s[i]);
            flag = 1;
        }
        if (ssize!=0) {
            if (s[i] == '}') {
                if (top() == '{')
                {
                    pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (top() == '[') {
                    pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (top() == '(') {
                    pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }
    
    if ((ssize == 0) && (flag == 1)) return 1;
    else return 0;
}
 
 
int main()
{
    int n;
    cin >> n;
    int A[n];
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        A[i]=check(s);
    }
    
    for (int i = 0; i < n; i++) {
        cout << A[i] << endl;
    }
    
    return 0;
}
