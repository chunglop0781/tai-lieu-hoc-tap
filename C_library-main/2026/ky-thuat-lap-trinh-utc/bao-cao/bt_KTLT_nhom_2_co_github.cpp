#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SP 1000
#define FILE_SP "sanpham.txt"
#define FILE_HD "hoadon.txt"

// Cau truc luu thong tin san pham
typedef struct {
    int masp;
    char tensp[50];
    char loai[30];
    char size[20];
    char mausac[20];
    float gianhap;
    float giaban;
    int soluong;
    int daban;
} sanpham;

// Cau truc Node cho danh sach lien ket san pham
typedef struct node {
    sanpham data;
    struct node *next;
} node;

// Cau truc luu thong tin hoa don
typedef struct {
    int mahd;
    int masp;
    char tensp[50];
    int soluong;
    float dongia;
    float thanhtien;
} hoadon;

// Bien toan cuc quan ly Hoa don
hoadon dshoadon[1000];
int sohoadon = 0;
int mahoadontudong = 1;

/* ================= NODE UTILS ================= */
node* taonode(sanpham sp) {
    node *p = (node *)malloc(sizeof(node));
    if (p == NULL) {
        printf("Khong du bo nho!\n");
        return NULL;
    }
    p->data = sp;
    p->next = NULL;
    return p;
}

void themcuoi(node **head, sanpham sp) {
    node *p = taonode(sp);
    if (*head == NULL) {
        *head = p;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

/* ================= HAM TACH CHUOI CHUAN HOA DU LIEU CO KHOANG TRANG ================= */

// Xoa khoang trang dau, cuoi va cac ky tu xuong dong
void chuanHoaChuoi(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\r' || str[len - 1] == '\n')) {
        str[len - 1] = '\0';
        len--;
    }
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }
    if (start > 0) {
        memmove(str, str + start, len - start + 1);
    }
}

// Ham phan tich tung dong thuan bang khoảng trang (Space/Tab) dua tren cau truc du lieu thuc te
int phanTichDongDuLieu(char *line, sanpham *sp) {
    chuanHoaChuoi(line);
    if (strlen(line) == 0) return 0;

    // Lay token dau tien: masp
    char *token = strtok(line, " \t");
    if (!token) return 0;
    sp->masp = atoi(token);

    // Dua tat ca cac tu con lai vao mang words
    char *words[100];
    int w_count = 0;
    while ((token = strtok(NULL, " \t")) != NULL) {
        words[w_count++] = token;
    }

    // File luon phai co toi thieu 7 cot phia sau masp (ten, loai, size, mau, gianhap, giaban, soluong)
    if (w_count < 7) return 0;

    // Kiem tra xem file co cot thu 9 (daban) hay khong
    // Neu tu cuoi cung khong chua dau cham thap phan va w_count == 8 thi do la cot daban
    int has_daban = 0;
    if (w_count == 8 && strchr(words[7], '.') == NULL) {
        has_daban = 1;
    }

    // Gán các biến cố định tính từ cuối dòng lên
    if (has_daban) {
        sp->daban   = atoi(words[7]);
        sp->soluong = atoi(words[6]);
        sp->giaban  = atof(words[5]);
        sp->gianhap = atof(words[4]);
        strcpy(sp->mausac, words[3]);
        strcpy(sp->size,   words[2]);
        
        // Vùng còn lại dành cho tensp và loai là từ words[0] đến words[1]
        // Cot 'loai' luon la tu ngay truoc 'size' (tuc la words[1])
        strcpy(sp->loai, words[1]);
        
        // Tat ca cac tu tu words[0] den truoc 'loai' gop lai thanh tensp
        sp->tensp[0] = '\0';
        for (int i = 0; i < 1; i++) {
            strcat(sp->tensp, words[i]);
        }
    } else {
        // Truong hop file chỉ có 8 cột gốc (chưa có daban) giống file mẫu của bạn
        sp->daban   = 0;
        sp->soluong = atoi(words[w_count - 1]); // words[6] hoac words[7] tùy thuộc so tu cua tensp
        sp->giaban  = atof(words[w_count - 2]);
        sp->gianhap = atof(words[w_count - 3]);
        strcpy(sp->mausac, words[w_count - 4]);
        strcpy(sp->size,   words[w_count - 5]);
        strcpy(sp->loai,   words[w_count - 6]); // Cột loại luôn đứng trước cột size

        // Chỉ số của các từ thuộc về tensp sẽ chạy từ index 0 đến trước cột loai
        int limit_tensp = w_count - 6; 
        sp->tensp[0] = '\0';
        for (int i = 0; i < limit_tensp; i++) {
            strcat(sp->tensp, words[i]);
            if (i < limit_tensp - 1) strcat(sp->tensp, " ");
        }
    }

    return 1;
}

