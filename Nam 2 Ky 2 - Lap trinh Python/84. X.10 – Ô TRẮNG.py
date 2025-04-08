def side_count(n: int, k: int) -> int:
    if n == 1: 
        return 6 * (k != 0)
    
    sides3 = 8
    if k <= sides3:
        return 3 * k
    
    sides2 = (n - 2) * 12
    if k - 8 <= sides2:
        return 24 + 2 * k
    
    sides1 = 6 * (n - 2) ** 2
    return 24 + sides2 * 2 + k

def main() -> None:
    n, k = map(int, input().split())
    print(side_count(n, k))

if __name__ == '__main__':
    main()