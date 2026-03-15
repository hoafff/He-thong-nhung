Exercise 1: Case Converter via argv[0]
Yêu cầu: Chương trình tự động chuyển chữ hoa thành thường hoặc ngược lại dựa vào tên file thực thi khi chạy.

Logic: Kiểm tra chuỗi argv[0]. Nếu tên file chứa "lower", dùng tolower(). Nếu chứa "upper", dùng toupper().

Cách chạy: Bạn có thể compile thành 2 file khác nhau hoặc dùng symbolic link.

Exercise 2: File Comparison
Yêu cầu: So sánh hai file và in ra dòng đầu tiên có sự khác biệt.

Logic: Sử dụng fgets() để đọc từng dòng từ cả hai file cùng lúc. Dùng strcmp() để so sánh. Nếu khác nhau, in ra dòng đó và thoát.

Exercise 3: File Printer with Pagination
Yêu cầu: In danh sách các file, mỗi file bắt đầu ở trang mới, có tiêu đề và số trang riêng.

Logic: Duyệt qua danh sách file từ argv. Với mỗi file, in Header (Tên file, số trang). Đếm số dòng đã in, nếu vượt quá giới hạn trang (thường là 50-60 dòng), thực hiện ngắt trang và tăng số trang.