/*
 * Bubble Sort - Algorithm Analysis Midterm
 * Bu program kabarcık sıralama algoritmasını gösterir.
 * Aynı zamanda farklı veri durumları için performans testi yapar.
 */

#include <stdio.h>   // Standart giriş/çıkış fonksiyonları için gerekli kütüphane
#include <stdlib.h>   // malloc, free, rand gibi fonksiyonlar için gerekli kütüphane
#include <time.h>     // time(), clock() fonksiyonları için gerekli kütüphane

/*
 * bubbleSort fonksiyonu diziyi kabarcık sıralama algoritması ile sıralar.
 * arr: sıralanacak dizi
 * n: dizinin eleman sayısı
 */
void bubbleSort(int arr[], int n) {
    // Dış döngü: dizinin her turunda en büyük eleman en sona yerleşir.
    for (int i = 0; i < n - 1; i++) {
        // swapped değişkeni, bu turda değişim yapılıp yapılmadığını kontrol eder.
        int swapped = 0;

        // İç döngü: komşu elemanları karşılaştırıp gerekli yer değiştirir.
        for (int j = 0; j < n - 1 - i; j++) {
            // Eğer sol eleman sağ elemandan büyükse yerlerini değiştir.
            if (arr[j] > arr[j + 1]) {
                // Geçici değişken ile iki değer yer değiştirir.
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Bu turda en az bir değişim yapıldı.
                swapped = 1;
            }
        }

        // Eğer bu turda hiç değişim olmadıysa dizi zaten sıralıdır; döngüden çık.
        if (!swapped) break; /* Zaten sirali, cik */
    }
}

/*
 * printArray fonksiyonu dizinin elemanlarını ekrana yazdırır.
 * arr: yazdırılacak dizi
 * n: dizinin eleman sayısı
 */
void printArray(int arr[], int n) {
    // Dizi elemanlarını tek tek yazdır.
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Satır sonu ekle.
    printf("\n");
}

/*
 * main fonksiyonu programın çalıştığı ana bölümdür.
 */
int main(void) {
    // Rastgele sayı üretimi için zaman tohumunu başlat.
    srand(time(NULL));

    /* Kucuk demo */
    // Örnek bir dizi oluşturuyoruz.
    int demo[] = {5, 3, 8, 4, 2};
    // Dizinin eleman sayısını tanımlıyoruz.
    int n = 5;

    // Başlık metnini ekrana yazdır.
    printf("=== BUBBLE SORT ===\n\n");
    // Sıralamadan önce diziyi göster.
    printf("Before: ");
    printArray(demo, n);

    // Diziyi bubble sort ile sırala.
    bubbleSort(demo, n);

    // Sıralamadan sonra diziyi göster.
    printf("After:  ");
    printArray(demo, n);

    /* Performans testi */
    // Farklı boyutlardaki veri setleri için test dizisi oluşturuyoruz.
    int sizes[] = {1000, 5000, 10000, 20000};
    // Test edilen boyut sayısını belirtiyoruz.
    int numSizes = 4;

    // Performans testi başlığını yazdır.
    printf("\n--- Performance Test ---\n");
    // Tablo başlıklarını yazdır.
    printf("%-10s %-15s %-15s %-15s\n", "n", "Best(s)", "Worst(s)", "Random(s)");

    // Her veri boyutu için test yap.
    for (int s = 0; s < numSizes; s++) {
        // Mevcut boyutu al.
        int size = sizes[s];
        // Dizinin bellekte yer ayır.
        int *arr = malloc(size * sizeof(int));

        // Başlama ve bitiş zamanlarını tutmak için değişkenler.
        clock_t start, end;

        /* Best: zaten sirali */
        // En iyi durumda dizi zaten sıralı olur.
        for (int i = 0; i < size; i++) arr[i] = i;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        bubbleSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek en iyi durum süresini hesapla.
        double best = (double)(end - start) / CLOCKS_PER_SEC;

        /* Worst: ters sirali */
        // En kötü durumda dizi tam tersi sıralı olur.
        for (int i = 0; i < size; i++) arr[i] = size - i;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        bubbleSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek en kötü durum süresini hesapla.
        double worst = (double)(end - start) / CLOCKS_PER_SEC;

        /* Random */
        // Rastgele elemanlarla dolu veri oluştur.
        for (int i = 0; i < size; i++) arr[i] = rand() % 10000;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        bubbleSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek rastgele durum süresini hesapla.
        double avg = (double)(end - start) / CLOCKS_PER_SEC;

        // Sonuçları tablo halinde yazdır.
        printf("%-10d %-15.4f %-15.4f %-15.4f\n", size, best, worst, avg);

        // Ayrılan belleği serbest bırak.
        free(arr);
    }

    // Program başarıyla bitti, 0 değeri döndür.
    return 0;
}
