import typing
import math

def print_coprime_triplets(lower_bound: int, upper_bound: int) -> None:
    coprime_pairs: typing.Set[typing.Tuple[int, int]] = set()
    for i in range(lower_bound, upper_bound):
        for j in range(i + 1, upper_bound + 1):
            if math.gcd(i, j) == 1:
                coprime_pairs.add((i, j))

    for i in range(lower_bound, upper_bound - 1):
        for j in range(i + 1, upper_bound):
            for k in range(j + 1, upper_bound + 1):
                if (i, j) in coprime_pairs and (i, k) in coprime_pairs and (j, k) in coprime_pairs:
                    print((i, j, k))

def main() -> None:
    lower_bound, upper_bound = map(int, input().split())
    print_coprime_triplets(lower_bound, upper_bound)

if __name__ == '__main__':
    main()