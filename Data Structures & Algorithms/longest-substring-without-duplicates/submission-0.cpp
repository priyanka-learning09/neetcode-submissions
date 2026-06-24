class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> mp;
        int left=0;
        int longest=0;
    
        for(int right=0;right<s.size();right++)
        {
            while(mp.count(s[right]))
            {
                mp.erase(s[left]);
                left++;
            }
            mp.insert(s[right]);
            longest=max(longest,right-left+1);
        }
        return longest;
    }
};
