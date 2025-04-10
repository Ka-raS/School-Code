import sys
import bisect    

def main() -> None:
    ANTI_PRIMES = (
        1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 
        720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 
        20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 
        166320, 221760, 277200, 332640, 498960, 554400, 665280, 
        720720, 1081080, 1441440, 2162160, 2882880, 3603600, 
        4324320, 6486480, 7207200, 8648640, 10810800
    )

    sys.stdin.readline()
    for line in sys.stdin:
        number = int(line)
        position = bisect.bisect_right(ANTI_PRIMES, number)
        print(ANTI_PRIMES[position])

if __name__ == '__main__':
    main()