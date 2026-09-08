class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int n=digits.size();
        int tot=0;
        for(auto &x : digits){
            tot+=x;
        }
        vector<int>ones;
        vector<int>twos;
        vector<int>zeros;
        string ans="";
        for(auto &x:digits){
            if(x%3==0){
                zeros.push_back(x);
            }
            else if(x%3==1){
                ones.push_back(x);
            }
            else{
                twos.push_back(x);
            }
        }
        sort(ones.begin(),ones.end());
        sort(twos.begin(),twos.end());
        sort(zeros.begin(),zeros.end());
        int n1=ones.size();
        int n2=twos.size();
        int n3=zeros.size();
        if(tot%3==0){
            for(auto &x:digits){
                ans.push_back((char)('0'+x));
            }
            sort(ans.begin(),ans.end());
        }
        else if(tot%3==1){
            if(n1>0){
                for(int i=1;i<n1;i++){
                    ans.push_back((char)('0'+ ones[i]));
                }
                for(int i=0;i<n2;i++){
                    ans.push_back((char)('0'+ twos[i]));
                }
                for(int i=0;i<n3;i++){
                    ans.push_back((char)('0'+ zeros[i]));
                }
            }
            else if(n2>1){
                for(int i=0;i<n1;i++){
                    ans.push_back((char)('0'+ ones[i]));
                }
                for(int i=2;i<n2;i++){
                    ans.push_back((char)('0'+ twos[i]));
                }
                for(int i=0;i<n3;i++){
                    ans.push_back((char)('0'+ zeros[i]));
                }
            }
            sort(ans.begin(),ans.end());
        }
        else{
            if(n2>0){
                for(int i=0;i<n1;i++){
                    ans.push_back((char)('0'+ ones[i]));
                }
                for(int i=1;i<n2;i++){
                    ans.push_back((char)('0'+ twos[i]));
                }
                for(int i=0;i<n3;i++){
                    ans.push_back((char)('0'+ zeros[i]));
                }
            }
            else if(n1>1){
                for(int i=2;i<n1;i++){
                    ans.push_back((char)('0'+ ones[i]));
                }
                for(int i=0;i<n2;i++){
                    ans.push_back((char)('0'+ twos[i]));
                }
                for(int i=0;i<n3;i++){
                    ans.push_back((char)('0'+ zeros[i]));
                }
            }
            sort(ans.begin(),ans.end());
        }
        while(ans.size()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0 && n3>0 && zeros[0]==0){
            ans.push_back('0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};