#pragma once
#include <iostream>
#include <string>
#include <stack>

struct Node
{
    std::string val;
    std::string key;
    Node *right;
    Node *left;

    Node(std::string _v = "", std::string _k = "", Node *_r = NULL, Node *_l = NULL) : val(_v), key(_k), right(_r), left(_l) {}
    /* data */
};

void printTRL(std::ostream &o, Node *root, Node *curr, int lvl)
{
    if (root == NULL)
        return;
    if (root == curr)
        o << "*";
    else
        o << " ";
    for (int i = 0; i < lvl; i++)
    {
        o << "  ";
    }
    o << root->val << std::endl;
    printTRL(o, root->right, curr, lvl + 1);
    printTRL(o, root->left, curr, lvl);
}

void delRLT(Node *root)
{
    if (root == NULL)
        return;

    delRLT(root->right);
    delRLT(root->left);
    // std::cout << root->val;
    delete root;
    root = NULL;
}

void my_findTRL(Node *root, std::string k)
{
    if (root == NULL)
        return;
    std::stack<Node *> s1;
    Node *tmp = root;

    while (tmp != NULL || !s1.empty())
    {
        if (!s1.empty())
        {
            tmp = s1.top();
            s1.pop();
        }
        while (tmp != NULL)
        {
            if (k == tmp->key)
            {
                std::cout << "find is:" << tmp->val << "\n";
                return;
            }
            if (tmp->right != NULL)
                s1.push(tmp->right);
            tmp = tmp->left;
        }

        // if(tmp->key==k)
        //     return tmp->key;
        // s1.push(tmp);
        // if(tmp->right!=NULL)
        //     tmp=tmp->right;
    }

    return;
    //  while (top!=null || !stack.empty()){
    //          if (!stack.empty()){
    //              top=stack.pop();
    //          }
    //          while (top!=null){
    //              top.treatment();
    //              if (top.right!=null) stack.push(top.right);
    //              top=top.left;
    //          }
    //      }
}

class Text
{
private:
    Node *root;
    Node *curr;
    std::stack<Node *> s;

public:
    Text()
    {
        // root=curr=NULL;
        Node *n1 = new Node("n1", "k2");
        Node *n2 = new Node("n2", "k1");
        Node *n3 = new Node("n3", "k3", n2);
        root = curr = new Node("root", "k", n1, n3);
    }

    ~Text()
    {
        delRLT(root);
    }

    void right()
    {
        if (root == NULL)
            throw "root is nullptr";
        if (curr == NULL)
            throw "current is nullptr";
        if (curr->right == NULL)
            throw "I cant move right, becouse theres is nothing there";
        s.push(curr);
        curr = curr->right;
        return;
    }

    void left()
    {
        if (root == NULL)
            throw "root is nullptr";
        if (curr == NULL)
            throw "current is nullptr";
        if (curr->left == NULL)
            throw "I cant move left, becouse theres is nothing there";
        s.push(curr);
        curr = curr->left;
        return;
    }

    void up()
    {
        if (root == NULL)
            throw "root is nullptr";
        if (curr == NULL)
            throw "current is nullptr";
        if (s.empty())
            throw "I cant move up, becouse theres is nothing there";
        curr = s.top();
        s.pop();
        return;
    }

    void add_l(std::string s = "", std::string key = "")
    {
        if (root == NULL)
        {
            root = curr = new Node(s, "r0");
            return;
        }

        Node *new_el = new Node(s, key);

        if (curr->left == NULL)
        {
            curr->left = new_el;
        }
        else
        {
            new_el->left = curr->left;
            curr->left = new_el;
        }
    }

    void add_r(std::string s = "", std::string key = "")
    {
        if (root == NULL)
        {
            root = curr = new Node(s, "r0");
            return;
        }

        Node *new_el = new Node(s, key);

        if (curr->right == NULL)
        {
            curr->right = new_el;
        }
        else
        {
            new_el->left = curr->right;
            curr->right = new_el;
        }
    }

    void del_branch()
    {
        if (curr == NULL)
            throw "is NULL!";

        if(curr->right!=NULL)
        {
            delRLT(curr->right);
            curr->right=NULL;
        }

        if(curr==root)
        {
            curr=curr->left;
            delete root;
            root = curr;
        }
        else
        {
            Node* tmp = s.top();
            if(tmp->right==curr)
            {
                tmp->right=curr->left;
                delete curr;
                curr=tmp;
            }
            else
            {
                tmp->left=curr->left;
                delete curr;
                curr = tmp;
            }
        }      
        

    }

    void find(std::string k)
    {
        if (curr != NULL)
            my_findTRL(curr, k);
        return;
    }

    friend std::ostream &operator<<(std::ostream &o, const Text &t)
    {
        printTRL(o, t.root, t.curr, 0);
        // std::cout<<t.s.size()<<std::endl;
        return o;
    }
};
