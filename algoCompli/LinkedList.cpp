#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

template <typename T>
struct Node{
    Node() {}
    Node(T data) : _data(data) {}
    
    T _data;
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
};

/*Double linked List: cursor는 끝 노드 다음까지 가리킬 수 있음*/
template<typename T>
class LinkedList
{
public:
    LinkedList() {
        begin = end = new Node<T>();
    }

    /* cursor 위치에 node를 삽입하고, 삽입한 원소의 위치를 반환 */
    // 해당 위치에 있던 node는 뒤로 밀린다.
    Node<T>* Insert(Node<T>* cursor, T data){
        Node<T>* newNode = new Node<T>(data);
        if(empty()){
            newNode->next = end;
            end->prev = newNode;

            begin = newNode;
            return newNode;
        }
        
        // prevNode <=> newNode
        Node<T>* prevNode = cursor->prev;
        if(prevNode){ 
            prevNode->next = newNode;
            newNode->prev = prevNode;
        }
        else{ // prevNode 없음 -> begin
            begin = newNode;
        }

        // newNode <=> curNode
        Node<T>* curNode = cursor;
        newNode->next = curNode;
        curNode->prev = newNode;

        return newNode;
    }

    /* return: cursor 위치에 있는 노드를 지우고, 다은 원소의 위치를 반환 */
    // 주의: 원소가 들어있는 위치의 cursor만 들어와야한다.
    Node<T>* Erase(Node<T>* cursor){
        Node<T>* prevNode = cursor->prev;
        Node<T>* removeNode = cursor;
        Node<T>* nextNode = cursor->next;
        
        Node<T>* res;
        if(cursor == begin){
            begin = nextNode;
            // 댕글링 포인터 방지용(delete한 cursor의 메모리가 할당에 재사용된 경우 문제 발생)
            nextNode->prev = nullptr;
            res = begin;
        }
        else{
            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            res = nextNode;
        }
        
        // 삭제되는 노드의 포인터들을 초기화 (메모리 재사용 시 문제 방지)
        // cursor->prev = nullptr;
        // cursor->next = nullptr;
        delete cursor;

        return res;
    }
       
    void PushBack(T data){
        Insert(end, data);
    }

    /* return: 다음(오른쪽)으로 이동*/
    void MoveNext(Node<T>*& cursor) {
        cursor = cursor->next;
    }

    /* return: 이전(왼쪽)으로 이동*/
    void MovePrev(Node<T>*& cursor) {
        cursor = cursor->prev;
    }

public:
    Node<T>* Begin() { return begin; }
    Node<T>* End() { return end; }

private:
    bool empty() { return begin == end; }

private:
    Node<T>* begin;
    Node<T>* end;
};

void ApplyCmd(LinkedList<char>& l1, Node<char>*& cursor, char cmd){
    switch (cmd)
    {
    case 'L':
        if(cursor != l1.Begin())
            l1.MovePrev(cursor);
        break;
    case 'D':
        if(cursor != l1.End())
            l1.MoveNext(cursor);
        break;    
    case 'B':
        if(cursor != l1.Begin()){
            l1.MovePrev(cursor);
            cursor = l1.Erase(cursor);
        }
        break;
    case 'P':
        char c; cin >> c;
        cursor = l1.Insert(cursor, c);
        if(cursor != l1.End())
            l1.MoveNext(cursor);
        break;
    default:
        break;
    }
}

int main(void){
    // fastio;
    LinkedList<char> l1;
    string str; cin >> str;
    for(char c : str){
        l1.PushBack(c);        
    }

    auto cursor = l1.End();
    int M; cin >> M;
    for(int i = 0; i < M; i++){
        char cmd; cin >> cmd;
        
        ApplyCmd(l1, cursor, cmd);

        {
            Node<char>* it = l1.Begin();
            while(it != nullptr){
                // cout << "check" << '\n';
                if(it == cursor){
                    cout << "[]";
                }
                
                if(it != l1.End())
                    cout << it->_data;
                l1.MoveNext(it);
                
            }
            cout << '\n';
        }
        
    }

    {
        Node<char>* cursor = l1.Begin();
        while(cursor != l1.End()){
            cout << cursor->_data;
            l1.MoveNext(cursor);
        }
        cout << '\n';
    }
    
    return 0;
}