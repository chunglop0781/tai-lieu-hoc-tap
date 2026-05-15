### MỤC LỤC
### ◆ Danh sách liên kết đặc biệt: Stack (LIFO).
### ◆ Danh sách liên kết đặc biệt: Queue (FIFO).
### ◆ So sánh danh sách liên kết và mảng.
### ◆ Ví dụ thực hành.
### ◆ Nhắc lại & Kết nối
### Danh sách liên kết đơn, con trỏ, cấp phát động
### + Cấp phát động: malloc(), calloc(), free().
### + Cấu trúc tự trở: struct Node { int data; struct Node "next: );
### + Danh sách liên kết đơn:
### Tập hợp các Node nổi nhau bằng con trỏ next.
### Quản lý bằng con trỏ head (nếu rỗng thì NULL).
### Thao tác cơ bản: Tạo rỗng, duyệt/in, thêm đầu cuối, xóa đầu cuối giữa, tìm kiếm, giải phóng toàn bộ.
### Tại sao chúng ta cần FIFO, LIFO?
### Buổi hôm nay, chúng ta sẽ đi vào hai cấu trúc dữ liệu rất quan trọng khác, mà mình có thể cài đặt bằng Danh sách liên kết: Stack (LIFO) và Queue (FIFO).
### Stack (LIFO - Last In, First Out) và Queue (FIFO - First In, First Out):
### + Là hai cấu trúc dữ liệu cơ bản, nhưng có nguyên tắc hoạt động rất đặc trưng.
### + Ứng dụng cực kỳ rộng rãi trong khoa học máy tính (quản lý hàm gọi, hàng đợi tác vụ, xử lý dữ liệu).
### So sánh danh sách liên kết và mảng:
### + Cả hai đều là cách lưu trữ dữ liệu tuyến tính.
### + Mỗi cấu trúc có ưu nhược điểm riêng phù hợp với các bài toán khác nhau.
### + Hiểu rõ sự khác biệt giúp lựa chọn cấu trúc dữ liệu tối ưu.
### 1) Danh sách liên kết đặc biệt: Stack (LIFO)
### Stack (Ngăn xếp - LIFO) là gì?
### - LIFO, viết tắt của Last-In, First-Out, mô tả một nguyên tắc xử lý dữ liệu nơi phần tử được thêm vào cuối cùng sẽ được lấy ra đầu tiên.
### - Ngăn xếp (Stack) là một cấu trúc dữ liệu trừu tượng hoạt động theo nguyên tắc LIFO.
### - Ta có thể hình dung ngăn xếp như một chồng đĩa: đĩa mình đặt lên trên cùng là đĩa ta sẽ lấy ra đầu tiên.
### Các thao tác cơ bản của Stack
### - Để cài đặt ngăn xếp bằng danh sách liên kết, chúng ta thường sử dụng một con trỏ duy nhất:
### + Top (đỉnh): Trỏ đến phần tử trên cùng của ngăn xếp (nơi phần tử mới được thêm vào và cũng là phần tử sẽ được lấy ra).
### 1. Push (Thêm vào ngăn xếp): Thêm một phần tử mới lên đỉnh ngăn xếp.
### Tạo một nút mới bằng cấp phát động (ví dụ: malloc).
### Gán dữ liệu cho nút mới.
### Con trỏ next của nút mới sẽ trỏ đến nút mà Top hiện tại đang trỏ tới.
### Cập nhật con trỏ Top trỏ đến nút mới này.
### Các thao tác cơ bản của Stack
### - Thao tác Push:
### + Dùng để chèn hoặc thêm một phần tử vào đỉnh của ngăn xếp (stack).
### + Việc đặt một phần tử mới vào ngăn xếp được gọi là thao tác push.
### Các bước thực hiện trong thao tác push:
###   Bước 1 – Kiểm tra xem ngăn xếp đã đầy chưa.
###   Bước 2 – Nếu ngăn xếp đầy, báo lỗi và thoát.
###   Bước 3 – Nếu ngăn xếp chưa đầy, tăng top để trỏ đến ô trống tiếp theo.
###   Bước 4 – Thêm phần tử dữ liệu vào vị trí mà top đang trỏ tới.
###   Bước 5 – Trả về trạng thái thành công.
### Ví dụ: Cài đặt Stack bằng danh sách liên kết đơn (Hàm push)
<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/b319af78-5884-4f76-b320-be34ff2363de" />

