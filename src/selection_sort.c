/*
 * Selection Sort - Algorithm Analysis Midterm
 * Bu program seçim sıralama algoritmasını gösterir.
 * Aynı zamanda farklı veri durumları için performans testi yapar.
 */

#include <stdio.h>   // Standart giriş/çıkış işlemleri için gerekli kütüphane
#include <stdlib.h>   // malloc, free, rand gibi fonksiyonlar için gerekli kütüphane
#include <time.h>     // time(), clock() fonksiyonları için gerekli kütüphane

/*
 * selectionSort fonksiyonu diziyi seçim sıralama algoritması ile sıralar.
 * arr: sıralanacak dizi
 * n: dizinin eleman sayısı
 */
void selectionSort(int arr[], int n) {
    // Dış döngü: her adımda bir minimum eleman bulunur ve başa yerleştirilir.
    for (int i = 0; i < n - 1; i++) {
        // En küçük elemanın indeksini başta i olarak kabul et.
        int minIdx = i;

        // İç döngü: kalan kısımda minimum değeri bul.
        for (int j = i + 1; j < n; j++) {
            // Eğer mevcut eleman, şu anki minimumdan küçükse yeni minimumu güncelle.
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Eğer minimum eleman mevcut konumda değilse yer değiştir.
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
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
    // Rastgele sayı üretebilmek için zaman tohumunu başlat.
    srand(time(NULL));

    /* Kucuk demo */
    // Örnek bir dizi oluştur.
    int demo[] = {64, 25, 12, 22, 11};
    // Dizinin eleman sayısını belirle.
    int n = 5;

    // Başlık bilgisi yazdır.
    printf("=== SELECTION SORT ===\n\n");
    // Sıralamadan önceki diziyi ekrana yazdır.
    printf("Before: ");
    printArray(demo, n);

    // Diziyi seçim sıralama algoritması ile sırala.
    selectionSort(demo, n);

    // Sıralamadan sonraki diziyi ekrana yazdır.
    printf("After:  ");
    printArray(demo, n);

    /* Performans testi */
    // Farklı boyutlarda veri setleri tanımla.
    int sizes[] = {1000, 5000, 10000, 20000};
    // Test edilen veri boyutu sayısını belirt.
    int numSizes = 4;

    // Performans testi başlığını yazdır.
    printf("\n--- Performance Test ---\n");
    // Tablo başlıklarını yazdır.
    printf("%-10s %-15s %-15s %-15s\n", "n", "Best(s)", "Worst(s)", "Random(s)");

    // Her boyut için işlem yap.
    for (int s = 0; s < numSizes; s++) {
        // Mevcut boyut değerini al.
        int size = sizes[s];
        // Dizinin bellekte yer ayır.
        int *arr = malloc(size * sizeof(int));

        // Başlangıç ve bitiş zamanlarını saklamak için değişkenler.
        clock_t start, end;

        /* Best: zaten sirali */
        // En iyi durumda dizi zaten sıralıdır.
        for (int i = 0; i < size; i++) arr[i] = i;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        selectionSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek en iyi durum süresini hesapla.
        double best = (double)(end - start) / CLOCKS_PER_SEC;

        /* Worst: ters sirali */
        // En kötü durumda dizi tam tersi sırada olur.
        for (int i = 0; i < size; i++) arr[i] = size - i;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        selectionSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek en kötü durum süresini hesapla.
        double worst = (double)(end - start) / CLOCKS_PER_SEC;

        /* Random */
        // Rastgele veriler üret.
        for (int i = 0; i < size; i++) arr[i] = rand() % 10000;
        // Zamanı başlat.
        start = clock();
        // Diziyi sırala.
        selectionSort(arr, size);
        // Zamanı durdur.
        end = clock();
        // Saniyeye çevirerek rastgele veri seti süresini hesapla.
        double avg = (double)(end - start) / CLOCKS_PER_SEC;

        // Sonuçları yazdır.
        printf("%-10d %-15.4f %-15.4f %-15.4f\n", size, best, worst, avg);

        // Ayrılan belleği serbest bırak.
        free(arr);
    }

    // Program başarıyla sona erdi; 0 değeri döndür.
    return 0;
}
