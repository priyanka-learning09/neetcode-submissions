class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
               int sum=nums[i]+nums[left]+nums[right];
               if(sum==0)
               {
                ans.insert({nums[i],nums[left],nums[right]});
                left++;
                right--;
               }
               else if(sum<0)
               {
                left++;
               }
               else
               {
                right--;
               }
            }
        }
        for(auto x:ans)
        {
            res.push_back(x);
            
        }
        return res;
    }
};
