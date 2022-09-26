#include <iostream>
#include <vector>
using namespace std;

// vector<int>& coins
//二分法
int binarySearch(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2; //取当前中间数
        //判断中间数mid与target目标大小
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
    }

    return -1;
}

//寻找左侧边界
int left_bound(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size(); // 注意
    while (left < right)
    { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target)
        {
            //             找到 target 时不要⽴即返回，⽽是缩⼩「搜索区间」的上界
            // right ，在区间 [left, mid) 中继续搜索，即不断向左收缩，达到锁定左
            // 侧边界的⽬的。
            right = mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid; // 注意
        }
    }
    return left;
}

int main()
{
    vector<int> nums = {1, 4, 25};
    int res = binarySearch(nums, 4);
    int res_left = left_bound(nums, 4);
    printf("%s", "二分法:");
    printf("%d", res);
    printf("%s", "寻找左侧边界:");
    printf("%d", res_left);
    return 0;
}