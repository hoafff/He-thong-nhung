#include <stdio.h> 

/* (a) Loi: Du dau ';' sau include [cite: 9]
 (b) Loi: Kieu 'void' khong dung cho tham so co ten [cite: 10]
 (c) Loi: Macro khong dung dau '=' [cite: 11]
*/

#define MESSAGE "Happy new year!" // Fix (c) [cite: 11]

int function(int arg1) { // Fix (b): doi void thanh int [cite: 10]
    return arg1 - 1;
}

int main() {
    puts(MESSAGE); // Fix (c) [cite: 12]
    return 0;
}