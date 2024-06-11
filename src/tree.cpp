//
// Created by natek on 6/6/2024.
//
#include "tree.h"

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
        return 1 + std::max(set_height(node->left), set_height(node->right)); // recursively set the height
    }

}

AVLTree::TreeNode* AVLTree::left_left(AVLTree::TreeNode* node) //in the case of left left imbalance, perform a right rotation
{
    TreeNode* new_parent = node->left;
    node->left = new_parent->right;
    new_parent->right = node;

    node->height = set_height(node);
    new_parent->height = set_height(new_parent);

    return new_parent;
}


AVLTree::TreeNode* AVLTree::left_right(AVLTree::TreeNode* node) // left rotation followed by right rotation
{
    node->left = right_right(node->left);
    return left_left(node);

}
AVLTree::TreeNode* AVLTree::right_right(TreeNode* node) // left rotation
{
    TreeNode* new_parent = node->right;
    node->right = new_parent->left;
    new_parent->left = node;

    node->height = set_height(node);
    new_parent->height = set_height(new_parent);

    return new_parent;
}

AVLTree::TreeNode* AVLTree::right_left(TreeNode* node) // right rotation followed by left rotation
{

    node->right = left_left(node->right);
    return right_right(node);

}

void AVLTree::printInorder()
{

    std::vector<TreeNode*> t = inorder_help(root);
    for(auto i = 0; i < t.size(); i++)
    {
        std::cout << t[i]->name;
        if(i != t.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

std::vector<AVLTree::TreeNode*> AVLTree::inorder_help(AVLTree::TreeNode* head) //return a vector for format issues
{
    std::vector<TreeNode*> t;
    if(!head)
        return t;
    std::vector<TreeNode*> left = inorder_help(head->left);
    std::vector<TreeNode*> right = inorder_help(head->right);


    //inorder, left, head, right
    t.insert(t.end(), left.begin(), left.end());
    t.push_back(head);
    t.insert(t.end(), right.begin(), right.end());
    return t;
}

std::vector<AVLTree::TreeNode*> AVLTree::preorder_help(AVLTree::TreeNode *head)
{
    std::vector<TreeNode*> t;
    if(!head)
        return t;
    std::vector<TreeNode*> left = preorder_help(head->left);
    std::vector<TreeNode*> right = preorder_help(head->right);

    //preorder, head, left, right
    t.push_back(head);
    t.insert(t.end(), left.begin(), left.end());
    t.insert(t.end(), right.begin(), right.end());
    return t;
}

void AVLTree::printPreorder()
{
    std::vector<TreeNode*> t = preorder_help(root);
    for(auto i = 0; i < t.size(); i++)
    {
        std::cout << t[i]->name;
        if(i != t.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

std::vector<AVLTree::TreeNode*> AVLTree::postorder_help(AVLTree::TreeNode *head)
{
    std::vector<TreeNode*> t;
    if(!head)
        return t;
    std::vector<TreeNode*> left = postorder_help(head->left);
    std::vector<TreeNode*> right = postorder_help(head->right);

    //left, right, visit
    t.insert(t.end(), left.begin(), left.end());
    t.insert(t.end(), right.begin(), right.end());
    t.push_back(head);
    return t;
}

void AVLTree::printPostorder()
{
    std::vector<TreeNode*> t = postorder_help(root);
    for(auto i = 0; i < t.size(); i++)
    {
        std::cout << t[i]->name;
        if(i != t.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int AVLTree::balance_factor(AVLTree::TreeNode *node)
{
    // used for rotations after insert
    return set_height(node->left) - set_height(node->right);
}

AVLTree::TreeNode* AVLTree::InsertHelp(AVLTree::TreeNode *node, std::string name, std::string ufid)
{

    if(!node) {
        std::cout << "successful" <<std::endl;
        return new TreeNode(name, ufid);
    }
    if(std::stoi(node->ufid) > std::stoi(ufid))
    { //insert recursively
        node->left = InsertHelp(node->left, name, ufid);

    }
    else if(std::stoi(node->ufid) < std::stoi(ufid))
    {
        node->right = InsertHelp(node->right, name, ufid);

    }
    else
    {
        std::cout << "unsuccessful" <<std::endl;
        return node;
    }

    //check for balance after the inserts, from the bottom up
    node->height = set_height(node);
    int balance = balance_factor(node);

    //handle all cases for imbalance
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



    this->root = InsertHelp(root, name, ufid);
}

void AVLTree::levelcount() // prints the amount of levels in the tree
{
    std::cout << set_height(root) << std::endl;
}

AVLTree::TreeNode* AVLTree::searchid_help(AVLTree::TreeNode *node, std::string id)
{
//recursively finds the node with the given id, O(h) time, where h is the height of the tree
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


void AVLTree::name_from_id(std::string id)
{

    TreeNode* node = searchid_help(root, id);
    if(!node)
        std::cout << "unsuccessful" << std::endl;
    else
    {
        std::cout << node->name << std::endl;
    }
}

std::vector<AVLTree::TreeNode*> AVLTree::searchname_help(AVLTree::TreeNode *node, std::string name)
{//O(n) time, where n is number of nodes. this is because the tree is not sorted by name
    std::vector<TreeNode*> t; // make a vector in the case of duplicate names
    if(!node)
        return t;
    if(node->name == name)
    {
        t.push_back(node);
    }
    if(node->left)
    {
        std::vector<TreeNode*> l = searchname_help(node->left, name);
        t.insert(t.end(), l.begin(), l.end());
    }
    if(node->right)
    {
        std::vector<TreeNode*> r = searchname_help(node->right, name);
        t.insert(t.end(), r.begin(), r.end());
    }

    return t;
}



void AVLTree::id_from_name(std::string name)
{
    std::vector<TreeNode*> ids = searchname_help(root, name);
    if(ids.empty()) //case where no names were found
        std::cout << "unsuccessful" << std::endl;
    else
    { // print every name in the vector
        for(int i = 0; i < ids.size(); i++)
        {
            std::cout << ids[i]->name << std::endl;
        }
    }
}
AVLTree::TreeNode* AVLTree::remove_help(AVLTree::TreeNode *head, std::string id)
{
    if(head == nullptr)
    {
        std::cout << "unsuccessful" <<std::endl;
        return head;
    }
    if(std::stoi(head->ufid) > std::stoi(id))
    {
        head->left = remove_help(head->left, id);
    }
    else if(std::stoi(head->ufid) < std::stoi(id))
    {
        head->right = remove_help(head->right, id);
    }
    else
    {
        if(!head->right || !head->left) // no children or one child
        {
            TreeNode* child = head->right ? head->right : head->left;
            if(!child)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                *head = *child;
                delete child;
            }
            std::cout << "successful" << std::endl;
        }
        else
        {
            TreeNode* successor = head->right;
            while(successor->left)
                successor = successor->left;
            head->ufid = successor->ufid;
            head->name = successor->name;

            head->right = remove_help(head->right, successor->ufid);
            std::cout << "successful" << std::endl;
        }


    }

    return head;


}

void AVLTree::remove(std::string id)
{
    root = remove_help(root, id);
}

void AVLTree::removeInorder(int N)
// call the inorder function to get a vector of the nodes inorder, then call delete on the Nth node
{
    std::vector<TreeNode*> nodes = inorder_help(root);
    if(N <  0 || N > nodes.size()-1)
    {
        std::cout << "unsuccessful" << std::endl;
        return;
    }
    remove(nodes[N]->ufid);
}

AVLTree::AVLTree()
{
    root = nullptr; // initializes tree
}
AVLTree::~AVLTree()
{
    clear(root); //frees allocated memory
}
void AVLTree::clear(AVLTree::TreeNode *head)
{
    if(!head)
        return;
    clear(head->left);
    clear(head->right);
    delete head;
}