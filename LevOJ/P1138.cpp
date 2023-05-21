/*
P1138 American Heritage
样例输入(先输入中序，后输入先序)
ABEDFCHG
CBADEFGH
样例输出
AEFDBHGC
解决：(分治，递归)
    前序遍历的首元素是根节点，
    在中序遍历中找到该元素，
    则该元素的左边为左子树，右边为右子树，兵器可以知道它们的长度
    前序遍历除去首元素后，左边为左子树，右边为右子树，根据上一步获取的长度可将他们分隔开
    =========递归左子树============
    此时前序遍历第一个节点是左子树的根节点
    在中序遍历中找到该元素，
    则该元素的左边为左子树，右边为右子树，
    前序遍历除去首元素，
    ..............................
    =========递归右子树============
    //此时根结点及左子树结点都被清空
    此时前序遍历第一个节点是右子树的根节点
    在中序遍历中找到该元素，
    则该元素的左边为左子树，右边为右子树，
    前序遍历除去首元素，
*/
#include <cstring>
#include <iostream>
using namespace std;

void postorder(string pre, string in)
{
    cout << pre << "," << in << endl;
    int len = pre.length();
    if (len == 0)
        return;
    if (len == 1)
    { //只有一个结点
        cout << pre[0];
        return;
    }
    // 查找根节点在中序序列中的位置
    // 中序遍历中pos左边为左子树，右边为右子树
    int pos = in.find(pre[0]);
    postorder(pre.substr(1, pos), in.substr(0, pos));
    postorder(pre.substr(pos + 1, len - pos - 1), in.substr(pos + 1, len - pos - 1));
    cout << pre[0];
}

void preorder(string inorder, string postorder) //由中序遍历+后序遍历序列，递归实现先序序列 (NLR)
{
    int len = postorder.length();
    if (len == 0) // 空树
        return;
    if (len == 1) // 单个结点
    {
        cout << inorder[0];
        return;
    }
    int pos = inorder.find(postorder[len - 1]);
    // 类似于先序遍历过程
    cout << postorder[len - 1];
    preorder(inorder.substr(0, pos), postorder.substr(0, pos));                             //先序遍历左子树
    preorder(inorder.substr(pos + 1, len - pos - 1), postorder.substr(pos, len - pos - 1)); //先序遍历右子树
}

int main()
{
    string pre, in;
    while (cin >> in >> pre)
    {
        postorder(pre, in);
        cout << endl;
    }
    return 0;
}
