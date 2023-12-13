-- Soal 1
SELECT c.c_nama, c.c_email FROM customer c
WHERE c.c_telp LIKE '081%';

-- Soal 2
SELECT ts.ts_id, SUM(tr.t_harga) AS total FROM transaksi ts
INNER JOIN
treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN
treatment tr ON tr.t_id = tt.treatment_t_id
GROUP BY
ts.ts_id
ORDER BY total DESC
LIMIT 5;

-- Soal 3
SELECT COUNT(DISTINCT c.c_id) FROM customer c
INNER JOIN
transaksi ts ON ts.customer_c_id = c.c_id
INNER JOIN
treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN
treatment t ON t.t_id = tt.treatment_t_id
WHERE
c.c_jenis_kelamin = 'L' AND t.t_nama = 'Haircut';

-- Soal 4
SELECT ts_metode_pembayaran AS Metode_Pembayaran, COUNT(ts_metode_pembayaran) AS Jumlah FROM transaksi
GROUP BY ts_metode_pembayaran;

-- Soal 5
SELECT c.c_nama FROM customer c
INNER JOIN
transaksi ts ON ts.customer_c_id = c.c_id
GROUP BY
c.c_id
HAVING
COUNT(ts.ts_id) > 3;

-- Soal 6
SELECT p.p_nama AS nama_pegawai, ts.ts_id AS id_transaksi, COUNT(t.t_id) AS jumlah_transaksi FROM pegawai p
INNER JOIN
transaksi ts ON ts.pegawai_p_nik = p.p_nik
INNER JOIN
treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN
treatment t ON t.t_id = tt.treatment_t_id
GROUP BY
tt.transaksi_ts_id
HAVING
COUNT(t.t_id) > 3;

-- Soal 7
SELECT AVG(t_harga) FROM treatment t
INNER JOIN
treatment_transaksi tt ON tt.treatment_t_id = t.t_id
INNER JOIN
transaksi ts ON ts.ts_id = tt.transaksi_ts_id
INNER JOIN
pegawai p ON p.p_nik = ts.pegawai_p_nik
WHERE
p.p_jenis_kelamin = 'L' AND ts.ts_waktu_transaksi BETWEEN '2023-11-04 00:00:00' AND '2023-11-04 23:59:59';

-- Soal 8
SELECT ts.*, c.c_nama, p.p_nama FROM transaksi ts
INNER JOIN
customer c ON ts.customer_c_id = c.c_id
INNER JOIN
pegawai p ON p.p_nik = ts.pegawai_p_nik
INNER JOIN
treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN
treatment t ON t.t_id = tt.treatment_t_id
HAVING
MAX(ts_waktu_transaksi);

-- Soal 9
SELECT c.c_nama, SUM(t.t_harga) 
FROM customer c
INNER JOIN transaksi ts ON ts.customer_c_id = c.c_id
INNER JOIN treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN treatment t ON t.t_id = tt.treatment_t_id
WHERE ts.ts_metode_pembayaran <> 'Credit Card'
GROUP BY c.c_id
HAVING COUNT(DISTINCT ts.ts_metode_pembayaran) = 2;



-- Soal 10
SELECT t.t_nama, SUM(t.t_harga) FROM customer c
INNER JOIN
transaksi ts ON c.c_id = ts.customer_c_id
INNER JOIN
treatment_transaksi tt ON tt.transaksi_ts_id = ts.ts_id
INNER JOIN
treatment t ON t.t_id = tt.treatment_t_id
WHERE
c.c_nama = 'Hendri Kusuma'
GROUP BY
t.t_id;