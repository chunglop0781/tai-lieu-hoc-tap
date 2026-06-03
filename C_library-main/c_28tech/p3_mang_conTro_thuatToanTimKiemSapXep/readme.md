
# p3b51.mp4

# MẢNG MỘT CHIỀU (1D ARRAY)
## /PROBLEM
* Giả sử bạn cần tính trọng lượng của 1 đàn gà lên đến "hàng nghìn con". Vậy việc lưu trữ trọng lượng của hàng nghìn con gà này sẽ phải xử lý ra sao?
## 1. ĐỊNH NGHĨA VÀ TÍNH CHẤT
### Mảng một chiều:
* Là một cấu trúc dữ liệu gồm nhiều phần tử có cùng kiểu dữ liệu, được lưu trữ ở các ô nhớ liên tiếp nhau trong bộ nhớ.
* Được sử dụng khi bạn cần lưu trữ một số lượng lớn các phần tử có cùng kiểu dữ liệu.
* Mảng 1 chiều đơn giản, dễ hiểu và được sử dụng rất nhiều trong mọi ngôn ngữ lập trình.
## 2. KHAI BÁO MÁNG
```
CÚ PHÁP
Data_type array_name [Number_of_element]
```
* Ví dụ:

| Khai báo | Ý nghĩa |
|----------|----------|
| int a[100]; | Mảng số nguyên int a có 100 phần tử |
| float b[1000]; | Mảng số thực float b có 1000 phần tử |
| double diem[10]; | Mảng số thực double diem có 10 phần tử |
| char ten[50]; | Mảng kí tự char ten có 50 phần tử |

## 2. KHAI BÁO MẢNG
### Khai báo mảng a có 3 phần tử là số nguyên, các giá trị của a là giá trị rác
* int a[3]; => | 100 | 21455 | 0 |
### Khai báo mảng a có 3 phần tử là số nguyên, gán lần lượt các phần tử trong mảng a là 1, 2, 3
* int a[3] = {1, 2, 3} => | 1 | 2 | 3 |

## 3. CÁC THAO TÁC TRÊN MẢNG
### Truy cập phần tử và duyệt mảng
* Các phần tử trong mảng được truy cập thông qua chỉ số. Chỉ số của mảng được đánh từ 0 và kết thúc bởi n - 1 (với n là số lượng phần tử của mảng)
```
Cú pháp truy cập
array_name [index]
```
* Ví dụ:
```
int a[6] = {3, 8, 9, 1, 7, 4}
Array  | 3 | 8 | 9 | 1 | 7 | 4 |
Index  | 0 | 1 | 2 | 3 | 4 | 5 |
printf("%d", a[0]); // 3
printf("%d", a[5]); // 4
printf("%d", a[2]); // 9
```
* Code 1:
```
#include <stdio.h>
int main(){
    int a[5]= {3, 4, 2, 7, 6};
    printf("Phan tu o chi so 4: %d\n", a[4]);
    printf("%d\n", a[2]);
    for(int i = 0; i < 5 ; i++) {
        printf("Phan tu o chi so %d: %d\n", i, a[i]);
    }
    for(int i = 0; i < 5 ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 4; i >= 0 ; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
```
* Code 2:
```
#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    int a[n]; // Mang so nguyen a co n phan tu
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
```
* Code 3:
```
#include <stdio.h>
#include <math.h>

int nt(int n) {
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
        return n > 1; /// ?????
}

//Input
//5
//2 7 6 12 17
//Output
//2 7 17

int main() {
    int n;
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    int a[n]; // Mang so nguyen a co n phan tu
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int dem = 0;
    for(int i = 0; i < n; i++) {
        if(nt(a[i])){
            printf("%d ", a[i]);
            ++dem;
        }
    }
    printf("\n%d", dem);
    return 0;
}
```
## 3. CÁC THAO TÁC TRÊN MẢNG
### Duyệt mảng thông qua chỉ số
```
#include <stdio.h>
int main(){
  int n; // Số lượng phần tử máng
  scanf("%d", &n);
  int a[1000]; //Chú ý nếu n lớn phải
  // khai báo máng ít nhất n phần tử
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++){
    printf("%d", a[i]);
  }
}
```
*Chú ý: Khi khai báo kích thước của mảng hãy chú ý tới giới hạn số lượng phần tử tối đa của đầu bài.
### Code 4:
```
#include<stdio.h>
#include<math.h>
    int tong(int a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

void change(int a[], int n) {
    for(int i = 0; i < n; i++){
        a[i] *= 2;
    }
}

int main(){
    int n; // tran bo nho stack
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    change (a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
```
### Mảng làm tham số của hàm
* Khi mảng làm tham số của hàm, những thay đổi trong hàm sẽ làm thay đổi tới mảng được truyền vào.
* Chú ý: Khi xây dựng hàm có tham số là mảng, cần phải kèm theo 1 tham số nữa là số lượng phần tử trong mảng.
### Ví dụ 1 : Gấp đôi mọi phần tử trong mảng
```
#include<stdio.h>
void nhanDoi(int a[], int n){
  for(int i = 0; i < n; i++){
    a[i] *= 2;
  }
}

int main(){
  int a[5] = {1, 2, 3, 4, 5};
  nhanDoi(a, 5);
  for(int i = 0; i < 5; i++){
    printf("%d ", a[i]);
  }
}
// Output: 2 4 6 8 10
```

