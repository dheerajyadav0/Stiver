// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         vector<int>left(0,n);
//         vector<int >right(0,n);
        
//         int sum = 0 ;
//         for(int i = 1 ; i< k ; i++){
//             left[i] = left[i-1]+cardPoints[i-1];
//         }
//         for(int i = 1; i<k ; i++){
//             right[i] = right[i-1] + cardPoints[n-i]; 
//         }
//         int maxx = 0 ;
//         for(int i = 0 ;i<k ; i++){
//             maxx = max(left[i],right[i]);
//         }
//         return maxx ;
//     }
// };

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        vector<int> left(k + 1, 0);
        vector<int> right(k + 1, 0);


        for (int i = 1; i <= k; i++) {
            left[i] = left[i - 1] + cardPoints[i - 1];
        }

        for (int i = 1; i <= k; i++) {
            right[i] = right[i - 1] + cardPoints[n - i];
        }

        // Find the max sum by considering different split points
        int maxx = 0;
        for (int i = 0; i <= k; i++) {
            maxx = max(maxx, left[i] + right[k - i]);
        }

        return maxx;
    }
};