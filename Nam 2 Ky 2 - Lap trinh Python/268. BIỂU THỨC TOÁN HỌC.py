from typing import List

def max_sum(nums: List[int], groups: int) -> int:
    nums.sort()
    result = 0
    left = 0
    right = len(nums) - 1
    
    for group in range(groups):
        result += (5 * nums[right]) - (4 * nums[left]) + (3 * nums[right - 1]) - (2 * nums[left + 1]) + nums[right - 2]
        left += 2
        right -= 3
        
    return result

def main() -> None:
    length, groups = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(max_sum(numbers, groups))

if __name__ == '__main__':
    main()