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
    /*
    ** Time complexity: O(|l1| + |l2|)
    ** Space complexity: O(|l1| + |l2|)
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) {
        return l2;
      }
      
      if (l2 == nullptr) {
        return l1;
      }
      
      ListNode* currentNode = nullptr;
      ListNode* mergedList = nullptr;
     
      if (l1->val < l2->val) {
        currentNode = new ListNode(l1->val);
        l1 = l1->next;
      }
      else {
        currentNode = new ListNode(l2->val);
        l2 = l2->next;
      }
      
      mergedList = currentNode;
      
      while (l1 != nullptr and l2 != nullptr) {
        if (l1->val < l2->val) {
          currentNode->next = new ListNode(l1->val);
          l1 = l1->next;
        }
        else {
          currentNode->next = new ListNode(l2->val);
          l2 = l2->next;
        }
        
        currentNode = currentNode->next; 
      }

      while (l1 != nullptr) {
        currentNode->next = new ListNode(l1->val);
        l1 = l1->next;
        currentNode = currentNode->next;
      }
      
      while (l2 != nullptr) {
        currentNode->next = new ListNode(l2->val);
        l2 = l2->next;
        currentNode = currentNode->next;
      }
      
      return mergedList;
    }
};

