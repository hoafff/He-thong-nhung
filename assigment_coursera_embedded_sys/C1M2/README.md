# C1M2 - Build System Assignment

## Mục tiêu bài

Bài `C1M2` tập trung vào việc xây dựng hệ thống build bằng `Makefile`.

Mục tiêu chính:

- Biên dịch source code C bằng GCC.
- Tạo object file `.o`.
- Tạo dependency file `.d`.
- Tạo assembly dump `.asm`.
- Tạo linker map `.map`.
- Link ra executable `.out`.
- Hỗ trợ build cho hai platform: `HOST` và `MSP432`.

## Cấu trúc thư mục

```text
C1M2/
├── include/
│   ├── CMSIS/
│   ├── common/
│   └── msp432/
├── src/
│   ├── Makefile
│   ├── main.c
│   ├── memory.c
│   ├── startup_msp432p401r_gcc.c
│   ├── system_msp432p401r.c
│   └── interrupts_msp432p401r_gcc.c
└── msp432p401r.lds
```

## Platform hỗ trợ

### HOST

Build native cho máy Ubuntu x86_64.

Có thể chạy trực tiếp:

```bash
./c1m2.out
```

### MSP432

Build cho ARM Cortex-M4/MSP432.

Không chạy trực tiếp trên Ubuntu.

Chỉ kiểm tra bằng:

```bash
file c1m2.out
arm-none-eabi-size c1m2.out
```

## Build HOST

Từ thư mục `C1M2/src`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M2/src

make clean
make build PLATFORM=HOST
```

## Chạy HOST

```bash
./c1m2.out
```

Kết quả sẽ in ra chuỗi test của chương trình, ví dụ:

```text
aXy72_L+R
```

## Kiểm tra output HOST

```bash
file c1m2.out
size c1m2.out
ls -lh c1m2.out c1m2.map c1m2.asm
```

Kết quả mong đợi:

- `c1m2.out` là executable x86_64.
- `c1m2.map` được tạo.
- `c1m2.asm` được tạo.

## Build MSP432

Với Ubuntu 24.04 hoặc `arm-none-eabi-gcc` phiên bản mới, cần sửa Makefile để tránh lỗi interrupt handler.

### Bước 1: thêm fix cho interrupt file

Từ thư mục `Assignments`:

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments

sed -i 's/ -mgeneral-regs-only//g' C1M2/src/Makefile

grep -q '^interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only' C1M2/src/Makefile || \
cat >> C1M2/src/Makefile <<'PATCH_EOF'

# Fix for newer arm-none-eabi-gcc: interrupt handlers must not use FP registers
interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
PATCH_EOF
```

### Bước 2: kiểm tra Makefile đã được sửa

```bash
grep -n "mgeneral-regs-only" C1M2/src/Makefile
```

Kết quả mong đợi:

```text
interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
```

### Bước 3: build MSP432

```bash
cd ~/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/Assignments/C1M2/src

make clean
make build PLATFORM=MSP432
```

## Kiểm tra output MSP432

```bash
file c1m2.out
arm-none-eabi-size c1m2.out
ls -lh c1m2.out c1m2.map c1m2.asm
```

Kết quả mong đợi:

```text
c1m2.out: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, with debug_info, not stripped
```

Ví dụ size table:

```text
text    data    bss     dec     hex     filename
6572    1360    820     8752    2230    c1m2.out
```

## Các file được sinh ra

Sau khi build, Makefile có thể tạo:

```text
*.o
*.d
*.asm
*.map
*.out
```

| File | Ý nghĩa |
|---|---|
| `.o` | Object file |
| `.d` | Dependency file |
| `.asm` | Assembly dump |
| `.map` | Linker map |
| `.out` | Executable/binary output |

## Dọn build

```bash
make clean
```

Nếu cần dọn kỹ hơn:

```bash
rm -f *.i *.d *.asm *.o *.map *.out
```

## Lỗi thường gặp

### Lỗi `FP registers might be clobbered`

```text
error: FP registers might be clobbered despite 'interrupt' attribute: compile with '-mgeneral-regs-only'
```

Nguyên nhân:

- Compiler ARM mới cảnh báo interrupt handler không nên dùng floating-point registers.
- Makefile dùng `-Werror`, khiến warning trở thành error.

Cách sửa:

```makefile
interrupts_msp432p401r_gcc.o: CFLAGS += -mgeneral-regs-only
```

Không thêm `-mgeneral-regs-only` cho toàn bộ project, vì `system_msp432p401r.c` có dùng `float`.

### Warning `_close`, `_read`, `_write`, `_lseek`

Khi build MSP432 có thể thấy:

```text
warning: _close is not implemented and will always fail
warning: _lseek is not implemented and will always fail
warning: _read is not implemented and will always fail
warning: _write is not implemented and will always fail
```

Đây là warning thường gặp khi dùng `nosys.specs` trong bare-metal build.

Nếu vẫn tạo được `c1m2.out`, `c1m2.map`, `c1m2.asm` thì build đã thành công.

## Kết luận

Bài `C1M2` đã build được cho cả `HOST` và `MSP432`.

`HOST` có thể chạy trực tiếp trên Ubuntu.

`MSP432` chỉ cần kiểm tra binary ARM bằng `file` và `arm-none-eabi-size`.

---

## Liên hệ với Course Notes/Lecture

Assignment này liên quan trực tiếp nhất tới:

```text
Course Notes/2- Compilation with GCC and GNU Make
```

Link tham khảo:

```text
https://github.com/renatosoriano/Coursera_Introduction-to-Embedded-Systems-Software-and-Development-Environments/tree/master/Course%20Notes/2-%20Compilation%20with%20GCC%20and%20GNU%20Make
```

### Phần kiến thức tương ứng

| Nội dung trong Course Notes | Áp dụng trong C1M2 |
|---|---|
| `Introduction to Build Systems Using GNU Toolsets` | Tạo build system bằng GNU Make và GCC. |
| `Compiling and Invoking GCC` | Dùng `gcc`/`arm-none-eabi-gcc` với các option như `-c`, `-Wall`, `-Werror`, `-std=c99`, `-DHOST`, `-DMSP432`. |
| `Preprocessor Directives` | Sinh file dependency `.d`, dùng macro `HOST` và `MSP432`. |
| `Creating Header and Implementation Files` | Dùng include path `../include/...` và tách source/header. |
| `Linkers` | Link object files thành `c1m2.out`, dùng linker script khi build MSP432. |
| `Make` và `Makefiles` | Dùng target `clean`, `build`, `PLATFORM=HOST`, `PLATFORM=MSP432`. |
| `Other Useful GNU Bin Tools` | Dùng `size`, `objdump`, `file`, tạo `.asm`, `.map`. |
| Native compilation vs Cross compilation | `HOST` là native build; `MSP432` là cross build cho ARM Cortex-M4. |

### Tóm tắt kiến thức cần nắm

- Hiểu pipeline build: preprocessor → compiler → assembler → linker/locator.
- Hiểu sự khác nhau giữa native compilation và cross compilation.
- Biết dùng Makefile để tự động hóa build.
- Biết các file sinh ra trong quá trình build: `.o`, `.d`, `.asm`, `.map`, `.out`.
- Biết vì sao binary MSP432 không chạy trực tiếp trên Ubuntu x86_64.

C1M2 là assignment chính của Week 2 vì nó yêu cầu viết/sử dụng build system để build cho cả host và target platform.
