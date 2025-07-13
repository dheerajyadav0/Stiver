class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();
        int cnt = 0 ;
        int found = 0 ;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        for(int i = 0 ; i<n ; i++ ){
            int x = lower_bound(trainers.begin()+found, trainers.end(),players[i])-trainers.begin();
            if(x == m ) break;
            found = x+1;
            cnt++;
        }
        return cnt;
    }
};