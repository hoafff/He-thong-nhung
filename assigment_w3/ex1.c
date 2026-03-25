/******************************************************************************
 * File: ex1.c
 * Mo ta: Chuong trinh chuyen doi chu hoa thanh chu thuong hoac nguoc lai
 * dua vao ten file thuc thi (argv[0]).
 *
 * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/******************************************************************************
 * Function: main
 * Description: 
 * Ham chinh kiem tra ten file thuc thi. Neu ten chua "upper" thi chuyen
 * sang chu hoa, nguoc lai chuyen sang chu thuong.
 * Parameters:
 * int argc: So luong doi so dong lenh.
 * char *argv[]: Mang cac chuoi doi so.
 * Return:
 * 0: Neu chuong trinh chay thanh cong.
 ******************************************************************************/
int main(int argc, char *argv[]) {
    int c;
    // Kiem tra xem trong ten file thuc thi co chu "upper" hay khong
    int upper = (strstr(argv[0], "upper") != NULL);

    while ((c = getchar()) != EOF) {
        putchar(upper ? toupper(c) : tolower(c));
    }
    return 0;
}