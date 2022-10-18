/*
*Viet chuong trinh nhap vao cac so ngau nhien, roi luu vao mang arr[]
*Nhan 1: Sap xep theo thu tu tu be den lon 
*Nhan 2: Sap xep theo thu tu tu lon den be
*Nhan 3: Tim so lon nhat
*Nhan 4: Thoat chuong trinh
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
}typeArr;

void swap(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void BedenLon(typeArr *A){
    for(int i = 1; i < A->size;i ++){
        for(int j = 0 ; j < A->size-1;j++){
            if(A->arr[j]> A->arr[j+1]){
                swap(&A->arr[j],&A->arr[j+1]);
            }
        }
    }
}

void LondenBe(typeArr *A){
    for(int i = 1; i < A->size;i ++){
        for(int j = 0 ; j < A->size-1;j++){
            if(A->arr[j]< A->arr[j+1]){
                swap(&A->arr[j],&A->arr[j+1]);
            }
        }
    }
}

int Timsolonnhat(typeArr *A){
    int max = 0;
    for(int i = 0; i < A->size;i++){
        if(max < A->arr[i]){
            max = A->arr[i];
        }
    }
    return max;
}

typeArr  *Nhapthongtin(){

    static typeArr a;
    printf("\nNhap so luong phan tu: ");
    scanf("%d",&a.size);
    a.arr = (int *)malloc(a.size*sizeof(int));
    for(int i = 0; i < a.size; i ++){
        printf("\nNhap arr[%d]: ",i);
        scanf("%d",&a.arr[i]);

    }
    return &a;
}


int main(){
   
    typeArr *Arr;
    int lenh = 0;
    Arr = Nhapthongtin();
    for(int i = 0; i < Arr->size; i++){
        printf("\nptr[%d] = %d",i, Arr->arr[i] );
    }
    do{
        printf("\n Nhap cau lenh: ");
        scanf("%d",&lenh);
        if(lenh == 1){
            BedenLon(Arr);
            for(int i = 0; i < Arr->size; i++){
            printf("\nptr[%d] = %d",i, Arr->arr[i] );
            }
        }else if(lenh ==2 ){
            LondenBe(Arr);
            for(int i = 0; i < Arr->size; i++){
            printf("\nptr[%d] = %d",i, Arr->arr[i] );
            }
        }else if(lenh == 3){
            printf("\nSo lon nhat la: %d",Timsolonnhat(Arr));
            }
    
    }while(lenh!= 4);

    return 0;
}

