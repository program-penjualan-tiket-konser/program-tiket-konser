#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datapembelian.c"
#include "jadwalkonser.c"

//PEMBELIAN TIKET KONSER
//Ida Bagus Gede Surya Mahendra 2105551040
//Ni Kadek Yumitha Septyandari 2105551045

int main(){
    char x;
    do {

    int pilihan;
    printf("\n");
    printf("\t\t---------------------------------------------\n");
    printf("\t\t----    Program Login Dan Registrasi   ------\n");
    printf("\t\t---------------------------------------------\n");
    printf("\t\t 1. login \n");
    printf("\t\t 2. registrasi \n");
    printf("\n");
    printf("\t\tMasukan angka pilihan : ");
    scanf("%d",&pilihan);
    if(pilihan==1)
    {
        login();
    }

    else if(pilihan==2)
    {
        registers();
    }

    printf("\t\tApakah ingin masuk ke menu awal lagi? (y/t) : "); scanf(" %s", &x);
    system("cls");


    // return 0;
    } while (x=='Y' || x=='y');

	return 0;
}


void jalankanApp(){

    int i;
	DataPembelian data[20]; //adt data integer
    int input = 0;
	while(input!=5){
		system("cls");
		printf("\t\t-------------------------------------------\n");
		printf("\t\t--      PROGRAM PENJUALAN TIKET KONSER   --\n");
		printf("\t\t-------------------------------------------\n");
		printf("\t\t==============[ MENU KONSER ]==============\n");
		printf("\t\t              1. Beli Tiket                \n");
		printf("\t\t              2. Lihat Tiket               \n");
		printf("\t\t              3. Cari Kode Tiket           \n");
		printf("\t\t              4. Lihat Jadwal Konser       \n");
		printf("\t\t              5. Exit                      \n");
		printf("\t\tInput Angka Menu : ");
		scanf("%d", &input);
		system("cls");
		switch(input){
			case 1:{
				int tutup = 1;
                printf("\t\t\n");
				printf("\t\t----------------------------------------------\n");
				printf("\t\t==========[ PENJUALAN TIKET KONSER ]==========\n\n");
		   		printf("\t\t--                Menu Kelas                --\n");
		  		printf("\t\t----------------------------------------------\n");
		    	printf("\t\t:   Kode Kelas  :   Kelas   :       Harga    :\n");
		    	printf("\t\t:_______________:___________:________________:\n");
		    	printf("\t\t:       1       :   VVIP    : Rp 1.000.000,00:\n");
		    	printf("\t\t:       2       :   VIP     : Rp   750.000,00:\n");
		    	printf("\t\t:       3       : Festival  : Rp   500.000,00:\n");
		    	printf("\t\t:       4       :  Biasa    : Rp   250.000,00:\n");
		    	printf("\t\t______________________________________________\n\n\n\n");
				while(tutup==1){
					i=i+1;
					printf("\t\t=============[ DATA PEMBELIAN %d ]=============\n", i);
					printf("\t\tKode Tiket Konser      : %d\n", i);
					printf("\t\tNama                   : ");
					scanf(" %[^\n]s", &data[i].nama_pembeli);
					printf("\n\n\t\t==============[ PILIHAN KONSER ]==============\n\n");
				    printf("\t\t1. Jumat      [Sky Garden]\n");
				    printf("\t\t2. Sabtu      [LXXY]\n");
				    printf("\t\t3. Minggu     [Boshe]\n");
				    printf("\t\t______________________________________________\n");
				    do{
				    	printf("\t\tMasukkan nomor hari : ");
				    	scanf("%d" ,&data[i].no_hari);
					}while(data[i].no_hari<1 || data[i].no_hari>3);

				    printf("\n\t\t===========[ KONSER YANG TERSEDIA ]===========\n\n");
				    if(data[i].no_hari==1){
				        data[i].no_konser=1;
			            strcpy(data[i].nama_hari,"Jumat");
			            strcpy(data[i].nama_konser,"Sky Garden");
				    }else if(data[i].no_hari==2){
			            data[i].no_konser=2;
			            strcpy(data[i].nama_hari,"Sabtu");
				        strcpy(data[i].nama_konser,"LXXY");
			        }else{
			            data[i].no_konser=3;
			            strcpy(data[i].nama_hari,"Minggu");
				        strcpy(data[i].nama_konser,"Boshe");
				    }
				    printf("\t\t%d.%s      [%s]\t\n" , data[i].no_konser, data[i].nama_hari, data[i].nama_konser);
				    printf("\t\t______________________________________________\n");
				    printf("\t\tPilihan hari  Anda      : %s\n" , data[i].nama_hari);
				    printf("\t\tPilihan konser  Anda    : %s\n" , data[i].nama_konser);
					printf("\t\tPilihan kelas konser    : ");
					scanf("%d", &data[i].kelas_tiket);
					switch(data[i].kelas_tiket){
						case 1:{
							data[i].harga_tiket = 1000000;
							break;
						}
						case 2:{
							data[i].harga_tiket = 750000;
							break;
						}
						case 3:{
							data[i].harga_tiket = 500000;
							break;
						}
						case 4:{
							data[i].harga_tiket = 250000;
							break;
						}
					}
					printf("\t\tJumlah pembelian tiket  : ");
					scanf("%d", &data[i].jumlah_tiket);
					data[i].total_harga = data[i].jumlah_tiket * data[i].harga_tiket;
					printf("\t\t_______________________________________________\n");
					printf("\t\tTotal harga             : %d\n", data[i].total_harga);
					do{
						printf("\t\tUang yang Dibayarkan    : ");
						scanf("%d", &data[i].total_bayar);
					}while(data[i].total_bayar < data[i].total_harga);
					data[i].kembalian = data[i].total_bayar-data[i].total_harga;
					printf("\t\tKembalian Uang          : %d\n", data[i].kembalian);
					printf("\t\tUntuk memasukkan data lagi Enter 1 [MAX 20 DATA], untuk menutup menu Enter 0:");
					scanf("%d", &tutup);
				}
				break;
			}
			case 2:{
				HistoryTransaksi(data, i);
				break;
			}
			case 3:{
				PencarianHistory(data, i);
				break;
			}
			case 4:{
				JadwalKonser();
				break;
			}
			case 5:{
				printf("Anda Telah Keluar Dari Program");
				break;
			}
			default:{
				printf("Input Menu Salah");
				break;
			}
		}
	}
}
void registers()
{
char d;
 do {
    char username[ ][10] = {"","","","","","","","","","",""};
    char password[ ][10] = {"","","","","","","","","","",""};

    FILE *fusername,*fpassword;
    fusername = fopen("username.data", "a");
    fpassword = fopen("password.data", "a");

    for(int i=0; i<10; i++)
    {
        fgets(username[i], 255, (FILE*)fusername);

        fgets(password[i], 255, (FILE*)fpassword);

    }

    fclose(fusername);
    fclose(fpassword);
    printf("%s",username[1]);

    printf("\t\t_____________________________________________\n");
    printf("\t\t---                                       ---\n");
    printf("\t\t--              --REGISTRASI--             --\n");
    printf("\t\t-----                                   -----\n");
    printf("\t\tMasukan Username : ");
    scanf("%s[^\n]",username[0]);

    printf("\t\tMasukan Password : ");
    scanf("%s[^\n]",password[0]);


    FILE *f = fopen("username.data", "a");

    //input username ke file
    fputs(username[0], f);
    fputs("\n", f);
    fclose(f);
    //input password ke file
    f = fopen("password.data", "a");
    fputs(password[0], f);
    fputs("\n", f);
    fclose(f);

    printf("\t\t_____________________________________________\n");
    printf("\t\t---                                       ---\n");
    printf("\t\t--          --BERHASIL REGISTRASI--        --\n");
    printf("\t\t-----                                   -----\n");
    printf("\t\t---------------------------------------------\n");
    printf("\n");


 printf("\t\tApakah ingin registrasi lagi? (y/t) : "); scanf(" %s", &d);
system("cls");

 }while (d=='Y' || d=='y');
}

