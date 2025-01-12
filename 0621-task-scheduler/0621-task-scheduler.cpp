class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char,int>mp;
        for(int i=0;i<tasks.size();i++)
        mp[tasks[i]]++;// freq

        priority_queue<int>pq;
        for(auto it:mp)pq.push(it.second);//

        int gaps=pq.top()-1;  // freq-1
        int idle=gaps*n;    // max idle time
        pq.pop();

        while(!pq.empty())
        {
            int freq=pq.top();
            pq.pop();

            idle-=min(freq,gaps);  // freq<gaps
        }

        if(idle<0)idle=0;

        return tasks.size()+idle;
    }
};