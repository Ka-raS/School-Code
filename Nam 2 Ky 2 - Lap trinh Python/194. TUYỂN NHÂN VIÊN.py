def calculate_score(theoretical_score: float, practical_score: float) -> float:
    if theoretical_score > 10:
        theoretical_score /= 10
    if practical_score > 10:
        practical_score /= 10
    return (theoretical_score + practical_score) / 2

def ranking(score: float) -> str:
    if score < 5:
        return 'TRUOT'
    if score < 8:
        return 'CAN NHAC'
    if score <= 9.5:
        return 'DAT'
    return 'XUAT SAC'

class Applicant:
    def __init__(self, id: str, name: str, theoretical_score: float, practical_score: float) -> None:
        self.id = id
        self.name = name
        self.score = calculate_score(theoretical_score, practical_score)

    def __str__(self):
        return f'{self.id} {self.name} {self.score:.2f} {ranking(self.score)}'

def main() -> None:
    applicants: list[Applicant] = []
    applicant_count = int(input())

    for index in range(1, applicant_count + 1):
        id = f'TS0{index}'
        name = input()
        theoretical_score = float(input())
        practical_score = float(input())
        
        applicant = Applicant(id, name, theoretical_score, practical_score)
        applicants.append(applicant)
    
    applicants.sort(key=lambda applicant: -applicant.score)
    for applicant in applicants:
        print(applicant)

if __name__ == '__main__':
    main()