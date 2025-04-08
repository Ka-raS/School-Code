from datetime import time

class RainReport:
    def __init__(self, id: str, name: str):
        self.id = id
        self.name = name
        self.time_total = 0
        self.rainfall_total = 0

    def __str__(self) -> str:
        return f'{self.id} {self.name} {self.rainfall_average():.2f}'

    def add(self, start: time, end: time, rainfall: int) -> None:
        duration = 60 * (end.hour - start.hour) + end.minute - start.minute
        self.time_total += duration
        self.rainfall_total += rainfall 

    def rainfall_average(self) -> float:
        return self.rainfall_total / (self.time_total / 60)

def main() -> None:
    index = 1
    reports: dict[str, RainReport] = {}

    report_count = int(input())
    for _ in range(report_count):
        name = input()
        start = time(*map(int, input().split(':')))
        end = time(*map(int, input().split(':')))
        rainfall = int(input())
        
        if name not in reports:
            reports[name] = RainReport(f'T{index:02}', name)
            index += 1
        reports[name].add(start, end, rainfall)

    for report in reports.values():
        print(report)

if __name__ == '__main__':
    main()