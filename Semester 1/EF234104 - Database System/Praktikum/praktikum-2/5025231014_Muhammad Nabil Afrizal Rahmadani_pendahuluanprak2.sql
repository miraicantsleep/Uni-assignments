-- Nama : Muhammad Nabil Afrizal Rahmadani
-- NRP : 5025231014

CREATE DATABASE kedai_kopi_nuri;
USE kedai_kopi_nuri;

CREATE TABLE Pegawai(
    NIK CHAR(16) NOT NULL PRIMARY KEY,
    Nama_pegawai VARCHAR(100) NOT NULL,
    Jenis_kelamin CHAR(1),
    Email VARCHAR(50),
    Umur INTEGER
);

CREATE TABLE Telepon(
    No_telp_pegawai VARCHAR(15) NOT NULL PRIMARY KEY,
    Pegawai_NIK CHAR(16) NOT NULL,
    FOREIGN KEY (Pegawai_NIK) REFERENCES Pegawai(NIK)
);

CREATE TABLE Customer(
    ID_customer CHAR(6) NOT NULL PRIMARY KEY,
    Nama_customer VARCHAR(100) NOT NULL
);

CREATE TABLE Transaksi(
    ID_transaksi CHAR(10) NOT NULL PRIMARY KEY,
    Tanggal_transaksi DATE NOT NULL,
    Metode_pembayaran VARCHAR(15) NOT NULL,
    Customer_ID_customer CHAR(6) NOT NULL,
    Pegawai_NIK CHAR(16) NOT NULL,
    FOREIGN KEY (Customer_ID_customer) REFERENCES Customer(ID_customer),
    FOREIGN KEY (Pegawai_NIK) REFERENCES 
);