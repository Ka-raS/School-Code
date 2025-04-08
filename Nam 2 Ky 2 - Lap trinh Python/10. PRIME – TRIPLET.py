import typing

MAX_VALUE: int = 10 ** 6 + 1

def find_primes() -> typing.List[bool]:
    is_prime: typing.List[bool] = [True] * MAX_VALUE
    is_prime[0] = is_prime[1] = False

    for i in range(2, 1000):
        if is_prime[i]:
            for j in range(i * i, MAX_VALUE, i): 
                is_prime[j] = False

    return is_prime

def find_prime_triplet_counts() -> typing.List[int]:
    is_prime: typing.List[bool] = find_primes()
    prime_triplet_counts: typing.List[int] = [0] * MAX_VALUE

    for upper_bound in range(7, MAX_VALUE):
        prime_triplet_counts[upper_bound] = prime_triplet_counts[upper_bound - 1]

        if is_prime[upper_bound - 1] and is_prime[upper_bound - 7]:
            if is_prime[upper_bound - 5]:
                prime_triplet_counts[upper_bound] += 1
            if is_prime[upper_bound - 3]:
                prime_triplet_counts[upper_bound] += 1
    
    return prime_triplet_counts

def run_test(prime_triplet_counts: typing.List[int]) -> None:
    upper_bound: int = int(input())
    print(prime_triplet_counts[upper_bound])

def main() -> None:
    # (p, p + 2, p + 6) or (p, p + 4, p + 6)
    prime_triplet_counts: typing.List[int] = find_prime_triplet_counts()

    tests: int = int(input())
    for test in range(tests):
        run_test(prime_triplet_counts)

if __name__ == '__main__':
    main()