int taiDuLieuGitHub(sanpham ds[]) {
    printf("Dang chay lenh tai file tu GitHub ve thiet bi...\n");
    int check = system("curl -k -s https://raw.githubusercontent.com/chunglop0781/tai-lieu-hoc-tap/refs/heads/main/C_library-main/2026/ky-thuat-lap-trinh-utc/bao-cao/sanpham.txt -o sanpham.txt");
    
    if (check != 0) {
        printf("Loi: Thiet bi khong the chay lenh curl hoac mat ket noi Internet!\n");
        return 0;
    }

    FILE *file = fopen("sanpham.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file sanpham.txt vua tai ve!\n");
        return 0;
    }
    
    char line[512];
    // Doc bo qua dong tieu de dau tien
    fgets(line, sizeof(line), file);
    
    int count = 0;
    while (count < MAX_SP && fgets(line, sizeof(line), file)) {
        sanpham sp;
        if (phanTichDongDuLieu(line, &sp)) {
            ds[count++] = sp;
        }
    }
    
    fclose(file);
    printf("-> Thanh cong! Da nap duoc %d san pham tu GitHub vao bo nho.\n", count);
    return count;
}

void luuFileLocal(sanpham ds[], int count) {
    FILE *f = fopen(FILE_SP, "w");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        return;
    }
    // Ghi tieu de ngan cach bang Tab de he thong ghi lai file dep nhat
    fprintf(f, "masp\ttensp\tloai\tsize\tmau\tgianhap\tgiaban\tsoluong\tdaban\n");
    for (int i = 0; i < count; i++) {
        fprintf(f, "%d\t%s\t%s\t%s\t%s\t%.2f\t%.2f\t%d\t%d\n", 
                ds[i].masp, ds[i].tensp, ds[i].loai, ds[i].size, 
                ds[i].mausac, ds[i].gianhap, ds[i].giaban, ds[i].soluong, ds[i].daban);
    }
    fclose(f);
}

void luuhoadon() {
    FILE *f = fopen(FILE_HD, "w");
    if (f == NULL) return;
    fprintf(f, "%d\n", sohoadon);
    fprintf(f, "mahd\tmasp\ttensp\tsoluong\tdongia\tthanhtien\n");
    for(int i = 0; i < sohoadon; i++) {
        fprintf(f, "%d\t%d\t%s\t%d\t%.2f\t%.2f\n", 
                dshoadon[i].mahd, dshoadon[i].masp, dshoadon[i].tensp, 
                dshoadon[i].soluong, dshoadon[i].dongia, dshoadon[i].thanhtien);
    }
    fclose(f);
}

void dochoadon() {
    FILE *f = fopen(FILE_HD, "r");
    if (f == NULL) return;
    if (fscanf(f, "%d\n", &sohoadon) != 1) {
        sohoadon = 0;
        fclose(f);
        return;
    }
    char header[200];
    fgets(header, sizeof(header), f); 
    char line[256];
    for(int i = 0; i < sohoadon; i++) {
        if(fgets(line, sizeof(line), f)) {
            // Hoa don ghi theo tab de khong lam lech chuoi tieng viet/co dau cách
            sscanf(line, "%d\t%d\t%[^\t\n]\t%d\t%f\t%f", 
                   &dshoadon[i].mahd, &dshoadon[i].masp, dshoadon[i].tensp, 
                   &dshoadon[i].soluong, &dshoadon[i].dongia, &dshoadon[i].thanhtien);
        }
    }
    fclose(f);
    if (sohoadon > 0) {
        mahoadontudong = dshoadon[sohoadon - 1].mahd + 1;
    }
}

