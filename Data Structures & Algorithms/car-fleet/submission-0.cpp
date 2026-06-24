class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int,int>> a;
        stack<double> st;
        for(int i=0;i<position.size();i++)
        {
            a.push_back({position[i],speed[i]});
        }
        sort(a.begin(),a.end(),[](auto x,auto y)
        {
            return x.first>y.first;
        });
        for(int i=0;i<position.size();i++)
        {
            double time_needed=1.0 *(target-a[i].first)/a[i].second;
            if(st.empty() ||  st.top()<time_needed)
            {
                    st.push(time_needed);
            }

        }
        return st.size();
    }
};
