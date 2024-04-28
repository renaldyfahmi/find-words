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

