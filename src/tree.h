#ifndef PROJECT1_TREE_H
#define PROJECT1_TREE_H
#include<iostream>
class AVLTree
{
private:
    struct TreeNode
    {

        std::string name;
        std::string ufid;
        int height = 0;
        TreeNode *left;
        TreeNode *right;
        TreeNode(std::string x, std::string y);
    };

    TreeNode* root = nullptr;

    void balance(TreeNode* node);
    TreeNode* left_left(TreeNode* node);
    TreeNode* left_right(TreeNode* node);
    TreeNode* right_right(TreeNode* node);
    TreeNode* right_left(TreeNode* node);
    int set_height(TreeNode* node);



    TreeNode* InsertHelp(TreeNode* node, std::string name, std::string ufid);

    void inorder_help(TreeNode* head);
    void preorder_help(TreeNode* head);
    void postorder_help(TreeNode* head);
    int balance_factor(TreeNode* node);
    TreeNode* searchid_help(TreeNode* node, std::string id);
    TreeNode* searchname_help(TreeNode* node, std::string name);






public:
    TreeNode* getRoot();

    void insert(std::string name, std::string id);

    void remove(std::string id);

    TreeNode* searchid(std::string id);
    void name_from_id(std::string id);

    TreeNode* searchname(std::string name);
    void id_from_name(std::string name);

    void printInorder();
    void printPreorder();
    void printPostorder();

    void removeInorder(int N);
    void levelcount();

};






//helpers in private, others in public

#endif //PROJECT1_TREE_H
