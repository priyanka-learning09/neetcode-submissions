class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp.insert(nums[i]);
        }
        int longest=0;
        for(int num:mp)
        {
            if(mp.find(num-1)==mp.end())
            {
                int curnum=num;
                int curlen=1;
                while(mp.find(curnum+1)!=mp.end())
                {
                    curnum++;
                    curlen++;
                }
                longest=max(longest,curlen);
            }
        }
       return longest; 
    }
};
