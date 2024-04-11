#include "BinaryTree.hpp"

#include <vector>
int main(int argc, char const *argv[])
{
    int n, input;
    BinaryTree binaryTree;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        binaryTree.insert(input);
    }

    std::cout << binaryTree.size() << ' ' << binaryTree.depth() << ' ' << binaryTree.minimum() << ' ' << binaryTree.maximum() << std::endl;

    binaryTree.preorder();
    for (int i = 1; i <= 9; i++)
        (binaryTree.search(i) != nullptr) ? std::cout << "Yes\n" : std::cout << "No\n";
    return 0;
}
