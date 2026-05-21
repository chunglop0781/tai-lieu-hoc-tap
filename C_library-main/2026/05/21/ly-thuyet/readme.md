# Hàm (Function)
## Khái niệm
### Chương trình (program):
#### - Một chương trình bao gồm một hoặc nhiều hàm
#### - Hàm main() là hàm bắt buộc của chương trình
#### - Chương trình luôn bắt đầu thực hiện từ câu lệnh đầu tiên của hàm main() và thường kết thúc khi gặp dấu } cuối cùng của nó.
#### - Hàm (Function): là một đoạn chương trình độc lập thực hiện trọn vẹn một công việc nhất định, nó thường trả về cho chương trình gọi nó một giá trị.
### Note: Không cho phép xây dựng một hàm bên trong một hàm khác.
### Để viết một hàm, trước hết ta phải xác định mục đích của hàm là dùng để làm gì, từ đó xác định các thành phần:
#### - Nguyên mẫu hàm
#### - Kiểu giá trị trả về của hàm (kiểu hàm)
#### - Tên hàm
#### - Các tham số (đối số) của hàm
#### - Nội dung hàm
# Xây dựng hàm – Nguyên mẫu hàm (Prototype)
## <kiểu dữ liệu của hàm> <tên hàm(danh sách các tham số)>;
### Có thể viết hoặc không viết nguyên mẫu
### Các nguyên mẫu hàm (nếu có) cần đặt trước hàm main()
### Ví dụ:
```
double exp(double x);
double pow(double x, double y);
char *strcat(char *des, const char *source);
```
# Xây dựng hàm – Tên hàm
## Theo quy định đặt tên (định danh – identifier)
## Nên ngắn gọn và phản ánh phần nào mục đích của hàm
## Tên hàm trong nguyên mẫu, khai báo và sử dụng phải giống nhau
# Xây dựng hàm – Tham số của hàm
## Các tham số mà ta ghi trong nguyên mẫu hay lúc khai báo hàm gọi là tham số hình thức
## Các giá trị, biến mà ta ghi sau tên hàm được gọi để thực hiện hàm đó gọi là tham số thực
## Tham số của một hàm có hai công dụng:
### + Cung cấp các giá trị cho hàm khi ta gọi nó thực hiện
### + Lưu các kết quả tính toán được trong quá trình hàm hoạt động
## Như vậy ta có thể chia thành:
### + Tham số vào: cung cấp giá trị cho hàm
### + Tham số ra: Lưu kết quả tính toán được trong hàm
### + Tham số vừa vào, vừa ra.
## => Khi viết hàm, ta phải xác định xem có bao nhiêu tham số? Và là tham số gì?
# Xây dựng hàm – Thân hàm
## Thân hàm là nội dung chính của hàm bắt đầu bằng dấu { và kết thúc bởi dấu }.
## Trong thân hàm chứa các câu lệnh cần thiết để thực hiện một yêu cầu nào đó đã đề ra cho hàm
## Trong thân hàm có thể sử dụng một câu lệnh return, có thể dùng nhiều câu lệnh return ở những chỗ khác nhau và cũng có thể không sử dụng câu lệnh này. Dạng tổng quát của nó là:  
```
         return [ biểu thức ];
```
## Giá trị của biểu thức trong câu lệnh return sẽ được gán cho hàm.
# Xây dựng hàm (tổng kết)
```
[kiểu_hàm tên_hàm (khai báo các đối – tham số hình thức);] // Nguyên mẫu hàm

kiểu_hàm tên_hàm (khai báo các đối – tham số hình thức) // Tiêu đề hàm
{
    khai báo các biến cục bộ
    các câu lệnh                                        // Thân hàm
    [return [biểu thức];]
}
```
# Sử dụng hàm
## Hàm được sử dụng thông qua lời gọi tới nó. Cách viết một lời gọi hàm như sau:
```
         tên_hàm ([ danh sách tham số thực ])
```
## Một điều cần nhớ khi viết lời gọi hàm là:
### + Số lượng tham số thực phải bằng số lượng tham số hình thức (đối)
### + Mỗi tham số thực phải có cùng kiểu giá trị như kiểu giá trị của đối tương ứng với nó.
## Ví dụ:
```
sqrt(100)
sqrt(3*x)
pow(d, 1.0/k)
```
# Quy tắc hoạt động của hàm
## Khi gặp một lời gọi hàm thì hàm bắt đầu được thực hiện. Nói cách khác, khi máy gặp một lời gọi hàm ở một chỗ nào đó của chương trình, thì máy sẽ tạm rời chỗ đó và chuyển đến hàm tương ứng.
## Quá trình thực hiện hàm sẽ diễn ra theo trình tự 4 bước như sau:
### a/ Cấp phát bộ nhớ cho các đối và các biến cục bộ.
### b/ Gán giá trị của các tham số thực cho các đối tương ứng.
### c/ Thực hiện các câu lệnh trong thân hàm.
### d/ Khi gặp câu lệnh return hoặc dấu } cuối cùng của thân hàm thì máy sẽ xoá các đối, các biến cục bộ (giải phóng bộ nhớ của các đối, biến cục bộ) và thoát khỏi hàm.
## Nếu trở về từ một câu lệnh return có chứa biểu thức thì giá trị của biểu thức được gán cho hàm. Giá trị của hàm sẽ được sử dụng trong các biểu thức chứa nó.
# Dùng dẫn hướng #define để định nghĩa hàm đơn giản (inline)
## Ví dụ 1:
```
#include <stdio.h>
#include <math.h>

#define tong(x, y) x + y
#define KC(x1, y1, x2, y2) sqrt(pow(x1-x2,2)+pow(y1-y2,2))

main()
{
    int a = 5, b = 8;
    printf("%d + %d = %d", a, b, tong(a, b));
    printf("Khoang cach giua diem (0,1) va (-6,5) la %f", KC(0, 1, -6, 5));
}
```
## Ví dụ 2:
```
#include <stdio.h>

#define lamtron(x) (x - (int)x < 0.5 ? (int)x : (int)x + 1 )
main()
{
    float a = 2.0/3;
    printf(" %d ",lamtron(a));
}
```
## Ví dụ 3:
```
#include <stdio.h>
#include <math.h>
/*
double KC(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2))
}*/

#define KC(x1,y1,x2,y2) sqrt(pow(x1-x2,2)+pow(y1-y2,2))

main()
{
    printf("Khoang cach giua diem (0,1) va (-6,5) la %f",KC(0,1,-6,5))
}
```
# 1) Khái niệm Đệ quy
## Đệ quy là một phương pháp mà trong đó một hàm tự gọi chính nó để giải quyết một vấn đề.
## Giải quyết các bài toán có tính chất lặp lại cấu trúc (fractal), như duyệt cây, tính giai thừa.
## Phương pháp đệ quy thường được sử dụng phổ biến trong những ứng dụng mà cách giải quyết có thể được thể hiện bằng việc áp dụng liên tiếp cùng giải pháp cho những tập hợp con của bài toán.
# 1) Nguyên tắc xây dựng hàm đệ quy
## Một hàm đệ quy thường bao gồm hai phần chính:
## 1. Trường hợp cơ bản (Base Case):
### Đây là điều kiện dừng của hàm đệ quy. Khi điều kiện này được đáp ứng, hàm sẽ trả về một giá trị mà không gọi lại chính nó nữa.
### Nếu thiếu trường hợp cơ bản, hàm đệ quy sẽ chạy vô hạn (lặp vô hạn) gây lỗi tràn bộ nhớ.
## 2. Trường hợp đệ quy (Recursive Step): * Hàm gọi lại chính nó, nhưng với một đầu vào đã thay đổi (thường là nhỏ hơn hoặc đơn giản hơn) để tiến dần đến trường hợp cơ bản.
### Minh họa cấu trúc mã (bên phải slide):
```
void recurse() {
    ...
    recurse(); // Gọi đệ quy (recursive call)
    ...
}

int main() {
    ...
    recurse();
    ...
}
```
## 1) Cú pháp xây dựng
```
kieu_tra_ve tenhamdequi(danh sách tham số hình thức) {
    // code
    tenhamdequi(danh sách tham số thực); /* gọi lại chính nó */
}

int main() {
    tenhamdequi(danh sách tham số thực);
}
```
# Ví dụ 1 về hàm đệ quy
## Ví dụ này minh họa cách hoạt động của hàm đệ quy bằng cách:
### + In ra dãy số nguyên từ $n$ về 1, mỗi lần gọi đệ quy sẽ giảm giá trị $n$ đi 1.
### + Hàm gọi lại chính nó với giá trị nhỏ hơn cho đến khi gặp điều kiện dừng ($n == 0$).
```
#include <stdio.h>

void recursive(int n){
    if(n > 0){
        printf("%d ", n);
        recursive(n - 1);
    }
}

int main(){
    recursive(4);
    return 0;
}
```
# Ví dụ 2 : Tính tổng tự nhiên từ 1 tới N
## + Tính tổng các số nguyên từ $n$ về 0 bằng cách liên tục gọi lại chính hàm sum(n) với đối số giảm dần.
## + Mỗi lần gọi đệ quy sẽ giảm giá trị $n$ đi 1, cộng dồn vào kết quả trả về.
## + Hàm tự gọi lại chính nó cho đến khi gặp điều kiện dừng ($n == 0$).
```
#include <stdio.h>

int sum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + sum(n - 1);
    }
}

int main(){
    printf("%d", sum(3));
    return 0;
}
```
# 1) Đệ quy
## Công thức truy hồi
### Trong các bài toán đệ quy tính toán kết quả tồn tại một khái niệm là công thức truy hồi, kiến thức này ta sẽ được học tại môn toán rời rạc tại đại học. 
### Có thể hiểu đơn giản công thức truy hồi giúp xác định giá trị của phần tử hay kết quả của 1 bài toán lớn hơn thông qua bài toán con nhỏ hơn đã biết trước kết quả.
### Ví dụ khi ta cần tìm số Fibonacci thứ 10 mình có thể sử dụng số Fibonacci thứ 8 và 9. Và công thức truy hồi của dãy Fibonacci là:
```
$$F_n = F_{n-1} + F_{n-2}$$
```
### - Ví dụ: Tìm số Fibonacci bằng đệ quy
```
#include <stdio.h>

int fibonacci(int n) {
    // Điều kiện dừng (Base Case)
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    // Bước đệ quy (Recursive Step)
    else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Hàm gọi chính nó 2 lần
    }
}

int main() {
    int num;
    printf("Nhap mot so nguyen khong am: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Vui long nhap so khong am.\n");
    } else {
        printf("So Fibonacci thu %d la: %d\n", num, fibonacci(num));
    }
    return 0;
}
```
# Ưu điểm và nhược điểm của đệ quy
## - Ưu điểm:
### * Code ngắn gọn, thanh lịch, dễ đọc (khi bài toán có tính chất đệ quy tự nhiên).
### * Gần với định nghĩa toán học.
### * Phù hợp cho các cấu trúc dữ liệu đệ quy (cây, đồ thị).
## - Nhược điểm:
### * **Hiệu suất:** Thường chậm hơn vòng lặp (do overhead của lời gọi hàm, quản lý Stack).
### * **Tốn bộ nhớ Stack:** Mỗi lời gọi đệ quy tạo một frame mới trên stack. Dễ gây stack overflow nếu độ sâu đệ quy quá lớn.
### * Khó debug và theo dõi luồng thực thi hơn.
