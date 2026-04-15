#include <stdio.h>

/*
 - Loi 1: Ten bien '2nd value' bat dau bang so [cite: 27]
 - Loi 2: 'alliszero' gan bang (x=1) se luon true, y viet hoa/thuong k dong nhat [cite: 28]
 - Loi 3: 'z=z-->x' thieu dau ngoac, de gay nham lan [cite: 29]
 - Loi 4: 'x&MASK==MASK' sai do uu tien [cite: 30, 31]
*/

int main() {
    int second_value = 10; // Fix [cite: 27]
    int x = 0, y = 0, alliszero = 1;
    alliszero = (x == 1) && (y == 0); // Fix [cite: 28]
    
    x = 10; y = 3; int z = 0;
    y = ++x + y; 
    z = (z--) > x; // Fix [cite: 29]
    
    int MASK = 0xF;
    int ison = (x & MASK) == MASK; // Fix [cite: 31]
    
    return 0;
}