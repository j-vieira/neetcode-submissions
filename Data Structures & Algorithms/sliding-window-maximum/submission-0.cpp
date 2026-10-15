class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0; int j = k-1;
        
        deque<int> dq;
        vector<int> result;

        for (int p = 0; p < k; p++) {
            while (!dq.empty() && nums[dq.back()] <= nums[p]) { // vai removendo os antigos que sao menores que os novos que estao chegando
                dq.pop_back();
            }
            dq.push_back(p);
        }

        for (int p = 0; p < k; p++) {
            while (!dq.empty() && nums[dq.back()] <= nums[p]) {
                dq.pop_back();
            }
            dq.push_back(p);
        }

        while (j<nums.size()) {

            // tira quem nao esta no intervalo
            while (!dq.empty() && dq.front() < i) {
                dq.pop_front();
            }            

            // tira quem é menor que o novo elemento
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }

            dq.push_back(j);
            
            result.push_back(nums[dq.front()]);
            
            i++; j++;
        }
        return result;
    }

};