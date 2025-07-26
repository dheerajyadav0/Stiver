// int sum = 0;
//          int mod = 1e9+7;
//     int n = arr.size();
//     for (int i = 0; i < n; i++) {
//         int large = arr[i];
//         int small = arr[i];
//         for (int j = i + 1; j < n; j++) {
//             large = max(large, arr[j]);
//             small = min(small, arr[j]);
//             sum += (large - small)%mod;
//         }
//     }
//     return (long long )sum;

class Solution {
    vector<int> getmax(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getmin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

public:
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long totalMax = 0, totalMin = 0;

        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;

            int left = i, right = i;
            while (left - 1 >= 0 && arr[left - 1] <= arr[i]) left--;
            while (right + 1 < n && arr[right + 1] < arr[i]) right++;
            totalMax += (long long)(i - left + 1) * (right - i + 1) * arr[i];

            left = i, right = i;
            while (left - 1 >= 0 && arr[left - 1] >= arr[i]) left--;
            while (right + 1 < n && arr[right + 1] > arr[i]) right++;
            totalMin += (long long)(i - left + 1) * (right - i + 1) * arr[i];
        }

        return totalMax - totalMin;
    }
};
