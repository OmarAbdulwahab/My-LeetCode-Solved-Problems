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
        if(head->next == NULL)return head;
        // keep the correct nodes in a monotonic stack
        stack<int> st;
        ListNode* node = head;
        while(node != NULL){
            while(!st.empty() and st.top() < node->val)
                st.pop();
            
            st.push(node->val);
            node = node->next;
        }
        
        // convert the stack into a linked list
        ListNode* dummy = new ListNode();
        node = dummy;
        while(!st.empty()){
            int value = st.top();
            ListNode* tmp = new ListNode(value);
            node->next = tmp;
            node = node->next;
            st.pop();
        }
        
        // reverse the linked list 
        node = dummy->next;
        ListNode* tmp = node->next;
        // ListNode* nxt = tmp->next;
        node->next = NULL;
        while(tmp != NULL){
            ListNode* nxt = tmp->next;
            tmp->next = node;
            node = tmp;
            tmp = nxt;
        }
        
        return node;
    }
};








