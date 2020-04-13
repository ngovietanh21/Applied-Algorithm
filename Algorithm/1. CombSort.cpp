#include <iostream>
using namespace std;
 
int NextGap(int gap)
{
    gap = (gap*10)/13;
    
    if (gap < 1)
        return 1;
    return gap;
}
 
void combSort(float A[], int n)
{
    int gap = n;
    
    bool swapped = true;
    
    while (gap != 1 || swapped == true)
    {
        gap = NextGap(gap);
        
        swapped = false;
        
        for (int i=0; i<n-gap; i++)
        {
            if (A[i] > A[i+gap])
            {
                swap(A[i], A[i+gap]);
                swapped = true;
            }
        }
    }
}
 
int main()
{
    int n;
    cin >> n;
    float A[n];
    for (int i=0; i<n; i++)
        cin >> A[i];
    combSort(A, n);
    
    for (int i=0; i<n; i++)
        printf("%.2f ", A[i]);
    
    return 0;
}