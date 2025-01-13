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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr; // Correct size check and return nullptr

        // Priority queue 
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Push the head nodes of all lists into the priority queue
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) { // Avoid null pointers
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while (!pq.empty()) {
            auto [val, minNode] = pq.top(); // Use structured binding for clarity
            pq.pop();

            temp->next = minNode;
            temp = temp->next;

            if (minNode->next) { // Push the next node from the same list into the queue
                pq.push({minNode->next->val, minNode->next});
            }
        }

        return dummy->next; // Return the merged list
    }
};
