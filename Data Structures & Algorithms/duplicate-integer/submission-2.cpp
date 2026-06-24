class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        set<int> copy;
        for(int num:nums)
        {
            if(copy.count(num))
            {
                return true;
            }
            copy.insert(num);
        }
        return false;
        
    }
};