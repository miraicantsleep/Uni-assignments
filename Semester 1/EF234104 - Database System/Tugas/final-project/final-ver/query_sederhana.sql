-- Muhammad Ryan Fikri Nugraha 5025231013
-- Menampilkan data pegawai yang lahir pada tahun 1998
SELECT *
FROM pegawai
WHERE YEAR(tanggal_lahir) = 1998;

-- Menampilkan data buku yang tahun terbitnya pada 2001 sampai dengan 2015
SELECT *
FROM buku
WHERE tahun_terbit BETWEEN 2001 AND 2015;

-- Menampilkan data keanggotaan yang memiliki 4 digit NRP pertama adalah 5025
SELECT *
FROM keanggotaan
WHERE nrp LIKE '5025%';

-- Menampilkan semua data dari setiap ruangan yang ada di perpustakaan ITS 
SELECT *
FROM ruangan;

-- Menampilkan data dari setiap penulis yang ada pada buku buku yang ada di perpustakaan
SELECT DISTINCT penulis
FROM buku;

-- Muhammad Nabil Afrizal Rahmadani 5025231014
-- Menampilkan data mahasiswa yang berasal dari jurusan Teknik Informatika
SELECT *
FROM keanggotaan
WHERE jurusan LIKE '%Teknik Informatika';

-- Menampilkan data pengunjung yang bukan berasal dari ITS
SELECT *
FROM keanggotaan
WHERE nrp IS NULL;

-- Menampilkan data mahasiswa yang memiliki nama Ryan
SELECT *
FROM pengunjung
WHERE nama LIKE '%Ryan%';

-- Menampilkan anggota laki-laki yang memiliki tahun lahir di bawah 2005
SELECT *
FROM keanggotaan
WHERE jenis_kelamin = 'L' AND YEAR(tanggal_lahir) < 2005;

-- Menampilkan ruangan yang berada di lantai 3
SELECT *
FROM ruangan
WHERE lokasi = 'Lantai 3';

-- Randi Palguna Artayasa 5025231020
-- Menampilkan id pengunjung yang pernah datang berkunjung sekitar jam 15:00:00 - 17:00:00
SELECT DISTINCT id_pengunjung
FROM waktu_berkunjung
WHERE TIME(waktu) BETWEEN '15:00:00' AND '17:00:00';

-- Menampilkan data keanggotaan yang tanggal lahirnya di bulan Januari
SELECT *
FROM keanggotaan
WHERE MONTH(tanggal_lahir) = 1;

-- Menampilkan judul buku, nama penerbit, dan tahun terbit yang judul bukunya terdapat kata "Programming"
SELECT
    judul_buku,
    penerbit,
    tahun_terbit
FROM buku
WHERE judul_buku LIKE '%Programming%';

-- Menampilkan judul buku, subjek buku, dan penerbit yang bukunya dientri pada tahun 2021, 2022, 2023
SELECT
    judul_buku,
    subjek,
    penerbit
FROM buku
WHERE YEAR(tanggal_entry) BETWEEN 2021 AND 2023;

-- Menampilkan semua data Transaksi_Buku yang dendanya lebih dari 10000,00
SELECT *
FROM transaksi_buku
WHERE denda > 10000;

-- I Gusti Ngurah Arya Sudewa 5025231030
-- Menampilkan data buku yang memiliki tahun terbit setelah 2015
SELECT *
FROM buku
WHERE tahun_terbit > 2015;

-- Menampilkan data transaksi buku yang memiliki denda
SELECT *
FROM transaksi_buku
WHERE denda IS NOT NULL;

-- Menampilkan data pegawai dengan awalan nomor telepon '081'
SELECT *
FROM pegawai
WHERE no_telp LIKE '081%';

-- Menampilkan data buku dengan status peminjaman 'Dipinjam'
SELECT *
FROM buku
WHERE status_peminjaman = 'Dipinjam';

-- Menampilkan data ruangan dengan lokasi selain 'Lantai 1' dan 'Lantai 2'
SELECT *
FROM ruangan
WHERE lokasi NOT IN ('Lantai 1', 'Lantai 2');