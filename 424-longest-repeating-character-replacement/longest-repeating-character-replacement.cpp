class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0,left=0,maxL=0,maxF=0;
        vector<int> mpp(26, 0);
        while(right<s.size()){
            mpp[s[right]-'A']++;
            maxF=max(maxF,mpp[s[right]-'A']);
            int changes=(right-left+1)-maxF;
            while(changes>k){
                mpp[s[left]-'A']--;
                maxF=0;
                for(int i=0;i<26;i++) maxF=max(maxF,mpp[i]);
                left++;
                changes=(right-left+1)-maxF;
            }
            if(changes<=k) maxL=max(maxL,right-left+1);
            right++;
        }
        return maxL;
    }
};