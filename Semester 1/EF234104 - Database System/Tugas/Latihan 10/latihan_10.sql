-- Nama : Muhammad Nabil Afrizal Rahmadani
-- NRP : 5025231014

-- Soal 1
CREATE DATABASE persewaan_5025231014;
USE persewaan_5025231014;

-- Soal 2
CREATE TABLE kelompok_film(
  jenis VARCHAR(20) NOT NULL PRIMARY KEY, 
  harga_sewa NUMERIC NOT NULL
);

CREATE TABLE film(
  kode_film CHAR(4) NOT NULL PRIMARY KEY, 
  jenis VARCHAR(20) NOT NULL, 
  judul VARCHAR(32) NOT NULL, 
  jml_keping INTEGER, 
  jml_film INTEGER, 
  FOREIGN KEY (jenis) REFERENCES kelompok_film(jenis)
);

CREATE TABLE customer(
  no_identitas CHAR(3) NOT NULL PRIMARY KEY, 
  jenis_identitas CHAR(6) NOT NULL, 
  nama VARCHAR(20) NOT NULL, 
  alamat VARCHAR(20) NOT NULL
);

CREATE TABLE menyewa(
  kode_sewa CHAR(5) NOT NULL, 
  no_identitas CHAR(3) NOT NULL, 
  tgl_sewa DATE NOT NULL, 
  tot_film INTEGER NOT NULL, 
  tgl_kembali DATE, 
  tot_hrg NUMERIC NOT NULL, 
  denda NUMERIC, 
  PRIMARY KEY(kode_sewa, no_identitas), 
  FOREIGN KEY (no_identitas) REFERENCES customer(no_identitas)
);

CREATE TABLE detailmenyewa(
  kode_sewa CHAR(5) NOT NULL, 
  kode_film CHAR(4) NOT NULL, 
  PRIMARY KEY (kode_sewa, kode_film),
  FOREIGN KEY (kode_sewa) REFERENCES menyewa(kode_sewa),
  FOREIGN KEY (kode_film) REFERENCES film(kode_film)
);

INSERT INTO kelompok_film (jenis, harga_sewa) 
VALUES 
  ('action', '3000'), 
  ('drama', '3500'), 
  ('horor', '3000');

INSERT INTO film (kode_film, jenis, judul, jml_keping, jml_film)
VALUES
  ('A01', 'action', 'Spiderman', '2', '3'),
  ('A02', 'action', 'Spiderman 2', '2', '5'),
  ('D01', 'drama', 'Love Story', '2', '3'),
  ('H01', 'horor', 'Evil Death', '2', '2');

INSERT INTO customer (no_identitas, jenis_identitas, nama, alamat)
VALUES
  ('001', 'SIM', 'Andi', 'pontianak'),
  ('002', 'SIM', 'Budi', 'pontianak');

INSERT INTO menyewa (kode_sewa, no_identitas, tgl_sewa, tot_film, tgl_kembali, tot_hrg, denda)
VALUES
  ('S0001', '001', '2007-01-01', '2', '2007-01-02', '6000', '0'),
  ('S0002', '002', '2007-01-03', '1', '2007-01-03', '3500', '0'),
  ('S0003', '001', '2007-01-06', '3', '2007-01-08', '9500', '0');

INSERT INTO detailmenyewa (kode_sewa, kode_film)
VALUES
  ('S0001', 'A01'),
  ('S0001', 'A02'),
  ('S0002', 'D01'),
  ('S0003', 'A02'),
  ('S0003', 'D01'),
  ('S0003', 'H01');

-- Soal 2
ALTER TABLE customer
ADD no_hp VARCHAR(15);

-- Soal 4
ALTER TABLE customer
CHANGE no_hp no_wa VARCHAR(15);

-- Soal 5
ALTER TABLE customer
DROP COLUMN jenis_identitas;

-- Soal 6
INSERT INTO kelompok_film (jenis, harga_sewa)
VALUES
  ('komedi', '5000');

-- Soal 7
INSERT INTO film (kode_film, jenis, judul, jml_keping, jml_film)
VALUES
  ('K01', 'komedi', 'Kapan Kawin', '10', '2'),
  ('K02', 'komedi', 'Takut Kawin', '6', '3'),
  ('D02', 'drama', 'Ayat ayat Cinta', '8', '3'),
  ('D03', 'drama', 'Tiga doa tiga Cinta', '5', '2'),
  ('H02', 'horor', 'Resident Evil', '7', '4');

-- Soal 8
UPDATE kelompok_film
SET harga_sewa = harga_sewa * 10;