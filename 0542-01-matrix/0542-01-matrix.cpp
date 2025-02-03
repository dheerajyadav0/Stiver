// class Solution {

// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         int dirr[] ={-1,0,1,0};
//         int dirc[]= {0,+1,0,-1}
//          int m = mat.size();
//          int n = mat[0].size();
//         vector<vector<int>>vis[m][n]={0};
//         vector<vector<int>>dis;
//         queue<int, int>q;
//         for(int i = 0 ; i< m ; i++){
//             for(int j =0 ; j<n ; j++){
//                 if(mat[i][j]==1){
//                     q.push({i,j});
//                     vis[i][j]=1
//                 }else{
//                     vis[i][j]=0;
//                 }
//             }
//         }
//         queue<int, int>q;
//         while(!q.empty()){
//             int q.size()= int sz; 
//             while(sz--){
//                 pair<int , int>p = q.front();
//                 int row = p.first;
//                 int col = p.second;
//                 q.pop();

//                 for(int i ; i<4 ;i++){
//                     int nrow = row + dirr[i];
//                     int ncol = col + dirc[i];

//                     if(nrow>0 && )
//                 }
//             }

//             return mat;
//         }
        
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        int dirr[] = {-1, 0, 1, 0};
        int dirc[] = {0, 1, 0, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
              int sz = q.size();
            while(sz--){
                pair<int , int>p = q.front();
                int row = p.first;
                int col = p.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + dirr[i];
                int ncol = col + dirc[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && dist[nrow][ncol] == -1) {
                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        }
        return dist;
    }
};