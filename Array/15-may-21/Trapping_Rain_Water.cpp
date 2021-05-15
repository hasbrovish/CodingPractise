/*
Src: Leetcode
Link for the Question:https://leetcode.com/problems/trapping-rain-water/
*/
//----------------------CODE-----------------------------

class Solution {
public:

    int trap(vector<int>& height) {
        
        int n=height.size();
        
        if(n==0 || n==1 || n==2)
            return 0;
        
        vector<int> ltMax(height.size());
        vector<int> rtMax(height.size());
        ltMax[0]=height[0];
        rtMax[n-1]=height[n-1];
        
        
        for(int i=1;i<n;i++)
        {
            ltMax[i]=max(ltMax[i-1],height[i]);
            
        }
        
        for(int i=n-2;i>=0;i--)
        {
            rtMax[i]=max(rtMax[i+1],height[i]);
        }
        

        int amt=0;
        
        for(int i=1;i<n-1;i++)
        {
            int dt=min(ltMax[i-1],rtMax[i+1]);
            if(dt>height[i])
            {
                amt+=dt-height[i];
            }
            
        }
        
    return amt;
    }
};
