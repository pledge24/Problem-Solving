#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<string> split(string &str){
    vector<string> ret;

    vector<char> delimiter {'\n', ' ', '\t'};

    int idx = 0;
    while(idx < str.length()){
        int nextIdx = str.length();
        for(char c : delimiter){
            int temp = str.find(c, idx);
            if(temp != string::npos)
                nextIdx = min(nextIdx, temp);
        }

        if(nextIdx - idx > 0){
            ret.push_back(str.substr(idx, nextIdx - idx));
        }

        idx = nextIdx + 1;
    }

    return ret;
}

void printLine(string &str){
    if(str.back() == ' ') str.pop_back();
    cout << str << '\n';

    str = "";
}

int main() {
	fastio;
    string str; 

    vector<string> v1;
    while(getline(cin, str)){
        vector<string> splitted = split(str);
        v1.insert(v1.end(), splitted.begin(), splitted.end());
    }

    // Test
    // for(string s : v1) 
    //     cout << s << '|';
    // cout << "\n\n";

    string hr = ""; hr.append(80, '-');
    string lineStr = "";
    for(string word : v1){
        // 태그인가?
        if(word[0] == '<'){
            if(word == "<br>"){
                printLine(lineStr);
            }
            else if(word == "<hr>"){
                if(lineStr.length() != 0){
                    printLine(lineStr);
                }
                cout << hr << '\n';
            }

            continue;
        }

        // 길이가 80을 넘는가?
        if(lineStr.length() + word.length() > 80){
            printLine(lineStr);
            lineStr = word;
            if(lineStr.length() < 80) lineStr += " ";
        }
        // 모든 것이 안전한 경우
        else{
            lineStr += word;
            if(lineStr.length() < 80) lineStr += " ";
        }
    }

    // 버퍼에 남은 문자열이 있다면 마저 출력.
    if(lineStr.length() > 0) 
        printLine(lineStr);

}