/*
Nama : Muhammad Nabil Afrizal Rahmadani
NRP : 5025231014
*/


-- Soal 1
SELECT * FROM transaksi
WHERE tanggal_transaksi BETWEEN '2023-10-10' AND '2023-10-20';

-- Soal 2
-- Hitung total harga dari setiap transaksi, tampilkan id transaksi dan total harga nya
SELECT trans.ID_transaksi, SUM(mm.harga_minuman * transM.Jumlah_minuman) AS TOTAL_HARGA FROM Transaksi trans
INNER JOIN
Transaksi_minuman transM ON trans.ID_transaksi = transM.TM_transaksi_ID
INNER JOIN
Menu_minuman mm ON transM.tm_menu_minuman_id = mm.id_minuman
GROUP BY trans.ID_transaksi;

-- Soal 3
-- Hitung total biaya yang pernah dikeluarkan oleh setiap cutsomer pada dari tanggal 3
-- Oktober 2023 hingga 22 Oktober 2023, tampilkan semua kolom dari tabel customer dan
-- total biaya dengan tampilan nama kolom “Total_Belanja”. Urutkan berdasarkan nama
-- customer dari A ke Z.
SELECT c.*, SUM(mm.harga_minuman * transM.jumlah_minuman) AS TOTAL_BELANJA FROM Customer c
LEFT JOIN
Transaksi trans ON trans.customer_ID_customer = c.ID_customer
LEFT JOIN
Transaksi_minuman transM ON trans.ID_transaksi = transM.TM_transaksi_ID
LEFT JOIN
Menu_minuman mm ON transM.tm_menu_minuman_id = mm.id_minuman
WHERE trans.tanggal_transaksi BETWEEN '2023-10-03' AND '2023-10-22'
GROUP BY c.nama_customer
ORDER BY nama_customer;

-- Soal 4
-- Mbak Nuri ingin mengetahui data pegawai yang pernah melayani customer dengan nama
-- Davi Liam, Sisil Triana, atau Hendra Asto
SELECT p.*, c.nama_customer FROM pegawai p
INNER JOIN
Transaksi trans ON trans.pegawai_nik = p.nik
INNER JOIN
Customer c ON trans.customer_id_customer = c.id_customer
WHERE
nama_customer IN  ('Davi Liam', 'Sisil Triana', 'Hendra Asto');

-- Soal 5
-- Hitunglah jumlah cup yang terjual pada Kopi Nuri setiap bulannya (perhatikan bulan dan
-- tahunnya)! Tampilkan kolom bulan, tahun, dan jumlah cup dengan nama ‘BULAN’,
-- ‘TAHUN’, ‘JUMLAH_CUP’. Urutkan berdasarkan tahun dari yang terbesar dan bulan
-- yang terkecil.
SELECT SUM(tm.jumlah_minuman) AS JUMLAH_CUP, MONTH(t.tanggal_transaksi) AS BULAN, YEAR(t.tanggal_transaksi) AS TAHUN FROM transaksi_minuman tm
INNER JOIN
transaksi t ON tm.tm_transaksi_id = t.id_transaksi
INNER JOIN
menu_minuman mm ON mm.id_minuman = tm.tm_menu_minuman_id
GROUP BY BULAN, TAHUN
ORDER BY TAHUN DESC, BULAN ASC;


-- Soal 6
-- Berapa nilai rata-rata total belanja transaksi seluruh customer?
SELECT AVG(mm.harga_minuman * tm.jumlah_minuman) AS rata_rata FROM customer c
INNER JOIN
transaksi t ON c.ID_customer = t.customer_id_customer
INNER JOIN
transaksi_minuman tm  ON t.id_transaksi = tm.tm_transaksi_id
INNER JOIN
menu_minuman mm ON mm.id_minuman = tm.tm_menu_minuman_id;


-- Soal 7
-- Dapatkan data customer dengan rata-rata total belanja lebih dari rata-rata total belanja
-- seluruh customer. Tampilkan kolom id customer, nama customer, dan total belanja!
SELECT c.nama_customer, AVG(mm.harga_minuman * tm.jumlah_minuman) AS rata_rata FROM customer c
INNER JOIN
transaksi t ON c.ID_customer = t.customer_id_customer
INNER JOIN
transaksi_minuman tm  ON t.id_transaksi = tm.tm_transaksi_id
INNER JOIN
menu_minuman mm ON mm.id_minuman = tm.tm_menu_minuman_id
GROUP BY
c.id_customer
HAVING
    rata_rata > (SELECT AVG(mm.harga_minuman * tm.jumlah_minuman) FROM transaksi_minuman tm 
    LEFT JOIN menu_minuman mm ON mm.id_minuman = tm.tm_menu_minuman_id);

-- Soal 8
-- Tampilkan data customer yang tidak terdaftar sebagai membership!
SELECT c.*, m.m_id_customer FROM customer c
LEFT JOIN
membership m ON m.m_id_customer = c.id_customer
WHERE
m.id_membership IS NULL;

-- Soal 9
-- Berapakah jumlah customer yang pernah memesan minuman Latte?
SELECT COUNT(DISTINCT c.id_customer), mm.Nama_minuman FROM customer c
INNER JOIN
transaksi t ON c.id_customer = t.customer_id_customer
INNER JOIN
transaksi_minuman tm ON tm.tm_transaksi_id = t.id_transaksi
INNER JOIN
menu_minuman mm ON tm.tm_menu_minuman_id = mm.id_minuman
WHERE Nama_minuman = 'Latte';

-- Soal 10
-- Mbak Nuri penasaran, dia ingin mengetahui nama customer, menu minuman, dan total
-- jumlah cup menu minuman dari customer dengan nama yang berawalan dengan huruf S!
SELECT c.*, mm.nama_minuman, SUM(tm.jumlah_minuman) FROM customer c
INNER JOIN
transaksi t ON c.id_customer = t.customer_id_customer
INNER JOIN
transaksi_minuman tm ON tm.tm_transaksi_id = t.id_transaksi
INNER JOIN
menu_minuman mm ON tm.tm_menu_minuman_id = id_minuman
WHERE c.nama_customer REGEXP '^[S]'
GROUP BY c.id_customer, mm.nama_minuman;