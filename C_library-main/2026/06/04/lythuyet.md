## 2) Đối dòng lệnh - Hàm main có tham số

### ● Đối dòng lệnh là gì?

Hàm main là điểm bắt đầu của mọi chương trình C. Thông thường, chúng ta khai báo void main(void) hoặc int main() nếu không cần truyền đối số.

Tuy nhiên, hàm main có thể nhận các tham số từ dòng lệnh khi chương trình được thực thi.

Nó cho phép chương trình tùy biến hoạt động dựa trên đầu vào ban đầu mà không cần nhập liệu sau khi chạy.

Ví dụ: compiler.exe mycode.c -o myapp (compiler.exe là chương trình, mycode.c và -o myapp là các đối dòng lệnh).

### ● Cấu trúc hàm main() với tham số dòng lệnh

Hàm main() có thể nhận hai tham số để xử lý đối dòng lệnh:

**C**
```c
int main(int argc, char *argv[]) {
    // ... code ...
    return 0;
}
```

Trong đó:

**argc (argument count):**

Là một số nguyên, đếm số lượng đối số trên dòng lệnh (bao gồm cả tên chương trình).

Luôn >= 1.

### ● Ví dụ: Truy cập đối dòng lệnh

**C**
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("So luong doi so (argc): %d\n", argc);
    printf("Cac doi so dong lenh\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    if (argc > 1) { // Neu co it nhat 1 doi so (ngoai ten chuong trình)
        printf("Doi so thu nhat la: %s\n", argv[1]);
    } else {
        printf("Khong co doi so nao ngoai ten chuong trinh.\n");
    }
    return 0;
}
```

### ● Ví dụ: Ứng dụng đơn giản với đối dòng lệnh

Chúng ta cùng xem một ứng dụng đơn giản hơn: tính tổng các số được truyền từ dòng lệnh:

**C**
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    printf("Tinh tong cac so tu doi dong lenh\n");
    
    if (argc < 2) {
        printf("Su dung: %s <so1> <so2> ...\n", argv[0]);
        return 1;
    }
    
    for (int i = 1; i < argc; i++) { // Bat dau tu argv[1] (doi so dau tien)
        int num = atoi(argv[i]); // Chuyen chuoi thanh so nguyen (ASCII to Integer)
        sum += num;
    }
    
    printf("Tong cac so la: %d\n", sum);
    return 0;
}
```

Giải thích chi tiết:

Ta kiểm tra if (argc < 2) để đảm bảo người dùng đã nhập ít nhất một số (vì argv[0] là tên chương trình).

Trong vòng lặp for, mình bắt đầu từ i = 1 (đối số đầu tiên).

Quan trọng: Các đối số dòng lệnh luôn là chuỗi ký tự. Để tính tổng, mình phải chuyển chúng thành số nguyên bằng hàm atoi() (ASCII to Integer) từ thư viện <stdlib.h>.

Nếu là số thực, dùng atof() (ASCII to Float).

Sau đó, mình cộng các số này vào sum.

→ Ứng dụng này minh họa cách chương trình có thể hoạt động ngay lập tức với đầu vào ban đầu mà không cần đợi nhập liệu.

## 3) Con trỏ trỏ tới hàm

### ● Con trỏ trỏ tới hàm là gì?

Con trỏ trỏ tới hàm (Function Pointer) là một biến con trỏ dùng để lưu trữ địa chỉ của một hàm. Tương tự như con trỏ biến lưu địa chỉ của biến, con trỏ hàm lưu địa chỉ nơi mã thực thi của hàm bắt đầu trong bộ nhớ.

Việc này cho phép ta:

Gán hàm cho biến con trỏ.

Truyền hàm như một đối số cho hàm khác (callback functions).

Lưu trữ nhiều hàm vào một mảng con trỏ hàm.

Tạo các hàm tổng quát.

Mỗi hàm trong C cũng có một địa chỉ bộ nhớ duy nhất.

### ● Khai báo và khởi tạo con trỏ hàm

Cú pháp khai báo:

Kiểu_trả_về (*Tên_con_trỏ)(Danh_sách_đối_số);

Ví dụ:

**C**
```c
void (*funcPtr)(int);
```

(Trong đó funcPtr là tên của function pointer. Function pointer cũng chỉ là một biến pointer).

Lưu ý quan trọng: Thiếu 2 dấu ngoặc đơn đơn này (*Tên_con_trỏ), cú pháp sẽ trở thành khai báo một hàm trả về một con trỏ (function return pointer to void):

**C**
```c
void *funcPtr(int);
```

### ● Gọi hàm thông qua con trỏ hàm

Sau khi con trỏ hàm được khởi tạo, ta có thể gọi hàm thông qua con trỏ đó.

Cú pháp:

(*Tên_con_trỏ)(Danh_sách_đối_số);

Hoặc (cách viết gọn hơn, phổ biến hơn):

Tên_con_trỏ(Danh_sách_đối_số);

**C**
```c
#include <stdio.h>

int cong(int a, int b) { return a + b; }

int main() {
    int (*ptr_cong)(int, int);
    ptr_cong = cong;
    
    int x = 10, y = 5;
    
    // Goi ham cong thong qua con tro ham
    int ket_qua1 = (*ptr_cong)(x, y); // Cach viet ro rang hon
    int ket_qua2 = ptr_cong(x, y);    // Cach viet gon hon, pho bien
    
    printf("Ket qua cong (qua con tro): %d\n", ket_qua1);
    printf("Ket qua cong (qua con tro, cach gon): %d\n", ket_qua2);
    return 0;
}
```

