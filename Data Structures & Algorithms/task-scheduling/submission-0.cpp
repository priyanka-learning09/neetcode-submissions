class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                pq.push(freq[i]);
            }
        }
        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() || !q.empty())
        {
            time++;
            if(!q.empty() && q.front().first==time)
            {
                pq.push(q.front().second);
                q.pop();
            }
            if(!pq.empty())
            {
                int x=pq.top();
                x--;
                pq.pop();
                if(x>0)
                {
                    q.push({time+n+1,x});
                }
            }

            

        }
        return time;
    }
};
