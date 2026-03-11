/******************************************************************************
 * File: expand.c
 * * Mo ta: Chuong trinh mo rong cac ky hieu viet tat nhu a-z, 0-9
 * tu chuoi nguon sang chuoi dich day du.
 * 
 * Ngay: 10/03/2026
 *****************************************************************************/

#include <stdio.h>

/******************************************************************************
 * Function: expand
 * Description:
 * Ham nay tim cac ky tu viet tat dang 'a-z' trong s1 va viet ra
 * day du 'abcdef...xyz' vao s2.
 * Parameters:
 * char s1[]: Chuoi dau vao chua ky hieu viet tat.
 * char s2[]: Chuoi dau ra sau khi da mo rong.
 * Return:
 * None
 *****************************************************************************/
void expand(char s1[], char s2[]) {
    int i, j, c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++; 
            while (c < s1[i]) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-a-z0-9-";
    char s2[100];
    expand(s1, s2);
    printf("Ket qua: %s\n", s2);
    return 0;
}