Kết quả màn hình:

**Plaintext**
```text
Ket qua cong (qua con tro): 15
Ket qua cong (qua con tro, cach gon): 15
```

### ● Ví dụ: Sử dụng con trỏ hàm

**C**
```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    int (*ptr_operation)(int, int);
    
    printf("Thuc hien phep cong\n");
    ptr_operation = add; // Gan dia chi ham add cho con tro ham
    printf("Ket qua cong: %d\n", ptr_operation(10, 5)); // Goi ham add qua con tro
    
    printf("\nThuc hien phep tru\n");
    ptr_operation = subtract; // Gan dia chi ham subtract
    printf("Ket qua tru: %d\n", ptr_operation(10, 5)); // Goi ham subtract qua con tro
    
    printf("\nThuc hien phep nhan\n");
    ptr_operation = multiply; // Gan dia chi ham multiply
    printf("Ket qua nhan: %d\n", ptr_operation(10, 5)); // Goi ham multiply qua con tro
    
    return 0;
}
```

Kết quả màn hình:

**Plaintext**
```text
Thuc hien phep cong
Ket qua cong: 15

Thuc hien phep tru
Ket qua tru: 5

Thuc hien phep nhan
Ket qua nhan: 50
```

→ Ý nghĩa: Ví dụ này cho thấy tính linh hoạt của con trỏ hàm: một biến con trỏ có thể đại diện cho nhiều hàm khác nhau, và mình có thể chọn hàm để gọi ở thời điểm chạy chương trình.

### ● Gọi hàm thông qua con trỏ hàmSau khi con trỏ hàm được khởi tạo, ta có thể gọi hàm thông qua con trỏ đó.Cú pháp:(*Tên_con_trỏ)(Danh_sách_đối_số);Hoặc (cách viết gọn hơn, phổ biến hơn):Tên_con_trỏ(Danh_sách_đối_số);C#include <stdio.h>

```c
int cong(int a, int b) { return a + b; }

int main() {
    int (*ptr_cong)(int, int);
    ptr_cong = cong;
    
    int x = 10, y = 5;
    
    // Gọi hàm cộng thông qua con trỏ hàm
    int ket_qua1 = (*ptr_cong)(x, y); // Cách viết rõ ràng hơn
    int ket_qua2 = ptr_cong(x, y);    // Cách viết gọn hơn, phổ biến
    
    printf("Ket qua cong (qua con tro): %d\n", ket_qua1);
    printf("Ket qua cong (qua con tro, cach gon): %d\n", ket_qua2);
    return 0;
}
```

Kết quả màn hình:PlaintextKet qua cong (qua con tro): 15

Ket qua cong (qua con tro, cach gon): 15

### ● Ví dụ: Sử dụng con trỏ hàmC#include <stdio.h>

```c
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    int (*ptr_operation)(int, int);
    
    printf("Thuc hien phep cong\n");
    ptr_operation = add; // Gán địa chỉ hàm add cho con trỏ hàm
    printf("Ket qua cong: %d\n", ptr_operation(10, 5)); // Gọi hàm add qua con trỏ
    
    printf("\nThuc hien phep tru\n");
    ptr_operation = subtract; // Gán địa chỉ hàm subtract
    printf("Ket qua tru: %d\n", ptr_operation(10, 5)); // Gọi hàm subtract qua con trỏ
    
    printf("\nThuc hien phep nhan\n");
    ptr_operation = multiply; // Gán địa chỉ hàm multiply
    printf("Ket qua nhan: %d\n", ptr_operation(10, 5)); // Gọi hàm multiply qua con trỏ
    
    return 0;
}
```

Kết quả màn hình:PlaintextThuc hien phep cong

Ket qua cong: 15

Thuc hien phep tru

Ket qua tru: 5

Thuc hien phep nhan

Ket qua nhan: 50

$\rightarrow$ Ý nghĩa: Ví dụ này cho thấy tính linh hoạt của con trỏ hàm: một biến con trỏ có thể đại diện cho nhiều hàm khác nhau, và mình có thể chọn hàm để gọi ở thời điểm chạy chương trình.

### ● Ví dụ: Con trỏ hàm cho hàm CallbackC#include <stdio.h>

```c
// Hàm callback: In ra một số (logic xử lý từng phần tử)
void printNumber(int num) {
    printf("%d ", num);
}

// Hàm callback: In ra bình phương của một số
void printSquare(int num) {
    printf("%d(binh phuong) ", num * num);
}

// Hàm tổng quát: Duyệt mảng và thực hiện một thao tác (hàm callback) trên mỗi phần tử
void processArray(int arr[], int size, void (*callback_func)(int)) {
    printf("Ket qua xu ly mang: ");
    for (int i = 0; i < size; i++) {
        callback_func(arr[i]);
    }
    printf("\n");
}

int main() {
    int myArr[] = {1, 2, 3, 4, 5};
    int N = sizeof(myArr) / sizeof(myArr[0]);
    
    printf("In mang thong thuong\n");
    processArray(myArr, N, printNumber); // Truyền hàm printNumber làm đối số
    
    printf("\nIn binh phuong cua cac phan tu\n");
    processArray(myArr, N, printSquare); // Truyền hàm printSquare làm đối số
    
    return 0;
}
```
