#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;


int N, M;

map<int, int> num_data;

vector<int> v1;

vector<int> ans;
void dfs(map<int, int>::iterator iter, int cnt){

    if(ans.size() == M){
        for(int elem: ans){
            cout << elem << ' ';
        }
        cout <<'\n';

        return;
    }

    for(auto i=iter; i!=num_data.end(); i++){
        for(int cur_cnt = cnt; cur_cnt > 0; cur_cnt--){

            ans.push_back(i->first);
            dfs(i, cur_cnt-1);    
            ans.pop_back();
        }
        iter++;
        int left_len = M-ans.size();
        cnt = iter->second < left_len ? iter->second : left_len;
    }
    
        
    

    return;
}

int main() {
	fastio;
    cin >> N >> M;

    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        num_data[num]++;
    }
    
    // sort(v1.begin(), v1.end());
    dfs(num_data.begin(), num_data.begin()->second);

    for(auto elem : num_data){
        printf("elem: %d cnt: %d\n", elem.first, elem.second);
    }
}