```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    };
    
// Con tro HEAD cua Stack (day chinh la con tro top)
struct Node *top = NULL; // Stack rong ban dau

void push(int data_val) {
    // Cấp phát bộ nhớ cho một nút (node) mới
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Kiểm tra xem việc cấp phát bộ nhớ có thành công không
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai! Khong the them phan tu.\n");
        return;
    }
    newNode->data = data_val;    // Gán dữ liệu cho nút mới
    newNode->next = top;         // Nút mới trỏ đến nút mà top đang trỏ tới
    top = newNode;               // Cập nhật top trỏ đến nút mới
    printf("Pushed %d vao Stack.\n", data_val);
}
// Hàm kiểm tra Stack có rỗng không
int isEmpty() {
    return top == NULL;
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack rỗng.\n");
        return;
    }
    printf("Stack (Top -> Bottom): ");
    struct Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    push(10); // Stack: 10
    displayStack();
    push(20); // Stack: 20 -> 10
    displayStack();
    push(30); // Stack: 30 -> 20 -> 10
    displayStack();
    return 0;
}
```
<img width="1525" height="166" alt="image" src="https://github.com/user-attachments/assets/21f1328e-f226-4ddd-a081-68af3d864c6c" />

### Ví dụ: Cài đặt Stack bằng danh sách liên kết đơn (Hàm pop)

<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/660781b9-251a-4bd4-b369-258d8012b930" />

### - Ta giữ nguyên các đoạn code ở ví dụ trước bao gồm:
### - Trong hàm main ta thực hiện chạy chương trình và xem kết quả:
```
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    };
    
// Con tro HEAD cua Stack (day chinh la con tro top)
struct Node *top = NULL; // Stack rong ban dau

void push(int data_val) {
    // Cấp phát bộ nhớ cho một nút (node) mới
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Kiểm tra xem việc cấp phát bộ nhớ có thành công không
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai! Khong the them phan tu.\n");
        return;
    }
    newNode->data = data_val;    // Gán dữ liệu cho nút mới
    newNode->next = top;         // Nút mới trỏ đến nút mà top đang trỏ tới
    top = newNode;               // Cập nhật top trỏ đến nút mới
    printf("Pushed %d vao Stack.\n", data_val);
}
// Hàm kiểm tra Stack có rỗng không
int isEmpty() {
    return top == NULL;
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack rỗng.\n");
        return;
    }
    printf("Stack (Top -> Bottom): ");
    struct Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int pop() {
    if (isEmpty()) {
        printf("Stack rong.\n");
        return -1;
    }
    struct Node *temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Stack rong.\n");
        return -1;
    }
    return top->data;
}


int main() {
    push(10);
    push(20);
    push(30);
    displayStack(); // Stack: 30 20 10
    printf("\nThuc hien Pop\n");
    printf("Pop: %d\n", pop()); // Pop: 30
    displayStack();
    printf("Peek: %d\n", peek()); // Peek: 20
    displayStack();
    printf("Pop: %d\n", pop()); // Pop: 20
    displayStack();
    printf("Stack is empty? %s\n", isEmpty() ? "True" : "False");
    printf("Pop: %d\n", pop()); // Pop: 10
    displayStack();
    printf("Stack is empty? %s\n", isEmpty() ? "True" : "False");
    return 0;
}

```

<img width="1538" height="463" alt="image" src="https://github.com/user-attachments/assets/09f8c272-7cd1-49a7-9bbc-890e530fff1a" />


