class Solution {
public:
    bool valid(vector<int> freqs,vector<int> freqt)
    {
        for(int i=0;i<128;i++)
        {
            if(freqs[i]<freqt[i])
            {
                return false;
            }

        }
        return true;
    }
    string minWindow(string s, string t) 
    {
        vector<int> freqs(128);
        vector<int> freqt(128);
        int m=s.size();
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            freqt[t[i]]++;
        }
        int left=0;
        int minlength=INT_MAX;
        int start=0;
        for(int right=0;right<m;right++)
        {
            freqs[s[right]]++;
            while(valid(freqs,freqt))
            {
                if(right-left+1<minlength)
                {
                    minlength=right-left+1;
                    start=left;
                }
                freqs[s[left]]--;
                left++;

            }
        }
    if(minlength==INT_MAX)
    {
        return "";
    }
    return s.substr(start,minlength);
        
    }
};