### Ví dụ 2: Tính tổng các phần tử trong mảng
```
#include<stdio.h>
int tong(int a[], int n){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += a[i];
  }
  return sum;
}

int main(){
  int a[5] = {1, 2, 3, 4, 5};
  printf("%d", tong(a, 5));
}
// Output: 15
```
## 4. MỘT SỐ CHÚ Ý TRÊN MẢNG
### Ưu điểm
* Đơn giản, dễ hiểu và dễ sử dụng
* Truy cập vào phần tử trong mảng nhanh chóng thông qua chỉ số.
* Dễ dàng khai báo một loạt các phần tử cùng kiểu dữ liệu
* Dễ dàng duyệt mọi phần tử trong mảng bằng một vòng lặp duy nhất
### Nhược điểm
* Kích thước của mảng là cố định, bạn không thể mở rộng cũng như thu hẹp mảng một khi nó đã được khai báo
* Việc chèn và xóa phần tử trong mảng là khó khăn
### No index out of bound checking:
* Mảng trong ngôn ngữ lập trình C không kiểm tra việc bạn có truy cập vào một chỉ số hợp lệ hay không.
* Khi mảng của bạn có N phần tử thì chỉ số hợp lệ sẽ là từ 0 tới N-1. Tuy nhiên bạn hoàn toàn có thể truy cập vào các chỉ số không hợp lệ như-1, N, N+1,...
* Các giá trị này có thể là giá trị rác, các ô nhớ tương ứng với các phần tử này có thể đang thuộc quản lý của một tiến trình khác.
* Các ngôn ngữ bậc cao sẽ hạn chế điều này còn trong C++ các bạn lập trình viên phải tự đảm bảc code của mình không truy cập vào chỉ số không hợp lệ.
* Việc truy cập vào các chỉ số không hợp lệ sẽ gây lỗi Segmentation Fault trên Hackerrank hoặc các lỗi Runtime Error trên các Online judge khác.

# p3b52.mp4

## [Mảng 1 chiều cơ bản]. Bài 1. Đếm chẵn lẻ, tổng chẵn lẻ
* Đề bài: Cho mảng số nguyên A[] gồm N phần tử, nhiệm vụ của bạn là đếm xem trong máng có bao nhiêu số chẵn, bao nhiêu số lẻ, tống các phần tử là số chẵn, tổng các phần tử là số lẻ.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng
* Constraints: 1<=N<=1000;-10^3<= A[i]<=10^3;
* Output Format: Dòng đầu tiên in ra số lượng số chân. Dòng thứ 2 in ra số lượng số lẻ. Dòng thứ 3 in ra tổng các số chần. Dòng thứ 4 in ra tổng các số lẻ.
* Sample Input 0:
```
6
-711 327 372 779 451 -864
```
* Sample Output 0
```
2
4
-492
846
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int chan = 0, le = 0, tongchan = 0, tongle = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            ++chan; tongchan += a[i];
        }
        else{
            ++le; tongle += a[i];
        }
    }
    printf("%d\n%d\n%d\n%d\n", chan, le, tongchan, tongle);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 2. Trung bình cộng nguyên tố
* Đề bài: Cho màng số nguyên A[] gồm N phân tử, nhiệm vụ của bạn là tính trung bình cộng của các số là số nguyên tố trong dãy.
* Input Format: Dòng đầu tiên là số nguyên dương N: Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng
* Constraints: 1<=N<=1000;-10^3<= A[i]<=10^3;
* Output Format: In ra đáp án của bài toán lấy 3 số sau đấu phẩy.
* Sample Input 0:
```
5
-911 234 151 347 231
```
* Sample Output 0
```
249.000
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int nt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return n > 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int dem = 0, tong = 0;
    for(int i = 0; i < n; i++){
        if(nt(a[i])){
            ++dem; tong += a[i];
        }
    }
    double tbcong = (double)tong/dem;
    printf("%.3lf\n", tbcong);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 3. Số nhỏ nhất
