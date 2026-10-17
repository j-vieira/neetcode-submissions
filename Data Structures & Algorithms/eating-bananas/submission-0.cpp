class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }

        return binarySearch(piles, 1, maxPile, h, -1);
    }

    bool isValidRate(vector<int> &piles, int k, int expectedHours) { 
        long long int totalHours = 0;
        for (int pile : piles) {
            long long hoursForPile = (pile + k - 1LL) / k; // equivalente a ceil(pile/k) => evita problema com divisao int
            totalHours += hoursForPile;
        }
        return totalHours <= expectedHours;
    }

    int binarySearch(vector<int> &piles, int l, int r, int h, int best) {
        if (l > r) return best;

        int mid = (l+r)/2;
        if (isValidRate(piles, mid, h)) { // v[mid] == rate
            best = mid; 
            return binarySearch(piles, l, mid-1, h, best); // continua busca na esq
         } 

        return binarySearch(piles, mid+1, r, h, best); // vai p direita
    }
};
