#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;
    int N, M; cin >> N >> M;

    map<string, vector<string>> groupToMember;
    map<string, string> nameToGroup;

    // Input
    for(int i = 0; i < N; i++){
        string groupName; cin >> groupName;
        int memberN; cin >> memberN;
        // 멤버 입력
        for(int j = 0; j < memberN; j++){
            string name; cin >> name;
            groupToMember[groupName].push_back(name);
            nameToGroup[name] = groupName;
        }
        sort(groupToMember[groupName].begin(), groupToMember[groupName].end());
    }

    // Quiz
    for(int i = 0; i < M; i++){
        string str; cin >> str;
        int type; cin >> type;
        if(type == 0/*팀 네임 입력*/){
            for(const string& name : groupToMember[str]){
                cout << name << '\n';
            }
        }
        else{
            cout << nameToGroup[str] << '\n';
        }

    }


    return 0;
}