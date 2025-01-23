class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr(m,0);
        vector<int> brr(n,0);

        int total = 0;
            for(int i = 0 ; i < m ; i++){
                for(int j=0 ; j<n ; j++){
                    if(grid[i][j]==1){
                    arr[i]++;
                    brr[j]++;
                    total++;
                    }
                }
            }
            for(int i = 0 ; i< m ; i++){
                for(int j = 0; j<n ; j++){
                    if((grid[i][j]!= 0)&&(arr[i]==1 && brr[j]== 1)){
                        total--;
                    }
                }
            }
      return total;
    }
};