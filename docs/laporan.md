# LAPORAN PROYEK

## Judul

Parallel Matrix Multiplication Using OpenMP

## Tujuan

Membandingkan performa perkalian matriks menggunakan metode sequential dan parallel dengan OpenMP.

## Dasar Teori

OpenMP merupakan API untuk parallel programming pada CPU multicore yang memungkinkan pembagian pekerjaan ke beberapa thread sehingga waktu komputasi dapat dipercepat.

## Metode

Program membuat dua buah matriks berukuran 500 x 500.

Pengujian dilakukan dengan dua metode:

1. Sequential Matrix Multiplication
2. Parallel Matrix Multiplication menggunakan OpenMP

## Implementasi OpenMP

Directive yang digunakan:

#pragma omp parallel for collapse(2)

Directive tersebut membagi proses perkalian matriks ke beberapa thread CPU.

## Hasil Pengujian

Contoh:

Sequential Time = 1.82 sec

Parallel Time = 0.54 sec

Speedup = 3.37x

## Analisis

Berdasarkan hasil pengujian, metode parallel menghasilkan waktu eksekusi yang lebih cepat dibandingkan metode sequential.

Hal ini terjadi karena OpenMP membagi pekerjaan ke beberapa core CPU.

Speedup tidak selalu linear karena adanya overhead thread management dan bottleneck memori.

## Kelebihan

- Performa lebih cepat
- Memanfaatkan CPU multicore
- Implementasi sederhana

## Kekurangan

- Membutuhkan CPU multicore
- Ada overhead sinkronisasi thread

## Kesimpulan

OpenMP mampu meningkatkan performa perkalian matriks dibandingkan metode sequential dengan menghasilkan waktu eksekusi yang lebih singkat.