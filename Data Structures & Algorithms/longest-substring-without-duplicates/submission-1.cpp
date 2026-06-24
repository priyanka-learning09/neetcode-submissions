class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left=0;
        set<char> mp;
        int maxlen=0;
        for(int right=0;right<s.size();right++)
        {
            while(mp.count(s[right]))
            {
                mp.erase(s[left]);
                left++;
            }
                maxlen=max(maxlen,right-left+1);

            mp.insert(s[right]);

        }
        return maxlen;
        

        
    }
};
