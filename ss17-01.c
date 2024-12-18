#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,choice,max;
	int count =0; 
	do{
	
	printf("\n==MENU==\n");
	printf("1.Nhap vao so phan tu va tung phan tu\n");
	printf("2.Hien thi cac phan tu trong mang\n");
	printf("3.Tinh do dai\n");
	printf("4.Tinh tong cac phan tu trong mang\n");
	printf("5.Hien thi phan tu lon nhat\n");
	printf("6.Thoat\n");
	printf("Moi nhap vao lua chon cua ban:");
	scanf("%d",&choice);
	 switch (choice){
	 	case 1 :
		 int size , choice ,i;
		 printf("Moi nhap vao so phan tu trong mang: ");
		 scanf("%d",&size); 
		 int* arr;
		 //cap phat bo nho 
	   arr = (int*)calloc(size,size*sizeof(int)); 
	   //nhap vao phan tu trong mang  
	   fflush(stdin); 
	printf("Moi ban nhap vao phan tu\n ") ;
	for(i=0;i<size;i++){
		printf("arr[%d]=",i);
		scanf("%d",&arr[i]);
	
	}
	 break; 
	
	 case 2 : 
	 //in ra phan tu co trong mang  
	  for(i=0;i<size;i++){
		printf("arr[%d]=%d\n",i,arr[i]);
	
	
	}
	 break; 
	 
	 case 3 : 
	 //tinh do dai 
     printf("Do dai cua mang la : %d",size );
	  break;
	  
	  case 4 :
	  //tinh tong cac phan tu trong mang 
	   for(i=0;i<size;i++){
	   	 count += arr[i]; 
	   }
	 printf("\n Tong cac phan tu co trong mang la :%d",count);
	 break;
	 
	 case 5:
	 //hien thi phan tu lon nhat 
	  //duyet qua mang 
	 
	   for(i=0;i<size;i++){
	   	//gan gtri dau tien la gtln 
		    max = arr[0]; 	
	   	if(arr[i]>max){
	   		//neu ohan tu moi lon hon max thi gan lai max cho so moi 
	   		max=arr[i]; 
		   } 
	   }
	 printf("\nPhan tu lon nhat la : %d",max) ;
	 break; 
	 
	 case 6 : 
	 printf("Hen gap lai!");
	 default:
	 printf("Khong hop le.");
	 break; 
	 
	 
	
}
}while(choice!=6); 
	return 0; 
} 

























