#ifndef PROJECT1_TREE_H
#define PROJECT1_TREE_H
#include<iostream>
#include<vector>
#include<regex>

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
    TreeNode* root;



    TreeNode* left_left(TreeNode* node); // rotation methods
    TreeNode* left_right(TreeNode* node);
    TreeNode* right_right(TreeNode* node);
    TreeNode* right_left(TreeNode* node);
    int set_height(TreeNode* node);



    TreeNode* InsertHelp(TreeNode* node, std::string name, std::string ufid);

    std::vector<TreeNode*> inorder_help(TreeNode* head); // need for format and helps removeInorder function
    std::vector<TreeNode*> preorder_help(TreeNode* head);
    std::vector<TreeNode*> postorder_help(TreeNode* head); // needed for format
    int balance_factor(TreeNode* node); // used for balancing tree
    TreeNode* searchid_help(TreeNode* node, std::string id); // abstracts search ID function
    std::vector<TreeNode*> searchname_help(TreeNode* node, std::string name); // abstracts the search NAME function
    TreeNode* remove_help(TreeNode* node, std::string id); //helps abstract the remove function
    void clear(TreeNode* head); // use for destructor






public:

    TreeNode* getRoot() // only used for unit tests
    {
        return root;
    }

    std::vector<std::string> inorder_unit_test(TreeNode* head); // only used for help on the unit test


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

    ~AVLTree();
    AVLTree();


};






//helpers in private, others in public

#endif //PROJECT1_TREE_H
