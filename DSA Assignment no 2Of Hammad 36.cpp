#include <iostream>
#include <stack>
#include<string>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;
struct tree_node
{
    public:
    int val=0;
    char var='0';
    tree_node *left, *right;
    char getChar(){return var;}
    void setValue(int v){val=v;}
    int getValue(){return val;}
};
class exp_tree
{
    string postfix;
    tree_node *root;

public:

    int evaluateExpTree(tree_node *start)
    {
        if (start != nullptr)
        {
            if ((start->left == NULL && start->right == NULL))
            {
                return start->getValue();
            }
            int left = evaluateExpTree(start->left);
            int right = evaluateExpTree(start->right);
            if (start->getChar() == '+')
            {
                return left + right;
            }
            if (start->getChar() == '-')
            {
                return left - right;
            }
            if (start->getChar() == '*')
            {
                return left * right;
            }
            if (start->getChar() == '/')
            {
                return left / right;
            }
            if (start->getChar() == '^')
            {
                return pow(left, right);
            }
        }
        else
        {
            cout << "Tree is Empty";
        }
    }
    void afterRandomVal(tree_node *tmp)
    {
    if (tmp == NULL)
        return;
    afterRandomVal(tmp->left);
    afterRandomVal(tmp->right);
    if(tmp->var >='a'&& tmp->var<='z')
    {

        cout <<tmp->getChar()<<"="<< tmp->val<<" ";
    }
    }
    int generateRandomValues()
    {
            return (rand() % (20 - 1 + 1) - 1 );
    }
    void randomValues(tree_node *start)
    {
        if (start)
        {
            if ((start->getChar() >= 'a' && root->getChar() <= 'z'))
            {
                start->setValue(generateRandomValues());
            }
            randomValues(start->left);
            randomValues(start->right);
        }
    }
    exp_tree()
    {
        root = NULL;
    }
    void get_exp()
    {
        // cout << "Enter the infix expression ";
        // string infix;
        // cin >> infix;
        postfix = convert("a+b*c/d");
    }

    int priority(char alpha)
    {
        if (alpha == '+' || alpha == '-')
            return 1;

        if (alpha == '*' || alpha == '/')
            return 2;

        if (alpha == '^')
            return 3;

        return 0;
    }

    string convert(string infix)
    {
        int i = 0;
        string postfix = "";

        stack<int> s;

        while (infix[i] != '\0')
        {

            if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z')
            {
                postfix += infix[i];
                i++;
            }

            else if (infix[i] == '(')
            {
                s.push(infix[i]);
                i++;
            }

            else if (infix[i] == ')')
            {
                while (s.top() != '(')
                {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
                i++;
            }
            else
            {
                while (!s.empty() && priority(infix[i]) <= priority(s.top()))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.push(infix[i]);
                i++;
            }
        }
        while (!s.empty())
        {
            postfix += s.top();
            s.pop();
        }

        cout << "Postfix created " << endl;


        return postfix;
    }
    void inorder(tree_node *);

    tree_node *get_root()
    {
        return root;
    }
    void exp_to_tree();
    void postorder(tree_node *);
};
void exp_tree::exp_to_tree()
{
    int top = -1, z;
    tree_node *stack[20];
    for (int i = 0; postfix[i] != 0; i++)
    {
        stack[++top] = new tree_node;
        if (postfix[i] >= 97 && postfix[i] <= 122)
        {
            stack[top]->var = postfix[i];
            stack[top]->left = stack[top]->right = NULL;
        }
        else
        {
            stack[top]->var = postfix[i];
            stack[top]->left = stack[top - 2];
            stack[top]->right = stack[top - 1];
            top = top - 2;
            root = stack[top] = stack[top + 2];
        }
    }
}

void exp_tree::postorder(tree_node *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->var;
}


int main()
{
    srand(time(NULL));

    exp_tree exp;
    exp.get_exp();
    exp.exp_to_tree();
    exp.postorder(exp.get_root());
    cout<<"\nTree created sucsefully\n";
    cout<<"Randomly Assigning Values to variables\nAfter Assignment of values";
    exp.randomValues(exp.get_root());
    exp.afterRandomVal(exp.get_root());
    cout<<"\nCongtatulations Final Result is : ";
    cout<<"Final"<<exp.evaluateExpTree(exp.get_root());
    return 0;
}