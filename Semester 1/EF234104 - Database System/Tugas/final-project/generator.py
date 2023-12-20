from datetime import datetime, timedelta
import random

# Global counters for P and A
counter_p = 10
counter_a = 10

def generate_random_datetime(start_datetime, end_datetime):
    return start_datetime + timedelta(
        days=random.randint(0, (end_datetime - start_datetime).days),
        hours=random.randint(0, 7),  # Updated upper bound to 17 for 24-hour format
        minutes=random.randint(0, 59),
        seconds=random.randint(0, 59)
    )

def generate_sql_insert(data):
    global counter_p
    global counter_a
    
    pengunjung_entries = []
    keanggotaan_entries = []

    for line in data.split('\n'):
        if not line.strip():
            continue

        values = line.split('\t')  # Use tab as the separator
        
        # Check if the line contains the expected number of values
        if len(values) != 4:
            print(f"Error: Incorrect number of values in line: {line}")
            continue

        # Increment counters for P and A
        counter_p += 1
        counter_a += 1

        # Generate sequential ID_pengunjung starting from 0001
        id_pengunjung = f"P{counter_p:04}"

        nrp = values[0]  # Use the first element as NRP
        nama = values[1]
        department = values[2]
        jenis_kelamin = values[3]

        # Generate sequential ID_anggota starting from 001
        id_anggota = f"A{counter_a:03}"

        # Generate a random date of birth between 2004 and 2005
        tanggal_lahir = generate_random_datetime(datetime(2004, 1, 1), datetime(2005, 12, 31)).strftime('%Y-%m-%d')

        # Generate email using the NRP
        email = f"{nrp}@student.its.ac.id"

        # Generate a random visit date between November and December 2023
        waktu_berkunjung = generate_random_datetime(datetime(2023, 11, 1, 7), datetime(2023, 12, 31, 19)).strftime('%Y-%m-%d %H:%M:%S')
        
        # Entry for pengunjung table
        pengunjung_entry = f"('{id_pengunjung}', '{nama}')"
        pengunjung_entries.append(pengunjung_entry)

        # Entry for keanggotaan table
        keanggotaan_entry = f"('{id_anggota}', '{nrp}', '{email}', '{department}', '{tanggal_lahir}', '{jenis_kelamin}', '{id_pengunjung}')"
        keanggotaan_entries.append(keanggotaan_entry)

    pengunjung_sql = """INSERT INTO pengunjung (id_pengunjung, nama, waktu_berkunjung)
VALUES
""" + ',\n'.join(pengunjung_entries) + ';'

    keanggotaan_sql = """INSERT INTO keanggotaan (id_anggota, nrp, email, jurusan, tanggal_lahir, jenis_kelamin, id_pengunjung)
VALUES
""" + ',\n'.join(keanggotaan_entries) + ';'

    return pengunjung_sql, keanggotaan_sql

