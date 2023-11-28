//
//  main.cpp
//  Searching
//
//  Created by Muhammad Askar Habibulloh on 22/11/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // Nama file yang ingin dibaca
    std::string namaFile;
    std::cout << "Masukkan nama file (.txt): ";
    std::getline(std::cin, namaFile);

    // Membuka file
    std::ifstream file(namaFile);

    // Memeriksa apakah file berhasil dibuka
    if (file.is_open()) {
        // Membaca isi file ke dalam satu string
        std::string kalimat((std::istreambuf_iterator<char>(file)),
                             std::istreambuf_iterator<char>());

        // Input kata kunci yang akan dicari
        std::cout << "Masukkan kata kunci (pisahkan dengan spasi): ";
        std::string inputKataKunci;
        std::getline(std::cin, inputKataKunci);

        // Menggunakan vector untuk menyimpan setiap kata kunci
        std::vector<std::string> kataKunci;
        size_t posAwal = 0;
        size_t posSpasi = inputKataKunci.find(' ');

        while (posSpasi != std::string::npos) {
            kataKunci.push_back(inputKataKunci.substr(posAwal, posSpasi - posAwal));
            posAwal = posSpasi + 1;
            posSpasi = inputKataKunci.find(' ', posAwal);
        }

        // Menambahkan kata kunci terakhir setelah loop
        kataKunci.push_back(inputKataKunci.substr(posAwal));

        // Melakukan pencarian untuk setiap kata kunci
        for (const auto &kunci : kataKunci) {
            size_t pos = kalimat.find(kunci);

            // Memeriksa apakah kata kunci ditemukan atau tidak
            if (pos != std::string::npos) {
                std::cout << "Kata kunci \"" << kunci << "\" ditemukan pada posisi " << pos << std::endl;
            } else {
                std::cout << "Kata kunci \"" << kunci << "\" tidak ditemukan dalam file." << std::endl;
            }
        }
    } else {
        std::cerr << "Gagal membuka file." << std::endl;
    }

    return 0;
}
