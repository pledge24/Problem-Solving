#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using UserData = pair<int, string>; // lvl, name

struct RoomData
{
    int lvl = 0;
    vector<UserData> users;
};

bool inRange(int srcL, int tgtL){
    int under = max(srcL - 10, 0);
    int upper = srcL + 10;

    return under <= tgtL && tgtL <= upper;
}

void printRoomData(RoomData& Room, bool isFull = true){
    if(isFull)
        cout << "Started!" << '\n';
    else
        cout << "Waiting!" << '\n';

    auto& users = Room.users;
    sort(users.begin(), users.end(), [](const UserData& p1, const UserData& p2){
        return p1.second < p2.second;
    });

    for(const UserData& data : users){
        cout << data.first << " " << data.second << '\n';
    }
}

int main(void){
    fastio;

    int P, M; cin >> P >> M;
    vector<RoomData> v1;
    for(int i = 0; i < P; i++){
        int L; string N; cin >> L >> N;

        // Try Push
        bool push = false;
        for(RoomData& roomData : v1){
            int roomLev = roomData.lvl;
            auto& users = roomData.users;

            if(inRange(roomLev, L) && users.size() < M){
                users.push_back(make_pair(L, N));
                // cout << "exist Push! size: " << users.size() << '\n';
                push = true;
                break;
            }

        }

        if(!push){
            // cout << "new Push" << '\n';
            v1.push_back({L, {make_pair(L, N)}});
        }
    }

    for(auto room : v1){
        bool isFull = room.users.size() == M;
        // cout << "size: " << room.users.size() << '\n';

        printRoomData(room, isFull);
    }

    return 0;
}