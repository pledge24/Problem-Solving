#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    int a = 90;

    switch(a){
        case 100:
            cout << "is 100" << '\n';
        case 90:
            cout << "is 90" << '\n';
        case 80:
            cout << "is 80" << '\n';
            cout << "Pass" << '\n';
        default:
            cout << "non-Pass" << '\n';
    }
    
    {
        bool alreadyPassed = false;
        if(a == 100 || alreadyPassed){
            alreadyPassed = true;
            cout << "is 100" << '\n';
        }
        
        if(a == 90 || alreadyPassed){
            alreadyPassed = true;
            cout << "is 90" << '\n';
        }  

        if(a == 80 || alreadyPassed){
            alreadyPassed = true;
            cout << "is 80" << '\n';
            cout << "Pass" << '\n';
        } 

        cout << "non-Pass" << '\n';

    }
    
}