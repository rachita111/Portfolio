class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int right=0,left=0,maxLen=0;
        unordered_map<int,int> basket;
        while(right<fruits.size()){
            basket[fruits[right]]++;
            if(basket.size()>2){
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0) basket.erase(fruits[left]);
                left++;
            }else{
                maxLen=max(maxLen,right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};