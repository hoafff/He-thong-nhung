# C1M1 - Statistics Assignment

## Mục tiêu bài

Bài `C1M1` yêu cầu viết chương trình C để xử lý một mảng dữ liệu kiểu `unsigned char`.

Các chức năng chính:

- In mảng ban đầu.
- Sắp xếp mảng theo thứ tự giảm dần.
- Tìm giá trị nhỏ nhất.
- Tìm giá trị lớn nhất.
- Tính giá trị trung bình.
- Tính giá trị trung vị.
- In kết quả thống kê.

## File chính

```text
C1M1/
├── stats.c
└── stats.h
```

| File | Chức năng |
|---|---|
| `stats.c` | Chứa chương trình chính và implementation các hàm thống kê |
| `stats.h` | Khai báo prototype các hàm |

## Các hàm quan trọng

Bài này thường bao gồm các hàm:

```c
print_statistics()
print_array()
find_median()
find_mean()
find_maximum()
find_minimum()
sort_array()
```

| Hàm | Mục đích |
|---|---|
| `print_statistics()` | In min, max, mean, median |
| `print_array()` | In nội dung mảng |
| `find_median()` | Tìm median |
| `find_mean()` | Tính mean |
| `find_maximum()` | Tìm phần tử lớn nhất |
| `find_minimum()` | Tìm phần tử nhỏ nhất |
| `sort_array()` | Sắp xếp mảng từ lớn đến nhỏ |

## Build trên Ubuntu

Từ thư mục `C1M1`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M1

gcc -std=c99 stats.c -o stats.out
```

## Chạy chương trình

```bash
./stats.out
```

## Kết quả mong đợi

Chương trình sẽ in:

- Mảng trước khi sắp xếp.
- Mảng sau khi sắp xếp.
- Minimum.
- Maximum.
- Mean.
- Median.

Ví dụ kết quả chính:

```text
The minimum is: 2
The maximum is: 250
The mean is: 93
The median is: 87
```

## Kiểm tra file output

```bash
ls -lh stats.out
file stats.out
```

Kết quả `file` mong đợi là executable cho Linux x86_64, ví dụ:

```text
stats.out: ELF 64-bit LSB executable, x86-64
```

## Dọn file build

```bash
rm -f stats.out
```

## Ghi chú

Bài này chạy trực tiếp trên Ubuntu bằng `gcc`.

Không cần `Makefile`.

Không cần ARM toolchain.

Không cần build cho MSP432.

---

## Liên hệ với Course Notes/Lecture

Assignment này liên quan trực tiếp nhất tới:

```text
Course Notes/1- Embedded System Development Components
```

Link tham khảo:

```text
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/1-%20Embedded%20System%20Development%20Components
```

### Phần kiến thức tương ứng

| Nội dung trong Course Notes | Áp dụng trong C1M1 |
|---|---|
| `C Standardization and Team Coding Standards` | Viết code C rõ ràng, chia prototype trong `.h`, implementation trong `.c`, dùng chuẩn `-std=c99`. |
| `Development Environments Overview` | Làm việc bằng command line trên Ubuntu: `cd`, `ls`, `gcc`, chạy executable. |
| `Version Control` | Clone repo, quản lý source bằng Git. |
| `Perform Compilation with GCC and execute output files from the command line` | Biên dịch `stats.c` bằng `gcc` và chạy `./stats.out`. |
| Bài tập thống kê đơn giản | C1M1 chính là bài in thống kê mảng: min, max, mean, median, sort array. |

### Tóm tắt kiến thức cần nắm

- Biết cấu trúc một chương trình C cơ bản.
- Biết khai báo hàm trong header file.
- Biết compile một file C bằng `gcc`.
- Biết chạy executable trên Ubuntu.
- Biết kiểm tra output chương trình từ terminal.

C1M1 chưa cần Makefile và chưa cần ARM toolchain. Đây là bài khởi động để làm quen với môi trường phát triển embedded software trên host machine.