/* ================= NGHIEP VU 1: QUAN LY SAN PHAM ================= */
void hienthi1sanpham(sanpham sp) {
    printf("|  %-5d  |  %-20s  |  %-12s  |  %-5s  |  %-8s  |  %-10.0f  |  %-10.0f  |  %-6d  |  %-5d  |\n", 
           sp.masp, sp.tensp, sp.loai, sp.size, sp.mausac, sp.gianhap, sp.giaban, sp.soluong, sp.daban);
}

void hienthisanpham(sanpham ds[], int n) {
    if (n == 0) {
        printf("\nDanh sach hien tai trong! Vui long chon menu 5 de tai du lieu.\n");
        return;
    }
    printf("\n===========================================================================================================================\n");
    printf("|  %-5s  |  %-20s  |  %-12s  |  %-5s  |  %-8s  |  %-10s  |  %-10s  |  %-5s  |  %-5s  |\n", "Ma", "Ten SP", "Loai", "Size", "Mau", "GiaNhap", "GiaBan", "Ton", "DaBan");
    printf("===========================================================================================================================\n");
    for (int i = 0; i < n; i++) {
        hienthi1sanpham(ds[i]);
    }
    printf("===========================================================================================================================\n");
}

int timKiemIndexTheoMa(sanpham ds[], int n, int ma) {
    for (int i = 0; i < n; i++) {
        if (ds[i].masp == ma) return i;
    }
    return -1;
}

void themsanpham(sanpham ds[], int *n) {
    if (*n >= MAX_SP) {
        printf("Bo nho mang da day!\n");
        return;
    }
    sanpham sp;
    printf("\n===== THEM SAN PHAM =====\n");
    printf("Ma san pham: ");
    scanf("%d", &sp.masp);
    if (timKiemIndexTheoMa(ds, *n, sp.masp) != -1) {
        printf("Ma san pham da ton tai!\n");
        return;
    }
    getchar();
    printf("Ten san pham: ");
    fgets(sp.tensp, sizeof(sp.tensp), stdin);
    sp.tensp[strcspn(sp.tensp, "\n")] = '\0';
    printf("Loai san pham: ");
    fgets(sp.loai, sizeof(sp.loai), stdin);
    sp.loai[strcspn(sp.loai, "\n")] = '\0';
    printf("Size: ");
    fgets(sp.size, sizeof(sp.size), stdin);
    sp.size[strcspn(sp.size, "\n")] = '\0';
    printf("Mau sac: ");
    fgets(sp.mausac, sizeof(sp.mausac), stdin);
    sp.mausac[strcspn(sp.mausac, "\n")] = '\0';
    printf("Gia nhap: ");
    scanf("%f", &sp.gianhap);
    printf("Gia ban: ");
    scanf("%f", &sp.giaban);
    printf("So luong: ");
    scanf("%d", &sp.soluong);
    sp.daban = 0;

    chuanHoaChuoi(sp.tensp);
    chuanHoaChuoi(sp.loai);

    ds[*n] = sp;
    (*n)++;
    printf("\nThem thanh cong vao mang tam thoi!\n");
}

void timkiemtheoma(sanpham ds[], int n) {
    int ma;
    printf("\nNhap ma can tim: ");
    scanf("%d", &ma);
    int idx = timKiemIndexTheoMa(ds, n, ma);
    if (idx == -1) {
        printf("Khong tim thay!\n");
        return;
    }
    printf("\n--- THONG TIN TIM THAY ---\n");
    printf("Ma SP      : %d\n", ds[idx].masp);
    printf("Ten SP     : %s\n", ds[idx].tensp);
    printf("Loai       : %s\n", ds[idx].loai);
    printf("Size       : %s\n", ds[idx].size);
    printf("Mau sac    : %s\n", ds[idx].mausac);
    printf("Gia nhap   : %.0f\n", ds[idx].gianhap);
    printf("Gia ban    : %.0f\n", ds[idx].giaban);
    printf("So luong   : %d\n", ds[idx].soluong);
    printf("Da ban     : %d\n", ds[idx].daban);
}

