class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> st;
        int n=heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int a=(nse[i]-pse[i]-1)*heights[i];
            ans=max(ans,a);

        }
        return ans;
    }
};
