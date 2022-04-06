// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Concept used : Linked list
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
    ListNode* deleteMiddle(ListNode* head) {
        int len=0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            tmp=tmp->next;
            len++;
        }
        int mid = len/2;
        int i=0;
        tmp = head;
        ListNode* prev=NULL;
        while(i!=mid){
            i++;
            prev = tmp;
            tmp = tmp->next;
        }
        // NodeList* prev=tmp->next;
        if(len==1){
            return NULL;
        }
        if(len==2){
            head->next=NULL;
            return head;
        }
        prev->next = tmp->next;
        return head;
    }
};
