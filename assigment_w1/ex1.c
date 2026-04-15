--- Exercise 1 ---
Cau lenh: double ans = 18.0 / squared(2+1);

1. #define squared(x) x*x
   Phan trien: 18.0 / 2 + 1 * 2 + 1 = 9.0 + 2 + 1 = 12.0
   Gia tri ans: 12.0

2. #define squared(x) (x*x)
   Phan trien: 18.0 / (2 + 1 * 2 + 1) = 18.0 / 5 = 3.6
   Gia tri ans: 3.6

3. #define squared(x) (x)*(x)
   Phan trien: 18.0 / (2 + 1) * (2 + 1) = 18.0 / 3 * 3 = 6.0 * 3 = 18.0
   Gia tri ans: 18.0

4. #define squared(x) ((x)*(x))
   Phan trien: 18.0 / ((2 + 1) * (2 + 1)) = 18.0 / 9 = 2.0
   Gia tri ans: 2.0 (Day la cach viet dung nhat)

--- Exercise 2 ---
(a) #include <stdio.h> ;
    Loi: Du dau cham phay (;) o cuoi dong directive.
    Sua: #include <stdio.h>

(b) int function(void arg1) { return arg1-1; }
    Loi: Kieu 'void' khong the dung lam kieu du lieu cho mot tham so co ten.
    Sua: int function(int arg1) { return arg1-1; }

(c) #define MESSAGE = "Happy new year!"
    puts (MESSAGE);
    Loi: Macro khong dung dau bang (=). Neu dung =, MESSAGE se duoc thay bang '= "Happy new year!"'.
    Sua: #define MESSAGE "Happy new year!"