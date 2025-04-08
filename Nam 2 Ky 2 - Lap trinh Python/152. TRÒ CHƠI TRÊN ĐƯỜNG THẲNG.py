import math
import itertools
from typing import (
    Iterable,
    Tuple
)

def min_cost_travel(cards: Iterable[Tuple[int, int]]) -> int:
    min_cost = {0: 0}
    divisors = [0]

    for distance, cost in cards:
        for divisor in divisors:
            current_divisor = math.gcd(distance, divisor)
            current_cost = cost + min_cost[divisor]

            if current_divisor not in min_cost:
                min_cost[current_divisor] = current_cost
                divisors.append(current_divisor)
            
            elif min_cost[current_divisor] > current_cost:
                min_cost[current_divisor] = current_cost

    return min_cost.get(1, -1)

def run_test() -> None:
    length = int(input())
    distances = map(int, input().split())
    costs = map(int, input().split())

    cards = sorted(zip(distances, costs), key=lambda card: card[1])
    print(min_cost_travel(cards))

def main() -> None:
    tests = int(input())
    for test in range(tests):
        run_test()

if __name__ == '__main__':
    main()