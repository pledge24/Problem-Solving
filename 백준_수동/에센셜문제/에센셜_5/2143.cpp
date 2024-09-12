#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
    fastio;
    long long T; cin >> T;
    
    int m1; cin >> m1;   
    map<long long, long long> map1;
    long long next_num;
    for (int i = 0; i < m1; i++)
    {
        cin >> next_num;
        vector<long long> temp;
        temp.push_back(next_num);
        for(auto it = map1.begin(); it != map1.end(); it++){
            temp.push_back(it->first+next_num);
        }

        for(long long num : temp){
            map1[num]++;
        }

        for(auto it = map1.begin(); it != map1.end(); it++){
        cout << "map1 data: " << it->first << " " << it->second << '\n';
        }
        cout << '\n';
    }


    int m2; cin >> m2;
    map<long long, long long> map2;
    for (int i = 0; i < m2; i++)
    {
        cin >> next_num;
        vector<long long> temp;
        temp.push_back(next_num);
        for(auto it = map2.begin(); it != map2.end(); it++){
            temp.push_back(it->first+next_num);
        }

        for(long long num : temp){
            map2[num]++;
        }
    }


    for(auto it = map1.begin(); it != map1.end(); it++){
       cout << "map1 data: " << it->first << " " << it->second << '\n';
    }
    cout << '\n';

    for(auto it = map2.begin(); it != map2.end(); it++){
        cout << "map2 data: " << it->first << " " << it->second << '\n';
    }

    long long ans = 0;
    for(auto it = map1.begin(); it != map1.end(); it++){
        if(map2[T-it->first] != 0){
            ans += it->second*map2[T-it->first];
            //cout << it->second*map2[T-it->first] << '\n';
        }
    }

    cout << ans << '\n';
}