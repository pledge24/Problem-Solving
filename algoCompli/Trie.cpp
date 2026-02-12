#include <array>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

const int ALPHA_N = 26;

// 'a' ~ 'z' 기준
class Trie
{
public:
    void Insert(const string& word)
    {
        Node* cur = root.get();
        for(char c : word)
        {
            const int idx = c - 'a';
            if(cur->next[idx] == nullptr)
            {
                cur->next[idx] = make_unique<Node>();
            }

            // Move Next
            cur = cur->next[idx].get();
        }

        // set end of word
        cur->isEnd = true;
    }

    // word가 Trie에 있는지 찾는 함수
    bool Find(const string& word) const
    {
        // const를 붙이면 Trie의 데이터 변경이 금지된다.
        // 단, delete는 통과된다.(의도적으로 쓰지만 않으면 상관X)
        const Node* cur = root.get();
        for(char c : word)
        {
            const int idx = c - 'a';
            if(cur->next[idx] == nullptr)
                return false;
            
            // Move Next
            cur = cur->next[idx].get();
        }

        return cur->isEnd;
    }

    // prefix로 시작하는 문자열이 Trie에 있는지 확인
    bool startsWith(const string& prefix) const
    {
        const Node* cur = root.get();
        for(char c : prefix)
        {
            const int idx = c - 'a';
            if(cur->next[idx] == nullptr)
                return false;
            
            // Move Next
            cur = cur->next[idx].get();
        }

        return true;
    }

private:
    struct Node
    {
        bool isEnd = false; // isEndOfWord
        array<unique_ptr<Node>, ALPHA_N> next;
    };

    // root는 단지 시작을 위한 node이다.
    unique_ptr<Node> root = make_unique<Node>();
};

int main(void)
{


    return 0;
}