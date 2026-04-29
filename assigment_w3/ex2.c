/******************************************************************************
 * File: ex2.c
 * Mo ta: Chuong trinh so sanh noi dung cua hai file va in ra dong dau tien
 * co su khac biet giua chung.
 *
 * Ngay: 15/03/2026
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

/******************************************************************************
 * Function: compare_files
 * Description: 
 * Doc tung dong tu hai file va so sanh. Neu thay khac biet se in ra 
 * noi dung cua ca hai dong do va dung lai.
 * Parameters:
 * FILE *f1: Con tro file thu nhat.
 * FILE *f2: Con tro file thu hai.
 * Return:
 * None 
 ******************************************************************************/
void compare_files(FILE *f1, FILE *f2) {
    char line1[MAXLINE], line2[MAXLINE];
    char *p1, *p2;

    do {
        p1 = fgets(line1, MAXLINE, f1);
        p2 = fgets(line2, MAXLINE, f2);

        if (p1 && p2 && strcmp(line1, line2) != 0) {
            printf("Difference found:\nFile 1: %sFile 2: %s", line1, line2);
            return;
        }
    } while (p1 && p2);

    if (p1 != p2) {
        printf("Files have different lengths (one ended early).\n");
    } else {
        printf("Files are identical.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    if (!f1 || !f2) {
        perror("Error opening files");
        return 1;
    }

    compare_files(f1, f2);

    fclose(f1);
    fclose(f2);
    return 0;
}