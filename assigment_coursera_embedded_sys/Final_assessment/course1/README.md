# Final Assessment - Course 1

## Mục tiêu bài

Bài `Final_assessment/course1` là bài tổng hợp cuối khóa.

Mục tiêu chính:

- Hoàn thiện các hàm xử lý memory.
- Hoàn thiện các hàm xử lý data conversion.
- Tích hợp lại phần thống kê.
- Build bằng Makefile.
- Chạy test suite trên `HOST`.
- Build được target `MSP432`.

## Chức năng chính

Bài final kiểm tra các nhóm chức năng:

- Data conversion.
- Memory move.
- Memory copy.
- Memory set.
- Reverse memory.
- Statistics.

Các test thường gồm:

```text
test_data1()
test_data2()
test_memmove1()
test_memmove2()
test_memmove3()
test_memcopy()
test_memset()
test_reverse()
```

## Cấu trúc thư mục

```text
Final_assessment/
└── course1/
    ├── Makefile
    ├── sources.mk
    ├── src/
    │   ├── main.c
    │   ├── memory.c
    │   ├── stats.c
    │   ├── course1.c
    │   ├── data.c
    │   ├── startup_msp432p401r_gcc.c
    │   ├── system_msp432p401r.c
    │   └── interrupts_msp432p401r_gcc.c
    └── README.md
```

Ngoài ra, khi build `MSP432`, Makefile cần linker script:

```text
Final_assessment/msp432p401r.lds
```

Nếu file này chưa có, có thể copy từ `C1M3`.

## Platform hỗ trợ

### HOST

Build native cho Ubuntu x86_64.

Có thể chạy trực tiếp:

```bash
./course1.out
```

### MSP432

Build cho ARM Cortex-M4/MSP432.

Không chạy trực tiếp trên Ubuntu x86_64.

Chỉ kiểm tra bằng:

```bash
file course1.out
arm-none-eabi-size course1.out
```

## Build HOST

Từ thư mục `Final_assessment/course1`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/Final_assessment/course1

make clean
rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm

make build PLATFORM=HOST
```

## Chạy test HOST

```bash
./course1.out
```

Kết quả mong đợi:

```text
test_data1();
test_data2():
test_memmove1() - NO OVERLAP
test_memmove2() -OVERLAP END OF SRC BEGINNING OF DST
test_memmove3() - OVERLAP END OF DEST BEGINNING OF SRC
test_memcopy()
test_memset()
test_reverse()
--------------------------------
Test Results:
  PASSED: 8 / 8
  FAILED: 0 / 8
--------------------------------
```

Nếu thấy:

```text
PASSED: 8 / 8
FAILED: 0 / 8
```

thì phần HOST đã chạy thành công.

## Build HOST với verbose

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/Final_assessment/course1

rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm

make build PLATFORM=HOST VERBOSE=ENABLE
./course1.out
```

Lưu ý:

```text
VERBOSE=ENABLE
```

không phải:

```text
VERBOSE=ENABLED
```

## Chuẩn bị build MSP432

### Bước 1: copy linker script

Từ thư mục `Assignments`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

cp C1M3/msp432p401r.lds Final_assessment/msp432p401r.lds
```

Kiểm tra:

```bash
ls -l Final_assessment/msp432p401r.lds
```

Kết quả mong đợi có file:

```text
Final_assessment/msp432p401r.lds
```

### Bước 2: thêm fix cho interrupt file

Với Ubuntu 24.04 hoặc `arm-none-eabi-gcc` phiên bản mới, cần thêm `-mgeneral-regs-only` riêng cho file interrupt.

Từ thư mục `Assignments`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

sed -i 's/ -mgeneral-regs-only//g' Final_assessment/course1/Makefile

grep -q '^src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only' Final_assessment/course1/Makefile || \
cat >> Final_assessment/course1/Makefile <<'PATCH_EOF'

# Fix for newer arm-none-eabi-gcc: interrupt handlers must not use FP registers
src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
PATCH_EOF
```

Kiểm tra:

```bash
grep -n "mgeneral-regs-only" Final_assessment/course1/Makefile
```

Kết quả mong đợi:

```text
src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
```

## Build MSP432

Từ thư mục `Final_assessment/course1`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/Final_assessment/course1

rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm

