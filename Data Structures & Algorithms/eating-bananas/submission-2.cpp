class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int minspeed=1;
        int maxspeed=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxspeed=max(maxspeed,piles[i]);
        }
        int left=minspeed;
        int right=maxspeed;
        int ans=maxspeed;
        while(left<=right)
        {
                int mid=left+(right-left)/2;
                int total=0;
                for(int i=0;i<piles.size();i++)
                {
                    total+=ceil((double)piles[i]/mid);
                }
                if(total<=h)
                {
                    ans=mid;
                    right=mid-1;
                }
                else if(total>h)
                {
                    left=mid+1;
                    
                }
        }
return ans;
        
    }
};
