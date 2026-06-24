class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        vector<int> ans;
        for(auto x: mp)
        {
            buckets[x.second].push_back(x.first);
        }
        for(int i=nums.size();i>=0;i--)
        {
            for(int y:buckets[i])
            {
                ans.push_back(y);
                k--;
                if(k==0)
                {
                    return ans;
                }
            }
        }
      return  {};  
    }
};
