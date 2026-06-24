class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string res;
        for(string s:strs)
        {
            res+=to_string(s.length());
            res+='#';
            res+=s;
        }
        return res;
    }

    vector<string> decode(string s) 
    {
        int i=0;
        vector<string> result;
        while(i<s.size())
        {
            int j=i;
            while(s[j]!='#')
            {
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            j++;
            result.push_back(s.substr(j,length));
            i=j+length;

        }
        return result;

    }
};
