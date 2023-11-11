DROP DATABASE servis_mobil_antera;

-- Nama : Muhammad Nabil Afrizal Rahmadani
-- NRP : 5025231014

CREATE DATABASE servis_mobil_antera;
USE servis_mobil_antera;

CREATE TABLE pelanggan(
    p_id CHAR(16) NOT NULL,
    p_nama VARCHAR(60) NOT NULL,
    p_no_telp VARCHAR(15) NOT NULL,
    p_email VARCHAR(256),
    p_alamat VARCHAR(100) NOT NULL,
    CONSTRAINT pelanggan_PK PRIMARY KEY (p_id)
);

CREATE TABLE mobil(
    mb_vin CHAR(17) NOT NULL,
    mb_merk VARCHAR(20) NOT NULL,
    mb_tipe VARCHAR(30) NOT NULL,
    mb_tahun INTEGER NOT NULL,
    mb_warna VARCHAR(20) NOT NULL,
    mb_p_id CHAR(16) NOT NULL,
    CONSTRAINT mobil_PK PRIMARY KEY (mb_vin),
    CONSTRAINT mobil_pelanggan_FK FOREIGN KEY (mb_p_id) REFERENCES pelanggan(p_id)
);

CREATE TABLE tiket_servis(
    ts_id CHAR(8) NOT NULL,
    ts_waktu_masuk TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    ts_waktu_keluar TIMESTAMP NULL,
    ts_deskripsi VARCHAR(400) NOT NULL,
    ts_komentar VARCHAR(400),
    ts_p_id CHAR(16) NOT NULL,
    ts_mb_vin CHAR(17) NOT NULL,
    CONSTRAINT tiket_servis_PK PRIMARY KEY (ts_id),
    CONSTRAINT tiket_servis_pelanggan_FK FOREIGN KEY (ts_p_id) REFERENCES pelanggan(p_id),
    CONSTRAINT tiket_servis_mobil_FK FOREIGN KEY (ts_mb_vin) REFERENCES mobil(mb_vin)
);

CREATE TABLE mekanik(
    mk_id CHAR(6) NOT NULL,
    mk_nama VARCHAR(60) NOT NULL,
    CONSTRAINT mekanik_PK PRIMARY KEY (mk_id)
);

CREATE TABLE mekanik_servis(
    mksv_mk_id CHAR(6) NOT NULL,
    mksv_ts_id CHAR(8) NOT NULL,
    CONSTRAINT Relation_8_PK PRIMARY KEY (mksv_mk_id, mksv_ts_id),
    CONSTRAINT Relation_8_Mekanik_FK FOREIGN KEY (mksv_mk_id) REFERENCES mekanik(mk_id),
    CONSTRAINT Relation_8_tiket_servis_FK FOREIGN KEY (mksv_ts_id) REFERENCES tiket_servis(ts_id)
);

CREATE TABLE suku_cadang(
    sc_id CHAR(7) NOT NULL,
    sc_nama VARCHAR(120) NOT NULL,
    sc_deskripsi VARCHAR(100) NOT NULL,
    sc_harga DECIMAL(10, 2) NOT NULL,
    CONSTRAINT suku_cadang_PK PRIMARY KEY (sc_id)
);

CREATE TABLE suku_cadang_servis(
    scsv_ts_id CHAR(8) NOT NULL,
    scsv_sc_id CHAR(7) NOT NULL,
    CONSTRAINT Relation_9_PK PRIMARY KEY (scsv_ts_id, scsv_sc_id),
    CONSTRAINT Relation_9_tiket_servis_FK FOREIGN KEY (scsv_ts_id) REFERENCES tiket_servis(ts_id),
    CONSTRAINT Relation_9_suku_cadang_FK FOREIGN KEY (scsv_sc_id) REFERENCES suku_cadang(sc_id)
);

-- Soal 2
CREATE TABLE supplier(
    sp_id CHAR(6) NOT NULL,
    sp_nama VARCHAR(60) NOT NULL,
    sp_no_telp VARCHAR(15) NOT NULL,
    sp_email VARCHAR(256) NOT NULL,
    sp_alamat VARCHAR(100) NOT NULL,
    CONSTRAINT supplier_PK PRIMARY KEY (sp_id)
);

-- Soal 3
RENAME TABLE mekanik TO pegawai;
CREATE TABLE posisi(
    ps_id CHAR(6) NOT NULL,
    ps_nama VARCHAR(15) NOT NULL,
    CONSTRAINT posisi_PK PRIMARY KEY (ps_id)
);

ALTER TABLE pegawai
ADD pegawai_posisi CHAR(6) NOT NULL,
ADD CONSTRAINT pegawai_posisi_FK FOREIGN KEY (pegawai_posisi) REFERENCES posisi(ps_id);

-- Soal 4
ALTER TABLE pegawai
DROP CONSTRAINT pegawai_posisi_FK;

ALTER TABLE pegawai
DROP COLUMN pegawai_posisi;

