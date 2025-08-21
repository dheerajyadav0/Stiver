class Solution {
public:
vector<vector<string>> ans;
bool check(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;--j;
    }
    return true;
}
void f(int i,string &s,vector<string> &ds){
    if(i==s.size()){
       ans.push_back(ds);
       return;
    }

    for(int k=i;k<s.size();++k){
        if(check(i,k,s)){
            string temp=s.substr(i,k-i+1);
            ds.push_back(temp);
            f(k+1,s,ds);
            ds.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        f(0,s,ds);
        return ans;
    }
};