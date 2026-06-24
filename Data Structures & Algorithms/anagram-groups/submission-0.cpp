class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string s: strs)
        {
            string temp=s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};
