class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row=-1;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int bottom=m-1;
        while(top<=bottom)
        {
            int mid=top+(bottom-top)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1]>=target)
            {
                row=mid;
                break;
            }
            else if(matrix[mid][0]>target)
            {
                bottom=mid-1;
            }
            else{
                top=mid+1;
            }
        }
        if(row==-1)
        {
            return false;
        }
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int middle=left+(right-left)/2;
            if(matrix[row][middle]==target)
            {
                return true;
            }
            else if(matrix[row][middle]>target)
            {
                right=middle-1;
            }
            else{
                left=middle+1;
            }
        }
        return false;
    }
};
