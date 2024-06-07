#ifndef PROJECT1_TREE_H
#define PROJECT1_TREE_H
#include<iostream>
class AVLTree
{
private:
    struct TreeNode
    {
        //This is the code for a singular
        int val;
        std::string name;
        std::string ufid;
        int height;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode* root = nullptr;

    void balance(TreeNode* node);
    TreeNode* left_left(TreeNode* node);
    TreeNode* left_right(TreeNode* node);
    TreeNode* right_right(TreeNode* node);
    TreeNode* right_left(TreeNode* node);
    int set_height(TreeNode* node);


    TreeNode* InsertHelp(TreeNode* node, std::string name, int ufid);

    void inorder_help(TreeNode* head);
    void preorder_help(TreeNode* head);
    void postorder_help(TreeNode* head);







public:
    void insert(std::string name, int id);
    void remove(int id);
    void search(int id);
    void search(std::string name);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int N);
};






//helpers in private, others in public

#endif //PROJECT1_TREE_H
