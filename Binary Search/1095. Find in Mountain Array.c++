/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int find(MountainArray &mountainArr){
        int l = 0, r = mountainArr.length() - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return l;
    }
    int bs(MountainArray &mountainArr, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    int reverseBS(MountainArray &mountainArr, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l) / 2;
            if(mountainArr.get(mid) == target) return mid;
            else if(mountainArr.get(mid) > target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIdx = find(mountainArr);
        int idx = bs(mountainArr, 0, peakIdx, target);
        if(idx == -1) return reverseBS(mountainArr, peakIdx, n-1, target);
        return idx;
    }
};