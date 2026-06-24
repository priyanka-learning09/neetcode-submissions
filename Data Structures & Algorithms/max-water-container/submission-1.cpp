class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int maxarea=0;
        int i=0;
        int j=heights.size()-1;
        while(i<j)
        {
            int minheight=min(heights[i],heights[j]);
            int width=j-i;
            int area=minheight*width;
            maxarea=max(maxarea,area);
            if(heights[i]<heights[j])
            {
                i++;
            }
            else
            {
                j--;
            }

        }
        return maxarea;
    }
};