void timkiemtheoten(sanpham ds[], int n) {
    char ten[50];
    getchar();
    printf("\nNhap ten can tim: ");
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(ds[i].tensp, ten) != NULL) {
            if (found == 0) {
                printf("\nKet qua tim kiem:\n");
                printf("===========================================================================================================================\n");
                printf("|  %-5s  |  %-20s  |  %-12s  |  %-5s  |  %-8s  |  %-10s  |  %-10s  |  %-5s  |  %-5s  |\n", "Ma", "Ten SP", "Loai", "Size", "Mau", "GiaNhap", "GiaBan", "Ton", "DaBan");
                printf("===========================================================================================================================\n");
            }
            hienthi1sanpham(ds[i]);
            found = 1;
        }
    }
    if (found == 0) printf("Khong tim thay san pham nao co ten khop!\n");
}

void suasanpham(sanpham ds[], int n) {
    int ma;
    printf("\nNhap ma can sua: ");
    scanf("%d", &ma);
    int idx = timKiemIndexTheoMa(ds, n, ma);
    if (idx == -1) {
        printf("Khong tim thay!\n");
        return;
    }
    getchar();
    printf("Ten moi: ");
    fgets(ds[idx].tensp, sizeof(ds[idx].tensp), stdin);
    ds[idx].tensp[strcspn(ds[idx].tensp, "\n")] = '\0';
    printf("Loai moi: ");
    fgets(ds[idx].loai, sizeof(ds[idx].loai), stdin);
    ds[idx].loai[strcspn(ds[idx].loai, "\n")] = '\0';
    printf("Size moi: ");
    fgets(ds[idx].size, sizeof(ds[idx].size), stdin);
    ds[idx].size[strcspn(ds[idx].size, "\n")] = '\0';
    printf("Mau moi: ");
    fgets(ds[idx].mausac, sizeof(ds[idx].mausac), stdin);
    ds[idx].mausac[strcspn(ds[idx].mausac, "\n")] = '\0';
    printf("Gia nhap moi: ");
    scanf("%f", &ds[idx].gianhap);
    printf("Gia ban moi: ");
    scanf("%f", &ds[idx].giaban);
    printf("So luong moi: ");
    scanf("%d", &ds[idx].soluong);
    
    chuanHoaChuoi(ds[idx].tensp);
    chuanHoaChuoi(ds[idx].loai);
    printf("\nCap nhat thanh cong!\n");
}

void xoasanpham(sanpham ds[], int *n) {
    int ma;
    printf("\nNhap ma can xoa: ");
    scanf("%d", &ma);
    int idx = timKiemIndexTheoMa(ds, *n, ma);
    if (idx == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }
    for (int j = idx; j < (*n) - 1; j++) {
        ds[j] = ds[j + 1];
    }
    (*n)--;
    printf("Xoa thanh cong!\n");
}

/* ================= NGHIEP VU 2: QUAN LY KHO ================= */
void nhapkho(sanpham ds[], int n) {
    int ma, sl;
    printf("\n===== NHAP KHO =====\n");
    printf("Nhap ma san pham: ");
    scanf("%d", &ma);
    int idx = timKiemIndexTheoMa(ds, n, ma);
    if (idx == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }
    printf("\nSan pham: %s\n", ds[idx].tensp);
    printf("Ton kho hien tai: %d\n", ds[idx].soluong);
    printf("Nhap so luong them: ");
    scanf("%d", &sl);
    if (sl <= 0) {
        printf("So luong khong hop le!\n");
        return;
    }
    ds[idx].soluong += sl;
    printf("\nNhap kho thanh cong! Ton moi: %d\n", ds[idx].soluong);
}

void kiemtratonkho(sanpham ds[], int n) {
    printf("\n================ TON KHO ======================\n");
    printf("%-8s%-30s%-15s\n", "Ma", "Ten san pham", "So luong");
    printf("================================================\n");
    for (int i = 0; i < n; i++) {
        printf("%-8d%-30s%-15d\n", ds[i].masp, ds[i].tensp, ds[i].soluong);
    }
}

