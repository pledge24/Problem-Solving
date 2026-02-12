#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void){
    fastio;

    int M; cin >> M;
    vector<bool> s(21);
    for(int i = 0; i < M; i++){
        string op; int op_num;
        cin >> op;

        if(op != "all" && op != "empty"){
            cin >> op_num;
        }

        if(op == "add"){
            s[op_num] = true;
        }
        else if(op == "remove"){
            s[op_num] = false;
        }
        else if(op == "check"){
            cout << (int)s[op_num] << '\n';
        }
        else if(op == "toggle"){
            s[op_num] = !s[op_num];
        }
        else if(op == "all"){
            for(int elem = 1; elem <= 20; elem++){
                s[elem] = true;
            }
        }
        else if(op == "empty"){
            for(int elem = 1; elem <= 20; elem++){
                s[elem] = false;
            }
        }


    }

    return 0;
}