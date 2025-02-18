#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

string getSignalPattern(const vector<string> &signals, int idx){
    string ret = "";

    int signalLen = idx + 3 <= signals[0].length() ? 3 : 1;
    int h = 5;
    for(int i = 0; i < h; i++){
        ret += signals[i].substr(idx, signalLen);
    }

    return ret;
}

int translateSignal(const vector<string> &signals, int idx){
    vector<string> pattern = {
        "####.##.##.####",
        "#####",
        "###..#####..###",
        "###..####..####",
        "#.##.####..#..#",
        "####..###..####",
        "####..####.####",
        "###..#..#..#..#",
        "####.#####.####",
        "####.####..####"
    };

    string signalPattern = getSignalPattern(signals, idx);

    int digit = 10;
    for(int i = 0; i < digit; i++){
        // 해당 숫자 패턴이랑 동일하면 해당 숫자를 출력한다.
        if(pattern[i] == signalPattern){
            return i;
        }
    }

    return 1;
}

int main() {
	fastio;

    int N; cin >> N;
    
    string str; cin >> str;
    
    int h = 5;
    int w = N/h;
    vector<string> signals;

    for(int i = 0; i < h; i++){
        signals.push_back(str.substr(i*w, w));
    }

   
    // for(int i = 0; i < h; i++){
    //     cout << signals[i] << '\n';
    // }   

    // 각 숫자의 시그널을 해석한다.
    int idx = 0;
    while(idx < w){
        if(signals[0][idx] == '#'){
            int signal = translateSignal(signals, idx);
            cout << signal;
            
            if(signal != 1) idx += 3;
            else idx++;
        }
        else{
            idx++;
        }
    }

}