class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        int left=0;
        auto &v=mp[key];
        int right=v.size()-1;
        string ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(v[mid].first<=timestamp)
            {
                left=mid+1;

                
                ans=v[mid].second;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
