class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num: nums) {
            map[num]++;
        }
        for(auto mp: map) {
            if(mp.second == 1) {
                return mp.first;
            }
        }
        return 0;
        // int result = 0;
        // for(int &num: nums) {
        //     result ^= num;
        // }
        // return result;
    }
};