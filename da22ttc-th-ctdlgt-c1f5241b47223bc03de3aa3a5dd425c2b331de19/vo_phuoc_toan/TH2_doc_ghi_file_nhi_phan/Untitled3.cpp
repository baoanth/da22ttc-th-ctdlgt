#include <stdio.h>
#include <string.h>

typedef struct HangHoa {
    char mh[6];
    int sl;
    float dg;
    float st;
} HangHoa;

int main() {
    FILE *file;
    HangHoa hh;
    char ma[6];
    char tenHang[100];

    // M? file DMHH.Dat d? d?c danh s�ch m� h�ng
    file = fopen("DMHH.Dat", "r");
    if (file == NULL) {
        printf("Khong the mo file DMHH.Dat\n");
        return 0;
    }

    printf("Nhap thong tin hang hoa (Nhap ma hang rong de ket thuc):\n");
    do {
        printf("Ma hang: ");
        fgets(ma, sizeof(ma), stdin);
        ma[strcspn(ma, "\n")] = '\0'; // X�a k� t? xu?ng d�ng trong chu?i ma

        // Ki?m tra m� h�ng nh?p v�o c� tr�ng v?i m� h�ng trong t?p tin DMHH.Dat hay kh�ng
        int timThay = 0;
        while (fscanf(file, "%s %[^\n]", hh.mh, tenHang) == 2) {
            if (strcmp(ma, hh.mh) == 0) {
                printf("Ten hang: %s\n", tenHang);
                timThay = 1;
                break;
            }
        }
        rewind(file); // �ua con tr? file v? d?u danh s�ch m� h�ng

        if (timThay) {
            strcpy(hh.mh, ma);

            printf("So luong: ");
            scanf("%d", &hh.sl);
            printf("Don gia: ");
            scanf("%f", &hh.dg);

            hh.st = hh.sl * hh.dg;

            getchar(); // �?c k� t? '\n' b? du trong b? d?m

            // Ghi th�ng tin h�ng h�a v�o t?p tin DSHH.Dat
            file = fopen("DSHH.Dat", "ab");
            if (file != NULL) {
                fwrite(&hh, sizeof(HangHoa), 1, file);
                fclose(file);
                printf("Ghi file DSHH.Dat thanh cong\n");

                // In th�ng tin h�ng h�a v?a nh?p ra m�n h�nh
                printf("%d- Ma hang: %s, ten hang: %s, so luong: %d, don gia: %.2f, so tien: %.2f\n",
                       hh.mh, tenHang, hh.sl, hh.dg, hh.st);
            } else {
                printf("Khong the mo file DSHH.Dat\n");
            }
        } else {
            if (strlen(ma) > 0) {
                printf("Ma hang khong ton tai trong danh sach DMHH.Dat\n");
            }
        }

    } while (strlen(ma) > 0);

    fclose(file);

    return 0;
}

