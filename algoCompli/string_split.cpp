#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 설명
// 1) delimeter가 idx 뒤에 없다 => nextIdx == string::npos
// 2) idx가 delimiter 시작점에 서있다 => nextIdx - idx = 0
// 3) idx는 추출한 문자열(0 이상) + delimeter 길이만큼 jump

// delimiter의 종류가 1개일 때(길이가 2이상인 것도 가능) 
vector<string> split(string& str, string& delimeter){
    vector<string> ret;
    int idx = 0;
    while(idx < str.size()){
        int nextIdx = str.find(delimeter, idx);
        if(nextIdx == string::npos) nextIdx = str.size();

        if(nextIdx - idx > 0)
            ret.push_back(str.substr(idx, nextIdx-idx));
            
        idx = nextIdx + delimeter.size();
    }

    return ret;
}

#define OUT
void Split(OUT vector<string>& res, string& str, string& delimeter)
{
    int pos = 0;
    while(pos < str.length())
    {
        int nextDelimeterPos = str.find(delimeter, pos);
        if(nextDelimeterPos == string::npos)
            nextDelimeterPos = str.length();

        int len = nextDelimeterPos - pos;

        if(len > 0)
        {
            string splittedStr = str.substr(pos, len);
            res.push_back(std::move(splittedStr));
        }

        // delimeter가 연달아 있는 경우 len이 0이 나옴
        pos = nextDelimeterPos + delimeter.size();
    }
}

int main() {
	fastio;

}