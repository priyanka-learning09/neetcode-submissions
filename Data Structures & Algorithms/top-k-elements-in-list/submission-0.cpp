class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto x: mp)
        {
            buckets[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=nums.size();i>=0;i--)
        {
            for(int nums:buckets[i])
            {
                ans.push_back(nums);
                k--;
                if(k==0)
                {
                    return ans;
                }
            }

        }
        
    }
};
