# Bài tập: Con trỏ hàm & Bảng băm (Function Pointers & Hash Tables)

Repository này chứa mã nguồn giải quyết 2 bài tập cơ bản trong C về cấu trúc dữ liệu và giải thuật.

## Problem 6.1: Function Pointers
**Yêu cầu đề bài:**
Sử dụng và tạo các hàm tận dụng con trỏ hàm (function pointers). Dữ liệu là một mảng các bản ghi chứa thông tin người nổi tiếng (celebrities), mỗi bản ghi gồm `firstname`, `lastname` và `age` (tuổi). Yêu cầu thực hiện:
1. Sắp xếp các bản ghi theo `firstname` sử dụng hàm `qsort()` của thư viện chuẩn C. Cần viết hàm callback so sánh phù hợp.
2. Sắp xếp các bản ghi theo `lastname` bằng cách viết hàm callback tương tự.
3. Viết một hàm `void apply(...)` duyệt qua các phần tử của mảng và gọi một hàm callback cho từng phần tử. Viết một hàm callback tên là `isolder()` để in ra bản ghi nếu tuổi lớn hơn 20, ngược lại không làm gì cả.

**Giải thuật tối ưu:**
* **Sắp xếp:** Sử dụng thuật toán **Quick Sort** (thông qua hàm `qsort` của thư viện `<stdlib.h>`). Đây là thuật toán sắp xếp tối ưu cho mảng với độ phức tạp thời gian trung bình là $O(N \log N)$ và độ phức tạp không gian là $O(\log N)$.
* **Duyệt và lọc (Filtering):** Thuật toán duyệt tuyến tính $O(N)$, kết hợp với con trỏ hàm để tăng tính đóng gói và linh hoạt (Strategy Pattern trong lập trình hướng cấu trúc).

---

## Problem 6.2: Hash Table with Chaining
**Yêu cầu đề bài:**
Cài đặt một bảng băm (Hash Table) sử dụng phương pháp nối chuỗi (chaining) bằng danh sách liên kết để lưu trữ và tra cứu tần suất xuất hiện của các từ trong một file. Bảng băm được biểu diễn dưới dạng mảng các danh sách liên kết (array of linked lists). Yêu cầu thực hiện:
1. Viết hàm `lookup()` trả về con trỏ đến bản ghi chứa chuỗi được yêu cầu. Nếu không tìm thấy, trả về `NULL`, hoặc tạo một bản ghi mới tại vị trí chuẩn xác trên bảng băm.
2. Hoàn thiện hàm `cleartable()` để thu hồi bộ nhớ. Đảm bảo mỗi lệnh `malloc()` phải đi kèm với một lệnh `free()`.

**Giải thuật tối ưu:**
* **Tra cứu & Cập nhật (Lookup & Insert):** Cấu trúc dữ liệu **Hash Table với Separate Chaining**. Thời gian tra cứu và chèn phần tử trung bình là $O(1)$, trong trường hợp xấu nhất (xung đột toàn bộ) là $O(N)$.
* **Hàm băm (Hash Function):** Mã nguồn sử dụng thuật toán băm chuỗi đa thức (Polynomial rolling hash) đơn giản để phân phối đều các chuỗi vào các bucket.
* **Giải phóng bộ nhớ:** Duyệt mảng độ phức tạp $O(M)$ (M là kích thước bảng) và duyệt giải phóng các node danh sách liên kết $O(N)$, tổng chi phí thời gian dọn dẹp là $O(N + M)$.