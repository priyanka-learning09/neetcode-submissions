class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int m=s.size();
        int n=t.size();
        if(m!=n)
        {
            return false;
        }
        int i=0;
        vector<int> freq(26);
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
