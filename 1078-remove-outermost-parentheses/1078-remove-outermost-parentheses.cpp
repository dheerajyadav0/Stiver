class Solution {
public:
    string removeOuterParentheses(string s) {
        string result ;
        int count = 0 ;
        int n = s.size();
        for(int i =0 ; i< n; i++){

         if(s[i]=='('){
             if(count>0){
                result += s[i];
             }
             count++;       
         }else{
            count--;
         
         if(count>0){
            result += s[i];
         }
         }
    }
    return result ;
    }
};