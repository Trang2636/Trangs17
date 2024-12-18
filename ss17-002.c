#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *str ;
    char buffer[1000]; 
    int choice;       

    do{
        	printf("\n==MENU==\n");
		printf("1.Nhap vao chuoi\n");
		printf("2.In ra chuoi\n");
		printf("3.Dem so luong chu cai trong chuoi va in ra\n");
		printf("4.Dem so luong chu so trong chuoi va in ra\n");
		printf("5.Dem so luong ki tu dac biet trong chuoi va in ra\n");
		printf("6.Thoat\n");
		printf("Moi ban nhap vao lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("\nNhap vao chuoi: ");
                fgets(buffer, sizeof(buffer), stdin);
                str = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
                strcpy(str, buffer);
                break;
            
            case 2: 
                // In ra chu?i
                printf("\nChu?i ð? nh?p: %s\n", str);
                
                break;
            
            case 3: 
                    int count=0;
                    for (int i = 0; str[i] != '\0'; i++) {
                        if ((str>='A'&& str<='Z')||((str>='a'&& str<='z')) {
                            count++;
                        }
                    }
                    printf("\nSo luong chu cai: %d\n", count);
                
                break;
            case 4: 
                    int count = 0;
                    for (int i = 0; str[i] != '\0'; i++) {
                        if ((str>='0'&& str<='9')) {
                            count++;
                        }
                    }
                    printf("\nSo luong chu so: %d\n", count);
                
                break;
            
            case 5: 
                // Ð?m s? lý?ng k? t? ð?c bi?t trong chu?i
                if (str == NULL) {
                    printf("\nChýa nh?p chu?i!\n");
                } else {
                    int count = 0;
                    for (int i = 0; str[i] != '\0'; i++) {
                        if (!isalnum(str[i]) && !isspace(str[i])) {
                            count++;
                        }
                    }
                    printf("\nSo luong ki tu dac biet: %d\n", count);
                }
                break;
            case 6: 
                printf("\nThoat chuong trinh.\n");
                break;
            
            default: 
                printf("\nkhong hop le.\n");
            
        }
    } while (choice != 6);

   
    free(str);
    return 0;
}

