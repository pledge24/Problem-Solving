#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

enum {MALE = 1, FEMALE = 2};

int N; 

bool inRange(int x){
    return 1 <= x && x <= N;
}

void simulate(vector<bool>& v1, int gender, int No){
    switch (gender)
    {
    case MALE:
        {
            int multiple = 1;
            while(No*multiple <= N){
                v1[No*multiple] = !v1[No*multiple];
                multiple++;
            }
            break;  
        }
    case FEMALE:
        {
            int center = No;
            v1[center] = !v1[center];
    
            int offset = 1;
            while(inRange(center-offset) && inRange(center+offset)){
                if(v1[center-offset] != v1[center+offset])
                    break;
    
                v1[center-offset] = !v1[center-offset];
                v1[center+offset] = !v1[center+offset];
    
                offset++;
            }
        }
        break;
    default:
        break;
    }
}

int main(void){
    fastio; 
    cin >> N;

    vector<bool> v1(N+1);
    for(int i = 1; i <= N; i++){
        int num; cin >> num;
        v1[i] = num;
    }

    int cmd; cin >> cmd;
    for(int i = 0; i < cmd; i++){
        int gender, No; cin >> gender >> No;

        simulate(v1, gender, No);
    }

    for(int i = 1; i <= N; i++){
        cout << (int)v1[i] << ' ';
        if(i % 20 == 0)
            cout << '\n';
    }
    cout << '\n';

    return 0;
}