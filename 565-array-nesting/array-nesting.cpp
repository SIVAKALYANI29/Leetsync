class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==-1){
                continue;
            }
            int cnt=0;
            int temp=nums[i];
            while(nums[temp]!=-1){
                cnt++;
                int dum=nums[temp];
                nums[temp]=-1;
                temp=dum;
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};