/******************************************************************************
 * File: ex3.c
 * Mo ta: Chuong trinh in danh sach cac file ra man hinh. Moi file se bat dau
 * o mot trang moi, co tieu de va so thu tu trang.
 *
 * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXPAGE 40 // Dinh nghia moi trang co 40 dong

/******************************************************************************
 * Function: print_file
 * Description: 
 * Mo mot file, doc va in tung dong. Theo doi so dong de ngat trang
 * va in tieu de moi khi sang trang moi.
 * Parameters:
 * char *name: Ten cua file can in.
 * Return:
 * None
 ******************************************************************************/
void print_file(char *name) {
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", name);
        return;
    }

    char line[1000];
    int line_count = 0, page_count = 1;

    printf("\n\f--- File: %s | Page: %d ---\n", name, page_count);
    
    while (fgets(line, sizeof(line), fp)) {
        if (line_count == MAXPAGE) {
            page_count++;
            printf("\n\f--- File: %s | Page: %d (cont) ---\n", name, page_count);
            line_count = 0;
        }
        fputs(line, stdout);
        line_count++;
    }
    fclose(fp);
    printf("\n--- End of File: %s ---\n", name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        print_file(argv[i]);
    }

    return 0;
}