* Đề bài: Cho mảng số nguyên A[] gồm N phần tử, hãy đếm xem trong máng của bạn có bao nhiêu số có cùng giá trị nhỏ nhất. Ví dụ máng A = {1, 2, 1, 3, 5} thì số nhỏ nhất trong máng là 1 xuất hiện 2 lần.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dùng thứ 2 gồm N xô nguyên việt cách nhau một vài khoảng trắng
* Constraints: 1<=N<=1000;-10^3<= A[i]<=10^3;
* Output Format: In ra đáp án của bài toán.
* Sample Input 0:
```
5
-854 600 222 472 207
```
* Sample Output 0
```
1
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int min = 1e9;
    for(int i = 0; i < n; i++){
        if(min > a[i]){
            min = a[i];
        //min = fmin(min, a[i]);
        }
    }
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == min){
            ++dem;
        }
    }
    printf("%d", dem);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 4. Lớn hơn, nhỏ hơn
* Đề bài: Cho mảng số nguyên A gồm N phần tử và số nguyên X, hãy đếm xem trong máng có bao nhiêu số lớn hơn X và bao nhiêu số nhỏ hơn X.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng; Dòng thứ 3 là số nguyên X.
* Constraints: 1<=N<=1000;-10^3<= A[i]<=10^3;
* Output Format: Dòng 1 in ra các số nhỏ hớn X, dòng 2 in ra các số lớn hơn X.
* Sample Input 0:
```
5
-798 183 434 850 555
135
```
* Sample Output 0
```
1
4
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int x;
    scanf("%d", &x);
    int lon = 0, nho = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > x){
            ++lon;
        }
        else if(a[i] < x){
            ++nho;
        }
    }
    printf("%d\n%d", nho, lon);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 5. In phần tử
* Đề bài: Cho mảng số nguyên A gồm N phần tử, nhiệm vụ của bạn là in ra các phần tử là số chẵn ở chỉ số chắn, mất mảng không tồn tại phần tử như vậy thì in ra "NONE".
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng.
* Constraints: 1<=N<=1000;-10^3<= A[i]<=10^3;
* Output Format: In ra các số cách nhau một khoảng trắng hoặc in ra NONE nếu không tìm thấy số thỏa mãn điều kiện của đầu bài.
* Sample Input 0:
```
5
-971 107 458 222 200
```
* Sample Output 0
```
458 200
```
* Explanation 0: Số 458 là số chẵn và ở chỉ số 2, số 200 là số chẵn ở ở chỉ số 4
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int check = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0 && a[i] % 2 == 0){
            printf("%d ", a[i]);
            check = 1; // da tim thay
        }
    }
    if(check == 0){
        printf("NONE");
    }
    return 0;
}
```

# p3b53.mp4

## [Mảng 1 chiều cơ bản]. Bài 6. Cặp số 1
* Đề bài: Cho mảng số nguyên AI] gồm N phân tử, hãy đếm xem trong mảng A[] tồn tại bao nhiêu cặp số A[i], A[j]) với khác j sao cho tổng của 2 phần tử này bằng số K cho trước.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng: Dòng thứ 3 là số nguyên K
* Constraints: 1<=N<=1000; 0<=A[i], X<=10^3;
* Output Format: In ra số lượng cặp thỏa mãn.
* Sample Input 0:
```
5
1 2 3 1 2
3
```
* Sample Output 0
```
4
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int k;
    scanf("%d", &k);
    int dem = 0;
    for(int i = 0; i < n - 1; i++){
        //xet thang a[i] => xet a[i] cap voi cac phan tu a[j], j bat dau i + 1 => n - 1
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == k){
                ++dem;
            }
        }
    }
    printf("%d", dem);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 7. Cặp số 2
