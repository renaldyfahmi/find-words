#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool findword(vector<vector<char>>& matriks, string kata) {
    int baris = matriks.size();
    int kolom = matriks[0].size();

for (int i = 0; i < baris; ++i) {
    for (int j = 0; j <= kolom - kata.length(); ++j) {
        bool ditemukan = true;
        for (int k = 0; k < kata.length(); ++k) {
            if (matriks[i][j + k] != kata[k]) {
                ditemukan = false;
                break;
            }
        }
        if (ditemukan) return true;
    }
}

for (int i = 0; i < baris; ++i) {
    for (int j = kolom - 1; j >= kata.length() - 1; --j) {
        bool ditemukan = true;
        for (int k = 0; k < kata.length(); ++k) {
            if (matriks[i][j - k] != kata[k]) {
                ditemukan = false;
                break;
            }
        }
        if (ditemukan) return true;
    }
}

    for (int i = 0; i <= baris - kata.length(); ++i) {
        for (int j = 0; j < kolom; ++j) {
            bool ditemukan = true;
            for (int k = 0; k < kata.length(); ++k) {
                if (matriks[i + k][j] != kata[k]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) return true;
        }
    }
    
	for (int i = baris - 1; i >= kata.length() - 1; --i) {
	    for (int j = 0; j < kolom; ++j) {
	        bool ditemukan = true;
	        for (int k = 0; k < kata.length(); ++k) {
	            if (matriks[i - k][j] != kata[k]) {
	                ditemukan = false;
	                break;
	            }
	        }
	        if (ditemukan) return true;
	    }
	}


    // Periksa secara diagonal (atas-kiri ke bawah-kanan)
    for (int i = 0; i <= baris - kata.length(); ++i) {
        for (int j = 0; j <= kolom - kata.length(); ++j) {
            bool ditemukan = true;
            for (int k = 0; k < kata.length(); ++k) {
                if (matriks[i + k][j + k] != kata[k]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) return true;
        }
    }
    
    // Periksa secara diagonal (bawah-kanan ke atas-kiri)
	for (int i = baris - 1; i >= kata.length() - 1; --i) {
	    for (int j = kolom - 1; j >= kata.length() - 1; --j) {
	        bool ditemukan = true;
	        for (int k = 0; k < kata.length(); ++k) {
	            if (matriks[i - k][j - k] != kata[k]) {
	                ditemukan = false;
	                break;
	            }
	        }
	        if (ditemukan) return true;
	    }
	}


    // Periksa secara diagonal (atas-kanan ke bawah-kiri)
    for (int i = 0; i <= baris - kata.length(); ++i) {
        for (int j = kata.length() - 1; j < kolom; ++j) {
            bool ditemukan = true;
            for (int k = 0; k < kata.length(); ++k) {
                if (matriks[i + k][j - k] != kata[k]) {
                    ditemukan = false;
                    break;
                }
            }
            if (ditemukan) return true;
        }
    }
    
    // Periksa secara diagonal (bawah-kiri ke atas-kanan)
for (int i = kata.length() - 1; i < baris; ++i) {
    for (int j = 0; j <= kolom - kata.length(); ++j) {
        bool ditemukan = true;
        for (int k = 0; k < kata.length(); ++k) {
            if (matriks[i - k][j + k] != kata[k]) {
                ditemukan = false;
                break;
            }
        }
        if (ditemukan) return true;
    }
}


    return false;
}

