# Coursera - Introduction to Embedded Systems Software and Development Environments

## Giới thiệu

Repository này chứa các bài thực hành của khóa học **Introduction to Embedded Systems Software and Development Environments**. Tài liệu này tập trung vào phần `Assignments` và mục tiêu là giúp build/chạy thành công trên Ubuntu.

Các bài build trên `HOST` có thể chạy trực tiếp trên Ubuntu. Các bài build cho `MSP432` tạo binary ARM bare-metal, vì vậy không chạy trực tiếp bằng `./file.out` trên máy Ubuntu x86_64.

## Cấu trúc phần Assignments

```text
Assignments/
├── C1M1
├── C1M2
├── C1M3
└── Final_assessment/
    └── course1
```

| Thư mục | Nội dung chính |
|---|---|
| `C1M1` | Bài thống kê mảng bằng C |
| `C1M2` | Bài Makefile/build system cho HOST và MSP432 |
| `C1M3` | Bài phân tích memory, linker map, symbol và assembly |
| `Final_assessment/course1` | Bài final về memory functions, data conversion, stats và test suite |

## Môi trường đã kiểm thử

```text
Ubuntu 24.04.3 LTS
x86_64
gcc 13.3.0
GNU Make 4.3
GNU Binutils 2.42
arm-none-eabi-gcc 13.2.1
```

## Công cụ cần có

Native build tools:

```text
git
gcc
make
ld
objdump
nm
size
```

ARM/MSP432 cross toolchain:

```text
arm-none-eabi-gcc
arm-none-eabi-ld
arm-none-eabi-objdump
arm-none-eabi-nm
arm-none-eabi-size
```

Package thường cần trên Ubuntu:

```bash
sudo apt update
sudo apt install build-essential gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi
```

## Kiểm tra toolchain

```bash
echo "== OS =="
lsb_release -a 2>/dev/null || cat /etc/os-release
uname -m

echo
echo "== Native build tools =="
for t in git gcc make ld objdump nm size; do
  if command -v "$t" >/dev/null 2>&1; then
    echo "[OK] $t -> $(command -v "$t")"
  else
    echo "[MISSING] $t"
  fi
done

echo
echo "== ARM MSP432 cross toolchain =="
for t in arm-none-eabi-gcc arm-none-eabi-ld arm-none-eabi-objdump arm-none-eabi-nm arm-none-eabi-size; do
  if command -v "$t" >/dev/null 2>&1; then
    echo "[OK] $t -> $(command -v "$t")"
  else
    echo "[MISSING] $t"
  fi
done

echo
echo "== ARM specs check =="
if command -v arm-none-eabi-gcc >/dev/null 2>&1; then
  arm-none-eabi-gcc --version | head -n 1
  echo "nosys.specs: $(arm-none-eabi-gcc -print-file-name=nosys.specs)"
  echo "nano.specs:  $(arm-none-eabi-gcc -print-file-name=nano.specs)"
else
  echo "arm-none-eabi-gcc chưa có, bỏ qua specs check"
fi
```

## Clone repository

```bash
cd ~
git clone --depth 1 https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments.git
cd Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments
ls
```

Kết quả mong đợi:

```text
C1M1  C1M2  C1M3  Final_assessment
```

## Build nhanh từng bài

### C1M1

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M1

gcc -std=c99 stats.c -o stats.out
./stats.out
```

### C1M2 HOST

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M2/src

make clean
make build PLATFORM=HOST
./c1m2.out
```

### C1M2 MSP432

Trên Ubuntu 24.04 hoặc `arm-none-eabi-gcc` mới, cần thêm flag riêng cho file interrupt:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

sed -i 's/ -mgeneral-regs-only//g' C1M2/src/Makefile

grep -q '^interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only' C1M2/src/Makefile || \
cat >> C1M2/src/Makefile <<'PATCH_EOF'

# Fix for newer arm-none-eabi-gcc: interrupt handlers must not use FP registers
interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
PATCH_EOF
```

Build:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M2/src

make clean
make build PLATFORM=MSP432
file c1m2.out
arm-none-eabi-size c1m2.out
```

Kết quả mong đợi:

```text
c1m2.out: ELF 32-bit LSB executable, ARM
```

### C1M3 MSP432

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M3/src

make clean
make build
file c1m3.out
arm-none-eabi-size c1m3.out
arm-none-eabi-nm c1m3.out | head
```

Kết quả mong đợi:

```text
c1m3.out: ELF 32-bit LSB executable, ARM
```

### Final HOST

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/Final_assessment/course1

make clean
rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm

make build PLATFORM=HOST
./course1.out
```

Kết quả mong đợi:

```text
PASSED: 8 / 8
FAILED: 0 / 8
```

### Final MSP432

Final cần linker script `msp432p401r.lds`. Nếu thiếu, copy từ `C1M3`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

cp C1M3/msp432p401r.lds Final_assessment/msp432p401r.lds
```

Thêm fix cho file interrupt:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

sed -i 's/ -mgeneral-regs-only//g' Final_assessment/course1/Makefile

grep -q '^src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only' Final_assessment/course1/Makefile || \
cat >> Final_assessment/course1/Makefile <<'PATCH_EOF'

# Fix for newer arm-none-eabi-gcc: interrupt handlers must not use FP registers
src/interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
PATCH_EOF
```

