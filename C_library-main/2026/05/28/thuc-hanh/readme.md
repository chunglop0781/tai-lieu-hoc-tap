# Bài thực hành: Viết chương trình bằng C thực hiện:
* Nhập danh sách n phần tử số nguyên vào danh sách liên kết đơn. In danh sách.
* Xóa K phần tử và in danh sách các phần tử còn lại.
* Đảo ngược danh sách liên kết đơn hiện có và in danh sách đảo ngược.
* Tính tổng các phần tử âm và dương và in ra màn hình.
* Hủy bỏ toàn bộ danh sách.
```
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *makeNode(int x){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// themCuoi
void pushBack(node ** head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//in
void duyet(node *head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// xoa 1 phan tu dau tien
void popFront(node **head){
    if(*head == NULL){
        printf("*head = NULL\n");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// xoa K phan tu dau tien
void deleteKNodes(node **head, int k){
    for(int i = 0; i < k && *head != NULL; i++){
        popFront(head);
    }
}

//daoNguocDSLK
void daoNguocDSLK(node **head){
    node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

//tinhTongAmDuong
void tinhTongAmDuong(node *head){
    long long tongAm = 0, tongDuong = 0;
    while(head != NULL){
        if(head->data > 0){
            tongDuong += head->data;
        }
        else if(head->data < 0){
            tongAm += head->data;
        }
        head = head->next;
    }
    printf("Tong am = %lld\nTong duong = %lld\n", tongAm, tongDuong);
}

int main(){
    node *head = NULL;
    int n, k, gtri;
    printf("Vui long nhap phan tu n: "); scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Nhap gia tri phan tu thu %d: ", i + 1); scanf("%d", &gtri);
        pushBack(&head, gtri);
    }
    printf("Danh sach ban dau: "); duyet(head);
    printf("Nhap so luong K can xoa: "); scanf("%d", &k);
        deleteKNodes(&head, k);
    printf("Danh sach sau khi xoa %d phan tu dau tien: ", k);
        duyet(head);
    printf("Danh sach sau khi dao nguoc: ");
        daoNguocDSLK(&head); duyet(head);
        tinhTongAmDuong(head);
    while (head != NULL){
        popFront(&head);
    }
    printf("Giai phong bo nho thanh cong!\n");
    return 0;
}
```
