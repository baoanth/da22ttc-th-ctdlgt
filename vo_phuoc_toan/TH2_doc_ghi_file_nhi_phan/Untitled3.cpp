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

    // M? file DMHH.Dat d? d?c danh sách mã hàng
    file = fopen("DMHH.Dat", "r");
    if (file == NULL) {
        printf("Khong the mo file DMHH.Dat\n");
        return 0;
    }

    printf("Nhap thong tin hang hoa (Nhap ma hang rong de ket thuc):\n");
    do {
        printf("Ma hang: ");
        fgets(ma, sizeof(ma), stdin);
        ma[strcspn(ma, "\n")] = '\0'; // Xóa kí t? xu?ng dòng trong chu?i ma

        // Ki?m tra mã hàng nh?p vào có trùng v?i mã hàng trong t?p tin DMHH.Dat hay không
        int timThay = 0;
        while (fscanf(file, "%s %[^\n]", hh.mh, tenHang) == 2) {
            if (strcmp(ma, hh.mh) == 0) {
                printf("Ten hang: %s\n", tenHang);
                timThay = 1;
                break;
            }
        }
        rewind(file); // Ðua con tr? file v? d?u danh sách mã hàng

        if (timThay) {
            strcpy(hh.mh, ma);

            printf("So luong: ");
            scanf("%d", &hh.sl);
            printf("Don gia: ");
            scanf("%f", &hh.dg);

            hh.st = hh.sl * hh.dg;

            getchar(); // Ð?c kí t? '\n' b? du trong b? d?m

            // Ghi thông tin hàng hóa vào t?p tin DSHH.Dat
            file = fopen("DSHH.Dat", "ab");
            if (file != NULL) {
                fwrite(&hh, sizeof(HangHoa), 1, file);
                fclose(file);
                printf("Ghi file DSHH.Dat thanh cong\n");

                // In thông tin hàng hóa v?a nh?p ra màn hình
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

