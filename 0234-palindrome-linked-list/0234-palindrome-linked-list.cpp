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
    bool palin(vector<int>& arr){
        int s = 0 ;
        int e = arr.size()-1;
        while(s <= e){
            if(arr[s] != arr[e]) return false;
            s++;
            e--;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> arr ;
        while(head != NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        return palin(arr);
    }
};