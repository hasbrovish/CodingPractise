//Src:Leetcode
//Link:https://leetcode.com/problems/max-chunks-to-make-sorted/
//------------------CODE-----------------------------/

Approach:Optimised --> precomputation , checking max till the point equated to the index or not, 
signifying all the number less than the current number have occured
{permutate is generating till ith index}

Time : o(n)
Space: o(n)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        vector<int> preMax(arr.size());
        preMax[0]=arr[0];
        
        for(int i=1;i<arr.size();i++)
        {
            preMax[i]=max(preMax[i-1],arr[i]);
        }
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            if(preMax[i]==i)
                count++;
        }
    return count;
    }
};
