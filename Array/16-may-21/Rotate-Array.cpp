SRC: Leetcode
link:https://leetcode.com/problems/rotate-array/
-------------------CODE-------------------------
  brute force : rotate 1 unit evertime till k%n(optimised a bit as cycle of repitation will be created).
  time: O(k.n)
  space: O(1)
  
    class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
        
       int n=nums.size(); 
       k=k%n;
        while(k--)
        {
           int temp=nums[n-1];
            for(int i=n-1;i>0;i--)
            {
                nums[i]=nums[i-1];
            }
            nums[0]=temp;
        }
    
};
  -------------------CODE-------------------------
optimised : Extra space and copy in a desired fashion
time: O(n)
space:O(n)
  
  class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       
       vector<int> temp(100005);
    
        for(int i=0;i<nums.size();i++)
        {
            
            if(i+k>nums.size()-1)
            {
                temp[(i+k)%nums.size()]=nums[i];
            }
            else
                temp[i+k]=nums[i];
            
            
        }
        temp.resize(nums.size());
        
    nums=temp;
    }
    };
        
      -------------------CODE-------------------------
optimised : Dual revarsal tends to make the original array
time: O(n)
space:O(1)
      
      
      class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k=k%nums.size();
       int p1=nums.size()-k;
       int p2=k;
        
      reverse(nums.begin(),nums.begin()+nums.size()-k);                                    
      reverse(nums.begin()+nums.size()-k,nums.end());
      reverse(nums.begin(),nums.end());
    }
    };
