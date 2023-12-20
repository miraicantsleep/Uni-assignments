-- Muhammad Ryan Fikri Nugraha 5025231013
-- Menampilkan data anggota yang telah melakukan peminjaman ruangan lebih dari 5 kali
SELECT
    a.*
FROM
    keanggotaan a
    INNER JOIN transaksi_ruangan tr ON a.id_anggota = tr.id_anggota
GROUP BY
    a.id_anggota
HAVING
    COUNT(tr.id_transaksi_ruangan) > 5;

-- Menampilkan data anggota yang melakukan transaksi peminjaman buku dan mendapatkan denda
SELECT
    DISTINCT a.*
FROM
    keanggotaan a
    INNER JOIN transaksi_buku tb ON a.id_anggota = tb.id_anggota
WHERE
    tb.denda IS NOT NULL;

-- Menampilkan data pegawai yang melayani transaksi peminjaman pada pelanggan yang mendapatkan denda
SELECT
    DISTINCT p.*
FROM
    pegawai p
    INNER JOIN transaksi_buku tb ON p.id_pegawai = tb.id_pegawai
    INNER JOIN transaksi_ruangan tr ON p.id_pegawai = tr.id_pegawai
WHERE
    tb.denda IS NOT NULL AND
    tr.denda IS NOT NULL;

-- Menampilkan data pegawai yang telah melayani transaksi peminjaman buku lebih dari 3 kali
SELECT
    p.*
FROM
    pegawai p
    INNER JOIN transaksi_buku tb ON p.id_pegawai = tb.id_pegawai
GROUP BY
    p.id_pegawai
HAVING
    COUNT(tb.id_transaksi_buku) > 3;

-- Menampilkan data anggota yang memiliki total denda transaksi peminjaman ruangan paling tinggi
SELECT
    a.*
FROM
    keanggotaan a
    INNER JOIN transaksi_ruangan tr ON a.id_anggota = tr.id_anggota
GROUP BY
    a.id_anggota
ORDER BY
    SUM(tr.denda) DESC
LIMIT 1;

-- Muhammad Nabil Afrizal Rahmadani 5025231014
-- Menampilkan anggota yang paling sering meminjam ruangan dan ruangan apa yang paling sering dia pinjam
SELECT
    a.*,
    r.*
FROM
    keanggotaan a
    INNER JOIN transaksi_ruangan tr ON a.id_anggota = tr.id_anggota
    INNER JOIN ruangan r ON tr.id_ruangan = r.id_ruangan
GROUP BY
    a.id_anggota
ORDER BY
    COUNT(id_transaksi_ruangan) DESC
LIMIT 1;

-- Menampilkan pengunjung yang berasal dari luar ITS yang mendaftar keanggotaan di perpustakaan ITS
SELECT
    p.*
FROM
    pengunjung p
    INNER JOIN keanggotaan a ON p.id_pengunjung = a.id_pengunjung
WHERE
    a.nrp IS NULL;

-- Menampilkan data anggota yang paling sering berkunjung pada bulan November 2023
SELECT
    a.*
FROM
    keanggotaan a
    INNER JOIN pengunjung p ON a.id_pengunjung = p.id_pengunjung
    INNER JOIN waktu_berkunjung wb ON p.id_pengunjung = wb.id_pengunjung AND MONTH(wb.waktu) = 11
GROUP BY
    wb.id_pengunjung
ORDER BY
    COUNT(wb.waktu) DESC
LIMIT 1;

-- Menampilkan rata-rata denda per ruangan
SELECT
    r.id_ruangan,
    r.nama_ruangan,
    AVG(tr.denda) rata_rata_denda
FROM
    transaksi_ruangan tr
    INNER JOIN ruangan r ON tr.id_ruangan = r.id_ruangan
GROUP BY
    r.id_ruangan;

-- Menampilkan pegawai dan pelanggan yang melayani dan meminjam ruangan pada tahun 2023
SELECT
    tr.id_transaksi_ruangan,
    pj.nama nama_anggota,
    pw.nama_pegawai
FROM
    transaksi_ruangan tr
    INNER JOIN keanggotaan a ON tr.id_anggota = a.id_anggota
    INNER JOIN pengunjung pj ON a.id_pengunjung = pj.id_pengunjung
    INNER JOIN pegawai pw ON tr.id_pegawai = pw.id_pegawai
WHERE
    YEAR(tr.waktu_transaksi) = 2023;

-- Randi Palguna Artayasa 5025231020
-- Menampilkan nama pengunjung yang datang berkunjung pada bulan Juli dan berasal dari jurusan Teknik Informatika
SELECT
    DISTINCT p.nama
FROM
    keanggotaan a
    INNER JOIN pengunjung p ON a.id_pengunjung = p.id_pengunjung
    INNER JOIN waktu_berkunjung wb ON p.id_pengunjung = wb.id_pengunjung
