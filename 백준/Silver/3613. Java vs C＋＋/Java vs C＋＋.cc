#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// delimiter의 종류가 1개일 때(길이가 2이상인 것도 가능)
vector<string> split(string &str, string &delimiter)
{
    vector<string> ret;
    int idx = 0;
    while (idx < str.size())
    {
        int nextIdx = str.find(delimiter, idx);
        if (nextIdx == string::npos)
            nextIdx = str.size();
        if (nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx - idx));
        idx = nextIdx + delimiter.size();
    }

    return ret;
}

bool isCpp(string str){

    int len = str.length();
    // 1) '_'가 문자열 처음 또는 끝 부분에 들어가 있으면 안된다.
    if(str[0] == '_' || str[len-1] == '_') 
        return false;
    
    bool flag = false;
    for(char c : str){
        // 2) 대문자가 없어야한다.
        if(isupper(c)) return false;
        // 3) '_'가 연속으로 들어가 있으면 안된다.
        if(c == '_'){
            if(flag) return false;
            flag = true;
        }
        else{
            flag = false;
        }
    }

    return true;
}

bool isJava(string str){
    // 1) '_'가 있으면 안된다
    if(str.find('_') != string::npos)
        return false;
    // 2) 첫번째 문자는 대문자면 안된다.
    if(isupper(str[0]))
        return false;

    return true;
}

string cpp2Java(string str){
    string ret = "";

    string delimiter = "_";
    vector<string> splitted = split(str, delimiter);

    for(int i = 0; i < splitted.size(); i++){
        string s = splitted[i];
        if(i != 0) s[0] = toupper(s[0]);
        ret += s;
    }

    return ret;
}

string java2Cpp(string str){
    string ret = "";

    for(char c : str){
        if(isupper(c)){
            ret += '_';
            ret += tolower(c);
        }
        else{
            ret += c;
        }
    }

    return ret;
}

int main() {
	fastio;

    string str; cin >> str;

    string ans;
    // cpp라고 가정한다. 올바른 cpp인지 체크한다.    
    if(isCpp(str)){   
        ans = cpp2Java(str); // 올바른 cpp라면 전환된 결과를 저장한다.
    }
    // java라고 가정한다. 올바른 java인지 체크한다. 
    else if(isJava(str)){ 
        ans = java2Cpp(str); // 올바른 java라면 전환된 결과를 저장한다.
    }
    else{
        ans = "Error!";
    }

    cout << ans << '\n'; 
}