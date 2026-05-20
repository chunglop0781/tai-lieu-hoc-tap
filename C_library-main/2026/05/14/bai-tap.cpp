#include <iostream>
#include <string>
#include <stdexcept>

// Sử dụng struct cho Node, có thể đặt bên trong lớp Queue để ẩn chi tiết cài đặt [18]
struct Node {
    int data;
    Node* next;
    
    // Constructor giúp khởi tạo Node gọn gàng hơn [19]
    Node(int val, Node* n = nullptr) : data{val}, next{n} {}
};

class TaskQueue {
public:
    // Khởi tạo hàng đợi rỗng [20]
    TaskQueue() : front{nullptr}, rear{nullptr} {}

    // Hàm hủy để giải phóng bộ nhớ theo nguyên tắc RAII [11, 21]
    ~TaskQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int data_val) {
        // new sẽ ném std::bad_alloc nếu hết bộ nhớ, không cần check nullptr thủ công [22, 23]
        Node* newNode = new Node{data_val}; 

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Enqueued " << data_val << " vao Queue.\n";
    }

    int dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Loi: Queue rong."); // Ném ngoại lệ thay vì dừng chương trình [14]
        }

        Node* temp = front;
        int dequeued_data = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp; // Sử dụng delete thay vì free [4, 5]
        return dequeued_data;
    }

    bool isEmpty() const { return front == nullptr; }

private:
    Node* front;
    Node* rear;
};

// Hàm bổ trợ, trình bày theo phong cách tách biệt logic xử lý và hiển thị
void printTaskName(int taskID) {
    switch (taskID) { // Sử dụng switch-case thay cho if-else if nếu có thể [24, 25]
        case 1: std::cout << "Dang in: document_A\n"; break;
        case 2: std::cout << "Dang in: image_B\n"; break;
        case 3: std::cout << "Dang in: report_C\n"; break;
        default: std::cout << "Task khong xac dinh\n"; break;
    }
}

int main() {
    try { // Bao quanh bằng khối try-catch để bắt các ngoại lệ [14, 15]
        TaskQueue queue;
        
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        std::cout << "\nBat dau qua trinh in:\n";
        while (!queue.isEmpty()) {
            int task = queue.dequeue();
            printTaskName(task);
        }
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}