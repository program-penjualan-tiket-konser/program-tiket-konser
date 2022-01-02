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

    int i,jumlahtiketjumat,jumlahtiketsabtu,jumlahtiketminggu;
	DataPembelian data[1000];



    FILE *load;
    load=fopen ("datapenjualan.txt", "r");
    fread(&data, sizeof(data), 1, load);
    fclose(load);


    FILE *loadjum;
    loadjum=fopen("jumlahdata.txt", "r");
    fscanf(loadjum,"%d",&i);
    fclose(loadjum);


    ///
    FILE *tjumat;
    tjumat=fopen("tiketjumat.txt", "r");
    fscanf(tjumat,"%d",&jumlahtiketjumat);
    fclose(tjumat);

    FILE *tsabtu;
    tsabtu=fopen("tiketsabtu.txt", "r");
    fscanf(tsabtu,"%d",&jumlahtiketsabtu);
    fclose(tsabtu);

    FILE *tminggu;
    tminggu=fopen("tiketminggu.txt", "r");
    fscanf(tminggu,"%d",&jumlahtiketminggu);
    fclose(tminggu);

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
				printf("\t\t==========[ PENJUALAN TIKET KONSER YOUTFEST ]==========\n\n");


				while(tutup==1){

					int kembali;
					printf("\t\tMasukan 0 untuk kembali, dan 1 untuk Lanjut:");
					scanf(" %d", &kembali);


					if(kembali==0){

                        tutup=0;

					}else{
					    i=i+1;
                    system("cls");
                    printf("\t\t\n");

					printf("\t\t=============[ DATA PEMBELIAN %d ]=============\n", i);

					printf("\t\tKode Tiket Konser      : %d\n", i);
					printf("\t\tNama                   : ");
					    scanf(" %[^\n]s", &data[i].nama_pembeli);
                    printf("\n\n\t\t=====[ PILIHAN HARI KONSER YOUTFEST ]=====\n\n");

				    printf("\t\t1. Jumat      [Yout Fest 1] %d",jumlahtiketjumat);
				    printf("\n");
				    printf("\t\t2. Sabtu      [Yout Fest 2] %d", jumlahtiketsabtu);
				    printf("\n");
				    printf("\t\t3. Minggu     [Yout Fest 3] %d", jumlahtiketminggu);
				    printf("\n");
				    printf("\t\t______________________________________________\n");
				    do{
				    	printf("\t\tMasukkan nomor hari : ");
				    	scanf("%d" ,&data[i].no_hari);
					}while(data[i].no_hari<1 || data[i].no_hari>3);

				    printf("\n\t\t===========[ KONSER YANG TERSEDIA ]===========\n\n");
				    int jumlahtiketpilihan;
				    if(data[i].no_hari==1){
                            jumlahtiketpilihan=jumlahtiketjumat;
				        data[i].no_konser=1;
			            strcpy(data[i].nama_hari,"Jumat");
			            strcpy(data[i].nama_konser,"Youtfest 1");
				    }else if(data[i].no_hari==2){
				         jumlahtiketpilihan=jumlahtiketsabtu;
			            data[i].no_konser=2;
			            strcpy(data[i].nama_hari,"Sabtu");
				        strcpy(data[i].nama_konser,"Youtfest 2");
			        }else{
			            data[i].no_konser=3;
			             jumlahtiketpilihan=jumlahtiketminggu;
			            strcpy(data[i].nama_hari,"Minggu");
				        strcpy(data[i].nama_konser,"Youtfest 3");
				    }
				    printf("\t\t%d.%s      [%s]\t\n" , data[i].no_konser, data[i].nama_hari, data[i].nama_konser);
				    printf("\t\t______________________________________________\n");
				    printf("\t\tPilihan hari  Anda      : %s\n" , data[i].nama_hari);
				    printf("\t\tPilihan konser  Anda    : %s\n" , data[i].nama_konser);

                    data[i].harga_tiket = 250000;
					do{

                        printf("\t\tJumlah pembelian tiket  : ");
                        scanf("%d", &data[i].jumlah_tiket);
					}

                    while(data[i].jumlah_tiket>jumlahtiketpilihan||data[i].jumlah_tiket<1);

					switch(data[i].no_hari){

                        case 1:
                        jumlahtiketjumat-=data[i].jumlah_tiket;
                        break;
                        case 2:
                        jumlahtiketsabtu-=data[i].jumlah_tiket;
                        break;
                        case 3:
                        jumlahtiketminggu-=data[i].jumlah_tiket;
                        break;

					}
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

				}

				FILE *outfile;
				outfile = fopen("datapenjualan.txt", "w");

				fwrite  (&data, sizeof(data), 1, outfile);

				fclose(outfile);


				///jumlah data
				FILE *jum;
				jum = fopen("jumlahdata.txt", "w");
				fprintf(jum,"%d",i);
				fclose(jum);
				///jumlah tiket jumat
				jum = fopen("tiketjumat.txt", "w");
				fprintf(jum,"%d",jumlahtiketjumat);
				fclose(jum);
				///jumlah tiket sabtu
				jum = fopen("tiketsabtu.txt", "w");
				fprintf(jum,"%d",jumlahtiketsabtu);
				fclose(jum);
				///jumlah tiket minggu
				jum = fopen("tiketminggu.txt", "w");
				fprintf(jum,"%d",jumlahtiketminggu);
				fclose(jum);



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

