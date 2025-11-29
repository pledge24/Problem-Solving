#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char& c : str){
        c = isupper(c) ? tolower(c) : toupper(c);
    }
    
    cout << str << '\n';
    
    return 0;
}