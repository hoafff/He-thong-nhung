/******************************************************************************
 * File: stack_op.c
 * * Mo ta: Cac thao tac bo sung cho Stack trong chuong trinh may tinh.
 * Bao gom: In phan tu dau, Sao chep, Hoan doi va Xoa stack.
 * 
 * Ngay: 10/03/2026
 *****************************************************************************/

#include <stdio.h>

#define MAXVAL 100    /* Do sau toi da cua stack */

int sp = 0;           /* Vi tri tiep theo trong stack */
double val[MAXVAL];   /* Mang luu tru cac gia tri stack */

/******************************************************************************
 * Function: push
 * Description:
 * Day mot gia tri vao stack.
 * Parameters:
 * double f: Gia tri can day vao.
 * Return:
 * None
 *****************************************************************************/
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack day, khong the push %g\n", f);
}

/******************************************************************************
 * Function: pop
 * Description:
 * Lay va tra ve gia tri tren cung cua stack.
 * Parameters:
 * None
 * con tro se tro den o rong hien tai
 * Return:
 * double: Gia tri lay ra tu stack.
 *****************************************************************************/
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: Stack trong\n");
        return 0.0;
    }
}

/******************************************************************************
 * Function: print_top
 * Description:
 * In phan tu tren cung cua stack ma khong lay no ra (peek).
 * Parameters:
 * None
 * Return:
 * None
 *****************************************************************************/
void print_top(void) {
    if (sp > 0)
        printf("Phan tu dau stack: %g\n", val[sp-1]);
    else
        printf("Error: Stack trong, khong co gi de in\n");
}

/******************************************************************************
 * Function: duplicate
 * Description:
 * Sao chep phan tu tren cung cua stack va day lai vao stack.
 * Parameters:
 * None
 * Return:
 * None
 *****************************************************************************/
void duplicate(void) {
    if (sp > 0)
        push(val[sp-1]);
    else
        printf("Error: Stack trong, khong the sao chep\n");
}

/******************************************************************************
 * Function: swap
 * Description:
 * Hoan doi vi tri cua hai phan tu tren cung stack.
 * Parameters:
 * None
 * Return:
 * None
 *****************************************************************************/
void swap(void) {
    if (sp > 1) {
        double temp1 = pop();
        double temp2 = pop();
        push(temp1);
        push(temp2);
    } else {
        printf("Error: Khong du phan tu de hoan doi\n");
    }
}

/******************************************************************************
 * Function: clear_stack
 * Description:
 * Xoa toan bo du lieu trong stack.
 * Parameters:
 * None
 * Return:
 * None
 *****************************************************************************/
void clear_stack(void) {
    sp = 0;
    printf("Stack da duoc xoa sach\n");
}

/******************************************************************************
 * Function: main
 * Description:
 * Ham chay thu nghiem cac tinh nang vua them.
 *****************************************************************************/
int main() {
    push(1.5);
    push(2.5);
    
    print_top();    /* In 2.5 */
    swap();         /* Dao 1.5 va 2.5 */
    print_top();    /* Gio se in 1.5 */
    
    duplicate();    /* Copy 1.5 -> stack co: 2.5, 1.5, 1.5 */
    clear_stack();  /* Xoa het */
    
    return 0;
}