void canhbaohethang(sanpham ds[], int n) {
    int found = 0;
    printf("\n===== CANH BAO HET HANG (<= 50) =====\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].soluong <= 50) {
            printf("-> Ma SP: %-5d | Ten SP: %-25s | Ton: %d\n", ds[i].masp, ds[i].tensp, ds[i].soluong);
            found = 1;
        }
    }
    if (found == 0) printf("Tat ca san pham deu du hang tren muc bao dong.\n");
}

/* ================= NGHIEP VU 3: BAN HANG & HOA DON ================= */
void taohoadon(sanpham sp, int soluong) {
    hoadon hd;
    hd.mahd = mahoadontudong++;
    hd.masp = sp.masp;
    strcpy(hd.tensp, sp.tensp);
    hd.soluong = soluong;
    hd.dongia = sp.giaban;
    hd.thanhtien = hd.soluong * hd.dongia;
    dshoadon[sohoadon++] = hd;
    luuhoadon();
    
    printf("\n=================================\n");
    printf("           HOA DON BAN HANG\n");
    printf("=================================\n");
    printf("Ma hoa don : %d\n", hd.mahd);
    printf("Ma SP      : %d\n", hd.masp);
    printf("Ten SP     : %s\n", hd.tensp);
    printf("So luong   : %d\n", hd.soluong);
    printf("Don gia    : %.0f\n", hd.dongia);
    printf("Thanh tien : %.0f\n", hd.thanhtien);
    printf("=================================\n");
}

void banhang(sanpham ds[], int n) {
    int ma, sl;
    printf("\n===== BAN HANG =====\n");
    printf("Nhap ma san pham can mua: ");
    scanf("%d", &ma);
    int idx = timKiemIndexTheoMa(ds, n, ma);
    if (idx == -1) {
        printf("Khong tim thay san pham!\n");
        return;
    }
    printf("\nTen san pham : %s\n", ds[idx].tensp);
    printf("Gia ban      : %.0f\n", ds[idx].giaban);
    printf("Ton kho      : %d\n", ds[idx].soluong);
    printf("\nNhap so luong mua: ");
    scanf("%d", &sl);
    if (sl <= 0) {
        printf("So luong khong dung!\n");
        return;
    }
    if (sl > ds[idx].soluong) {
        printf("Kho hang khong du de cung cap!\n");
        return;
    }
    ds[idx].soluong -= sl;
    ds[idx].daban += sl;
    
    taohoadon(ds[idx], sl);
    printf("\nGiao dich hoan tat!\n");
}

void hienthihoadon() {
    if (sohoadon == 0) {
        printf("\nLich su chua ghi nhan hoa don nao!\n");
        return;
    }
    printf("\n================================================================================\n");
    printf("%-10s%-10s%-30s%-10s%-15s%-15s\n", "MaHD", "MaSP", "TenSP", "SL", "DonGia", "ThanhTien");
    printf("================================================================================\n");
    for (int i = 0; i < sohoadon; i++) {
        printf("%-10d%-10d%-30s%-10d%-15.0f%-15.0f\n", 
               dshoadon[i].mahd, dshoadon[i].masp, dshoadon[i].tensp, 
               dshoadon[i].soluong, dshoadon[i].dongia, dshoadon[i].thanhtien);
    }
}

void timhoadon() {
    int ma;
    printf("\nNhap ma hoa don can tim: ");
    scanf("%d", &ma);
    for (int i = 0; i < sohoadon; i++) {
        if (dshoadon[i].mahd == ma) {
            printf("\n========== CHI TIET ==========\n");
            printf("Ma HD      : %d\n", dshoadon[i].mahd);
            printf("Ma SP      : %d\n", dshoadon[i].masp);
            printf("Ten SP     : %s\n", dshoadon[i].tensp);
            printf("So luong   : %d\n", dshoadon[i].soluong);
            printf("Don gia    : %.0f\n", dshoadon[i].dongia);
            printf("Thanh tien : %.0f\n", dshoadon[i].thanhtien);
            return;
        }
    }
    printf("Khong co du lieu ve hoa don nay!\n");
}

/* ================= NGHIEP VU 4: THONG KE ( Thao tac DSLK ) ================= */
void thongketongtonkho(node *head) {
    int tong = 0;
    while (head != NULL) {
        tong += head->data.soluong;
        head = head->next;
    }
    printf("\nTong so luong hang hien dang ton kho: %d\n", tong);
}

