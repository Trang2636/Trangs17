#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {ð?u
    char *str ; 
    int choice;       
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong t trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sánh chuoi do voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                
                char buffer[1000];
                printf("\nNhap vào chuoi: ");
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; 

                str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
                if (str == NULL) {
                    printf("\nKhông th? c?p phát b? nh?!\n");
                    exit(1);
                }
                strcpy(str, buffer);
                break;
            }
            case 2: {
                
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i!\n");
                } else {
                    printf("\nChu?i ð?o ngý?c: ");
                    for (int i = strlen(str) - 1; i >= 0; i--) {
                        printf("%c", str[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i!\n");
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
                    printf("\nS? lý?ng t? trong chu?i: %d\n", count);
                }
                break;
            }
            case 4: {
                
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i ban ð?u!\n");
                } else {
                    char buffer[1000];
                    printf("\nNh?p vào chu?i khác: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    if (strlen(buffer) < strlen(str)) {
                        printf("\nChu?i m?i ng?n hõn chu?i ban ð?u.\n");
                    } else if (strlen(buffer) > strlen(str)) {
                        printf("\nChu?i m?i dài hõn chu?i ban ð?u.\n");
                    } else {
                        printf("\nHai chu?i có ð? dài b?ng nhau.\n");
                    }
                }
                break;
            }
            case 5: {
                // In hoa t?t c? ch? cái trong chu?i
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i!\n");
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
                // Nh?p vào chu?i khác và thêm vào chu?i ban ð?u
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i ban ð?u!\n");
                } else {
                    char buffer[1000];
                    printf("\nNh?p vào chu?i khác: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    buffer[strcspn(buffer, "\n")] = '\0';

                    str = (char *)realloc(str, (strlen(str) + strlen(buffer) + 1) * sizeof(char));
                    if (str == NULL) {
                        printf("\nKhông th? c?p phát l?i b? nh?!\n");
                        exit(1);
                    }
                    strcat(str, buffer);
                    printf("\nChu?i sau khi thêm: %s\n", str);
                }
                break;
            }
            case 7: {
                printf("\nThoát chýõng tr?nh.\n");
                break;
            }
            default: {
                printf("\nL?a ch?n không h?p l?! Vui l?ng nh?p l?i.\n");
            }
        }
    } while (choice != 7);

    // Gi?i phóng b? nh? n?u ð? c?p phát
    free(str);
    return 0;
}

