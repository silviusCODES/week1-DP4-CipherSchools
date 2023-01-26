#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return (nums[start] == target ? start : -1);
    }
    else
    {
        // start < end ->  Sunny
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // find the element in the right section of the array
            return firstOcc(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // find the element in the left section of the array
            return firstOcc(nums, start, mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // we dont know whether the current element is the first occurance or not ???
            if ((mid == 0) && (mid >= 1 && nums[mid - 1] < nums[mid]))
                return mid;
            return firstOcc(nums, start, mid - 1, target);
        }
    }
}

int lastOcc(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return (nums[start] == target ? start : -1);
    }
    else
    {
        // start < end ->  Sunny
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // find the element in the right section of the array
            return firstOcc(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // find the element in the left section of the array
            return firstOcc(nums, start, mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // we dont know whether the current element is the first occurance or not ???
            if ((mid == nums.size() - 1) || (mid + 1 <= nums.size() - 1 && nums[mid] < nums[mid + 1]))
                return mid;
            return firstOcc(nums, mid + 1, end, target);
        }
    }
}

vector<int> firstAndlastOcc(vector<int> &nums, int target)
{
    int first = firstOcc(nums, 0, nums.size() - 1, target);

    int last = lastOcc(nums, 0, nums.size() - 1, target);
    return {first, last};
}

int main()
{
}