def print_swap(begin: str, end: str) -> None:
    print(f'{begin} -> {end}')

def hanoi_towers(disk_count, begin = 'A', middle = 'B', end = 'C') -> None:
    if disk_count == 0:
        return
    hanoi_towers(disk_count - 1, begin, end, middle)
    print_swap(begin, end)
    hanoi_towers(disk_count - 1, middle, begin, end)

def main() -> None:
    disk_count = int(input())
    hanoi_towers(disk_count)

if __name__ == '__main__':
    main()