int checkusername(){

    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    char checkus[255];
    filePointer = fopen("username.data", "r");
    int index=0;
    int indexfound=0;
    printf("\t\tMasukan Username : ");
    scanf("%s",checkus);

    while(fgets(buffer, bufferLength, filePointer)) {

    buffer[strlen(buffer)-1] = '\0';
    int length = strlen(buffer);
    if(strcmp(buffer,checkus)==0)
    {
        indexfound=index;
        return indexfound;
        //printf("found on index:%u",index);
    }
        //printf("length username: %u,lengh check:", length,length2);
         index++;

        //printf("%s", buffer);
    }

    fclose(filePointer);
    //printf(" username  found index:%u",indexfound);
    return 999;
}
int checkpassword(){

    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    char checkus[255];
    filePointer = fopen("password.data", "r");
    int index=0;
    int indexfound=0;
    printf("\t\tMasukan Passwrod : ");
    scanf("%s",checkus);

    while(fgets(buffer, bufferLength, filePointer)) {

    buffer[strlen(buffer)-1] = '\0';
    int length = strlen(buffer);
    if(strcmp(buffer,checkus)==0)
    {
        indexfound=index;
        return indexfound;

        //printf("found on index:%u",index);
    }
        //printf("length username: %u,lengh check:", length,length2);
         index++;

        //printf("%s", buffer);
    }

    fclose(filePointer);
 //   printf(" pw  found index:%u",indexfound);

return 193;
}
void login()
{
    char d;
    do {

    printf("\t\t_____________________________________________\n");
    printf("\t\t---                                       ---\n");
    printf("\t\t--                --LOGIN--                --\n");
    printf("\t\t-----                                   -----\n");
    int username=999;
    int password=123;
    username=checkusername();
    password=checkpassword();

    if(username==password)
    {
        jalankanApp();
    }
    else
    {
        printf("\t\tUser Tidak Di Temukan! \n");
    }

     printf("\nApakah ingin masuk login lagi? (y/t) : "); scanf(" %s", &d);
     system("cls");

 }while (d=='Y' || d=='y');
}

