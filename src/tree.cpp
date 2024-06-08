//
// Created by natek on 6/6/2024.
//
#include "tree.h"
#include<regex>

//Abstracted Functions


AVLTree::TreeNode::TreeNode(std::string x, std::string y) : name(x), ufid(y), left(nullptr), right(nullptr){}
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
    TreeNode* new_parent = node->left;
    node->left = new_parent->right;
    new_parent->right = node;

    node->height = set_height(node);
    new_parent->height = set_height(new_parent);

    return new_parent;
}


AVLTree::TreeNode* AVLTree::left_right(AVLTree::TreeNode* node)
{
    node->left = right_right(node->left);
    return left_left(node);

}
AVLTree::TreeNode* AVLTree::right_right(TreeNode* node)
{
    TreeNode* new_parent = node->right;
    node->right = new_parent->left;
    new_parent->left = node;

    node->height = set_height(node);
    new_parent->height = set_height(new_parent);

    return new_parent;
}

AVLTree::TreeNode* AVLTree::right_left(TreeNode* node){

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

int AVLTree::balance_factor(AVLTree::TreeNode *node)
{
    return set_height(node->left) - set_height(node->right);
}

AVLTree::TreeNode* AVLTree::InsertHelp(AVLTree::TreeNode *node, std::string name, std::string ufid)
{
    if(!node) {
        return new TreeNode(name, ufid);

    }
    if(std::stoi(node->ufid) > std::stoi(ufid))
    {
        node->left = InsertHelp(node->left, name, ufid);
    }
    else if(std::stoi(node->ufid) < std::stoi(ufid))
    {
        node->right = InsertHelp(node->right, name, ufid);
    }
    else
        return node;

    node->height = set_height(node);
    int balance = balance_factor(node);
    if(balance > 1)
    {
        if(balance_factor(node->left) > 0)
        {
            node = left_left(node);
        }
        else
        {
            node = left_right(node);
        }
    }
    else if(balance < -1)
    {
        if(balance_factor(node->right) < 0)
        {
            node = right_right(node);
        }
        else
        {
            node = right_left(node);
        }
    }
    return node;


}

void AVLTree::insert(std::string name, std::string ufid)
{
    std::regex name_obj = std::regex("[a-zA-Z\\s]*");
    std::regex id_obj = std::regex("[0-9]{8}");
    if(!std::regex_match(name, name_obj) || !std::regex_match(ufid, id_obj))
    {
        std::cout << "unsuccessful" << std::endl;
        return;

    }
    std::cout << "successful" << std::endl;
    this->root =  InsertHelp(root, name, ufid);
}

void AVLTree::levelcount()
{
    std::cout << root->height << std::endl;
}

AVLTree::TreeNode* AVLTree::searchid_help(AVLTree::TreeNode *node, std::string id)
{

    if(node == nullptr)
        return nullptr;
    if(node->ufid == id)
        return node;

    if(std::stoi(id) > std::stoi(node->ufid))
    {
        return searchid_help(node->right, id);
    }
    else
    {
        return searchid_help(node->left, id);
    }
}

AVLTree::TreeNode* AVLTree::searchid(std::string id)
{
    return searchid_help(root, id);
}

void AVLTree::name_from_id(std::string id)
{
    TreeNode* node = searchid(id);
    if(!node)
        std::cout << "unsuccessful" << std::endl;
    else
    {
        std::cout << node->name << std::endl;
    }
}

AVLTree::TreeNode* AVLTree::searchname_help(AVLTree::TreeNode *node, std::string name)
{
    if(!node)
        return nullptr;
    else if(node->name == name)
    {
        return node;
    }
    else
    {
        TreeNode* left = searchname_help(node->left, name);
        if(left)
            return left;
        else
        {
            return searchname_help(node->right, name);
        }
    }
}

AVLTree::TreeNode* AVLTree::searchname(std::string name)
{
    return searchname_help(root, name);
}

void AVLTree::id_from_name(std::string name)
{
    TreeNode* node = searchname(name);
    if(!node)
        std::cout << "unsuccessful" << std::endl;
    else
    {
        std:: cout << node->ufid << std::endl;
    }
}