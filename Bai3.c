/*
Cho 1 thung chua ngau nhien so vo do, vang, xanh. Dem xem co bao nhieu doi vo cung mau
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{  
    VO_DO,
    VO_VANG,
    VO_XANH
}VO;

typedef struct{
    VO *arr;
    int size;
}typeArr;

typeArr *Nhapthongtin(){
    static typeArr Arr;
    Arr.arr = (VO *)malloc(sizeof(VO));
    printf("\n Nhap so luong vo: ");
    scanf("%d",&Arr.size);
    int i = 0;
    do{
        char a[10];
        printf("\nNhap loai vo thu %d: ",i);
        scanf("%s",a);
        if(!strcmp(a,"VO_DO")){
            Arr.arr[i] = VO_DO;
            i++;
        }else if(!strcmp(a,"VO_VANG")){
            Arr.arr[i] = VO_VANG;
            i++;
        }else if(!strcmp(a,"VO_XANH")){
            Arr.arr[i] = VO_XANH;
            i++;
        }else{
            printf("\nKhong hop le");
        }
        
    }while(i < Arr.size);
    
    return &Arr;
}

void process(typeArr *A){
    int sl1=0,sl2=0,sl3=0;
    for(int i = 0; i< A->size;i++){
        if(A->arr[i] == 0){
            sl1++;
        }else if(A->arr[i] == 1){
            sl2++;
        }else{
            sl3++;
        }
    }
    printf("\nCo %d cap tat cung mau do",sl1/2);
    printf("\nCo %d cap tat cung mau vang",sl2/2);
    printf("\nCo %d cap tat cung mau xanh",sl3/2);
}

int main(){
    typeArr *A;
    A = Nhapthongtin();
    for(int i = 0; i < A->size; i++){
        if(A->arr[i] == 0){
            printf("\nDoi vo thu %d la VO DO",i);
        }else if(A->arr[i] == 1){
            printf("\nDoi vo thu %d la VO VANG",i);
        }else{
             printf("\nDoi vo thu %d la VO XANH",i);
        }
    }
    process(A);

    return 0;
}