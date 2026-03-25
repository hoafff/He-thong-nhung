/******************************************************************************
 * File: ex4.c
 * Mo ta: Trien khai thuat toan sap xep chen (Insertion Sort) su dung 
 * con tro va so hoc con tro thay vi chi so mang.
 * * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>

// Gia su mang arr va ham array_length da duoc dinh nghia truoc do
extern int arr[]; 
extern unsigned int array_length(int array[]);

/******************************************************************************
 * Function: shift_element
 * Description: 
 * Ham thuc hien dich chuyen cac phan tu dung truoc pElement sang phai
 * cho den khi tim duoc vi tri thich hop de chen gia tri cua pElement.
 * Parameters:
 * int *pElement: Con tro toi phan tu dang xet (bi dat sai vi tri).
 * Return:
 * None
 ******************************************************************************/
void shift_element(int *pElement) {
    int ivalue = *pElement; // Luu gia tri cua phan tu can chen
    int *p = pElement;      // Khoi tao con tro chay tu vi tri hien tai

    /* * p > arr: Dam bao khong tro ra ngoai pham vi mang (tuong duong i > 0)
     * *(p - 1) > ivalue: Kiem tra phan tu phia truoc co lon hon gia tri can chen khong
     */
    while (p > arr && *(p - 1) > ivalue) {
        *p = *(p - 1); // Dich phan tu lon hon sang phai
        p--;           // Lui con tro ve phia truoc
    }
    
    *p = ivalue; // Chen gia tri vao vi tri dung
}

/******************************************************************************
 * Function: insertion_sort
 * Description: 
 * Ham thuc hien sap xep mang theo thuat toan Insertion Sort su dung con tro.
 * Duyet qua tung phan tu, neu phan tu do nho hon phan tu truoc no thi
 * goi ham shift_element de dua no ve dung vi tri.
 * Parameters:
 * None
 * Return:
 * None
 ******************************************************************************/
void insertion_sort(void) {
    unsigned int len = array_length(arr);
    int *p;
    
    /* Bat dau tu phan tu thu hai (arr + 1) den cuoi mang */
    for (p = arr + 1; p < arr + len; p++) {
        /* Neu phan tu hien tai nho hon phan tu ngay truoc no */
        if (*p < *(p - 1)) {
            shift_element(p);
        }
    }
}