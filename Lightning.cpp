#include <stdio.h>
#include <string.h>

struct Gudang {
    char nama[100];
    long long stok; // Pakai long long biar aman
};

int main() {
    FILE *bukak = fopen("testdata.in", "r");
    if (bukak == NULL) return 1;

    int t, n;
    
    // Baca Jumlah Test Case
    fscanf(bukak, "%d", &t);

    for (int tc = 1; tc <= t; tc++) {
        // Baca Jumlah Transaksi per case
        fscanf(bukak, "%d", &n);
        
        struct Gudang barang[105]; // Array untuk simpan data unik
        int totalJenis = 0;        // Penghitung jumlah barang unik
        
        char tipe[10], namaTemp[100];
        int qty;

        // --- PROSES TRANSAKSI ---
        for (int i = 0; i < n; i++) {
            // Format: buy#mie instant#10
            fscanf(bukak, "%[^#]#%[^#]#%d\n", tipe, namaTemp, &qty);
            
            // 1. Cek apakah barang ini sudah ada di daftar?
            int indeksBarang = -1; // -1 artinya belum ketemu
            for (int j = 0; j < totalJenis; j++) {
                if (strcmp(barang[j].nama, namaTemp) == 0) {
                    indeksBarang = j; // Ketemu di indeks j
                    break;
                }
            }

            // 2. Kalau barang BARU (belum ada di daftar)
            if (indeksBarang == -1) {
                strcpy(barang[totalJenis].nama, namaTemp);
                barang[totalJenis].stok = 0; // Set 0 dulu
                indeksBarang = totalJenis;   // Indeksnya adalah urutan terakhir
                totalJenis++;                // Jenis barang nambah 1
            }

            // 3. Update Stok (Buy atau Sell)
            if (strcmp(tipe, "buy") == 0) {
                barang[indeksBarang].stok += qty;
            } else if (strcmp(tipe, "sell") == 0) {
                barang[indeksBarang].stok -= qty;
            }
        }

        // --- PROSES OUTPUT ---
        printf("Case #%d:\n", tc);

        // Cek dulu: Apakah ada yang minus?
        int adaMinus = 0;
        for (int i = 0; i < totalJenis; i++) {
            if (barang[i].stok < 0) {
                adaMinus = 1;
                break;
            }
        }

        if (adaMinus == 1) {
            // SKENARIO JELEK: Cetak HANYA yang minus
            for (int i = 0; i < totalJenis; i++) {
                if (barang[i].stok < 0) {
                    printf("stock is not enough for product %s\n", barang[i].nama);
                }
            }
        } else {
            // SKENARIO BAGUS: Cetak semua
            for (int i = 0; i < totalJenis; i++) {
                printf("%s - %lld\n", barang[i].nama, barang[i].stok);
            }
        }
    }

    fclose(bukak);
    return 0;
}
