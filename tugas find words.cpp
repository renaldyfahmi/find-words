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

int main() {
    int jumlah_kata;
    cin >> jumlah_kata;

    vector<string> kata_kunci(jumlah_kata);
    for (int i = 0; i < jumlah_kata; ++i) {
        cin >> kata_kunci[i];
    }

    vector<vector<char>> matriks = {
        {'A', 'A', 'F', 'L', 'K', 'H', 'P', 'F', 'S', 'S', 'U', 'F', 'I', 'C', 'I', 'C', 'L', 'E', 'S', 'G', 'N', 'N', 'H'},
        {'S', 'F', 'V', 'R', 'E', 'O', 'M', 'R', 'W', 'L', 'R', 'T', 'T', 'S', 'X', 'O', 'Q', 'Q', 'N', 'A', 'O', 'A', 'O'},
        {'Q', 'E', 'I', 'A', 'I', 'F', 'X', 'A', 'E', 'I', 'R', 'F', 'V', 'F', 'Y', 'S', 'X', 'I', 'M', 'I', 'N', 'J', 'I'},
        {'W', 'S', 'T', 'R', 'L', 'G', 'O', 'C', 'A', 'P', 'B', 'I', 'A', 'F', 'I', 'W', 'I', 'W', 'T', 'U', 'A', 'C', 'M'},
        {'F', 'E', 'Y', 'A', 'E', 'A', 'I', 'S', 'T', 'P', 'C', 'R', 'L', 'U', 'J', 'K', 'O', 'A', 'K', 'C', 'E', 'R', 'S'},
        {'R', 'V', 'D', 'A', 'K', 'P', 'N', 'D', 'E', 'E', 'H', 'D', 'E', 'M', 'S', 'N', 'C', 'K', 'K', 'F', 'O', 'A', 'H'},
        {'M', 'R', 'N', 'E', 'D', 'S', 'L', 'C', 'R', 'R', 'I', 'W', 'N', 'R', 'S', 'A', 'A', 'F', 'I', 'T', 'M', 'M', 'I'},
        {'Y', 'A', 'A', 'E', 'C', 'I', 'E', 'A', 'H', 'Y', 'M', 'O', 'T', 'A', 'V', 'H', 'R', 'S', 'S', 'T', 'I', 'S', 'B'},
        {'R', 'J', 'S', 'E', 'W', 'E', 'L', 'C', 'C', 'E', 'N', 'N', 'I', 'E', 'T', 'O', 'H', 'W', 'S', 'G', 'L', 'S', 'E'},
        {'A', 'T', 'A', 'N', 'Y', 'Y', 'M', 'O', 'I', 'E', 'E', 'S', 'N', 'E', 'S', 'I', 'O', 'I', 'R', 'E', 'L', 'T', 'R'},
        {'U', 'T', 'E', 'N', 'E', 'W', 'E', 'B', 'H', 'M', 'Y', 'B', 'E', 'T', 'N', 'N', 'R', 'A', 'I', 'E', 'B', 'E', 'N'},
        {'R', 'C', 'L', 'K', 'U', 'T', 'E', 'A', 'E', 'Q', 'J', 'L', 'S', 'G', 'S', 'H', 'T', 'G', 'D', 'S', 'K', 'O', 'A'},
        {'B', 'H', 'O', 'I', 'C', 'A', 'T', 'N', 'R', 'R', 'S', 'D', 'D', 'E', 'C', 'E', 'H', 'O', 'O', 'L', 'G', 'I', 'T'},
        {'E', 'N', 'S', 'L', 'U', 'A', 'R', 'I', 'R', 'S', 'E', 'T', 'A', 'L', 'O', 'C', 'O', 'H', 'C', 'T', 'O', 'H', 'E'},
        {'F', 'Z', 'F', 'U', 'D', 'Q', 'J', 'Y', 'M', 'A', 'D', 'O', 'Y', 'I', 'W', 'Y', 'G', 'L', 'O', 'V', 'E', 'S', 'U'},
        {'T', 'E', 'K', 'A', 'L', 'F', 'W', 'O', 'N', 'S', 'N', 'A', 'E', 'B', 'M', 'I', 'E', 'J', 'T', 'Z', 'N', 'T', 'G'},
        {'E', 'S', 'W', 'P', 'O', 'S', 'J', 'X', 'E', 'U', 'T', 'U', 'Y', 'O', 'Z', 'U', 'W', 'A', 'K', 'E', 'Z', 'H', 'M'},
        {'K', 'Z', 'U', 'H', 'B', 'P', 'E', 'Z', 'E', 'E', 'R', 'F', 'L', 'M', 'S', 'N', 'O', 'W', 'B', 'A', 'L', 'L', 'H'},
        {'N', 'S', 'N', 'O', 'W', 'B', 'O', 'A', 'R', 'D', 'Y', 'T', 'V', 'W', 'Y', 'C', 'L', 'E', 'V', 'O', 'H', 'S', 'A'},
        {'A', 'C', 'O', 'C', 'R', 'Q', 'L', 'G', 'Z', 'I', 'Y', 'C', 'H', 'O', 'D', 'R', 'A', 'Z', 'Z', 'I', 'L', 'B', 'I'},
        {'L', 'B', 'V', 'K', 'K', 'W', 'A', 'N', 'Z', 'A', 'A', 'Q', 'I', 'N', 'W', 'O', 'L', 'P', 'W', 'O', 'N', 'S', 'L'},
        {'B', 'F', 'R', 'E', 'E', 'Z', 'I', 'N', 'G', 'R', 'A', 'I', 'N', 'S', 'L', 'I', 'L', 'G', 'T', 'M', 'E', 'L', 'T'},
        {'H', 'Q', 'P', 'Y', 'L', 'W', 'H', 'E', 'M', 'N', 'E', 'F', 'U', 'F', 'P', 'S', 'W', 'X', 'N', 'U', 'M', 'M', 'V'}
    };

    for (const string& kata : kata_kunci) {
        if (findword(matriks, kata)) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}


    return false;
}

