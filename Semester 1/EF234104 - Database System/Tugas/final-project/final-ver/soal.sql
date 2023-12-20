-- Buku bisa lebih dari 1 penulis

CREATE TABLE penulis(
    id_penulis CHAR(5) NOT NULL,
    nama_penulis VARCHAR(100) NOT NULL,
    id_buku CHAR(5) NOT NULL,
    FOREIGN KEY id_buku REFERENCES buku(id_buku)
);

ALTER TABLE buku
DROP COLUMN penulis;

-- Perpustakaan menyewakan cd atau koleksi lain
CREATE TABLE cd(
    id_koleksi_cd CHAR(5) NOT NULL PRIMARY KEY,
    judul VARCHAR(100) NOT NULL,
    deskripsi_cd VARCHAR(100) NOT NULL
);

CREATE TABLE transaksi_cd(
    id_transaksi_cd CHAR(5) NOT NULL PRIMARY KEY,
    waktu_transaksi DATETIME NOT NULL,
    denda DECIMAL(10, 2),
    id_anggota CHAR(4) NOT NULL,
    id_pegawai CHAR(4) NOT NULL,
    id_koleksi_cd CHAR(5) NOT NULL,
    FOREIGN KEY (id_anggota) REFERENCES keanggotaan(id_anggota),
    FOREIGN KEY (id_pegawai) REFERENCES pegawai(id_pegawai),
    FOREIGN KEY (id_koleksi_cd) REFERENCES cd(id_koleksi_cd)
);
