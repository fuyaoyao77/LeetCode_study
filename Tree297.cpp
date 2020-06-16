//297. 二叉树的序列化与反序列化

/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。



*/

//  括号表示编码 + 递归下降解码
 


/*
思路和算法

我们也可以这样表示一颗二叉树：

如果当前的树为空，则表示为 X
如果当前的树不为空，则表示为 (<LEFT_SUB_TREE>)CUR_NUM(RIGHT_SUB_TREE)，其中：
<LEFT_SUB_TREE> 是左子树序列化之后的结果
<RIGHT_SUB_TREE> 是右子树序列化之后的结果
CUR_NUM 是当前节点的值
根据这样的定义，我们很好写出序列化的过程，后序遍历这颗二叉树即可，那如何反序列化呢？根据定义，我们可以推导出这样的巴科斯范式（BNF）：


T -> (T) num (T) | X
它的意义是：用 T 代表一棵树序列化之后的结果，| 表示 T 的构成为 (T) num (T) 或者 X，| 左边是对 T 的递归定义，右边规定了递归终止的边界条件。

因为：

T 的定义中，序列中的第一个字符要么是 X，要么是 (，所以这个定义是不含左递归的
当我们开始解析一个字符串的时候，如果开头是 X，我们就知道这一定是解析一个「空树」的结构，如果开头是 (，我们就知道需要解析 (T) num (T) 的结构，因此这里两种开头和两种解析方法一一对应，可以确定这是一个无二义性的文法
我们只需要通过开头的第一个字母是 X 还是 ( 来判断使用哪一种解析方法
所以这个文法是 LL(1) 型文法，如果你不知道什么是 LL(1) 型文法也没有关系，你只需要知道它定义了一种递归的方法来反序列化，也保证了这个方法的正确性——我们可以设计一个递归函数：

这个递归函数传入两个参数，带解析的字符串和当前当解析的位置 ptr，ptr 之前的位置是已经解析的，ptr 和 ptr 后面的字符串是待解析的
如果当前位置为 X 说明解析到了一棵空树，直接返回
否则当前位置一定是 (，对括号内部按照 (T) num (T) 的模式解析
具体请参考下面的代码

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/er-cha-shu-de-xu-lie-hua-yu-fan-xu-lie-hua-by-le-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "X";
        auto l = "(" + serialize(root->left) + ")";
        auto r = "(" + serialize(root->right) + ")";
        return  l + to_string(root->val) + r;
    }

    inline TreeNode* parseSubtree(const string &data, int &ptr) {
        ++ptr; // 跳过左括号
        auto subtree = parse(data, ptr);
        ++ptr; // 跳过右括号
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0';
        }
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
};



