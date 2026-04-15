# Assignment 7: Data Structures & Library Management in C

## 📝 Giới thiệu (Introduction)
Dự án này tổng hợp các bài thực hành về cấu trúc dữ liệu nâng cao và kỹ thuật tổ chức mã nguồn chuyên nghiệp trong ngôn ngữ C. Nội dung bao gồm Bảng băm (Hash Table), Thư viện tĩnh/động (Libraries), và Hàng đợi ưu tiên (Priority Queue).

---

## 🛠 Bài tập 1: Hash Table với cơ chế Chaining (Xử lý xung đột)

### 1. Tóm lược bài toán (Problem Summary)
Xây dựng hệ thống quản lý danh bạ điện thoại hỗ trợ các thao tác cơ bản:
- **Insert**: Thêm liên hệ mới.
- **Search**: Tìm kiếm theo tên với tốc độ nhanh.
- **Delete**: Xóa liên hệ khỏi hệ thống.

### 2. Phương pháp và Giải thuật (Methods & Algorithms)
- [cite_start]**Cấu trúc dữ liệu**: Sử dụng **Hash Table** kết hợp với **Chaining** (Sử dụng danh sách liên kết đơn tại mỗi bucket để xử lý xung đột băm). [cite: 8, 9]
- [cite_start]**Hàm băm (Hash Function)**: Sử dụng công thức đa thức (Polynomial Rolling Hash) với hệ số 31 để tối ưu hóa việc phân phối dữ liệu. [cite: 13]
- **Độ phức tạp**: Thao tác tìm kiếm trung bình đạt **O(1)**.

---

## 📚 Bài tập 2: Tổ chức Thư viện (Static & Dynamic Libraries)

### 1. Tóm lược bài toán (Problem Summary)
[cite_start]Tổ chức lại mã nguồn của Bài tập 1 thành một thư viện chuyên nghiệp để có thể tái sử dụng trong các dự án khác. [cite: 30]

### 2. Cấu trúc thư viện
- [cite_start]`hashtable.h`: Tệp tiêu đề (Header file) chứa khai báo kiểu dữ liệu và nguyên mẫu hàm. [cite: 33]
- [cite_start]`hashtable.c`: Tệp nguồn (Source file) chứa logic cài đặt chi tiết. [cite: 34]
- [cite_start]`main.c`: Chương trình kiểm thử (Testing). [cite: 35]

### 3. Quy trình biên dịch (Compilation)
- [cite_start]**Thư viện tĩnh (Static Library - .a)**: Mã thư viện được đóng gói trực tiếp vào tệp thực thi. [cite: 43, 44]
- [cite_start]**Thư viện động (Dynamic Library - .so)**: Thư viện được nạp vào bộ nhớ khi chương trình chạy (Runtime), giúp tiết kiệm dung lượng. [cite: 48, 49]

---

## 🏥 Bài tập 3: Priority Queue với Binary Heap (Hàng đợi ưu tiên)

### 1. Tóm lược bài toán (Problem Summary)
Mô phỏng hệ thống hàng đợi khám bệnh tại bệnh viện. [cite_start]Bệnh nhân có mức độ cấp cứu cao hơn (Priority lớn hơn) sẽ được ưu tiên khám trước. [cite: 57, 61]

### 2. Phương pháp và Giải thuật (Methods & Algorithms)
- [cite_start]**Cấu trúc dữ liệu**: Sử dụng **Max-Heap** biểu diễn bằng mảng để quản lý mức độ ưu tiên. [cite: 59, 60]
- **Thao tác chính**:
    - [cite_start]**Push**: Thêm bệnh nhân và thực hiện **Heapify-up** (Đẩy phần tử lên). [cite: 63]
    - [cite_start]**Pop**: Lấy bệnh nhân ưu tiên nhất ra và thực hiện **Heapify-down** (Đẩy phần tử xuống). [cite: 64]
    - [cite_start]**Peek**: Xem bệnh nhân ở đầu hàng đợi mà không xóa. [cite: 65]
- **Độ phức tạp**: Các thao tác thêm/xóa đạt hiệu suất **O(log n)**.

---

## 📖 Từ điển thuật ngữ (Glossary)
- **Chaining** (Chuỗi liên kết): Kỹ thuật dùng danh sách liên kết để giải quyết xung đột khi hai khóa có cùng giá trị băm.
- **Collision** (Xung đột băm): Hiện tượng hai đầu vào khác nhau tạo ra cùng một chỉ số trong bảng băm.
- **Binary Heap** (Đống nhị phân): Một cây nhị phân gần như hoàn chỉnh dùng để triển khai hàng đợi ưu tiên.
- **Static Linking** (Liên kết tĩnh): Quá trình sao chép mã thư viện vào file thực thi cuối cùng.
- **Dynamic Linking** (Liên kết động): Quá trình tham chiếu đến thư viện khi chương trình đang chạy.
- **Memory Management** (Quản lý bộ nhớ): Sử dụng `malloc` và `free` để kiểm soát bộ nhớ động, tránh rò rỉ (Memory Leak).

---
[cite_start]*Dự án được thực hiện theo yêu cầu của Assignment 7 - Thực hành Lecture 8 & 9.* [cite: 1]