#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c <= r; c++)
            cout << '*';
        cout << '\n';
    }
    
    return 0;
}