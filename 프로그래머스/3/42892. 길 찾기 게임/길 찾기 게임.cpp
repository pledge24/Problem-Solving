#include <bits/stdc++.h>

using namespace std;

// 1. 노드 구조체 정의
struct Node {
    int id;      // 노드 번호
    int x, y;    // 좌표
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

// 2. 정렬 기준: y 좌표 내림차순 (부모 우선), x 좌표 오름차순
bool compareNodes(const Node* a, const Node* b) {
    if (a->y != b->y) return a->y > b->y;
    return a->x < b->x;
}

// 3. 트리 노드 삽입 함수 (x 좌표 기준 분기)
void insertNode(Node* parent, Node* child) {
    if (child->x < parent->x) {
        if (parent->left == nullptr) parent->left = child;
        else insertNode(parent->left, child);
    } else {
        if (parent->right == nullptr) parent->right = child;
        else insertNode(parent->right, child);
    }
}

// 4. 전위 순회 (Root -> Left -> Right)
void preOrder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    result.push_back(node->id);
    preOrder(node->left, result);
    preOrder(node->right, result);
}

// 5. 후위 순회 (Left -> Right -> Root)
void postOrder(Node* node, vector<int>& result) {
    if (node == nullptr) return;
    postOrder(node->left, result);
    postOrder(node->right, result);
    result.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> nodes;
    
    // 노드 객체 생성 및 리스트 저장
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
    }

    // 1단계: 조건에 따른 정렬
    sort(nodes.begin(), nodes.end(), compareNodes);

    // 2단계: 트리 구성 (가장 높은 y값을 가진 첫 번째 노드가 루트)
    Node* root = nodes[0];
    for (int i = 1; i < nodes.size(); i++) {
        insertNode(root, nodes[i]);
    }

    // 3단계: 순회 결과 저장
    vector<int> preOrderResult;
    vector<int> postOrderResult;
    
    preOrder(root, preOrderResult);
    postOrder(root, postOrderResult);

    return {preOrderResult, postOrderResult};
}