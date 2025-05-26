class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<int> arr;
        ListNode* temp = head;


        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

       
        temp = head;
        for (int val : arr) {
            temp->val = val;
            temp = temp->next;
        }

        return head;
    }
};