# Example usage
user_input = """
5022231011\tRayanisa Sita\tS-1 Teknik Elektro\tP
5022231012\tRoos Faikarsyah Ravas Falah\tS-1 Teknik Elektro\tL
5022231013\tAhmad Harisul Hikam\tS-1 Teknik Elektro\tL
5022231014\tMuchammad Ainun Febriansyah\tS-1 Teknik Elektro\tP
5022231015\tArja Maula Razan\tS-1 Teknik Elektro\tL
5022231016\tRonald Listiyadhi\tS-1 Teknik Elektro\tP
5022231017\tStyvend Mosesaah Marpaung\tS-1 Teknik Elektro\tP
5022231018\tMuhammad Rifqi Febrian\tS-1 Teknik Elektro\tP
5022231019\tMuhammad Ilham Ramadhan Khasyyatullah\tS-1 Teknik Elektro\tP
5022231020\tAdhyaksa Afzaal Dhananjaya\tS-1 Teknik Elektro\tL
5010231011\tAhmad Zaidan Wahab\tS-1 Teknik Industri\tL
5010231012\tManuel Gerrard Maheswara\tS-1 Teknik Industri\tL
5010231013\tMarcelino Tody Adrianto\tS-1 Teknik Industri\tP
5010231014\tHanin Nur Aulia\tS-1 Teknik Industri\tL
5010231015\tDina Fahriyanti\tS-1 Teknik Industri\tL
5010231016\tNurita Udiyanti Salimah\tS-1 Teknik Industri\tP
5010231017\tAthalya Bella Pandjaitan\tS-1 Teknik Industri\tL
5010231018\tAlzena Cheiryl Violney\tS-1 Teknik Industri\tL
5010231019\tMuhammad Haikal Fikri Al Azhari \tS-1 Teknik Industri\tP
5010231020\tDhania Faza Naufalia\tS-1 Teknik Industri\tL
5007231011\tMuhammad Thaliban Habib Hudzaifah Naim\tS-1 Teknik Mesin\tP
5007231012\tTanaya Secyolita Putri Maulidya\tS-1 Teknik Mesin\tP
5007231013\tRaditia Damar Prasetyo\tS-1 Teknik Mesin\tL
5007231014\tAhmad Raihan Akbar\tS-1 Teknik Mesin\tL
5007231015\tImmanuel Mattew Sitorus\tS-1 Teknik Mesin\tL
5007231016\tChristopher Rocky Perkasa\tS-1 Teknik Mesin\tL
5007231017\tEinin Ellasya Putri\tS-1 Teknik Mesin\tL
5007231018\tRafi Ardell Nugraha\tS-1 Teknik Mesin\tL
5007231019\tIsyana Ershandari \tS-1 Teknik Mesin\tL
5007231020\tAryaputra Listyan\tS-1 Teknik Mesin\tP
5019231011\tAbyan Naufal Fahmi\tS-1 Teknik Sistem Perkapalan\tP
5019231012\tMuhammad Zaki Fauzan Sutomo\tS-1 Teknik Sistem Perkapalan\tP
5019231013\tRaden Raynor Matteo Seputro\tS-1 Teknik Sistem Perkapalan\tP
5019231014\tZahira Berliani Rahmadanti Yuvito\tS-1 Teknik Sistem Perkapalan\tP
5019231015\tRhevanza Felly Azahra\tS-1 Teknik Sistem Perkapalan\tL
5019231016\tPradipta Bagas Satriawan\tS-1 Teknik Sistem Perkapalan\tL
5019231017\tQaulan Syakilla Dorida\tS-1 Teknik Sistem Perkapalan\tL
5019231018\tZahrina Nur Amalina Syamsudin\tS-1 Teknik Sistem Perkapalan Joint Degree\tP
5019231019\tAziz Nabiel Daniswara\tS-1 Teknik Sistem Perkapalan Joint Degree\tL
5019231020\tDesyta Dwi Ardijantari\tS-1 Teknik Sistem Perkapalan Joint Degree\tL
5012231011\tDemetrius Floja\tS-1 Teknik Sipil\tP
5012231012\tWidyansyah Khalifian Dharmawan\tS-1 Teknik Sipil\tP
5012231013\tAhmad Syihan Al Askary\tS-1 Teknik Sipil\tL
5012231014\tRiezaldy Mumtaz Aqila\tS-1 Teknik Sipil\tL
5012231015\tIbnaty Rameyza Alya Karima\tS-1 Teknik Sipil\tP
5012231016\tDavid Christopher Wicaksono\tS-1 Teknik Sipil\tP
5012231017\tZahwa Anggeraeni\tS-1 Teknik Sipil\tP
5012231018\tSyelina Alifia Rozan\tS-1 Teknik Sipil\tP
5012231019\tJason Lurich\tS-1 Teknik Sipil\tL
5012231020\tFarrell Isyraq Wardoyo\tS-1 Teknik Sipil\tL
5027231011\tMuhammad Abhinaya Al-Faruqi\tS-1 Teknologi Informasi\tL
5027231012\tAswalia Novitriasari\tS-1 Teknologi Informasi\tP
5027231013\tRiskiyatul Nur Oktarani\tS-1 Teknologi Informasi\tL
5027231014\tMuhamad Arrayyan\tS-1 Teknologi Informasi\tL
5027231015\tFarida Qurrotu A'yuna\tS-1 Teknologi Informasi\tP
5027231016\tDian Anggraeni Putri\tS-1 Teknologi Informasi\tL
5027231017\tHazwan Adhikara Nasution\tS-1 Teknologi Informasi\tP
5027231018\tAthalla Barka Fadhil\tS-1 Teknologi Informasi\tP
5027231019\tRafael Gunawan\tS-1 Teknologi Informasi\tP
5027231020\tAcintya Edria Sudarsono\tS-1 Teknologi Informasi\tP
5006231011\tZahra Rania Putri Indra\tS-1 Sains Aktuaria\tL
5006231012\tKhansa Peridhia Naura\tS-1 Sains Aktuaria\tL
5006231013\tLunetta Herdanti Asshidiqah\tS-1 Sains Aktuaria\tP
5006231014\tTobias Ega Ekaputra\tS-1 Sains Aktuaria\tP
5006231015\tBrigita Apsari Waskitho\tS-1 Sains Aktuaria\tL
5006231016\tThania Marsya Kiroyan\tS-1 Sains Aktuaria\tL
5006231017\tAbhista Hevan Daniswara\tS-1 Sains Aktuaria\tP
5006231018\tOktavia Anis Nurrohmah\tS-1 Sains Aktuaria\tP
5006231019\tAzmiyah Tsauroh\tS-1 Sains Aktuaria\tP
5006231020\tNovia Farah Hashifah\tS-1 Sains Aktuaria\tP
"""
pengunjung_sql, keanggotaan_sql = generate_sql_insert(user_input)
print("Pengunjung SQL:")
print(pengunjung_sql)
# print("\nKeanggotaan SQL:")
# print(keanggotaan_sql)