void tonkhonhieunhat_itnhat(node *head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    node *max = head, *min = head;
    node *p = head->next;
    while (p != NULL) {
        if (p->data.soluong > max->data.soluong) max = p;
        if (p->data.soluong < min->data.soluong) min = p;
        p = p->next;
    }
    printf("\n--- BAO CAO TON KHO ---\n");
    printf("Ton nhieu nhat: %-25s Ma SP: %-5d SL: %d\n", max->data.tensp, max->data.masp, max->data.soluong);
    printf("Ton it nhat   : %-25s Ma SP: %-5d SL: %d\n", min->data.tensp, min->data.masp, min->data.soluong);
}

void thongkeloinhuan(node *head) {
    float loinhuan = 0;
    while (head != NULL) {
        loinhuan += (head->data.giaban - head->data.gianhap) * head->data.daban;
        head = head->next;
    }
    printf("\nTong loi nhuan dat duoc: %.0f VND\n", loinhuan);
}

void banchay_banit(node *head) {
    if (head == NULL) {
        printf("Khong co du lieu thong ke!\n");
        return;
    }
    node *max = head, *min = head;
    node *p = head->next;
    while (p != NULL) {
        if (p->data.daban > max->data.daban) max = p;
        if (p->data.daban < min->data.daban) min = p;
        p = p->next;
    }
    printf("\n--- HIEU SUAT KINH DOANH ---\n");
    printf("Ban chay nhat : %-25s Ma SP: %-5d Da ban: %d\n", max->data.tensp, max->data.masp, max->data.daban);
    printf("Ban cham nhat : %-25s Ma SP: %-5d Da ban: %d\n", min->data.tensp, min->data.masp, min->data.daban);
}

void sapXepVaXuatFile(node *head) {
    if (head == NULL) {
        printf("Danh sach trong!\n");
        return;
    }
    for (node *i = head; i->next != NULL; i = i->next) {
        node *minNode = i;
        for (node *j = i->next; j != NULL; j = j->next) {
            if (j->data.giaban < minNode->data.giaban) {
                minNode = j;
            }
        }
        sanpham temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
    }
    
    FILE *fout = fopen("sap-xep-gia.txt", "w");
    if (fout == NULL) {
        printf("Khong the thiet lap file sap-xep-gia.txt\n");
        return;
    }
    fprintf(fout, "=============================================================\n");
    fprintf(fout, "| %-10s | %-30s | %-10s |\n", "MA SP", "TEN SAN PHAM", "GIA BAN");
    fprintf(fout, "=============================================================\n");
    for (node *p = head; p != NULL; p = p->next) {
        fprintf(fout, "| %-10d | %-30s | %10.2f |\n", p->data.masp, p->data.tensp, p->data.giaban);
    }
    fprintf(fout, "=============================================================\n");
    fclose(fout);
    printf("Da sap xep danh sach va xuat thanh cong ra file 'sap-xep-gia.txt'!\n");
}


