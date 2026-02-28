// Example program
#include <iostream>
#include <memory>
#include <list>
#include <vector>

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
    if (!root) return lists;
    lists.push_back(ListPtrs{root});
    for(std::size_t i = 0; i < lists.size(); i++) {
        ListPtrs nextLevel;
        for(auto& node : lists[i]) {
            if(node->left != nullptr)
            {
                nextLevel.push_back(node->left);
            }
            if(node->right != nullptr)
            {
                nextLevel.push_back(node->right);
            }
        }
        if(!nextLevel.empty()) {
            lists.push_back(std::move(nextLevel));
        }
    }
    return lists;
}

int main()
{
    auto root = std::make_shared<Node>('a');
    root->left = std::make_shared<Node>('b');
    root->right = std::make_shared<Node>('c');

    root->left->left = std::make_shared<Node>('d');
    root->left->right = std::make_shared<Node>('e');

    root->right->left = std::make_shared<Node>('f');
    root->right->right = std::make_shared<Node>('g');

    root->left->right->left = std::make_shared<Node>('h');

    std::cout << "        " << root->value << "\n";
    std::cout << "       / \\\n";
    std::cout << "      " << root->left->value << "   " << root->right->value << "\n";
    std::cout << "     / \\ / \\\n";
    std::cout << "    " << root->left->left->value << "  " << root->left->right->value << " " << root->right->left->value << "  " << root->right->right->value << "\n";
    std::cout << "       /\n";
    std::cout << "      " << root->left->right->left->value << "\n\n";

    VList result = createLists(root);
    for(auto& list : result){
        std::cout << "[";
        for(auto &node : list) {
            std::cout << node->value;
        }
        std::cout << "]\n\n";
    }
}
