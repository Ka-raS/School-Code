from typing import List

def split_sums(number: int) -> List[List[int]]:
    lst = [number]
    result: List[List[int]] = [[number]]

    while lst[0] != 1:
        n = len(lst)
        i = n - 1
        while lst[i] == 1:
            i -= 1
        
        del lst[i + 1:]
        lst[i] -= 1
        num = lst[i]
        remain = number - sum(lst)

        lst.extend([num] * (remain // num))
        if remain % num > 0:
            lst.append(remain % num)
        result.append(lst.copy())

    return result

def main() -> None:
    tests = int(input())
    for test in range(tests):
        number = int(input())

        sums = split_sums(number)
        print(len(sums))
        for sum in sums:
            output = ' '.join(map(str, sum))
            print(f'({output})', end=' ')
        print()

if __name__ == '__main__':
    main()