class Solution {
public:

    ListNode * Reverse(ListNode *head){
        ListNode* curr = head;
        ListNode *prev = nullptr;

        while(curr){
            ListNode *nextNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head||!head->next){
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast &&fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode * reverse2nd = Reverse(slow);
        
        while(reverse2nd){
            if(reverse2nd->val != head->val){
                return false;
            }
            reverse2nd = reverse2nd->next;
            head = head->next;
        }

        return true;

      
    }
};
