class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        stack<double> s;
        vector<pair<int,int>> data;
        for(int i=0;i<position.size();i++)
        {
            data.push_back({position[i],speed[i]});

        }
        sort(data.begin(),data.end(),[](auto &x,auto &y)
        {
            return x.first>y.first;
        });
        for(int i=0;i<data.size();i++)
        {
            double time=1.0*(target-data[i].first)/data[i].second;
            if(s.empty() || time > s.top() )
            {
                    s.push(time);
            }
            
        }
        return s.size();

        
    }
};
