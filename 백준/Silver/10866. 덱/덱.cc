#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

/*반환값 있는지 여부, 반환값 */
pair<bool, int> Job(deque<int>& dq, const string& str){
    if(str == "push_front"){
        int num; cin >> num;
        dq.push_front(num);
        return make_pair(false, -1);
    }
    
    if(str == "push_back"){
        int num; cin >> num;
        dq.push_back(num);
        return make_pair(false, -1);
    }

    if(str == "pop_front"){
        if(dq.empty())
            return make_pair(true, -1);

        int res = dq.front();
        dq.pop_front();
        return make_pair(true, res);
    }

    if(str == "pop_back"){
        if(dq.empty())
            return make_pair(true, -1);

        int res = dq.back();
        dq.pop_back();
        return make_pair(true, res);
    }

    if(str == "size"){
        return make_pair(true, dq.size());
    }

    if(str == "empty"){
        return make_pair(true, dq.empty());
    }

    if(str == "front"){
        if(dq.empty())
            return make_pair(true, -1);
        else
            return make_pair(true, dq.front());
    }

    if(str == "back"){
        if(dq.empty())
            return make_pair(true, -1);
        else 
            return make_pair(true, dq.back());
    }

    return make_pair(false, -1);
}

int main(void){
    fastio;
    int N; cin >> N;

    deque<int> dq;
    for(int i = 0; i < N; i++){
        string str; 
        cin >> str;
        pair<bool, int> result = Job(dq, str);

        if(result.first == true)
            cout << result.second << '\n';
    }

    return 0;
}