/* ==================== MAIN CONSOLE MENU ==================== */
int main() {
    sanpham ds[MAX_SP];
    node *head = NULL;
    int n = 0;
    int luaChon;

    // 1. Doc sanpham.txt local neu co san (Da tu dong ghi chuan Tab tu phien truoc)
    FILE *f = fopen(FILE_SP, "r");
    if (f != NULL) {
        char line[512];
        fgets(line, sizeof(line), f); // Bo qua tieu de
        while (n < MAX_SP && fgets(line, sizeof(line), f)) {
            chuanHoaChuoi(line);
            if(strlen(line) == 0) continue;
            
            sanpham sp;
            // Neu mo tu file ghi lai cua he thong, no da duoc luu phan cach bang Tab kieu moi
            int tk = sscanf(line, "%d\t%[^\t\n]\t%[^\t\n]\t%s\t%s\t%f\t%f\t%d\t%d", 
                            &sp.masp, sp.tensp, sp.loai, sp.size, sp.mausac, 
                            &sp.gianhap, &sp.giaban, &sp.soluong, &sp.daban);
            if(tk >= 7) {
                if(tk < 9) sp.daban = 0;
                ds[n++] = sp;
            } else {
                // Neu mo file thuan bang khoang trang ban dau
                if (phanTichDongDuLieu(line, &sp)) {
                    ds[n++] = sp;
                }
            }
        }
        fclose(f);
        printf("He thong da tu dong load %d mat hang tu file sanpham.txt!\n", n);
    }
    
    dochoadon();

    while (1) {
        printf("\n========================================\n");
        printf("   QUAN LY SHOP THOI TRANG\n");
        printf("========================================\n");
        printf("1. Quan ly san pham\n");
        printf("2. Quan ly kho\n");
        printf("3. Ban hang & Hoa don\n");
        printf("4. Thong ke cao cap (Dung DSLK)\n");
        printf("5. Update / Dong bo lai du lieu tu GitHub\n");
        printf("0. Thoat chuong trinh\n");
        printf("========================================\n");
        printf("Chon menu: ");
        scanf("%d", &luaChon);

        if (luaChon == 1) { 
            int chonSub;
            do {
                printf("\n--- SUB MENU: QUAN LY SAN PHAM ---\n");
                printf("1. Them san pham\n2. Hien thi danh sach\n3. Tim theo ma\n4. Tim theo ten\n5. Sua san pham\n6. Xoa san pham\n0. Quay lai\nChon: ");
                scanf("%d", &chonSub);
                switch(chonSub) {
                    case 1: themsanpham(ds, &n); break;
                    case 2: hienthisanpham(ds, n); break;
                    case 3: timkiemtheoma(ds, n); break;
                    case 4: timkiemtheoten(ds, n); break;
                    case 5: suasanpham(ds, n); break;
                    case 6: xoasanpham(ds, &n); break;
                }
            } while(chonSub != 0);

        } else if (luaChon == 2) { 
            int chonSub;
            do {
                printf("\n--- SUB MENU: QUAN LY KHO ---\n");
                printf("1. Nhap kho (Tang so luong)\n2. Kiem tra ton kho\n3. Canh bao sap het hang\n0. Quay lai\nChon: ");
                scanf("%d", &chonSub);
                switch(chonSub) {
                    case 1: nhapkho(ds, n); break;
                    case 2: kiemtratonkho(ds, n); break;
                    case 3: canhbaohethang(ds, n); break;
                }
            } while(chonSub != 0);

        } else if (luaChon == 3) { 
            int chonSub;
            do {
                printf("\n--- SUB MENU: QUAN LY BAN HANG ---\n");
                printf("1. Tao don ban hang\n2. Danh sach hoa don\n3. Tim chi tiet hoa don\n0. Quay lai\nChon: ");
                scanf("%d", &chonSub);
                switch(chonSub) {
                    case 1: banhang(ds, n); break;
                    case 2: hienthihoadon(); break;
                    case 3: timhoadon(); break;
                }
            } while(chonSub != 0);

        } else if (luaChon == 4) { 
            head = NULL; 
            for (int i = 0; i < n; i++) {
                themcuoi(&head, ds[i]);
            }
            
            int chonSub;
            do {
                printf("\n--- SUB MENU: THONG KE ---\n");
                printf("1. Tong hang ton kho & San pham max/min ton\n2. Tinh toan loi nhuan thuc te\n3. Thong ke san pham ban chay / ban kem\n4. Sap xep danh sach theo gia ban & xuat file\n0. Quay lai\nChon: ");
                scanf("%d", &chonSub);
                switch(chonSub) {
                    case 1: 
                        thongketongtonkho(head); 
                        tonkhonhieunhat_itnhat(head); 
                        break;
                    case 2: 
                        thongkeloinhuan(head); 
                        break;
                    case 3: 
                        banchay_banit(head); 
                        break;
                    case 4: 
                        sapXepVaXuatFile(head); 
                        break;
                }
            } while(chonSub != 0);

        } else if (luaChon == 5) { 
            n = taiDuLieuGitHub(ds);
            luuFileLocal(ds, n);

        } else if (luaChon == 0) { 
            luuFileLocal(ds, n);
            printf("Du lieu da duoc ghi lai vao file %s local an toan.\nChuong trinh ket thuc!\n", FILE_SP);
            break;
        } else {
            printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}