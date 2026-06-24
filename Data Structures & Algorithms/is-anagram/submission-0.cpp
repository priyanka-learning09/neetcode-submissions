class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> freq(26);
        if(s.size()!=t.size())
        {
            return false;
        }
        int i=0;
        while(s[i])
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
            i++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0)
            {
                return false;
            }
        }
        return true;

        
    }
};
