#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

vector<char> moumList = {'a', 'e', 'i', 'o', 'u'};
vector<char> exceptList = {'e', 'o'};

bool isAcceptable(string& str){
    int moumStreak = 0;
    int zaumStreak = 0;
    bool haveMoum = false;

    char prevC = ' ';
    for(char c : str){
        if(!isalpha(c)){
            prevC = c;
            continue;
        }

        auto it = find(moumList.begin(), moumList.end(), c);
        if(it != moumList.end()){
            moumStreak++;
            zaumStreak = 0;
            haveMoum = true;
        }
        else{
            moumStreak = 0;
            zaumStreak++;
        }

        if(moumStreak >= 3 || zaumStreak >= 3)
            return false;

        // 같은 글자가 연속적으로 두 번 나오면 안됨(단, 예외 목록 제외.)
        if(prevC == c){
            // not include exceptList. 
            if(find(exceptList.begin(), exceptList.end(), c) == exceptList.end())
                return false;
        }

        prevC = c;
    }

    if(!haveMoum)
        return false;


    return true;
}
int main(void){
    fastio;
    while(true){
        string str; cin >> str;
        if(str == "end")
            break;

        if(isAcceptable(str)){
            cout << "<" << str << ">" << " is acceptable." << '\n';
        }
        else{
            cout << "<" << str << ">" << " is not acceptable." << '\n';
        }

        
    }


    return 0;
}