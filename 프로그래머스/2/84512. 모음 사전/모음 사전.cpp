#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string word) {
    int answer = 0;
    string cur_word = "";
    vector<char> v1 = {'A', 'E', 'I', 'O', 'U'};
    
    for(int i = 0; i < word.length(); i++){
        switch(word[i]){
            case 'A':
                word[i] = '0';
                break;
            case 'E':
                word[i] = '1';
                break;
            case 'I':
                word[i] = '2';
                break;
            case 'O':
                word[i] = '3';
                break;
            case 'U':
                word[i] = '4';
                break;
        }
    }
    
    cout << word << '\n';
    
    while(word != cur_word){
        if(cur_word.length() != 5){
            cur_word += '0';
        }
        else{
            cur_word[4]++;
            
            while(cur_word[cur_word.length()-1] > '4'){
                cur_word[cur_word.length()-2]++;
                cur_word.erase(cur_word.length()-1);
            }
        }
        //cout << cur_word << '\n';
        answer++;
    }

    return answer;
}