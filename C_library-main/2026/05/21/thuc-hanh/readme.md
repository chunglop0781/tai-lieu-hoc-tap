# Bài 1: Giả sử có file data.txt chứa n số nguyên. Đọc tất cả các số và thực hiện sắp xếp tăng dần và lưu lại dãy đã được sắp xếp.
```
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *head){
    struct Node *current = head;
    printf("Danh sach: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    FILE *f = popen("curl -s https://raw.githubusercontent.com/chunglop0781/tai-lieu-hoc-tap/main/C_library-main/2026/05/21/thuc-hanh/data.txt", "r");
    //FILE *f = fopen ("D:\\bai tap dh\\2026.01\\on-qua-hoc-phan-lap-trinh-c\\Untitled9.txt", "r");
    if (f == NULL){
        printf("Loi file data.txt!\n");
        return 1;
    }
    int n; fscanf(f, "%d\n", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    struct Node *head = NULL;
    struct Node *node[n];
    for(i = 0; i < n; i++){
        node[i] = (struct Node *)malloc(sizeof(struct Node));
    }
    for(i = 0; i < n-1; i++){
            node[i]->data = a[i];
            node[i]->next = node[i+1];
    }
    node[n-1]->data = a[n-1];
    node[n-1]->next = NULL;
    head = node[0];
    printList(head);
//    FILE *out = fopen("C:\\Users\\DHGTVT\\Downloads\\ketqua.txt", "w");
//	if(out == NULL){
//    	printf("Khong luu duoc file ketqua.txt\n");
//    	return 1;
//	}
//	struct Node *current = head;
//	while(current != NULL){
//    	fprintf(out, "%d -> ", current->data);
//	    current = current->next;
//	}
//	fprintf(out, "NULL");
//	fclose(out);
//	printf("Luu file thanh cong!\n");
	for(i = 0; i < n; i++){
    	free(node[i]);
    	node[i] = NULL;
	}
	head = NULL;
    pclose(f);
}
```
# Bài 2: Nhập danh sách n học viên, mỗi học viên là một cấu trúc (struct).
# Thông tin mỗi học viên gồm: Mã HV, Họ tên, giới tính, tổng điểm.
# Xét kết quả theo điều kiện: nếu tổng điểm >= 15 thì đỗ, < 15 thì trượt.
# Sắp xếp danh sách HV đỗ theo chiều giảm dần của tổng điểm và lưu vào tệp lop.dat.
# Xét lại trên danh sách trượt, nếu 14 <= tổng điểm <  và giới tính là nữ thì đỗ và lưu nối vào tệp lop.dat.
# In hai danh sách học viên đỗ và trượt dạng bảng.
```
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char line[200];
    char mahocvien[100];
    char hoten[100];
    char gioitinh[100];
    double tongdiem;
} HocVien;

struct Node{
    HocVien data;
    struct Node *next;
};

void printList(struct Node *head){
    struct Node *current = head;
    printf("Danh sach:\n");
    while (current != NULL) {
        printf("Ma hoc vien: %s | Ho ten: %s | Gioi tinh: %s | Diem: %.2f\n",
               current->data.mahocvien,
               current->data.hoten,
               current->data.gioitinh,
               current->data.tongdiem);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    FILE *f = popen("curl -s https://raw.githubusercontent.com/chunglop0781/tai-lieu-hoc-tap/main/C_library-main/2026/05/21/thuc-hanh/students.txt", "r");
    if (f == NULL){
        printf("Loi file students.txt!\n");
        return 1;
    }
    int n; 
    fscanf(f, "%d\n", &n);
    HocVien hv[n];
    char line[256];
	for (int i = 0; i < n; i++) {
    	fgets(line, sizeof(line), f);
    	line[strcspn(line, "\n")] = '\0';
    	char *token = strtok(line, "|");
    	strcpy(hv[i].mahocvien, token);
	    token = strtok(NULL, "|");
    	strcpy(hv[i].hoten, token);
	    token = strtok(NULL, "|");
    	strcpy(hv[i].gioitinh, token);
	    token = strtok(NULL, "|");
    	hv[i].tongdiem = atof(token);
	}
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(hv[i].tongdiem < hv[j].tongdiem) {
                HocVien temp = hv[i];
                hv[i] = hv[j];
                hv[j] = temp;
            }
        }
    }

    struct Node *head = NULL;
    struct Node *node[n];
    for(i = 0; i < n; i++){
        node[i] = (struct Node *)malloc(sizeof(struct Node));
    }
    for(i = 0; i < n-1; i++){
        node[i]->data = hv[i];
        node[i]->next = node[i+1];
    }
    node[n-1]->data = hv[n-1];
    node[n-1]->next = NULL;
    head = node[0];
    printList(head);
    for(i = 0; i < n; i++){
        free(node[i]);
        node[i] = NULL;
    }
    head = NULL;
    pclose(f);
}
```
