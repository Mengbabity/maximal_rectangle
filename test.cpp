class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        
        int res=0;
        vector<int> left(n,0);
        vector<int> right(n,n);
        vector<int> height(n,0);


        for(int i=0;i<m;i++)
        {
            int l=0,r=n;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    height[j]++;
                else
                    height[j]=0;
            }
            
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    left[j]=max(left[j],l);
                else
                {
                    left[j]=0;
                    l=j+1;
                }
            }
            
            for(int j=n-1;j>=0;j--)
            {
                if(matrix[i][j]=='1')
                    right[j]=min(right[j],r);
                else
                {
                    right[j]=n;
                    r=j;
                }
            }
            
            for(int j=0;j<n;j++)
                res=max(res,height[j]*(right[j]-left[j]));
        }
        
        return res;
    }
};
