#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N; cin >> N;
    int M; cin >> M;

    vector<int> streakList;
    int streak = 0;     // "IO"가 반복된 횟수
    char desired = 'I';
    for(int i = 0; i < M; i++){
        char c; cin >> c;

        if(c == desired){
            streak++;
            desired = (desired == 'I') ? 'O' : 'I';
        }
        else{

            if(streak >= 3){
                streakList.push_back((streak-1)/2);
            }

            if(c == 'I'){
                streak = 1;
                desired = 'O';
            }
            else{
                streak = 0;
                desired = 'I';
            }
            
        }
    }
    
    if(streak >= 3){
        streakList.push_back((streak-1)/2);
    }

    int cnt = 0;
    for(int elem : streakList){
        // cout << elem << ' ';

        if(elem - N + 1 > 0){
            cnt += elem - N + 1;
        }
        
    }

    cout << cnt << '\n';

    return 0;
}