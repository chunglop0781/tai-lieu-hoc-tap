# Quản lý Bộ nhớ Cấp phát động trong C

Việc hiểu cách máy tính quản lý bộ nhớ là yếu tố then chốt để viết mã hiệu quả và tránh các lỗi nghiêm trọng như rò rỉ bộ nhớ (memory leak) hay lỗi truy cập vùng nhớ (segmentation fault).

### 1. Bộ nhớ cấp phát động lấy từ vùng nào trong RAM?

Bộ nhớ cấp phát động được lấy từ vùng **Heap**.

* Khác với vùng **Stack** (dành cho biến cục bộ), vùng Heap là một khu vực bộ nhớ lớn và tự do.
* Nó cho phép chương trình yêu cầu và giải phóng bộ nhớ một cách linh hoạt tại thời điểm thực thi (**runtime**).

### 2. Điểm khác biệt lớn nhất giữa Stack và Heap là gì?

Điểm khác biệt cốt lõi nằm ở **cách quản lý** và **thời gian tồn tại**:

* **Stack:** Việc cấp phát và giải phóng được thực hiện **tự động** bởi trình biên dịch khi vào và thoát khỏi hàm. Tốc độ truy cập nhanh nhưng kích thước bị giới hạn.
* **Heap:** Việc cấp phát và giải phóng hoàn toàn do **lập trình viên kiểm soát**. Nếu bạn cấp phát mà quên giải phóng (`free`), sẽ dẫn đến hiện tượng rò rỉ bộ nhớ (memory leak).

### 3. Các hàm chính dùng để quản lý bộ nhớ trong C

Trong thư viện tiêu chuẩn `<stdlib.h>`, có 4 hàm cơ bản sau:

1. `malloc()`: Cấp phát một khối bộ nhớ.
2. `calloc()`: Cấp phát và xóa trống bộ nhớ (về giá trị 0).
3. `realloc()`: Thay đổi kích thước khối bộ nhớ đã cấp phát.
4. `free()`: Giải phóng bộ nhớ về lại cho hệ thống.

### 4. So sánh hàm `malloc()` và `calloc()`

Mặc dù cả hai đều dùng để xin cấp phát bộ nhớ, chúng có hai sự khác biệt chính được thể hiện trong bảng sau:

| Đặc điểm | `malloc()` | `calloc()` |
| --- | --- | --- |
| **Giá trị khởi tạo** | Chứa giá trị rác (không khởi tạo). | Tự động khởi tạo tất cả các bit bằng **0**. |
| **Tham số truyền vào** | **1 tham số**: Tổng số byte cần xin. | **2 tham số**: Số lượng phần tử và kích thước mỗi phần tử. |

### 5. Hàm `realloc()` dùng để làm gì?

Hàm `realloc()` (viết tắt của *re-allocate*) được dùng để thay đổi kích thước của một khối bộ nhớ đã được cấp phát trước đó.

* **Cơ chế hoạt động:**
* Nếu vùng nhớ hiện tại còn trống ở phía sau, nó sẽ mở rộng thêm tại chỗ.
* Nếu không đủ chỗ, nó sẽ tìm một vùng nhớ mới đủ lớn ở vị trí khác, sao chép dữ liệu cũ sang và tự động giải phóng vùng nhớ cũ.



### 6. Có được `free()` một biến cục bộ không?

Câu trả lời là: **KHÔNG**.

* **Tại sao?** Hàm `free()` chỉ được thiết kế để giải phóng bộ nhớ được cấp phát động trên **Heap**.
* **Hậu quả:** Biến cục bộ (ví dụ `int x`) nằm trên **Stack**. Khi bạn cố gắng gọi `free(&x)`, chương trình sẽ gặp lỗi **Runtime Error** (thường là lỗi *"invalid pointer"* hoặc *"segmentation fault"*) vì trình quản lý bộ nhớ không tìm thấy địa chỉ đó trong danh sách quản lý của Heap.

---

### Tài liệu tham khảo

1. **Kernighan, B. W., & Ritchie, D. M. (1988).** *The C Programming Language (2nd ed.)*. Prentice Hall.
2. **GNU C Library Documentation** - *Memory Allocation*.
3. **C Standard Library (ISO/IEC 9899)** - *Section 7.22.3 Memory management functions*.
