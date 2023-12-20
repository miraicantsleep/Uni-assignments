import random
from datetime import datetime, timedelta

def generate_random_dates_with_time(num_dates=1000):
    start_date = datetime.strptime('2023-07-04 07:00:00', '%Y-%m-%d %H:%M:%S')
    end_date = datetime.strptime('2023-12-31 18:59:00', '%Y-%m-%d %H:%M:%S')
    
    date_list = [
        start_date + timedelta(
            days=random.randint(0, (end_date - start_date).days),
            hours=random.randint(0, 11),
            minutes=random.randint(1, 59),
            seconds=random.randint(1, 59)
        ) for _ in range(num_dates)
    ]
    
    return date_list

if __name__ == "__main__":
    random_dates = generate_random_dates_with_time(1000)

    for date in random_dates:
        print(date.strftime('%Y-%m-%d %H:%M:%S'))
