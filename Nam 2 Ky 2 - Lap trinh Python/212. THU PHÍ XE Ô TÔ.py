from typing import (
    List, 
    Tuple,
    Iterable
)

class Ticket:
    fee = {
        '5': 10_000,
        '7': 15_000,
        '2': 20_000,
        '29': 50_000,
        '45': 70_000
    }

    def __init__(self, plate: str, form: str, seats: str, direction: str, date: str) -> None:
        self.plate = plate
        self.form = form
        self.seats = seats
        self.direction = direction
        self.date = date
    
    def __iter__(self) -> Iterable[str]:
        return iter((
            self.plate,
            self.form,
            self.seats,
            self.direction,
            self.date
        ))

def date_fees(tickets: List[Ticket]) -> List[Tuple[str, int]]:
    result: List[str, int] = []

    current_fee = 0
    current_date = tickets[0].date

    for plate, form, seats, direction, date in tickets:
        if direction == 'OUT':
            continue

        if date != current_date:
            result.append((current_date, current_fee))
            current_fee = 0
            current_date = date
        
        current_fee += Ticket.fee[seats]

    result.append((current_date, current_fee))
    return result

def main() -> None:
    tickets: list[Ticket] = []
    ticket_count = int(input())

    for _ in range(ticket_count):
        plate, form, seats, direction, date = input().split()
        tickets.append(Ticket(plate, form, seats, direction, date))
    
    for date, fee in date_fees(tickets):
        print(f'{date}: {fee}')


if __name__ == '__main__':
    main()