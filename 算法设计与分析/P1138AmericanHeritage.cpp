#include <iostream>
#include <string>
using namespace std;
void fun(string s1, string s2);
int main()
{
    string s1, s2; // s1中序，s2前序
    while (cin >> s1)
    {
        cin >> s2;
        fun(s1, s2);
    }
    return 0;
}

void fun(string s1, string s2)
{
    if (s2.empty())
        return;
    else
    {
        char root = s2[0];                   //根节点
        int k = s1.find(root);               //在中序中找到根节点对应的位置
        s2.erase(s2.begin());                //删除第一个结点
        string inorleft = s1.substr(0, k);   //找到根结点的左子树的中序序列,不包含k
        string inorright = s1.substr(k + 1); //找到根节点的右子树的中序序列
        string preleft = s2.substr(0, k);    //找到根结点的左子树的前序序列
        string preright = s2.substr(k);      //找到根结点的右子树的前序序列
        fun(inorleft, preleft);
        fun(inorright, preright);
        cout << root;
    }
}