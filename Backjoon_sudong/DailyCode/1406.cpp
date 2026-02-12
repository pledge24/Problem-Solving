#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

class Node
{
public:
    Node(char c, Node* prev = nullptr, Node* next= nullptr)
    : _c(c), _prev(prev), _next(next) {}
    
    /* Node Data */
    char _c;
    Node* _prev;
    Node* _next;
};

struct Cursor
{
    Node* _prev;
    Node* _next;
};


bool moveLeft(Cursor& cursor){
    if(cursor._prev == nullptr)
        return false;

    Node* temp = cursor._prev;
    cursor = {temp->_prev, temp};

    return true;
}

bool moveRight(Cursor& cursor){
    if(cursor._next == nullptr)
        return false;
        
    Node* temp = cursor._next;
    cursor = {temp, temp->_next};

    return true;
}

void processCmd(Cursor& cursor, char cmd, char c){
    switch (cmd)
    {
    case 'L':
        moveLeft(cursor);
        break;
    case 'D': /*right move*/
        moveRight(cursor);
        break;
    case 'B':
        {
            Node* nextTemp = cursor._next; // 뒤에서 이을 용도
            if(moveLeft(cursor) == false)
                return;
            Node* prevTemp = cursor._prev;

            prevTemp->_next = nextTemp;
            nextTemp->_prev = prevTemp;
        }
        break;
    case 'P':
        {
            Node* newNode = new Node(c);

            Node* prevNode = cursor._prev;
            Node* nextNode = cursor._next;
    
            if(prevNode != nullptr){
                prevNode->_next = newNode;
                newNode->_prev = prevNode;
            }
            if(nextNode != nullptr){
                nextNode->_prev = newNode;
                newNode->_next = nextNode;
            }
        }
        break;
    default:
        break;
    }

    return;
}

int main(void){
    fastio;
    Node* head = nullptr;

    string str; cin >> str;

    Node* tail = nullptr;
    bool isFirst = true;
    for(char c : str){
        if(isFirst){
            tail = head = new Node(c);
            isFirst = false;
            continue;
        }

        tail->_next = new Node(c, tail);
        tail = tail->_next;
    }

    Cursor cursor = {tail->_next, nullptr};

    int M; cin >> M;
    for(int i = 0; i < M; i++){
        char cmd, c; cin >> cmd;
        if(cmd == 'P'){
            cin >> c;
        }

        processCmd(cursor, cmd, c);
    }

    while(moveLeft(cursor)){
        head = cursor._prev;
    }

    Node* cur = head;
    while(cur != nullptr){
        cout << cur->_c << ' ';
        cur = cur->_next;
    }
    cout << '\n';

    return 0;
}