from typing import List, Tuple

def convert_equal(numbers: List[int]) -> Tuple[int, int]:
    convert_step = float('inf')
    target_number = None
    
    for target in numbers:
        step = 0
        for number in numbers:
            step += abs(target - number)
        
        if convert_step > step:
            convert_step = step
            target_number = target

    return convert_step, target_number

def main() -> None:
    length = int(input())
    numbers = list(map(int, input().split()))
    convert_step, target_number = convert_equal(numbers)
    print(convert_step, target_number)

if __name__ == '__main__':
    main()