### 2) Danh sách liên kết đặc biệt: Queue (FIFO)
### Queue (Hàng đợi - FIFO) là gì?
### FIFO, viết tắt của First-In, First-Out, mô tả một nguyên tắc xử lý dữ liệu nơi phần tử được thêm vào đầu tiên sẽ được lấy ra đầu tiên.
### - Hàng đợi (Queue) là một cấu trúc dữ liệu trừu tượng hoạt động theo nguyên tắc FIFO.
### - Khác với ngăn xếp, hàng đợi mở ở cả hai đầu.
### - Có hai thao tác được thực hiện:
###     enqueue hoặc chèn – thêm một phần tử vào hàng đợi
###     dequeue hoặc xóa – loại bỏ một phần tử khỏi hàng đợi
### - Để quản lý hàng đợi, sử dụng hai con trỏ:
###     Front (đầu hàng)
###     Rear (cuối hàng)
### Biểu diễn hàng đợi
### - Hàng đợi trong cấu trúc dữ liệu có thể được truy cập từ cả hai phía của nó (phía trước để xóa và phía sau để chèn).
### - Sơ đồ sau đây giải thích biểu diễn hàng đợi như một cấu trúc dữ liệu:
`Vào cuối - Ra cuối (Rear)` -> `Vào trước - Ra trước (Front)`
### Các thao tác cơ bản của Queue
### - Để cài đặt hàng đợi bằng danh sách liên kết, chúng ta thường sử dụng hai con trỏ:
### + Front (đầu): Trỏ đến phần tử đầu tiên của hàng đợi (phần từ sẽ được lấy ra).
### + Rear (cuối): Trỏ đến phần tử cuối cùng của hàng đợi (nơi phần tử mới được thêm vào).
### Các thao tác cơ bản của Queue
### 1 Enqueue (Thêm vào hàng đợi): Thêm một phần tử mới vào cuối hàng đợi.
### - Tạo một nút mới bằng cấp phát động (vì dụ: malloc).
### - Gán dữ liệu cho nút mới.
### - Nút mới này sẽ được nối vào sau nút cuối cùng hiện tại của hàng đợi (Rear).
### - Cập nhật con trỏ Rear trỏ đến nút mới này.
### 2. Dequeue (Lấy ra khỏi hàng đợi): Xóa và trả về phần tử ở đầu hàng đợi.
### - Kiểm tra xem hàng đợi có rỗng không.
### - Lưu trữ con trỏ đến nút đầu tiên (Front) để trả về dữ liệu.
### - Cập nhật con trỏ Front trỏ đến nút kế tiếp.
### - Giải phóng bộ nhớ của nút đã được lấy ra (ví dụ: free).
### Ví dụ: Cài đặt Queue bằng Danh sách liên kết đơn
### - Cài đặt hàm enqueue() và is QueueEmpty():

<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/6a325df8-35de-4d0f-9d03-663d00c291ca" />

```
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
// Con tro DAU va CUOI của Queue
struct Node *front = NULL; // Dau hang doi
struct Node *rear = NULL; // Cuoi hong doi
//////////
void enqueue(int data_val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai! Khong the them phan tu.\n");
        return;
    }
    newNode->data = data_val;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d vao Queue.\n", data_val);
}
//////////
int isQueueEmpty() {
    return front == NULL;
}
//////////
void displayQueue() {
    if(isQueueEmpty()){
        printf("Queue rong.\n");
        return;
    }
    printf("Queue (Front -> Rear): ");
    struct Node * current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
//////////
int main() {
    enqueue(10); //Queue: 10
    displayQueue();
    enqueue(20); //Queue: 10 -> 20
    displayQueue();
    enqueue(30); //Queue: 10 -> 20 -> 30
    displayQueue();
    return 0;
}
```

<img width="1517" height="231" alt="image" src="https://github.com/user-attachments/assets/2950b1a5-43c8-4616-be93-943c8c8f1b49" />

### Ví dụ: Cài đặt Queue bằng Danh sách liên kết đơn (Hàm dequeue())
### - Ta viết thêm cài đặt hàm dequeue() và peek_queue():

<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/3361f795-3b5b-43bd-b9c6-50eebd9141ec" />

