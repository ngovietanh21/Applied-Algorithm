#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>
using namespace std;

float arr[700000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char nameFile[10] = "input.txt";
    int n;
    cin >> n;
    // first half  : save to file
    int size1 = 0;
    if(n>500000) {
        size1 = n - 500000;
    }
    for (int k = 0; k < size1; cin >> arr[k++]);
    sort(arr,arr+size1);

    ofstream ofs(nameFile);
    copy(arr, arr + size1, ostream_iterator<float>(ofs, " "));
    ofs.close();

    // second half
    int size2 = n - size1;
    for (int k = 0; k < size2; cin >> arr[k++]);
    sort(arr,arr+size2);

    // merge
    ifstream ifs(nameFile); // re-open first half
    cout << fixed << setprecision(2);
    merge(istream_iterator<float>(ifs), istream_iterator<float>(),
          arr, arr + size2, ostream_iterator<float>(cout, " "));
    ifs.close();

    return 0;
}