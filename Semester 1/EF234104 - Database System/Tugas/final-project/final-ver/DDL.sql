-- Muhammad Nabil Afrizal Rahmadani 5025231014
CREATE TABLE pengunjung (
    id_pengunjung char(6) NOT NULL PRIMARY KEY,
    nama varchar(64) NOT NULL,
);

-- Muhammad Nabil Afrizal Rahmadani 5025231014
CREATE TABLE waktu_berkunjung (
    waktu datetime NOT NULL PRIMARY KEY,
    id_pengunjung char(6) NOT NULL,
    FOREIGN KEY (id_pengunjung)
    REFERENCES pengunjung(id_pengunjung)
);

-- Muhammad Nabil Afrizal Rahmadani 5025231014
CREATE TABLE keanggotaan (
    id_anggota char(4) NOT NULL PRIMARY KEY,
    nrp char(10),
    email varchar(256) NOT NULL,
    jurusan varchar(64),
    tanggal_lahir date NOT NULL,
    jenis_kelamin char(1) NOT NULL,
    id_pengunjung char(6) NOT NULL,
    FOREIGN KEY (id_pengunjung)
    REFERENCES pengunjung(id_pengunjung)
);

-- Muhammad Ryan Fikri Nugraha 5025231013
CREATE TABLE pegawai (
    id_pegawai char(6) NOT NULL PRIMARY KEY,
    nama_pegawai varchar(64) NOT NULL,
    tanggal_lahir date NOT NULL,
    email_pegawai varchar(256) NOT NULL,
    no_telp char(12) NOT NULL,
    jabatan varchar(100) NOT NULL
);

-- Randi Palguna Artayasa 5025231020
CREATE TABLE transaksi_buku (
    id_transaksi_buku char(5) NOT NULL PRIMARY KEY,
    waktu_transaksi_peminjaman datetime NOT NULL,
    waktu_transaksi_pengembalian datetime NOT NULL,
    status_transaksi varchar(30) NOT NULL,
    denda decimal(10, 2),
    id_anggota char(4) NOT NULL,
    id_pegawai char(6) NOT NULL,
    FOREIGN KEY (id_anggota)
    REFERENCES keanggotaan(id_anggota),
    FOREIGN KEY (id_pegawai)
    REFERENCES pegawai(id_pegawai)
);

-- Randi Palguna Artayasa 5025231020
CREATE TABLE koleksi_buku (
    id_koleksi_buku char(3) NOT NULL PRIMARY KEY,
    koleksi_buku varchar(20) NOT NULL
);

-- Muhammad Ryan Fikri Nugraha 5025231013
CREATE TABLE buku (
    id_buku char(5) NOT NULL PRIMARY KEY,
    judul_buku varchar(256) NOT NULL,
    subjek varchar(256),
    penerbit varchar(64),
    penulis varchar(256),
    tahun_terbit int,
    sinopsis varchar(512),
    tanggal_entry date NOT NULL,
    status_buku varchar(30) NOT NULL,
    status_peminjaman varchar(30) NOT NULL,
    id_koleksi_buku char(3) NOT NULL,
    FOREIGN KEY (id_koleksi_buku)
    REFERENCES koleksi_buku(id_koleksi_buku)
);

-- I Gusti Ngurah Arya Sudewa 5025231030
CREATE TABLE buku_transaksi_buku (
    id_transaksi_buku char(5) NOT NULL,
    id_buku char(5) NOT NULL,
    PRIMARY KEY (id_transaksi_buku, id_buku),
    FOREIGN KEY (id_transaksi_buku)
    REFERENCES transaksi_buku(id_transaksi_buku),
    FOREIGN KEY (id_buku)
    REFERENCES buku(id_buku)
);

-- Muhammad Ryan Fikri Nugraha 5025231013
CREATE TABLE ruangan (
    id_ruangan char(4) NOT NULL PRIMARY KEY,
    nama_ruangan varchar(64) NOT NULL,
    lokasi varchar(64) NOT NULL,
    deskripsi_fasilitas varchar(1000) NOT NULL
);

-- I Gusti Ngurah Arya Sudewa 5025231030
CREATE TABLE transaksi_ruangan (
    id_transaksi_ruangan char(5) NOT NULL PRIMARY KEY,
    waktu_transaksi datetime NOT NULL,
    denda decimal(10, 2),
    id_anggota char(4) NOT NULL,
    id_pegawai char(6) NOT NULL,
    id_ruangan char(4) NOT NULL,
    FOREIGN KEY (id_anggota)
    REFERENCES keanggotaan(id_anggota),
    FOREIGN KEY (id_pegawai)
    REFERENCES pegawai(id_pegawai),
    FOREIGN KEY (id_ruangan)
    REFERENCES ruangan(id_ruangan)
);