Build:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/Final_assessment/course1

rm -f src/*.o src/*.d src/*.i src/*.asm *.map *.out *.asm

make build PLATFORM=MSP432
file course1.out
arm-none-eabi-size course1.out
```

Kết quả mong đợi:

```text
course1.out: ELF 32-bit LSB executable, ARM
```

## HOST và MSP432 khác nhau thế nào?

`HOST` là build native cho Ubuntu x86_64, có thể chạy trực tiếp bằng `./file.out`.

`MSP432` là build cho ARM Cortex-M4/MSP432, không chạy trực tiếp trên Ubuntu. Chỉ cần kiểm tra binary bằng:

```bash
file file_name.out
arm-none-eabi-size file_name.out
```

## Lỗi thường gặp

### `FP registers might be clobbered`

```text
error: FP registers might be clobbered despite 'interrupt' attribute: compile with '-mgeneral-regs-only'
```

Cách xử lý: chỉ thêm `-mgeneral-regs-only` cho file `interrupts_msp432p401r_gcc.c`. Không thêm global cho toàn project vì `system_msp432p401r.c` có dùng `float`.

### `argument of type 'float' not permitted with '-mgeneral-regs-only'`

Lỗi này xảy ra khi thêm `-mgeneral-regs-only` quá rộng. Gỡ khỏi global:

```bash
sed -i 's/ -mgeneral-regs-only//g' Makefile
```

Sau đó chỉ thêm riêng cho object file interrupt.

### Thiếu linker script ở Final

```text
cannot open linker script file ../msp432p401r.lds: No such file or directory
```

Cách xử lý:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments
cp C1M3/msp432p401r.lds Final_assessment/msp432p401r.lds
```

### Warning `_close`, `_read`, `_write`, `_lseek`

Các warning này thường gặp khi build bare-metal với `nosys.specs`. Nếu vẫn tạo được `.out`, `.map`, `.asm` và `arm-none-eabi-size` chạy được thì build đã thành công.

## Trạng thái kiểm thử

| Assignment | HOST | MSP432 |
|---|---|---|
| `C1M1` | Thành công | Không áp dụng |
| `C1M2` | Thành công | Thành công |
| `C1M3` | Không áp dụng | Thành công |
| `Final_assessment/course1` | Thành công, test 8/8 | Thành công |

## Kết luận

Sau khi cài đủ toolchain và áp dụng các ghi chú cho Ubuntu 24.04, toàn bộ phần `Assignments` có thể build thành công. Các bài `HOST` chạy trực tiếp trên Ubuntu, còn các bài `MSP432` chỉ cần kiểm tra bằng `file` và `arm-none-eabi-size`.

---

## Liên hệ Assignment với Course Notes/Lecture

Trong thư mục `Course Notes` của repository có 3 nhóm lecture chính:

| Course Notes/Lecture | Nội dung kiến thức chính | Assignment liên quan |
|---|---|---|
| `1- Embedded System Development Components` | SCM, Git version control, coding standard, development environment, CLI, GCC cơ bản, chạy chương trình từ command line | `C1M1` |
| `2- Compilation with GCC and GNU Make` | GCC toolchain, native vs cross compilation, preprocessor, compiler, assembler, linker/locator, Make/Makefile, `.i`, `.asm`, `.o`, `.d`, `.map`, `.out`, GNU binutils | `C1M2`, một phần `C1M3`, một phần Final |
| `3- Memory Types, Segments and Management` | Memory organization, memory architecture, `.text`, `.data`, `.bss`, stack, heap, code/data memory, linker script, map file, symbol allocation, memory usage bằng GCC binutils | `C1M3`, phần lớn Final |

Nguồn Course Notes:

- Week 1: https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/1-%20Embedded%20System%20Development%20Components
- Week 2: https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/2-%20Compilation%20with%20GCC%20and%20GNU%20Make
- Week 3: https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/3-%20Memory%20Types%2C%20Segments%20and%20Management

### Mapping nhanh

| Assignment | Lecture tương ứng | Vì sao liên quan |
|---|---|---|
| `C1M1` | Week 1 - Embedded System Development Components | Bài này dùng C cơ bản, coding style, command line, GCC và chạy executable trên host. Week 1 cũng nêu mục tiêu viết assignment thống kê và compile bằng GCC. |
| `C1M2` | Week 2 - Compilation with GCC and GNU Make | Bài này chính là phần build system: dùng GNU Make, GCC, preprocessor, dependency, object, assembly, map, executable và cross compile cho MSP432. |
| `C1M3` | Week 3 - Memory Types, Segments and Management | Bài này tập trung phân tích memory layout, linker map, symbol, `.text`, `.data`, `.bss`, stack/heap và dùng `nm`, `objdump`, `size`. |
| `Final_assessment/course1` | Tổng hợp Week 1 + Week 2 + Week 3 | Final dùng lại C coding, build system, HOST/MSP432 cross compile, linker script, map/asm output và các hàm thao tác memory. |
