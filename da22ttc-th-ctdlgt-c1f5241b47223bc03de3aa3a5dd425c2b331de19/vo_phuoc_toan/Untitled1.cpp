#include <stdio.h>
#include <stdlib.h>

void nhap_va_ghi() {
    char buffer[256];
    printf("Nhap noi dung van ban: ");
    fgets(buffer, sizeof(buffer), stdin);
    FILE *file = fopen("tap_tin_van_ban.txt", "w");
    if (file == NULL) {
        printf("Loi khi mo tap tin.\n");
        return;
    }
    fputs(buffer, file);
    fclose(file);
    printf("Noi dung dã duoc ghi vào tap tin \"tap_tin_van_ban.txt\".\n");
}

void doc_va_in() {
    FILE *file = fopen("tap_tin_van_ban.txt", "r");
    if (file == NULL) {
        printf("Tap tin khong ton tai hoac looi khi mo tap tin.\n");
        return;
    }
    printf("Noi dung caa tap tin \"tap_tin_van_ban.txt\":\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void doc_in_va_noi_them() {
    FILE *file = fopen("tap_tin_van_ban.txt", "r+");
    if (file == NULL) {
        printf("Tap tin không ton tai hoac loi khi mo tap tin.\n");
        return;
    }
    printf("Noi dung cua tap tin \"tap_tin_van_ban.txt\":\n");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\nNhap noi dung moi do noi thêm vào cuoi tap tin:\n");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    fputs(buffer, file);
    fclose(file);
    printf("Ða noi thêm thông tin vào cuoi tap tin \"tap_tin_van_ban.txt\".\n");
}

int main() {
    char lua_chon;
    while (1) {
        printf("Chon chuc nang:\n");
        printf("a. Nhap va ghi van ban vao tap tin\n");
        printf("b. Doc va in noi dung tap tin\n");
        printf("c. Doc in noi dung và noi thêm thông tin\n");
        printf("q. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf(" %c", &lua_chon);
        getchar(); // Xóa b? nh? d?m c?a l?nh scanf

        switch (lua_chon) {
            case 'a':
                nhap_va_ghi();
                break;
            case 'b':
                doc_va_in();
                break;
            case 'c':
                doc_in_va_noi_them();
                break;
            case 'q':
                printf("Chuong trinh ket thuc.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }
    return 0;
}

