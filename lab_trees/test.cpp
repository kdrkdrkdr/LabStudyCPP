/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}

/**
 * Private helper function for the public mirror function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
    // Base case - null node
    if (subRoot == nullptr)
        return;

    // Swap left and right subtrees
    Node* temp = subRoot->left;
    subRoot->left = subRoot->right;
    subRoot->right = temp;

    // Recursively mirror the left and right subtrees
    mirror(subRoot->left);
    mirror(subRoot->right);
}

// Example usage:

int main()
{
    BinaryTree<int> bst;

    // Build a sample binary tree
    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);

    // Print original tree
    std::cout << "Original Tree: ";
    bst.printLeftToRight();
    std::cout << std::endl;

    // Mirror the tree
    bst.mirror();

    // Print mirrored tree
    std::cout << "Mirrored Tree: ";
    bst.printLeftToRight();
    std::cout << std::endl;

    return 0;
}