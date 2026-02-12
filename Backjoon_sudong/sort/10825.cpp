#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

struct Student{
    string name;
    int KRScore;
    int ENScore;
    int mathScore;
};

struct cmp{
    bool operator()(const Student& s1, const Student& s2){
        if(s1.KRScore != s2.KRScore){
            return s1.KRScore > s2.KRScore;
        }

        if(s1.ENScore != s2.ENScore){
            return s1.ENScore < s2.ENScore;
        }

        if(s1.mathScore != s2.mathScore){
            return s1.mathScore > s2.mathScore;
        }

        return s1.name < s2.name;
    }
};

int main(void){
    fastio;
    int N; cin >> N;

    vector<Student> v1(N);
    for(int i = 0; i < N; i++){
        cin >> v1[i].name;
        cin >> v1[i].KRScore;
        cin >> v1[i].ENScore;
        cin >> v1[i].mathScore;
    }

    sort(v1.begin(), v1.end(), cmp());

    for(auto elem : v1){
        cout << elem.name << '\n';
    }

    return 0;
}