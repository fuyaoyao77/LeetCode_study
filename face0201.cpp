//面试题 02.01. 移除重复节点

/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        unordered_set<int> occurred = {head->val};
        ListNode* pos = head;
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            ListNode* cur = pos->next;
            if (!occurred.count(cur->val)) {  //判断val是否在集合occurred中，在返回1，不在返回0
                occurred.insert(cur->val);    // 插入val  删除是set.erase()
                pos = pos->next;
            } else {
                pos->next = pos->next->next;   //不能写成 pos = pos->next.  考虑cur的因素
            }
        }
        pos->next = nullptr;  //结尾
        return head;
    }
};

















