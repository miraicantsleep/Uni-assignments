DROP DATABASE test; 
-- Nama : Muhammad Nabil Afrizal Rahmadani
-- NRP : 5025231014
-- Soal 1 --
CREATE DATABASE test;
USE test;
CREATE TABLE Pegawai(
    NIK CHAR(16) NOT NULL,
    Nama_pegawai VARCHAR(100) NOT NULL,
    Jenis_kelamin CHAR(1),
    Email VARCHAR(50),
    Umur INTEGER,
    CONSTRAINT Pegawai_PK PRIMARY KEY (NIK)
);
CREATE TABLE Telepon(
    No_telp_pegawai VARCHAR(15) NOT NULL,
    Pegawai_NIK CHAR(16) NOT NULL,
    CONSTRAINT Telepon_PK PRIMARY KEY (No_telp_pegawai),
    CONSTRAINT Telepon_Pegawai_FK FOREIGN KEY (Pegawai_NIK) REFERENCES Pegawai(NIK)
);
CREATE TABLE Customer(
    ID_customer CHAR(6) NOT NULL,
    Nama_customer VARCHAR(100) NOT NULL,
    CONSTRAINT Customer_PK PRIMARY KEY (ID_customer)
);
CREATE TABLE Transaksi(
    ID_transaksi CHAR(10) NOT NULL,
    Tanggal_transaksi DATE NOT NULL,
    Metode_pembayaran VARCHAR(15) NOT NULL,
    Customer_ID_customer CHAR(6) NOT NULL,
    Pegawai_NIK CHAR(16) NOT NULL,
    CONSTRAINT Transaksi_PK PRIMARY KEY (ID_transaksi),
    CONSTRAINT Transaksi_Customer_FK FOREIGN KEY (Customer_ID_customer) REFERENCES Customer(ID_customer),
    CONSTRAINT Transaksi_Pegawai_FK FOREIGN KEY (Pegawai_NIK) REFERENCES Pegawai(NIK)
);
CREATE TABLE Menu_minuman(
    ID_minuman CHAR(6) NOT NULL,
    Nama_minuman VARCHAR(50) NOT NULL,
    Harga_minuman FLOAT(2) NOT NULL,
    CONSTRAINT Menu_minuman_PK PRIMARY KEY (ID_minuman)
);
CREATE TABLE Transaksi_minuman(
    TM_Menu_minuman_ID CHAR(6) NOT NULL,
    TM_Transaksi_ID CHAR(10) NOT NULL,
    Jumlah_cup INTEGER NOT NULL,
    CONSTRAINT Transaksi_minuman_PK PRIMARY KEY (TM_Menu_minuman_ID, TM_Transaksi_ID),
    CONSTRAINT TM_ID_menu_minuman_FK FOREIGN KEY (TM_Menu_minuman_ID) REFERENCES Menu_minuman(ID_minuman),
    CONSTRAINT TM_ID_Transaksi_FK FOREIGN KEY (TM_TRANSAKSI_ID) REFERENCES Transaksi(ID_transaksi)
);
CREATE TABLE membership(
    id_membership CHAR(6) NOT NULL,
    no_telepon_customer VARCHAR(15) NOT NULL,
    alamat_customer VARCHAR(100) NOT NULL,
    tanggal_pembuatan_kartu_membership DATE NOT NULL,
    tanggal_kedaluawarsa_kartu_membership DATE,
    total_poin INTEGER NOT NULL,
    customer_ID_customer CHAR(6) NOT NULL
);
ALTER TABLE membership
ADD CONSTRAINT membership_PK PRIMARY KEY (id_membership);

ALTER TABLE membership
ADD CONSTRAINT customer_membership_FK FOREIGN KEY (customer_ID_customer) REFERENCES customer(ID_customer)
ON UPDATE CASCADE ON DELETE RESTRICT;

ALTER TABLE transaksi DROP CONSTRAINT Transaksi_Customer_FK;
ALTER TABLE transaksi
ADD CONSTRAINT Transaksi_Customer_FK FOREIGN KEY (Customer_ID_customer) REFERENCES Customer(ID_customer)
ON UPDATE CASCADE
ON DELETE CASCADE;

ALTER TABLE membership
ALTER COLUMN tanggal_pembuatan_kartu_membership SET DEFAULT CURRENT_DATE;

ALTER TABLE membership
ADD CHECK (total_poin >= 0);

ALTER TABLE membership
MODIFY alamat_customer VARCHAR(150) NOT NULL;

-- Soal 3 --
DROP TABLE Telepon;

ALTER TABLE Pegawai
ADD No_telp_pegawai VARCHAR(15);

-- Soal 4 --
-- Tabel Customer
INSERT INTO Customer(ID_customer, Nama_customer)
VALUES
  ('CTR001', 'Budi Santoso'),
  ('CTR002', 'Sisil Triana'),
  ('CTR003', 'Davi Liam'),
  ('CTRo04', 'Sutris Ten An'),
  ('CTR005', 'Hendra Asto');

