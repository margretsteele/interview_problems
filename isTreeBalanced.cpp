// Example program
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <string>
using namespace std;

struct Node {
    Node(string val) 
        : left(nullptr)
        , right(nullptr)
        , value(val)
        , discovered(false)
        {}

    Node(shared_ptr<Node> leftNode, shared_ptr<Node> rightNode, string val) 
        : left(leftNode)
        , right(rightNode)
        , value(val)
        , discovered(false)
        {}

    shared_ptr<Node> left;
    shared_ptr<Node> right;
    string value;
    bool discovered;
};

void dfs(shared_ptr<Node> node, int currentDistance, vector<int>& distances) {
    if(node == nullptr) {
        cout << "currentDistance: " << currentDistance << "\n";
        distances.push_back(currentDistance);
    }
    else {
        if((!node->discovered)) {
            currentDistance++;
            node->discovered = true;
            cout << "current: " << node->value << "\n";
        }
     
        dfs(node->left, currentDistance, distances);
        dfs(node->right, currentDistance, distances);
    }
}

bool isBalanced(shared_ptr<Node> root) {
    auto currentDistance = 0;
    vector<int> distances;

    dfs(root, currentDistance, distances);
    
    auto currentMaxDistance = 0; 
    for(auto distance : distances) {
        if(distance > currentMaxDistance) {
            currentMaxDistance = distance;
        }
    }
    
    for(auto distance : distances) {
        if(distance > currentMaxDistance + 1 || distance < currentMaxDistance -1) {
            return false;
        }
    }
    return true;
}

void makeBalancedTree(shared_ptr<Node> root) {    
    root->left->left = std::make_shared<Node>("A");
    root->left->right = std::make_shared<Node>("D");

    root->right->right = std::make_shared<Node>("I");
    root->right->right->left = std::make_shared<Node>("H");
    
    root->left->right->left = std::make_shared<Node>("C");
    root->left->right->right = std::make_shared<Node>("E");
}

int main()
{
    auto root = std::make_shared<Node>(
        std::make_shared<Node>("B"),
        std::make_shared<Node>("G"),
        "F"
        );
    makeBalancedTree(root);
    
    cout << (isBalanced(root) ? "TRUE" : "FALSE");
}
