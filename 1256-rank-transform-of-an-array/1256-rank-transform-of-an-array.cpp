class Solution {
public:
    vector<int> arrayRankTransform(std::vector<int>& arr) {
       vector<pair<int, int >> val ; 
       int n = arr.size();
       for(int i = 0 ; i< n ; i++){
            val.push_back({arr[i],i});
       }
       sort(val.begin(),val.end());
        int rank = 1;
        vector<int>res(n);
       for(int i = 0 ; i< n ; i++){
        if(i>0 && val[i].first != val[i-1].first ){
            rank ++;
        }
            res[val[i].second] = rank ;
        
       }
       return res;
    }
};