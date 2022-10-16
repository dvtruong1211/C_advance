#include <stdio.h>
#include <stdint.h>
#include <time.h>

int check(int ngay,int thang,int nam){
    if(ngay > 31 || ngay < 1 || thang > 12 || thang < 1 || nam < 1 || nam > 2022){
        return 0;
    }else{
        if(thang == 2 && ngay > 29){
            return 0;
        }else if((thang == 4 || thang == 6 || thang == 9 || thang == 11) && ngay == 31){
            return 0;
        }else{
            return 1;
        }
    }
}

void Process(int ngay, int thang ,int nam){
    int tuoi = 0;
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    if(thang < timeinfo->tm_mon +1){
        tuoi = timeinfo->tm_year + 1900 - nam;
    }else if(thang == timeinfo->tm_mon ){
        if(ngay <= timeinfo->tm_mday){
            tuoi = timeinfo->tm_year + 1900 - nam;
        }else{
            tuoi = timeinfo->tm_year + 1900 - nam - 1;
        }
    }else{
        tuoi = timeinfo->tm_year + 1900 - nam - 1;
    }
    printf("\nSo tuoi la: %d tuoi",tuoi);

}

int main(){
    
    int ngay;
	int thang;
    int nam;

    do{
        printf("\nNhap ngay sinh: ");
        scanf("%d",&ngay);
        printf("\nNhap thang sinh: ");
        scanf("%d",&thang);
        printf("\nNhap nam sinh: ");
        scanf("%d",&nam);
    }while(check(ngay,thang,nam) == 0);
    
    Process(ngay,thang,nam);
    
    
    return 0;
}