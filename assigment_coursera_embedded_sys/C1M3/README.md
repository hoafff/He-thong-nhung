# C1M3 - Memory Analysis Assignment

## Mục tiêu bài

Bài `C1M3` tập trung vào phân tích memory trong embedded system.

Mục tiêu chính:

- Biên dịch chương trình cho MSP432.
- Tạo file output ARM.
- Tạo linker map.
- Tạo assembly dump.
- Dùng các công cụ như `nm`, `objdump`, `size` để phân tích symbol và memory layout.
- Hiểu các vùng nhớ như `.text`, `.data`, `.bss`, stack, heap và peripheral/register region.

## Cấu trúc thư mục

```text
C1M3/
├── include/
│   └── ...
├── src/
│   ├── Makefile
│   ├── main.c
│   └── misc.c
└── msp432p401r.lds
```

## Platform

Bài này build cho `MSP432`.

Không chạy trực tiếp trên Ubuntu x86_64.

Chỉ cần build thành công và kiểm tra output.

## Build MSP432

Từ thư mục `C1M3/src`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M3/src

make clean
make build
```

## Kiểm tra output

```bash
file c1m3.out
arm-none-eabi-size c1m3.out
arm-none-eabi-nm c1m3.out | head
```

Kết quả mong đợi:

```text
c1m3.out: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, with debug_info, not stripped
```

Ví dụ size table:

```text
text    data    bss     dec     hex     filename
5088    1396    820     7304    1c88    c1m3.out
```

## Các file được sinh ra

Sau khi build thành công, thư mục `src` có thể có:

```text
c1m3.out
c1m3.map
c1m3.asm
main.o
misc.o
main.d
misc.d
```

| File | Ý nghĩa |
|---|---|
| `c1m3.out` | ELF binary cho ARM/MSP432 |
| `c1m3.map` | Linker map, dùng để xem symbol nằm ở vùng nhớ nào |
| `c1m3.asm` | Assembly dump |
| `.o` | Object file |
| `.d` | Dependency file |

## Phân tích bằng `size`

```bash
arm-none-eabi-size c1m3.out
```

Lệnh này cho biết kích thước các vùng:

```text
text
data
bss
```

| Cột | Ý nghĩa |
|---|---|
| `text` | Code và hằng số read-only |
| `data` | Biến global/static đã khởi tạo |
| `bss` | Biến global/static chưa khởi tạo |
| `dec` | Tổng kích thước dạng decimal |
| `hex` | Tổng kích thước dạng hexadecimal |

## Phân tích symbol bằng `nm`

```bash
arm-none-eabi-nm c1m3.out | head
```

Có thể xem toàn bộ symbol:

```bash
arm-none-eabi-nm c1m3.out
```

Một số ký hiệu thường gặp:

| Ký hiệu | Ý nghĩa |
|---|---|
| `T` | Symbol nằm trong vùng text/code |
| `D` | Symbol nằm trong vùng data |
| `B` | Symbol nằm trong vùng bss |
| `R` | Read-only data |
| `N` | Debug symbol |
| `U` | Undefined symbol |

## Phân tích assembly bằng `objdump`

Makefile thường tự tạo file:

```text
c1m3.asm
```

Có thể tạo lại thủ công:

```bash
arm-none-eabi-objdump -D c1m3.out > c1m3.asm
```

Mở file:

```bash
less c1m3.asm
```

## Phân tích linker map

Mở file:

```bash
less c1m3.map
```

Có thể tìm symbol:

```bash
grep -n "symbol_name" c1m3.map
```

Ví dụ:

```bash
grep -n ".text" c1m3.map
grep -n ".data" c1m3.map
grep -n ".bss" c1m3.map
```

## Warning thường gặp

Khi link có thể thấy:

```text
warning: _close is not implemented and will always fail
warning: _lseek is not implemented and will always fail
warning: _read is not implemented and will always fail
warning: _write is not implemented and will always fail
```

Đây là warning do build bare-metal với `nosys.specs`.

Nếu vẫn tạo được `c1m3.out`, `c1m3.map`, `c1m3.asm` và `arm-none-eabi-size c1m3.out` chạy được thì build đã thành công.

## Dọn build

```bash
make clean
```

Nếu muốn dọn kỹ:

```bash
rm -f *.i *.d *.asm *.o *.map *.out
```

## Kết luận

Bài `C1M3` không cần chạy chương trình trên Ubuntu.

Mục tiêu chính là:

- Build thành công cho MSP432.
- Sinh được file `.out`, `.map`, `.asm`.
- Dùng `size`, `nm`, `objdump` để phân tích memory layout.

---

## Liên hệ với Course Notes/Lecture

Assignment này liên quan trực tiếp nhất tới:

```text
Course Notes/3- Memory Types, Segments and Management
```

Link tham khảo:

```text
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/3-%20Memory%20Types%2C%20Segments%20and%20Management
```

Một phần nhỏ cũng liên quan tới Week 2 vì vẫn dùng GCC toolchain, linker script, Makefile và GNU binutils.

### Phần kiến thức tương ứng

| Nội dung trong Course Notes | Áp dụng trong C1M3 |
|---|---|
| `Introduction to Memory Organization` | Hiểu memory là tài nguyên giới hạn trong embedded system. |
| `Memory Architectures` | Phân biệt flash, RAM, registers/peripherals và đặc điểm truy cập memory. |
| `Memory Segments` | Phân tích `.text`, `.data`, `.bss`, stack, heap. |
| `Data Memory` | Xem biến global/static/initialized/uninitialized nằm ở vùng nhớ nào. |
| `Special Keywords (Const, Extern, Static)` | Hiểu ảnh hưởng của `const`, `static`, `extern` tới symbol, lifetime, visibility và placement. |
| `The Stack` | Hiểu vùng stack dùng cho local variables, function calls, runtime state. |
| `The Heap` | Hiểu vùng heap và dynamic allocation nếu có. |
| `Code Memory` | Hiểu code/instructions thường nằm trong vùng `.text`/flash. |
| Linker script và map file | Dùng `msp432p401r.lds`, `c1m3.map` để xem memory layout. |
| GCC binary utilities | Dùng `arm-none-eabi-size`, `arm-none-eabi-nm`, `arm-none-eabi-objdump`. |

### Tóm tắt kiến thức cần nắm

- Biết đọc bảng `text/data/bss` từ `size`.
- Biết dùng `nm` để xem symbol nằm trong vùng nhớ nào.
- Biết dùng `.map` file để kiểm tra địa chỉ và placement của symbol.
- Biết dùng `.asm` file để xem assembly output.
- Hiểu linker script quyết định cách map section vào flash/RAM.

C1M3 là assignment chính của Week 3 vì trọng tâm là memory layout và phân tích output của quá trình link.
