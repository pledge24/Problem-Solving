#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

deque<int> dq;

int binary_search(int num, int size){

    int low, mid, high;

    low = 0, high = size - 1; mid = (low + high) / 2;
    while(low < high){

        if(dq[mid] < num){      // 중앙값보다 큰 경우
            low = mid + 1;
        }
        else if(num < dq[mid]){ // 중앙값보다 작은 경우
            high = mid - 1;
        }
        else{
            return mid;
        }

        mid = (low + high) / 2;
    }


    return mid;
}

int main() {
	fastio;
    int N; cin >> N;
    
    //dq.resize(N);

    int num;
    int ans;
    for(int size = 0; size < N;){
        cin >> num;
        
        if(size == 0) {           
            dq.push_back(num);
            cout << num << '\n';    
            size++;
            continue;
        }
        
        int pos = binary_search(num, size);
        pos += dq[pos] < num;
        //cout << "pos: " << pos << '\n';
        dq.insert(dq.begin() + pos, num);
        size++;

        ans = dq[size/2 -1 + (size % 2)];
        
        cout << ans << '\n';
    }
    
    // for(int elem : dq){
    //     cout << elem << ' ';
    // }
    // cout << '\n';
}