DROP TABLE posisi;

ALTER TABLE pegawai
ADD COLUMN mk_posisi VARCHAR(15) NOT NULL;

-- Soal 5
INSERT INTO supplier(sp_id, sp_nama, sp_no_telp, sp_email, sp_alamat)
    VALUES
    ('SP0001', 'Indotrading', '6282283741247', 'indotrading@rocketmail.com', 'Jl. Bambu no 5'),
    ('SP0002', 'Jayasinda', '628227428238', 'Jayasinda@yahoo.com', 'Jl. Padi no 12'),
    ('SP0003', 'SAS Autoparts', '6282212382311', 'sasparts@gmail.com', 'Jl. Sorghum no 24');

INSERT INTO pelanggan(p_id, p_nama, p_no_telp, p_email, p_alamat)
    VALUES
    ('3225011201880002', 'Andy Williams', '62123456789', 'andy@gmail.com', 'Jl. Apel no 1'),
    ('3525010706950001', 'Marshall Paul', '621451871011', 'paulan@gmail.com', 'Jl. Jeruk no 12'),
    ('3525016005920002', 'Kazuya Tanaka', '62190129190', 'tanaka@gmail.com', 'Jl. JKT no 48'),
    ('3975311107780001', 'Budi Prutomo', '621545458901', NULL, 'Jl. Nanas no 45'),
    ('3098762307810002', 'Razai Ambudi', '621898989102', NULL, 'Jl. Mangga no 2');

INSERT INTO mobil(mb_vin, mb_merk, mb_tipe, mb_tahun, mb_warna, mb_p_id)
    VALUES
    ('JN8AZ1MW4BW678706', 'Nissan', 'Murano', 2011, 'biru', '3525010706950001'),
    ('2LMTJ8JP0GSJ00175', 'Lincoln', 'MKX', 2016, 'merah', '3525016005920002'),
    ('ZFF76ZHT3E0201920', 'Ferrari', 'Ferrari', 2014, 'merah', '3975311107780001'),
    ('1HGCP26359A157554', 'Honda', 'Accord', 2009, 'hitam', '3225011201880002'),
    ('5YJSA1DN5CFP01785', 'Tesla', 'Model S', 2012, 'putih', '3098762307810002');

INSERT INTO pegawai(mk_id, mk_nama, mk_posisi)
    VALUES
    ('MK0001', 'Walter Jones', 'mekanik'),
    ('MK0002', 'Kentaki Veraid', 'kasir'),
    ('MK0003', 'Leo', 'mekanik'),
    ('MK0004', 'Reyhand Janita', 'pencuci'),
    ('MK0005', 'Elizabeth Alexandra', 'mekanik');

INSERT INTO suku_cadang(sc_id, sc_nama, sc_deskripsi, sc_harga)
    VALUES
    ('SC00001', 'Damper', 'Damper Per Belakang Original', 800000.00),
    ('SC00002', 'Coil', 'Ignition Coil Ignition Denso Jepang', 550000.00),
    ('SC00003', 'Selang Filter', 'Selang Filter Udara Original', 560000.00),
    ('SC00004', 'Bushing', 'Bushing Upper Arm Original', 345000.00),
    ('SC00005', 'Radiator Racing', 'Radiator Racing Kotorad Manual Diesel', 6750000.00);

INSERT INTO tiket_servis(ts_id, ts_waktu_masuk, ts_waktu_keluar, ts_deskripsi, ts_komentar, ts_p_id, ts_mb_vin)
    VALUES
    ('TS000001', '2023-11-05 08:00:00', '2023-11-05 16:30:00', 'Mobil mengalami getaran yang tidak normal saat berkendara. Untuk memperbaikinya, kami akan mengganti damper yang aus dan juga bushing yang telah rusak.', 'Saya sangat puas dengan perbaikan ini. Mobil saya sekarang berjalan lebih halus dan  getarannya hilang. Terima kasih atas pelayanan yang baik!', '3098762307810002', '5YJSA1DN5CFP01785'),
    ('TS000002', '2023-11-05 09:15:00', '2023-11-05 17:45:00', 'Mesin mobil sering mati secara tiba-tiba atau tidak berjalan dengan baik. Permasalahannya terletak pada coil ignition yang bermasalah. Kami akan menggantinya dan melakukan pengaturan ulang untuk memastikan kinerja mesin yang lebih baik.', 'Mesin mobil saya sekarang berjalan seperti baru lagi. Tidak ada lagi mati mendadak, dan kinerjanya sangat baik. Pelayanan yang cepat dan profesional.', '3975311107780001', 'ZFF76ZHT3E0201920'),
    ('TS000003', '2023-11-06 10:30:00', '2023-11-06 18:15:00', 'UntuK meningkatkan kinerja pendinginan mesin, kami akan membersihkan radiator dan memeriksa apakah ada kerusakan atau kebocoran. Jika diperlukan, kami akan mengganti komponen yang rusak.', 'Mobil saya sekarang tidak lagi mengalami masalah panas berlebihan. Radiator berfungsi dengan baik, dan saya merasa aman saat berkendara. Terima kasih atas perbaikan yang berkualitas.', '3525016005920002', '2LMTJ8JP0GSJ00175'),
    ('TS000004', '2023-11-06 11:45:00', '2023-11-06 19:30:00', 'Mobil mengalami masalah saat memasok bahan bakar ke mesin. Masalah ini terjadi karena selang filter bahan bakar yang tersumbat. Kami akan menggantinya sehingga aliran bahan bakar menjadi lancar kembali.', 'Setelah penggantian selang filter bahan bakar, mobil saya kembali berjalan dengan lancar. Tidak ada lagi masalah pengiriman bahan bakar. Pelayanan yang sangat membantu', '3525010706950001', 'JN8AZ1MW4BW678706'),
    ('TS000005', '2023-11-06 12:30:00', '2023-11-06 20:00:00', 'Mobil akan menjalani pemeliharaan komprehensif, termasuk pemeriksaan seluruh sistem. Ini termasuk penggantian damper yang aus, coil ignition yang bermasalah, serta pemeriksaan dan perawatan selang filter dan radiator racing. Semua suku cadang yang perlu diganti akan diperbaiki agar mobil berfungsi seperti semula.', 'Pemeliharaan komprehensif yang telah dilakukan membuat mobil saya seperti baru. Semua masalah telah diperbaiki, dan saya merasa yakin dengan kualitas perbaikan yang diberikan. Terima kasih atas kerja kerasnya', '3225011201880002', '1HGCP26359A157554');

