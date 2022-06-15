class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;
        
        long long mid = 0;
        
        long long total = 0;
        
        while (low < high){
            mid = (low + high) / 2;
            total = 0;
            
            // 총여행시간 구하기
            for (auto &x : time){
                total += (mid / x);
            }
            
            if (total >= totalTrips){
                high = mid;
            }else {
                low = mid + 1;
            }
            //std::cout << total << ' ' << mid << std::endl;
        }
        
        return low;
    }
}
