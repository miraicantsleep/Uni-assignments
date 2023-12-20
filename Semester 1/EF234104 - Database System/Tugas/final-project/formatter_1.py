import random

def format_input(user_input):
    formatted_lines = []

    for line in user_input.split('\n'):
        if not line.strip():
            continue

        # Split the line into four elements: ID, name, "S-1 Teknik Informatika", and the last element
        id, name, rest = line.split('\t', 2)

        # If the last element is provided, use it; otherwise, randomize between 'L' and 'P'
        if len(rest.split('\t')) == 2:
            department, gender = rest.split('\t')
        else:
            department = rest.strip()
            gender = random.choice(['L', 'P'])

        formatted_line = f"{id}\\t{name}\\t{department}\\t{gender}"
        formatted_lines.append(formatted_line)

    return '\n'.join(formatted_lines)

# Example usage
user_input = """
5022231011	Rayanisa Sita	S-1 Teknik Elektro
5022231012	Roos Faikarsyah Ravas Falah	S-1 Teknik Elektro
5022231013	Ahmad Harisul Hikam	S-1 Teknik Elektro
5022231014	Muchammad Ainun Febriansyah	S-1 Teknik Elektro
5022231015	Arja Maula Razan	S-1 Teknik Elektro
5022231016	Ronald Listiyadhi	S-1 Teknik Elektro
5022231017	Styvend Mosesaah Marpaung	S-1 Teknik Elektro
5022231018	Muhammad Rifqi Febrian	S-1 Teknik Elektro
5022231019	Muhammad Ilham Ramadhan Khasyyatullah	S-1 Teknik Elektro
5022231020	Adhyaksa Afzaal Dhananjaya	S-1 Teknik Elektro
5010231011	Ahmad Zaidan Wahab	S-1 Teknik Industri
5010231012	Manuel Gerrard Maheswara	S-1 Teknik Industri
5010231013	Marcelino Tody Adrianto	S-1 Teknik Industri
5010231014	Hanin Nur Aulia	S-1 Teknik Industri
5010231015	Dina Fahriyanti	S-1 Teknik Industri
5010231016	Nurita Udiyanti Salimah	S-1 Teknik Industri
5010231017	Athalya Bella Pandjaitan	S-1 Teknik Industri
5010231018	Alzena Cheiryl Violney	S-1 Teknik Industri
5010231019	Muhammad Haikal Fikri Al Azhari 	S-1 Teknik Industri
5010231020	Dhania Faza Naufalia	S-1 Teknik Industri
5007231011	Muhammad Thaliban Habib Hudzaifah Naim	S-1 Teknik Mesin
5007231012	Tanaya Secyolita Putri Maulidya	S-1 Teknik Mesin
5007231013	Raditia Damar Prasetyo	S-1 Teknik Mesin
5007231014	Ahmad Raihan Akbar	S-1 Teknik Mesin
5007231015	Immanuel Mattew Sitorus	S-1 Teknik Mesin
5007231016	Christopher Rocky Perkasa	S-1 Teknik Mesin
5007231017	Einin Ellasya Putri	S-1 Teknik Mesin
5007231018	Rafi Ardell Nugraha	S-1 Teknik Mesin
5007231019	Isyana Ershandari 	S-1 Teknik Mesin
5007231020	Aryaputra Listyan	S-1 Teknik Mesin
5019231011	Abyan Naufal Fahmi	S-1 Teknik Sistem Perkapalan
5019231012	Muhammad Zaki Fauzan Sutomo	S-1 Teknik Sistem Perkapalan
5019231013	Raden Raynor Matteo Seputro	S-1 Teknik Sistem Perkapalan
5019231014	Zahira Berliani Rahmadanti Yuvito	S-1 Teknik Sistem Perkapalan
5019231015	Rhevanza Felly Azahra	S-1 Teknik Sistem Perkapalan
5019231016	Pradipta Bagas Satriawan	S-1 Teknik Sistem Perkapalan
5019231017	Qaulan Syakilla Dorida	S-1 Teknik Sistem Perkapalan
5019231018	Zahrina Nur Amalina Syamsudin	S-1 Teknik Sistem Perkapalan Joint Degree
5019231019	Aziz Nabiel Daniswara	S-1 Teknik Sistem Perkapalan Joint Degree
5019231020	Desyta Dwi Ardijantari	S-1 Teknik Sistem Perkapalan Joint Degree
5012231011	Demetrius Floja	S-1 Teknik Sipil
5012231012	Widyansyah Khalifian Dharmawan	S-1 Teknik Sipil
5012231013	Ahmad Syihan Al Askary	S-1 Teknik Sipil
5012231014	Riezaldy Mumtaz Aqila	S-1 Teknik Sipil
5012231015	Ibnaty Rameyza Alya Karima	S-1 Teknik Sipil
5012231016	David Christopher Wicaksono	S-1 Teknik Sipil
5012231017	Zahwa Anggeraeni	S-1 Teknik Sipil
5012231018	Syelina Alifia Rozan	S-1 Teknik Sipil
5012231019	Jason Lurich	S-1 Teknik Sipil
5012231020	Farrell Isyraq Wardoyo	S-1 Teknik Sipil
5027231011	Muhammad Abhinaya Al-Faruqi	S-1 Teknologi Informasi
5027231012	Aswalia Novitriasari	S-1 Teknologi Informasi
5027231013	Riskiyatul Nur Oktarani	S-1 Teknologi Informasi
5027231014	Muhamad Arrayyan	S-1 Teknologi Informasi
5027231015	Farida Qurrotu A'yuna	S-1 Teknologi Informasi
5027231016	Dian Anggraeni Putri	S-1 Teknologi Informasi
5027231017	Hazwan Adhikara Nasution	S-1 Teknologi Informasi
5027231018	Athalla Barka Fadhil	S-1 Teknologi Informasi
5027231019	Rafael Gunawan	S-1 Teknologi Informasi
5027231020	Acintya Edria Sudarsono	S-1 Teknologi Informasi
5006231011	Zahra Rania Putri Indra	S-1 Sains Aktuaria
5006231012	Khansa Peridhia Naura	S-1 Sains Aktuaria
5006231013	Lunetta Herdanti Asshidiqah	S-1 Sains Aktuaria
5006231014	Tobias Ega Ekaputra	S-1 Sains Aktuaria
5006231015	Brigita Apsari Waskitho	S-1 Sains Aktuaria
5006231016	Thania Marsya Kiroyan	S-1 Sains Aktuaria
5006231017	Abhista Hevan Daniswara	S-1 Sains Aktuaria
5006231018	Oktavia Anis Nurrohmah	S-1 Sains Aktuaria
5006231019	Azmiyah Tsauroh	S-1 Sains Aktuaria
5006231020	Novia Farah Hashifah	S-1 Sains Aktuaria
"""

formatted_input = format_input(user_input)
print(formatted_input)




