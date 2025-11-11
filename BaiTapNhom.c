#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char maSinhVien[10];
    char hoTen[50];
    char gioiTinh[5];
    char soDienThoai[15];
};

int xoaSinhVien(struct SinhVien ds[], int n) {
    char ma[10];
    int found = 0;

    printf("Nhap ma sinh vien can xoa: ");
    scanf("%s", ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSinhVien, ma) == 0) {
            found = 1;
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            printf("Da xoa sinh vien co ma %s thanh cong!\n", ma);
            return n - 1; 
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ma %s!\n", ma);
    }
    return n;
}
void chinhSuaSinhVien(struct SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach trong! Vui long nhap sinh vien truoc.\n");
        return;
    }

    char ma[10];
    int found = 0;

    printf("Nhap ma sinh vien can chinh sua: ");
    scanf("%s", ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSinhVien, ma) == 0) {
            found = 1;
            printf("\n--- Thong tin hien tai ---\n");
            printf("Ma SV: %s\nHo ten: %s\nGioi tinh: %s\nSo dien thoai: %s\n",
                   ds[i].maSinhVien, ds[i].hoTen, ds[i].gioiTinh, ds[i].soDienThoai);

            printf("\n--- Nhap thong tin moi ---\n");
            printf("Nhap ho ten moi: ");
            scanf(" %[^\n]", ds[i].hoTen);
            printf("Nhap gioi tinh moi: ");
            scanf("%s", ds[i].gioiTinh);
            printf("Nhap so dien thoai moi: ");
            scanf("%s", ds[i].soDienThoai);

            printf("Da cap nhat thong tin sinh vien thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ma %s!\n", ma);
    }
}

void hienThiDanhSach(struct SinhVien ds[], int n) {
    printf("\n--- DANH SACH SINH VIEN ---\n");
    for(int i = 0; i < n; i++) {
        printf("SV %d: %s - %s - %s - %s\n", 
               i + 1, ds[i].maSinhVien, ds[i].hoTen, 
               ds[i].gioiTinh, ds[i].soDienThoai);
    }
    printf("---------------------------\n");
}

void nhapDanhSach(struct SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap ma sinh vien: ");
        scanf("%s", ds[i].maSinhVien);
        printf("Nhap ho ten sinh vien: ");
        scanf(" %[^\n]", ds[i].hoTen); 
        printf("Nhap gioi tinh sinh vien: ");
        scanf("%s", ds[i].gioiTinh);
        printf("Nhap so dien thoai sinh vien: ");
        scanf("%s", ds[i].soDienThoai);
        printf("\n");
    }
}

int themSinhVien(struct SinhVien ds[], int n, int index) {
    if (index < 0 || index > n) {
        printf("Vi tri khong hop le!\n");
        return n;
    }
    
    for(int i = n; i > index; i--) {
        ds[i] = ds[i-1];
    }
    
    printf("Nhap thong tin sinh vien moi:\n");
    printf("Nhap ma sinh vien: ");
    scanf("%s", ds[index].maSinhVien);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]", ds[index].hoTen);
    printf("Nhap gioi tinh sinh vien: ");
    scanf("%s", ds[index].gioiTinh);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", ds[index].soDienThoai);
    return n + 1;
}
void timKiemSinhVien(struct SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach sinh vien trong! Vui long nhap danh sach truoc.\n");
        return;
    }
    
    char ten[50];
    int found = 0;

    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", ten);

    printf("\n=== KET QUA TIM KIEM ===\n");
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].hoTen, ten) != NULL) {
            printf("Ma SV: %s | Ho ten: %s | Gioi tinh: %s | So DT: %s\n",
                   ds[i].maSinhVien, ds[i].hoTen, ds[i].gioiTinh, ds[i].soDienThoai);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ten chua: %s\n", ten);
    }
    printf("========================\n");
}
int main() {
    char confirm = 'Y';
    int n, choice, index;
    struct SinhVien danhSach[100]; 
    
    
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    if (n > 0) {
        nhapDanhSach(danhSach, n);
    }
    do {
        printf("\n|-----------------------MENU-----------------------|\n");
        printf("|1. Hien thi danh sach sinh vien theo bang         |\n");
        printf("|2. Them moi mot sinh vien vao                     |\n");        
        printf("|3. Chinh sua thong tin sinh vien                  |\n");
        printf("|4. Xoa 1 sinh vien                                |\n");
        printf("|5. Tim kiem sinh vien theo ten hoac ma            |\n");
        printf("|6. Thoat                                          |\n");  
        printf("|--------------------------------------------------|\n");   

        printf("Nhap lua chon: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                hienThiDanhSach(danhSach, n);
                break;
            case 2:
                printf("Nhap vi tri muon them (0-%d): ", n);
                scanf("%d", &index);
                n = themSinhVien(danhSach, n, index);
                break;
            case 3:
                chinhSuaSinhVien(danhSach, n);
                break;
            case 4:
                n = xoaSinhVien(danhSach, n);
                hienThiDanhSach(danhSach, n);
                break;
            case 5:
                timKiemSinhVien(danhSach, n);
                break;
            case 6:
                printf("Thoat chuong trinh!\n");
                exit(0);
            default:
                printf("\nLua chon khong hop le! Vui long nhap lai.\n");
        }
        printf("Ban co muon tiep tuc khong (Y/N)? ");
        scanf(" %c", &confirm);
        
	    if (confirm == 'N' || confirm == 'n') {
	        printf("Thoat chuong trinh!\n");
	        break;
	    }
	    
    } while (1);

    return 0;
}
