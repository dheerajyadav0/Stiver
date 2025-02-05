class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        stack<int>st;
        for(int i = 0 ; i< s1.length(); i++ ){
            if(s1[i]!= s2[i])
            st.push(i);

        } 
        if(st.empty()) return true ;

        if(st.size()!=2) return false ; 

        int f = st.top() ; st.pop();
        int l = st.top() ; st.pop();
        if(s1[f]==s2[l] && s1[l] == s2 [f]) return  true ; 
        return false;
    }
};