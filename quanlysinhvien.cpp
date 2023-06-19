#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char id [50];
    char name [100];
    int tuoi;
    float diemTB;
}SinhVien;

typedef struct Node
{
    SinhVien sv;
    struct Node* next;
}Node;

//hàm tạo một Node mới vs thông tin sv
Node* createNode(SinhVien sv) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sv = sv;
    newNode->next = NULL;
    return newNode;
}

//hàm thêm một sv mới vào danh sách liên kết
Node* addStudent(Node* pHead, SinhVien sv) 
{
    Node* newNode = createNode(sv);
    if (pHead == NULL) 
    {
        pHead = newNode;
    } 
    else 
    {
        Node* Root = pHead;
        while (Root->next != NULL) 
        {
            Root = Root->next;
        }
        Root->next = newNode;
    }
    printf("Sinh vien da duoc them vao danh sach.\n");
    return pHead;
}

//hàm xóa và tìm kiếm sv
Node* deleteStudent(Node* pHead, char id[50]) 
{
    Node* Root = pHead;
    Node* prevNode = NULL;

    if (Root != NULL && strcmp(Root->sv.id, id) == 0) 
    {
        pHead = Root->next;
        free(Root);
        printf("Sinh vien da bi xoa khoi danh sach.\n");
        return pHead;
    }
    while (Root != NULL && strcmp(Root->sv.id, id) != 0) 
    {
        prevNode = Root;
        Root = Root->next;
    }

    if (Root == NULL) 
    {
        printf("Khong tim thay sinh vien voi ma so %s.\n", id);
        return pHead;
    }

    prevNode->next = Root->next;
    free(Root);
    printf("Sinh vien da bi xoa khoi danh sach.\n");
    return pHead;
}

//hàm tìm sv dựa trên mã số sv và cập nhật lại tt
void updateStudent(Node* pHead, char id [50]) 
{
    Node* Root = pHead;
    while (Root != NULL) 
    {
        if (strcmp(Root->sv.id, id) == 0) 
        {
            printf("Nhap ho ten moi: ");
            fgets(Root->sv.name, sizeof(Root->sv.name), stdin);
            printf("Nhap tuoi moi: ");
            scanf("%d", &(Root->sv.tuoi));
            printf("Nhap diem trung binh moi: ");
            scanf("%f", &(Root->sv.diemTB));
            printf("Thong tin sinh vien da duoc cap nhat.\n");
            return;
        }
        Root = Root->next;
    }
    printf("Khong tim thay sinh vien voi ma so %s.\n",id);
}

//hàm hiển thị ds sv
void displayStudents(Node* pHead) 
{
    if (pHead == NULL)
    {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    printf("Danh sach sinh vien:\n");
    Node* Root = pHead;
    while (Root != NULL) 
    {
        printf("Ma so: %s\n", Root->sv.id);
        printf("Ho ten: %s", Root->sv.name);
        printf("Tuoi: %d\n", Root->sv.tuoi);
        printf("Diem trung binh: %.2f\n", Root->sv.diemTB);
        printf("----------------------\n");
        Root = Root->next;
    }
}

//hàm chèn một Node vào sortStudents 
Node* insertNode(Node* sortedList, Node* newNode) 
{
    if (sortedList == NULL || strcmp(newNode->sv.id, sortedList->sv.id) < 0) 
    {
        newNode->next = sortedList;
        sortedList = newNode;
    } 
	else
	{
        Node* Root = sortedList;
        while (Root->next != NULL && strcmp(newNode->sv.id, Root->next->sv.id) >= 0) 
        {
            Root = Root->next;
        }
        newNode->next = Root->next;
        Root->next = newNode;
    }
    return sortedList;
}   

//hàm săp xếp sv theo thứ tự tăng dần
Node* sortStudents(Node* pHead) 
{
    if (pHead == NULL || pHead->next == NULL) 
    {
        return pHead;
    }
    Node* Root = pHead;
    Node* sortedList = NULL;
    while (Root != NULL) 
    {
        Node* nextNode = Root->next;
        sortedList = insertNode(sortedList, Root);
        Root = nextNode;
    }

    return sortedList;
} 
    
//hàm lưu ds sv vào file
void saveStudentsToFile(Node* pHead, char fileName[50]) 
{
    FILE* file = fopen(fileName, "w");
    if (file == NULL) 
    {
        printf("Khong the mo file %s.\n", fileName);
        return;
    }

    Node* Root = pHead;
    while (Root != NULL) 
    {
        fprintf(file, "%s\n", Root->sv.id);
        fprintf(file, "%s", Root->sv.name);
        fprintf(file, "%d\n", Root->sv.tuoi);
        fprintf(file, "%.2f\n", Root->sv.diemTB);
        Root = Root->next;
    }
    fclose(file);
    printf("Danh sach sinh vien da duoc luu vao file %s.\n", fileName);
}

void freeStudents(Node* pHead) 
{
    Node* Root = pHead;
    while (Root != NULL) 
    {
        Node* temp = Root;
        Root = Root->next;
        free(temp);
    }
}


int main() {
    Node* pHead = NULL;
    int luachon;
    char fileName[50];
    char id[10];
    SinhVien sv;

    do {
        printf("=========== QUAN LY SINH VIEN ===========\n");
        printf("1. Them sinh vien moi\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Luu danh sach sinh vien vao file\n");
        printf("6. Sap xep sinh vien theo ma so sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("=========================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luachon);
        getchar(); // Xóa ký tự '\n' thừa sau khi nhập lựa chọn

        switch (luachon) {
            case 1:
                printf("Nhap ma so sinh vien: ");
                fgets(sv.id, sizeof(sv.id), stdin);
                printf("Nhap ho ten: ");
                fgets(sv.name, sizeof(sv.name), stdin);
                printf("Nhap tuoi: ");
                scanf("%d", &sv.tuoi);
                printf("Nhap diem trung binh: ");
                scanf("%f", &sv.diemTB);
                pHead = addStudent(pHead, sv);
                break;
            case 2:
                printf("Nhap ma so sinh vien can xoa: ");
                fgets(id, sizeof(id), stdin);
                pHead = deleteStudent(pHead, id);
                break;
            case 3:
                printf("Nhap ma so sinh vien can sua: ");
                fgets(id, sizeof(id), stdin);
                updateStudent(pHead, id);
                break;
            case 4:
                displayStudents(pHead);
                break;
            case 5:
                printf("Nhap ten file: ");
                fgets(fileName, sizeof(fileName), stdin);
                saveStudentsToFile(pHead, fileName);
                break;
            case 6:
                pHead = sortStudents(pHead);
                printf("Danh sach sinh vien da duoc sap xep.\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
        printf("\n");
    } while (luachon != 0);

    // Giải phóng danh sách liên kết trước khi thoát
    Node* Root = pHead;
    while (Root != NULL) 
    {
        Node* temp = Root;
        Root = Root->next;
        free(temp);
    }

    return 0;
}
