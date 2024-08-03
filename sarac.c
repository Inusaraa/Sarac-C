#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int temelIslemler(float bir,float iki, char *argv[]) {
    if(!(bir == 0 || iki == 0 || argv[4] == 0)) {
        if(strcmp("t", argv[4]) == 0) {
                float sonuc = bir+iki;
                printf("Islemin sonucu: %f\n", sonuc);
        } else if (strcmp("ca", argv[4]) == 0) {
               float sonuc = bir*iki;
                printf("Islemin sonucu: %.3f\n", sonuc);
        } else if (strcmp("b", argv[4]) == 0) {
               float sonuc = bir/iki;
                printf("Islemin sonucu: %.3f\n", sonuc);
        } else if (strcmp("c", argv[4]) == 0) {
               float sonuc = bir-iki;
                printf("Islemin sonucu: %.3f\n", sonuc);
        } else if(strcmp("x", argv[4]) == 0){
		float sonuc = 0.0;
		int x;
		for(x = 0;x < iki;++x) {
			if(x==1) {
				sonuc = bir*bir;
			} else {
				sonuc = sonuc*bir;
			}
		}
		printf("Islemin sonucu: %.3f\n", sonuc);
	} else {
             printf("Hata: Hatali yazim | -h <ilk-deger> <son-deger> <islem>\n");
        }
    } else {
        printf("Hata: Hatali yazim | -h <ilk-deger> <son-deger> <islem>\n");
    }
    return 0 ;
}
int tekDegerli(float bir, char *argv[]) {
    if(!(bir == 0 ||  argv[3] == 0)) {
        if(strcmp("k", argv[3]) == 0) {
            float sonuc = bir*bir;
            printf("Islemin sonucu: %.3f\n",sonuc);
        } /*else if(strcmp("kk", argv[3]) == 0) {

            printf("Islemin sonucu: %.3f\n",b);
        }*/ else {
            printf("Hata: Hatali yazim | -th <ilk-deger> <islem>\n");
        }
    } else {
        printf("Hata: Hatali yazim | -th <ilk-deger> <islem>\n");
    }
    return 0;
}

int createFonk(float bir, float iki) {
    if(!(bir == 0 || iki == 0)) {
        float toplam = bir + iki;
        float carpim = bir*iki;
        char symbol1;
        char symbol2;
        if(toplam > 0 ) {symbol1 = '+';}
        if(carpim > 0 ) {symbol2 = '+';}
        printf("Islemin sonucu: f(x)=x²%c%.3fx%c%.3f\n",symbol1,toplam,symbol2,carpim);
    } else {
        printf("Hata: Hatali yazim | -f <ilk-deger> <ikinci-deger>\n");
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc == 2 && strcmp("-y", argv[1]) == 0) {
        printf("Basit, komut satirli hesap makinesi.\n\nKomutlar:\n-y : Klasik yardim komutu.\n-h <ilk-deger> <son-deger> <islem> : Hesaplama yapma komutu. \n  -- <islem> bolumune <t> (toplama), <c> (cikarma), <ca> (carpma), <b> (bolme) gelmesi gerekiyor.\n-th <ilk-deger> <islem> : Tek degerle yapilan hesaplama komutu.\n  -- <islem> bolumune <k>(degerin karesi) gelmesi gerekiyor.\n");
    } else if (argc == 5 && strcmp("-h", argv[1]) == 0) {
        char *argg = argv[2];
        char *arrg = argv[3];
        float arg1 = atoi(argg);
        float arg2 = atoi(arrg);
        temelIslemler(arg1,arg2,argv);
    } else if(argc == 4 && strcmp("-th", argv[1]) == 0) {
        char *argg = argv[2];
        float arg1 = atoi(argg);
        tekDegerli(arg1,argv);
    } else if (argc == 4 && strcmp("-f", argv[1]) == 0) {
        char *argg = argv[2];
        char *arrg = argv[3];
        float arg1 = atoi(argg);
        float arg2 = atoi(arrg);
        createFonk(arg1,arg2);
    }  else if(argc == 1) {
        printf("Basit, komut satirli hesap makinesi.\n\nKomutlar:\n-y : Klasik yardim komutu.\n-h <ilk-deger> <son-deger> <islem> : Hesaplama yapma komutu. \n  -- <islem> bolumune <t> (toplama), <c> (cikarma), <ca> (carpma), <b> (bolme) gelmesi gerekiyor.\n-th <ilk-deger> <islem> : Tek degerle yapilan hesaplama komutu.\n  -- <islem> bolumune <k>(degerin karesi), <kk>(degerin karekoku) gelmesi gerekiyor.\n");
    } else {
        printf("Hata: Eksik arguman girildi, program kapatiliyor.\n");
    }
    return 0;
}
