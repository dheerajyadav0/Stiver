class Solution {
public:
    bool check(vector<int>& arr) {
        
        int flag =0 ; 
        int n = arr.size();
        for(int i =0; i<n-1 ; i++){
            if(arr[i]>arr[i+1]){
                
                flag++;
            }
        
        }
        if(arr[arr.size()-1]>arr[0]) flag++;

        if(flag>1){
        return false;
        }
        else{
            return true ;
        }
    }
};