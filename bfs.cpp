// Example program
#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>
#include <ostream>

struct Node{
    Node(char val) : left(nullptr), right(nullptr), value(val) {}
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    char value;
};

using ListPtrs = std::list<std::shared_ptr<Node>>;
using VList = std::vector<ListPtrs>;

VList createLists(std::shared_ptr<Node> root) {
    VList lists;
    lists.push_back(ListPtrs{root});
    for(std::size_t i = 0; i < lists.size(); i++) {
        if(lists[i].size()) {
            lists.push_back(ListPtrs());
        }
        for(auto& node : lists[i]) {
            if(node->left != nullptr)
            {
                lists[i+1].push_back(node->left);
            }
            if(node->right != nullptr)
            {
                lists[i+1].push_back(node->right);
            }
        }
    }
    return lists;
}

int main()
{
    std::shared_ptr<Node> root(new Node('a'));
    root->left.reset(new Node('b'));
    root->right.reset(new Node('c'));

    root->left->left.reset(new Node('d'));
    root->left->right.reset(new Node('e'));

    root->right->left.reset(new Node('f'));
    root->right->right.reset(new Node('g'));

    root->left->right->left.reset(new Node('h'));

    VList result = createLists(root);
    for(auto& list : result){
        if(list.size()) std::cout << "[";
        for(auto &node : list) {
            std::cout << node->value;
        }
        if(list.size()) std::cout << "]\n\n";
    }
}