-- Tabel Membership
INSERT INTO Membership(id_membership, no_telepon_customer, alamat_customer, tanggal_pembuatan_kartu_membership, tanggal_kedaluawarsa_kartu_membership, total_poin, Customer_ID_customer)
VALUES
  ('MBR001', '08123456789', 'Jl. Imam Bonjol', '2023-10-24', '2023-11-30', '0', 'CTR001'),
  ('MBR002', '0812345678', 'Jl. Kelinci', '2023-10-24', '2023-11-30', '3', 'CTR002'),
  ('MBR003', '081234567890', 'Jl. Abah Ojak', '2023-10-25', '2023-12-01', '2', 'CTR003'),
  ('MBR004', '08987654321', 'Jl. Kenangan', '2023-10-26', '2023-12-02', '6', 'CTRo04');

-- Tabel Pegawai
INSERT INTO Pegawai(NIK, Nama_pegawai, Jenis_kelamin, Email, Umur, No_telp_pegawai)
  VALUES
  ('1234567890123456', 'Naufal Raf', 'L', 'nuafal@gmail.com', 19, '62123456789'),
  ('2345678901234561', 'Surinala', 'P', 'surinala@gmail.com', 24, '621234567890'),
  ('3456789012345612', 'Ben John', 'L', 'benjohn@gmail.com', 22, '6212345678');

-- Tabel Transaksi
INSERT INTO Transaksi(ID_transaksi, Tanggal_transaksi, Metode_pembayaran, Pegawai_NIK, Customer_ID_customer)
  VALUES
  ('TRX0000001', '2023-10-01', 'Kartu kredit', '2345678901234561', 'CTR002'),
  ('TRX0000002', '2023-10-03', 'Transfer bank', '3456789012345612', 'CTRo04'),
  ('TRX0000003', '2023-10-05', 'Tunai', '3456789012345612', 'CTR001'),
  ('TRX0000004', '2023-10-15', 'Kartu debit', '1234567890123456', 'CTR003'),
  ('TRX0000005', '2023-10-15', 'E-wallet', '1234567890123456', 'CTRo04'),
  ('TRX0000006', '2023-10-21', 'Tunai', '2345678901234561', 'CTR001');

-- Tabel Menu
INSERT INTO Menu_minuman(ID_minuman, Nama_minuman, Harga_minuman)
  VALUES
  ('MNM001', 'Expresso', 18000),
  ('MNM002', 'Cappuccino', 20000),
  ('MNM003', 'Latte', 21000),
  ('MNM004', 'Americano', 19000),
  ('MNM005', 'Mocha', 22000),
  ('MNM006', 'Macchiato', 23000),
  ('MNM007', 'Cold Brew', 21000),
  ('MNM008', 'Iced Coffee', 18000),
  ('MNM009', 'Affogato', 23000),
  ('MNM010', 'Coffee Frappe', 22000);


-- Tabel Transaksi_Menu
INSERT INTO Transaksi_minuman(TM_Menu_minuman_ID, TM_Transaksi_ID, Jumlah_cup)
VALUES
('MNM006', 'TRX0000005', 2),
('MNM010', 'TRX0000001', 1),
('MNM005', 'TRX0000002', 1),
('MNM009', 'TRX0000005', 1),
('MNM001', 'TRX0000003', 3),
('MNM003', 'TRX0000006', 2),
('MNM004', 'TRX0000004', 2),
('MNM010', 'TRX0000004', 1),
('MNM003', 'TRX0000002', 2),
('MNM007', 'TRX0000001', 1),
('MNM001', 'TRX0000005', 1),
('MNM003', 'TRX0000003', 1);

-- Soal 5 --
INSERT INTO Transaksi(ID_transaksi, Tanggal_transaksi, Metode_pembayaran, Pegawai_NIK, Customer_ID_customer)
  VALUES
  ('TRX0000007', '2023-10-03', 'Transfer bank', '2345678901234561', 'CTRo04');

INSERT INTO Transaksi_minuman(TM_Menu_minuman_ID, TM_Transaksi_ID, Jumlah_cup)
VALUES
('MNM005', 'TRX0000007', 1);

-- Soal 6 --
INSERT INTO Pegawai(NIK, Nama_pegawai, Jenis_kelamin, Email, Umur, No_telp_pegawai)
  VALUES
  ('1111222233334444', 'Maimunah', NULL, NULL, 25, NULL);

UPDATE customer
SET ID_customer = 'CTR004'
WHERE ID_customer = 'CTRo04';

UPDATE pegawai
SET Jenis_kelamin = 'P',
    No_telp_pegawai = '234234234',
    Email = 'maimunah@gmail.com'

UPDATE membership
SET total_poin = 0
WHERE MONTH(tanggal_kedaluawarsa_kartu_membership) < 12

DELETE FROM membership;
-- OR
TRUNCATE TABLE membership;

DELETE FROM pegawai
WHERE Nama_pegawai = 'Maimunah';

