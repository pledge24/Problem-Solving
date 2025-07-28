#include <bits/stdc++.h>

using namespace std;
using wordData = pair<string, int>;

// 단어를 변환하자.
// 알파벳 하나를 바꿀 수 있다. 단, 바꾼 단어는 word에 있어야한다.
// => 최소 단계는?

// word의 단어들은 길이가 전부 같으며, 중복되는 단어는 없다.
// word의 길이 3~50
// => 바꿀 수 있으면 바꾼다. 그리고 넣는다(Bfs)
void Bfs(string& begin, string& target, vector<string>& words, int& answer){
    queue<wordData> q;
    vector<bool> visited(words.size());
    
    int wordN = words[0].length();
    
    //init
    q.push(make_pair(begin, 0));
    while(!q.empty()){
        wordData cur = q.front(); q.pop();
        
        if(cur.first == target){
            answer = cur.second;
            return;
        }
        
        for(int i = 0; i < words.size(); i++){
            if(visited[i])
                continue;

            string& curWord = cur.first;
            string& cmpWord = words[i];
            int diff = 0;
            for(int j = 0; j < wordN; j++){
                diff += (curWord[j] != cmpWord[j]);
            }
            
            // 다른 단어로 변환할 수 있는경우(방문할 수 있는 경우)
            if(diff == 1){
                q.push(make_pair(cmpWord, cur.second+1));
                visited[i] = true;
            }
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    Bfs(begin, target, words, answer);
    
    return answer;
}