INSERT INTO mekanik_servis(mksv_ts_id, mksv_mk_id)
    VALUES
    ('TS000001', 'MK0005'),
    ('TS000002', 'MK0003'),
    ('TS000002', 'MK0004'),
    ('TS000003', 'MK0005'),
    ('TS000004', 'MK0003'),
    ('TS000005', 'MK0001'),
    ('TS000005', 'MK0005'),
    ('TS000005', 'MK0004');

INSERT INTO suku_cadang_servis(scsv_ts_id, scsv_sc_id)
    VALUES
    ('TS000001', 'SC00001'),
    ('TS000001', 'SC00004'),
    ('TS000002', 'SC00002'),
    ('TS000003', 'SC00005'),
    ('TS000004', 'SC00003'),
    ('TS000005', 'SC00001'),
    ('TS000005', 'SC00002'),
    ('TS000005', 'SC00003'),
    ('TS000005', 'SC00005');

-- Soal 6
UPDATE tiket_servis
SET ts_waktu_keluar = CURRENT_TIMESTAMP;

-- Soal 7
UPDATE pelanggan
SET p_nama = 'Andi Williams', p_email = 'andi@bing.com', p_alamat = 'Jl. Koreka No. 15'
WHERE p_id = '3225011201880002';

-- Soal 8
    ALTER TABLE suku_cadang
    ADD sp_id CHAR(6),
    ADD CONSTRAINT sc_sp_FK FOREIGN KEY (sp_id) REFERENCES supplier(sp_id);

    UPDATE suku_cadang
    SET sp_id = 'SP0001'
    WHERE sc_id = 'SC00004';

    UPDATE suku_cadang
    SET sp_id = 'SP0002'
    WHERE sc_id IN ('SC00001', 'SC00003');

    UPDATE suku_cadang
    SET sp_id = 'SP0003'
    WHERE sc_id IN ('SC00002', 'SC00005');

-- Soal 9
UPDATE suku_cadang
SET sc_harga = sc_harga + (sc_harga * 0.1)
WHERE sc_harga > 500000;

-- Soal 10
INSERT INTO tiket_servis(ts_id, ts_waktu_masuk, ts_waktu_keluar, ts_deskripsi, ts_komentar, ts_p_id, ts_mb_vin)
    VALUES
    ('TS000006', '2023-11-10 09:05:00', NULL, 'Mobil mengalami kerusakan damper belakang. Terdapat kebocoran cairan hidrolik dan kondisi damper sudah aus. Kami akan mengganti damper belakang.', NULL, '3525016005920002', '2LMTJ8JP0GSJ00175');

INSERT INTO mekanik_servis(mksv_ts_id, mksv_mk_id)
    VALUES
    ('TS000006', 'MK0001');

INSERT INTO suku_cadang_servis(scsv_ts_id, scsv_sc_id)
    VALUES
    ('TS000006', 'SC00001');

-- Soal 11
UPDATE tiket_servis
SET 
ts_waktu_keluar = CURRENT_TIMESTAMP,
ts_komentar = 'kurang memuaskan'
WHERE ts_id = 'TS000006';

DELETE FROM mekanik_servis
WHERE mksv_mk_id = 'MK0001';

DELETE FROM pegawai
WHERE mk_nama = 'Walter Jones';

-- Soal 12
DELETE FROM mekanik_servis;