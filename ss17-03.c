#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {�?u
    char *str ; 
    int choice;       
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong t trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so s�nh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                
                char buffer[1000];
                printf("\nNhap v�o chuoi: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 

                str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
                if (str == NULL) {
                    printf("\nKh�ng th? c?p ph�t b? nh?!\n");
                    exit(1);
                }
                strcpy(str, buffer);
                break;
            }
            case 2: {
                
                if (str == NULL) {
                    printf("\nCh�a nh?p chu?i!\n");
                } else {
                    printf("\nChu?i �?o ng�?c: ");
                    for (int i = strlen(str) - 1; i >= 0; i--) {
                        printf("%c", str[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                
                if (str == NULL) {
                    printf("\nCh�a nh?p chu?i!\n");
                } else {
                    int count = 0, inWord = 0;
                    for (int i = 0; str[i] != '\0'; i++) {
                        if (!isspace(str[i])) {
                            if (!inWord) {
                                count++;
                                inWord = 1;
                            }
                        } else {
                            inWord = 0;
                        }
                    }
                    printf("\nS? l�?ng t? trong chu?i: %d\n", count);
                }
                break;
            }
            case 4: {
                
                if (str == NULL) {
                    printf("\nCh�a nh?p chu?i ban �?u!\n");
                } else {
                    char buffer[1000];
                    printf("\nNh?p v�o chu?i kh�c: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if (strlen(buffer) < strlen(str)) {
                        printf("\nChu?i m?i ng?n h�n chu?i ban �?u.\n");
                    } else if (strlen(buffer) > strlen(str)) {
                        printf("\nChu?i m?i d�i h�n chu?i ban �?u.\n");
                    } else {
                        printf("\nHai chu?i c� �? d�i b?ng nhau.\n");
                    }
                }
                break;
            }
            case 5: {
                // In hoa t?t c? ch? c�i trong chu?i
                if (str == NULL) {
                    printf("\nCh�a nh?p chu?i!\n");
                } else {
                    printf("\nChu?i sau khi in hoa: ");
                    for (int i = 0; str[i] != '\0'; i++) {
                        printf("%c", toupper(str[i]));
                    }
                    printf("\n");
                }
                break;
            }
            case 6: {
                // Nh?p v�o chu?i kh�c v� th�m v�o chu?i ban �?u
                if (str == NULL) {
                    printf("\nCh�a nh?p chu?i ban �?u!\n");
                } else {
                    char buffer[1000];
                    printf("\nNh?p v�o chu?i kh�c: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    str = (char *)realloc(str, (strlen(str) + strlen(buffer) + 1) * sizeof(char));
                    if (str == NULL) {
                        printf("\nKh�ng th? c?p ph�t l?i b? nh?!\n");
                        exit(1);
                    }
                    strcat(str, buffer);
                    printf("\nChu?i sau khi th�m: %s\n", str);
                }
                break;
            }
            case 7: {
                printf("\nTho�t ch��ng tr?nh.\n");
                break;
            }
            default: {
                printf("\nL?a ch?n kh�ng h?p l?! Vui l?ng nh?p l?i.\n");
            }
        }
    } while (choice != 7);

    // Gi?i ph�ng b? nh? n?u �? c?p ph�t
    free(str);
    return 0;
}