make build PLATFORM=MSP432
```

## Kiểm tra output MSP432

```bash
file course1.out
arm-none-eabi-size course1.out
ls -lh course1.out course1.map course1.asm
```

Kết quả mong đợi:

```text
course1.out: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, with debug_info, not stripped
```

Ví dụ size table:

```text
text    data    bss     dec     hex     filename
9160    1356    808     11324   2c3c    course1.out
```

## Các file được sinh ra

Sau khi build, có thể có:

```text
course1.out
course1.map
course1.asm
src/*.o
src/*.d
```

| File | Ý nghĩa |
|---|---|
| `course1.out` | Executable/binary output |
| `course1.map` | Linker map |
| `course1.asm` | Assembly dump |
| `src/*.o` | Object files |
| `src/*.d` | Dependency files |

## Dọn build

```bash
make clean
rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm
```

Lý do dùng thêm `rm -f src/*.o ...`:

- Makefile có thể sinh object file trong thư mục `src/`.
- Khi đổi qua lại giữa `HOST` và `MSP432`, object cũ có thể gây lỗi link.
- Dọn kỹ giúp build sạch hơn.

## Lỗi thường gặp

### Lỗi thiếu linker script

```text
cannot open linker script file ../msp432p401r.lds: No such file or directory
```

Nguyên nhân:

Makefile đang tìm file:

```text
Final_assessment/msp432p401r.lds
```

nhưng file này chưa tồn tại.

Cách sửa:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

cp C1M3/msp432p401r.lds Final_assessment/msp432p401r.lds
```

### Lỗi `FP registers might be clobbered`

```text
error: FP registers might be clobbered despite 'interrupt' attribute: compile with '-mgeneral-regs-only'
```

Nguyên nhân:

- Compiler ARM mới cảnh báo interrupt handler không nên dùng FP registers.
- Makefile bật `-Werror`, nên warning thành error.

Cách sửa:

```makefile
src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
```

Không thêm flag này global cho toàn project.

### Lỗi `argument of type 'float' not permitted with '-mgeneral-regs-only'`

```text
argument of type 'float' not permitted with '-mgeneral-regs-only'
```

Nguyên nhân:

- Đã thêm `-mgeneral-regs-only` cho toàn bộ project.
- File `system_msp432p401r.c` có dùng `float`.

Cách sửa:

```bash
sed -i 's/ -mgeneral-regs-only//g' Makefile
```

Sau đó chỉ thêm lại flag này riêng cho:

```text
src/interrupts_msp432p401r_gcc.o
```

### Warning `_close`, `_read`, `_write`, `_lseek`

Ví dụ:

```text
warning: _close is not implemented and will always fail
warning: _lseek is not implemented and will always fail
warning: _read is not implemented and will always fail
warning: _write is not implemented and will always fail
```

Đây là warning thường gặp khi build bare-metal với `nosys.specs`.

Nếu vẫn tạo được `course1.out`, `course1.map`, `course1.asm` và `arm-none-eabi-size course1.out` chạy được thì build thành công.

## Kết quả kiểm thử

| Platform | Kết quả |
|---|---|
| `HOST` | Build thành công, chạy test `PASSED: 8 / 8` |
| `MSP432` | Build thành công, tạo `course1.out` ARM |

## Kết luận

Bài Final hoàn thành khi:

- `HOST` build thành công.
- `./course1.out` chạy và pass toàn bộ test.
- `MSP432` build thành công.
- `course1.out` là ARM ELF binary.
- `course1.map` và `course1.asm` được tạo.

Không chạy trực tiếp file MSP432 trên Ubuntu x86_64.

---

## Liên hệ với Course Notes/Lecture

Bài Final là bài tổng hợp, liên quan đến cả 3 nhóm Course Notes:

| Course Notes/Lecture | Vai trò trong Final |
|---|---|
| `1- Embedded System Development Components` | Làm việc trên Ubuntu CLI, coding style, C programming, Git/repo workflow. |
| `2- Compilation with GCC and GNU Make` | Build bằng Makefile, build `HOST`, cross compile `MSP432`, sinh `.o`, `.d`, `.asm`, `.map`, `.out`. |
| `3- Memory Types, Segments and Management` | Viết và kiểm tra các hàm thao tác memory; hiểu memory layout, linker script, map file và ARM binary. |

Link tham khảo:

```text
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/1-%20Embedded%20System%20Development%20Components
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/2-%20Compilation%20with%20GCC%20and%20GNU%20Make
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/3-%20Memory%20Types%2C%20Segments%20and%20Management
```

### Phần kiến thức tương ứng

| Nội dung trong Course Notes | Áp dụng trong Final |
|---|---|
| C programming và coding standard | Hoàn thiện các file `memory.c`, `data.c`, `stats.c`, `course1.c`. |
| CLI development environment | Build/run/test bằng terminal trên Ubuntu. |
| GCC và Make | Dùng `make build PLATFORM=HOST`, `make build PLATFORM=MSP432`. |
| Native vs cross compilation | HOST chạy được trên Ubuntu; MSP432 chỉ tạo ARM ELF binary. |
| Linker và linker script | MSP432 build cần `msp432p401r.lds`. |
| GNU binutils | Dùng `file`, `size`, `objdump`, map/asm output để kiểm tra kết quả build. |
| Memory segments | Hiểu code/data/bss và memory placement của chương trình final. |
| Memory management | Cài đặt/test `memmove`, `memcopy`, `memset`, `reverse`, data conversion. |

### Tóm tắt kiến thức cần nắm

- Final không chỉ là bài C thuần, mà là bài tích hợp toàn bộ workflow của course.
- Phần `HOST` dùng để chạy test suite và xác nhận logic đúng.
- Phần `MSP432` dùng để xác nhận code có thể cross compile cho target embedded.
- Output quan trọng gồm `course1.out`, `course1.map`, `course1.asm`.
- Nếu `HOST` pass `8/8` và `MSP432` tạo được ARM ELF binary thì assignment đạt mục tiêu build/run/check.
