#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    int a = 11; // 1011
    int b = 4;  // 0100

    int c = a | b;
//     for(int i = 0 ; i <= 10; i++)
//     {
//         cout << c << '\n';
//     }   
    int last_num = 3;
    cout << (1 << (last_num + 1)) << '\n';
}