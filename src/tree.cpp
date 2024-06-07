//
// Created by natek on 6/6/2024.
//
#include "tree.h"

//Abstracted Functions



//actual functions
int AVLTree::set_height(AVLTree::TreeNode *node)
{
    if(!node)
    {
        return 0;
    }
    else
    {
        return 1 + std::max(set_height(node->left), set_height(node->right));
    }

}

AVLTree::TreeNode* AVLTree::left_left(AVLTree::TreeNode* node)
{
    TreeNode* grandchild = node->left->right;
    TreeNode* new_parent = node->left;
    new_parent->right = node;
    node->left = grandchild;


    new_parent->height = set_height(new_parent);
    node->left->height = set_height(node->left);
    node->height = set_height(node);

    return new_parent;
}


AVLTree::TreeNode* AVLTree::left_right(AVLTree::TreeNode* node)
{
    node->left = right_right(node->left);
    return left_left(node);

}
AVLTree::TreeNode* AVLTree::right_right(TreeNode* node)
{
    TreeNode* grandchild = node->right->left;
    TreeNode* new_parent = node->right;
    new_parent->left = node;
    node->right = grandchild;

    new_parent->height = set_height(new_parent);
    node->right->height = set_height(node->right);
    node->height = set_height(node);

    return new_parent;
}

AVLTree::TreeNode* AVLTree::right_left(TreeNode* node)
{
    node->right = left_left(node->right);
    return right_right(node);

}

void AVLTree::printInorder()
{
    inorder_help(root);
}

void AVLTree::inorder_help(AVLTree::TreeNode* head)
{
    if(!head)
        return;

    else
    {
        inorder_help(head->left);
        std::cout << head->name << ", " << std::endl;
        inorder_help(head->right);
    }
}

void AVLTree::preorder_help(AVLTree::TreeNode *head)
{
    if(!head)
        return;

    std::cout << head->name << ", " << std::endl;
    preorder_help(head->left);
    preorder_help(head->right);
}

void AVLTree::printPreorder()
{
    preorder_help(root);
}

void AVLTree::postorder_help(AVLTree::TreeNode *head)
{
    if(!head)
        return;
    postorder_help(head->left);
    postorder_help(head->right);
    std::cout << head->name << ", " << std::endl;
}

void AVLTree::printPostorder()
{
    postorder_help(root);
}




