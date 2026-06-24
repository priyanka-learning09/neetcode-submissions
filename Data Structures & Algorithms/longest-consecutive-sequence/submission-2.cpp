class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> mp;
        for(int num:nums)
        {
            mp.insert(num);
        }
        int maxlen=0;
        for(auto x:mp)
        {
            if(mp.find(x-1)==mp.end())
            {
                int curr=x;
                int currlen=1;
                while(mp.find(curr+1)!=mp.end())
                {
                    curr++;
                    currlen++;
                }
                maxlen=max(maxlen,currlen);

            }
        }
        return maxlen;
    }
};