* Đề bài: Cho mảng số nguyên A[] gồm N phần tử, hãy tìm độ chênh lệch nhỏ nhất giữa 2 phần tử trong mảng.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết tách nhau một vài khoảng trắng;
* Constraints: 1<=N<=1000; 0<=A[i], X<=10^3;
* Output Format: In ra độ chênh lệch nhỏ nhất giữa 2 phân tử bất kì trong mảng.
* Sample Input 0:
```
8
69 96 93 27 84 32 78 56
```
* Sample Output 0
```
3
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int min = 1e9;
    for(int i = 0; i < n - 1; i++){
        //xet thang a[i] => xet a[i] cap voi cac phan tu a[j], j bat dau i + 1 => n - 1
        for(int j = i + 1; j < n; j++){
            if(abs(a[i] - a[j]) < min){
                min = abs(a[i] - a[j]);
            }
        }
    }
    printf("%d", min);
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 8. Liệt kê các giá trị khác nhau
* Đề bài: Cho mảng số nguyên A gồm N phân tử, hãy liệt kê các giá trị khác nhau trong màng theo thứ tự xuất hiện, mỗi giá trị chỉ liệt kê 1 lần. Ở thời điểm hiện tại các bạn có thể for trâu để giải bài này, sau này sẽ dùng cách tôi ưu hơn.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng;
* Constraints: 1<=N<=1000; 0<=A[i], X<=10^3;
* Output Format: In ra các giá trị khác nhau theo thứ tự xuất hiện, mỗi giá trị chỉ liệt kê 1 lần.
* Sample Input 0:
```
9
1 2 3 4 1 2 3 4 5
```
* Sample Output 0
```
1 2 3 4 5
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //O(n^2)
    for(int i = 0; i < n; i++){
        //xet thang a[i] => xet a[i] cap voi cac phan tu a[j], j bat dau i + 1 => n - 1
        int kiemtra = 1; //kiem tra xem a[i] da duoc in truoc do hay chua
        for(int j = 0; j < i; j++){
            if(a[i] == a[j]){
               kiemtra = 0; break;
            }
        }
        if(kiemtra){
            printf("%d ", a[i]);
        }
    }
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 9. Tần suất
* Đề bài: Cho mảng số nguyên A[] gồm N phần tử, hãy liệt kê các giá trị xuất hiện trong mảng kèm theo tần suất tương ứng, mỗi giá trị chỉ liệt kê một lần theo thứ tự xuất hiện.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng;
* Constraints: 1<=N<=1000; 0<=A[i], X<=10^3;
* Output Format: In ra nhiều dòng, mỗi dòng gồm giá trị kèm theo tần suất tương ứng.
* Sample Input 0:
```
8
57 58 29 28 19 42 14 72
```
* Sample Output 0:
```
57 1
58 1
29 1
28 1
19 1
42 1
14 1
72 1
```
* Sample Input 1:
```
10
1 2 1 2 1 2 4 5 5 5
```
* Sample Output 1:
```
1 3
2 3
4 1
5 3
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //O(n^2)
    for(int i = 0; i < n; i++){
        //xet thang a[i] => xet a[i] cap voi cac phan tu a[j], j bat dau i + 1 => n - 1
        int kiemtra = 1; //kiem tra xem a[i] da duoc in truoc do hay chua
        for(int j = 0; j < i; j++){
            if(a[i] == a[j]){
               kiemtra = 0; break;
            }
        }
        if(kiemtra){
            int dem = 1;
            for(int j = i + 1; j < n; j++){
                if(a[i] == a[j]){
                    ++dem;
                }
            }
            printf("%d %d\n", a[i], dem);
        }
    }
    return 0;
}
```
## [Mảng 1 chiều cơ bản]. Bài 10. Cân bằng nguyên tố
* Đề bài: Cho mảng số nguyên A[] gôm N phân tử, hãy liệt kê các chỉ số i trong mảng thỏa mãn: Tông các phần tử bên trái i và tổng các phân tử bên phải i là các số nguyên tố.
* Input Format: Dòng đầu tiên là số nguyên dương N; Dòng thứ 2 gồm N số nguyên viết cách nhau một vài khoảng trắng;
* Constraints: 1<=N<=1000; 0<=A[i], X<=10^3;
* Output Format: In ra các chỉ số thỏa mãn trên một đông, các số cách nhau một khoảng trắng.
* Sample Input 0:
```
5
53 5 69 47 19
```
* Sample Output 0
```
3
```
* Code
```
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int nt(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return n > 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        //tinh tong cac phan tu ben trai, va ben phai
        int left = 0, right = 0;
        for(int j = 0; j < i; j++){
            left += a[j];
        }
        for(int j = i + 1; j < n; j++){
            right += a[i];
        }
        if(nt(left) && nt(right)){
            printf("%d ", i);
        }
    }
    return 0;
}
```

# p3b54.mp4