```
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *next; };
// Con tro DAU va CUOI của Queue
struct Node *front = NULL; // Dau hang doi
struct Node *rear = NULL; // Cuoi hong doi
//////////
void enqueue(int data_val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai! Khong the them phan tu.\n");
        return;
    }
    newNode->data = data_val;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d vao Queue.\n", data_val);
}
//////////
int isQueueEmpty() {
    return front == NULL;
}
//////////
void displayQueue() {
    if(isQueueEmpty()){
        printf("Queue rong.\n");
        return;
    }
    printf("Queue (Front -> Rear): ");
    struct Node * current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
//////////
int dequeue() { //dequeue: thao tac loai bo va lay mot phan tu ra khoi hang doi (queue)
    if (isQueueEmpty()) {
        printf("Loi: Queue rong, khong the dequeue.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = front;           // 1. Tạo con trỏ tạm trỏ đến nút đầu (front)
    int dequeued_data = temp->data;      // 2. Lưu giá trị của nút sắp xóa
    front = front->next;                 // 3. Di chuyển front sang nút kế tiếp
    if (front == NULL) {                 // 4. Kiểm tra nếu hàng đợi rỗng sau khi lấy ra
        rear = NULL;                     // 5. Cập nhật con trỏ rear về NULL
    }
    free(temp);
    temp = NULL;
    return dequeued_data;
}
//////////
// Hom peek queue: Xem du tieu o dau Queue
int peek_queue() {
    if (isQueueEmpty()) {
        printf("Loi: Queue rong, khong the peek.\n");
        exit(EXIT_FAILURE);
    }
    return front->data;
}
//////////
int main() {
    enqueue(10); enqueue(20); enqueue(30); displayQueue(); // Queue: 10 20 30
    printf("\nThuc hien Dequeue\n");
    printf("Dequeue: %d\n", dequeue()); // Dequeue 10 displayQueue();
    printf("Peek: %d\n", peek_queue()); // Peek 20 displayQueue();
    printf("Dequeue: %d\n", dequeue()); // Dequeue 20
    displayQueue();
    printf("Queue is empty? %s\n", isQueueEmpty() ? "True" : "False");
    printf("Dequeue: %d\n", dequeue()); // Dequeue 30
    displayQueue();
    printf("Queue is empty? %s\n", isQueueEmpty() ? "True" : "False");
    return 0;
}
```

<img width="1527" height="417" alt="image" src="https://github.com/user-attachments/assets/dec347d7-4075-4735-9a2d-69e04f23b8d7" />

### 
### 
### 
## Nguồn
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/e5d980a9-140e-4d67-abd2-253cd7840e69" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/dcf912f3-2159-49da-b5bf-aa244ef17d2e" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/5a09eb95-42ae-4629-ae25-ab8b5feda8ba" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/0b7fc421-0984-4dbe-b33a-2ddd4ad37911" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/2b83847f-1be5-40b3-b061-a2e8befcc84f" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/5f4807f5-ac26-4fac-a93d-405e4d784367" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/6b9cf316-5be7-495b-afe2-7d60ba5482bc" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/751de04a-0cc7-48dd-b85d-14f209589f5a" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/a76bf485-0b91-4954-9cf5-658de42c1c6a" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/a28ff6de-790a-493e-aaf5-10ad179e9b94" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/5dae7288-b5c3-48e2-9af3-62a312b0818f" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/d31216a1-f6bb-44eb-9d3f-f5b9ac9a4ca6" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/abcd3e42-77f7-4b72-8dea-ec81385ab958" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/253b1877-c65c-44f1-8166-23cd4a9408d7" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/ec181ba2-1185-46bf-89b3-b6354b27f0e6" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/c35d1326-dd2d-471d-b412-6f10607eb7e3" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/7620b026-406a-4796-bcb7-5044ad851efe" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/dcc967e6-ffc7-432c-ab54-925eb87d9c29" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/d82dc660-53cd-43b6-9561-b24db055fcce" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/4b735207-0a44-4963-a844-3bc188fc8482" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/748e57ba-a7b5-48e3-8299-f9b11c23feaf" />
<img width="2048" height="1536" alt="image" src="https://github.com/user-attachments/assets/119056f6-c6c3-404a-8671-cb92bf468de9" />
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/637cef97-9744-42ab-8eaf-080056d578ce" />
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/94035609-af84-4e2c-ac06-89cf6c791390" />
<img width="1536" height="2048" alt="image" src="https://github.com/user-attachments/assets/e67a4ec0-53e7-41ea-9819-ba32e68aa9c3" />
