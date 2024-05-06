/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head->next == NULL)
            return head;
        
        ListNode* new_head = reverse(head);
        ListNode* cur = new_head;
        int mx = cur->val;
        while(cur->next != NULL){
            // ListNode* prev = cur;
            if(cur->next->val < mx){
                cur->next = cur->next->next;
                // cur->next = tmp;
            }
            else{
                mx = cur->next->val;
                cur = cur->next;
            }
            // prev = cur;
            // mx = cur->next->val;
        }
        
        return reverse(new_head);
        
        
        
        // --------------------------------------------------------------------------------------------
        // keep the correct nodes in a monotonic stack (decreasing)
        // input: [24,5,2,13,3,8]
//         stack<int> st;
//         ListNode* node = head;
//         while (node != NULL) {
//             while (!st.empty() and st.top() < node->val)
//                 st.pop();

//             st.push(node->val);
//             node = node->next;
//         }
        // output: [24, 13, 8]

        // convert the stack into a linked list
        // ListNode* dummy = new ListNode();
        // node = dummy;
        // while (!st.empty()) {
        //     int value = st.top();
        //     ListNode* tmp = new ListNode(value);
        //     node->next = tmp;
        //     node = node->next;
        //     st.pop();
        // }
        // output: 8 -> 13 -> 24

        // reverse the linked list
        // node = dummy->next;
        // ListNode* tmp = node->next;
        // node->next = NULL;
        // while (tmp != NULL) {
        //     ListNode* nxt = tmp->next;
        //     tmp->next = node;
        //     node = tmp;
        //     tmp = nxt;
        // }
        // output: 24 -> 13 -> 8

        // return reverse(dummy->next);
    }
private:
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* cur = node;
        while(cur != NULL){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
};