WHERE
    MONTH(wb.waktu) = 7 AND
    a.jurusan LIKE '%Teknik Informatika';

-- Menampilkan total denda pada transaksi_buku yang dimiliki masing-masing seluruh keanggotaan
SELECT
    a.id_anggota,
    SUM(tb.denda) total_denda
FROM
    keanggotaan a
    LEFT JOIN transaksi_buku tb ON a.id_anggota = tb.id_anggota
GROUP BY
    a.id_anggota;

-- Menampilkan total jumlah buku yang dimiliki oleh koleksi umum
SELECT
    COUNT(b.id_buku) total_buku_umum
FROM
    buku b
    INNER JOIN koleksi_buku kb ON b.id_koleksi_buku = kb.id_koleksi_buku
WHERE
    kb.koleksi_buku = 'Umum'
GROUP BY
    kb.id_koleksi_buku;

-- Tampilkan 5 nama keanggotaan dan id transaksi buku dari 5 denda transaksi buku terbesar
SELECT 
    DISTINCT p.nama, tb.id_transaksi_buku
FROM
    buku b
    INNER JOIN buku_transaksi_buku btb ON b.id_buku = btb.id_buku
    INNER JOIN transaksi_buku tb ON btb.id_transaksi_buku = tb.id_transaksi_buku
    INNER JOIN keanggotaan a ON tb.id_anggota = a.id_anggota
    INNER JOIN pengunjung p ON a.id_pengunjung = p.id_pengunjung
ORDER BY
    tb.denda DESC
LIMIT 5;

-- Menampilkan nama, nrp, dan jurusan keanggotaan yang pernah meminjam buku yang judulnya terdapat kata "Algoritma"
SELECT DISTINCT
    p.nama,
    a.nrp,
    a.jurusan
FROM
    pengunjung p
    INNER JOIN keanggotaan a ON p.id_pengunjung = a.id_pengunjung
    INNER JOIN transaksi_buku tb ON a.id_anggota = tb.id_anggota
    INNER JOIN buku_transaksi_buku btb ON tb.id_transaksi_buku = btb.id_transaksi_buku
    INNER JOIN buku b ON btb.id_buku = b.id_buku
WHERE
    b.judul_buku LIKE '%Algoritma%';

-- I Gusti Ngurah Arya Sudewa 5025231030
-- Menampilkan data transaksi buku dan jumlah buku yang dipinjam untuk transaksi dengan peminjaman lebih dari satu buku
SELECT
	tb.*,
    COUNT(btb.id_buku) jumlah_buku
FROM
	transaksi_buku tb
    INNER JOIN buku_transaksi_buku btb ON tb.id_transaksi_buku = btb.id_transaksi_buku
GROUP BY
	btb.id_transaksi_buku
HAVING
	COUNT(btb.id_buku) > 1;

-- Menampilkan data buku yang tidak pernah dipinjam
SELECT
    b.*
FROM
    buku b
    LEFT JOIN buku_transaksi_buku btb ON b.id_buku = btb.id_buku
WHERE
    btb.id_buku IS NULL;

-- Menampilkan nama anggota dan jumlah transaksi buku dari anggota tersebut. Diurutkan dari transaksi buku terbanyak
SELECT
    p.nama,
    COUNT(tb.id_transaksi_buku) jumlah_transaksi_buku
FROM
    pengunjung p
    INNER JOIN keanggotaan a ON p.id_pengunjung = a.id_pengunjung
    INNER JOIN transaksi_buku tb ON a.id_anggota = tb.id_anggota
GROUP BY
    a.id_anggota
ORDER BY
    COUNT(tb.id_transaksi_buku) DESC;

-- Menampilkan data pegawai yang pernah mengurus transaksi buku tetapi tidak pernah mengurus transaksi ruangan
SELECT
    DISTINCT p.*
FROM
    pegawai p
    INNER JOIN transaksi_buku tb ON p.id_pegawai = tb.id_pegawai
    LEFT JOIN transaksi_ruangan tr ON p.id_pegawai = tr.id_pegawai
WHERE
    tr.id_pegawai IS NULL;

-- Menampilkan data anggota yang pernah meminjam buku dengan judul yang sama lebih dari satu kali
SELECT
    DISTINCT a.*
FROM
    keanggotaan a
    INNER JOIN transaksi_buku tb ON a.id_anggota = tb.id_anggota
WHERE
    a.id_anggota IN (
        SELECT
            tb.id_anggota
        FROM
            transaksi_buku tb
            INNER JOIN buku_transaksi_buku btb ON tb.id_transaksi_buku = btb.id_transaksi_buku
            INNER JOIN buku b ON btb.id_buku = b.id_buku
        GROUP BY
            tb.id_anggota,
            b.judul_buku
        HAVING
            COUNT(b.judul_buku) > 1
    );