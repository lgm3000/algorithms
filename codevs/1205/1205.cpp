#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string t;
    vector<string> a;
    while(cin >> t) a.push_back(t);
    for(int i = a.size()-1;i>0;i--) cout << a[i] << " ";
    cout << a[0];
    return 0;

}

