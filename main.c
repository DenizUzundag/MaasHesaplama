#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ad[50],soyad[50],yuksek_Ad[50],yuksek_soyad[50],Medeni_durum = ' ',es = ' ',secim = ' ', engel_durumu = ' ';
    long double tc_no,yuksek_Tc;
    float aylik_brut_asgari= 1777.50,aylik_brut,tum_brut_toplam=0,tum_net_toplam=0,tum_net_gelir=0,ort_aylik_brut=0;
    int cocuk_sayisi,engel_derecesi,engel_yuzdesi=0,calismayan_es,calisan_sayisi=0,ikiBin_alti=0,toplam_calisan;
    int evli_sayisi=0,bekar_sayisi=0,evli_yuzde=0,bekar_yuzde=0,calisanes_yuzdesi=0,calisanes=0;
    int onbes_vergi=0,yirmi_vergi=0,yirmiyedi_vergi=0,otuzbes_vergi=0,engel_indirimi=0;//vergiler
    int buyuk_cocuk_sayisi,kucuk_cocuk_sayisi,buyuk_cocuk_ek,kucuk_cocuk_ek;//cocuk sayýlarý ve ek gelir
    int  cocuk_ort=0,toplam_cocuk=0,cocuklu_calisan=0,ucden_Fazla=0,engelli_sayisi=0,engelli_yuzdesi=0;
    int ikiyuz_tl=0,yuz_tl=0,elli_tl=0,yirmi_tl =0,on_tl=0,bes_tl=0,bir_tl=0;
    int elli=0,yirmibes=0,on=0,bes=0,bir=0;
    float en_yuksek_brut=0,yuksek_Vergi=0,en_yuksek_net=0;//en yuksek net
    float gelir_kesinti,aylik_brut_ucret,aylik_brut_toplam,aylik_net_ucret,kalan=0;

     printf("****Personel Maas Hesaplama Yazilimi****\n");
     do{
          printf("\n");
          printf("Adi Giriniz:");
          scanf(" %s",ad);
          printf("Soyadi Giriniz:");
          scanf(" %s",soyad);
          printf("Tc Kimlik Numarasi Giriniz:");
          scanf("%lf",&tc_no);
          printf("Aylik brut ucret:");
          scanf("%f",&aylik_brut);
           if(aylik_brut<=aylik_brut_asgari)
         {
           aylik_brut_asgari=1777.50;
           printf("asgari ucretin altinda giris yapildigi icin asgari ucrete esitlendi\n");
         }
        else{
               aylik_brut_asgari=aylik_brut;
        }

        printf("Medeni durumu  evli/bekar (e/E/b/B karakterleri):");
        scanf("%s",&Medeni_durum);
       if(Medeni_durum == 'E' || Medeni_durum == 'e' )
      {
        evli_sayisi++;
        printf("Esin calisiyor mu evet/hayir (e/E/h/H karakterleri):");
        scanf("%s",&es);
        if(es=='h' || es =='H')
        {
              calismayan_es= 220;
              calisanes++;
        }
        else if(es=='E' || es== 'e')
        {
            calismayan_es= 0;
        }
}
        else
       {
        calismayan_es=0;
        bekar_sayisi++;
       }
        printf("Bakmakla yukumlu oldugu cocuk sayisi:");
        scanf("%d",&cocuk_sayisi);
        if(cocuk_sayisi>0){
        cocuklu_calisan++;
        toplam_cocuk+=cocuk_sayisi;
        cocuk_ort=toplam_cocuk/cocuklu_calisan;
        printf("Yasi 6dan buyuk olanlarin sayisi:");
        scanf("%d",&buyuk_cocuk_sayisi);
        buyuk_cocuk_ek=45*buyuk_cocuk_sayisi;
        kucuk_cocuk_sayisi=cocuk_sayisi-buyuk_cocuk_sayisi;
        kucuk_cocuk_ek=25*kucuk_cocuk_sayisi;
       }
        else {
        kucuk_cocuk_ek=0;
        buyuk_cocuk_ek=0;
        }
       if(cocuk_sayisi>3)
       {
        ucden_Fazla++;
        }
       printf("Engelli olup olmadigi evet/hayir (e/E/h/H karakterleri):");
       scanf("%s",&engel_durumu);
        if(engel_durumu == 'H' || engel_durumu=='h')
       {
           engel_indirimi=0;
           engel_derecesi =0;
       }
       if(engel_durumu == 'E' || engel_durumu == 'e')
       {
        engelli_sayisi++;
        printf("Engel Yuzdesi(1 ile 100 arasinda):");
        scanf("%d",&engel_yuzdesi);
        if(engel_yuzdesi>=80)
        {
        engel_derecesi=1;
        engel_indirimi = 900;
        }
         else if(engel_yuzdesi>=60 && engel_yuzdesi<80)
        {
            engel_derecesi =2;
            engel_indirimi =470;
        }
         else if(engel_yuzdesi>=40 && engel_yuzdesi<60)
        {
            engel_derecesi =3;
            engel_indirimi =210;
        }
        else{
            engel_durumu =0 ;
            engel_indirimi =0;
            printf("Engel indiriminden yararlanmiyor\n");
        }
       }

    printf("\n");
    printf("---CALISANIN BILGILERI---\n");
    printf("Ad ve Soyad: %s %s \n",ad,soyad);
    printf("Tc kimlik numarasy:%.0lf\n",tc_no);
    printf("Es icin aile yardimi odenegi(TL):%d\n",calismayan_es);
    printf("cocuk icin aile yardimi odenegi (TL):%4d\n",buyuk_cocuk_ek+kucuk_cocuk_ek);
    aylik_brut_toplam =(aylik_brut_asgari+buyuk_cocuk_ek+kucuk_cocuk_ek+calismayan_es);
    printf("Aylik Toplam Brut Ucret : %.2f\n",aylik_brut_toplam);
    tum_brut_toplam += aylik_brut_toplam;

    if(aylik_brut_toplam<2000)
    {
        gelir_kesinti = (aylik_brut_toplam*15)/100;
        onbes_vergi++;
    }
    else if(aylik_brut_toplam>=2000 &&aylik_brut_toplam<5000)
    {
        gelir_kesinti= (aylik_brut_toplam*20)/100;
        yirmi_vergi++;
    }
    else if(aylik_brut_toplam>=5000 && aylik_brut_toplam<10000)
    {
        gelir_kesinti = (aylik_brut_toplam*27)/100;
        yirmiyedi_vergi++;
    }
    else if(aylik_brut_toplam>=10000)
    {
        gelir_kesinti=(aylik_brut_toplam*35)/100;
        otuzbes_vergi++;
    }
       if(aylik_brut_toplam>en_yuksek_brut)
        {
        en_yuksek_brut=aylik_brut_toplam;;
         strcpy(yuksek_Ad,ad);
         strcpy(yuksek_soyad,soyad);

         yuksek_Vergi=gelir_kesinti;
        en_yuksek_brut=aylik_brut_toplam;
        en_yuksek_net=aylik_net_ucret;
        }

    printf("Aylik Gelir Vergisi Kesintisi : %.2f\n",gelir_kesinti);
    tum_net_gelir+=gelir_kesinti;

    printf("Engelli derecesi(1,2,3) :%d\n",engel_derecesi);
    printf("Engel indirimi:%d\n",engel_indirimi);
    if(gelir_kesinti<engel_indirimi)
        {
            gelir_kesinti=0;
            engel_indirimi=0;
            printf("Gelir vergisinden muaf tutuluyor\n");
         }
     aylik_net_ucret= (aylik_brut_toplam-gelir_kesinti+engel_indirimi);
     printf("Aylik Net Ucret : %.2f\n",aylik_net_ucret);
     tum_net_toplam+=aylik_net_ucret;
     if(aylik_net_ucret>en_yuksek_net)
     {
         en_yuksek_net=aylik_net_ucret;
         strcpy(yuksek_Ad,ad);
         strcpy(yuksek_soyad,soyad);

         yuksek_Vergi=gelir_kesinti;
        en_yuksek_brut=aylik_brut_toplam;
        en_yuksek_net=aylik_net_ucret;
     }

     if(aylik_net_ucret<2000)
        {
            ikiBin_alti++;
        }

        printf("Aylik net ucretin odenebilmesi icin tedavuldeki her para biriminden gereken:\n");
        if(aylik_net_ucret/200>=1)
        {
            ikiyuz_tl=aylik_net_ucret/200;
            if(ikiyuz_tl>0)
            kalan=aylik_net_ucret-ikiyuz_tl*200;
            printf("200 tl den gereken banklot sayisi:%d\n",ikiyuz_tl);
        }
        if(kalan/100>=1)
        {
            yuz_tl=kalan/100;
            if(yuz_tl>0)
            kalan=kalan-100*yuz_tl;
            printf("100 tl den gereken banknot sayisi:%d\n",yuz_tl);
        }
         if(kalan/50>=1)
        {
            elli_tl=kalan/50;
            if(elli_tl>0)
            kalan=kalan-50*elli_tl;
            printf("50 tl den gereken banknot sayisi:%d\n",elli_tl);

        }
         if(kalan/20>=1)
        {
            yirmi_tl=kalan/20;
            if(yirmi_tl>0)
            kalan=kalan-20*yirmi_tl;
            printf("20 tl den gereken banknot sayisi:%d\n",yirmi_tl);
        }
         if(kalan/10>=1)
        {
            on_tl=kalan/10;
            if(on_tl>0)
            kalan=kalan-10*on_tl;
            printf("10 tl den gereken banknot sayisi:%d\n",on_tl);
        }
         if(kalan/5>=1)
        {
            bes_tl=kalan/5;
            if(bes_tl>0)
            kalan=kalan-5*bes_tl;
            printf("5 tl den gereken banknot sayisi:%d\n",bes_tl);
        }
         if(kalan/1>=1)
        {
            bir_tl=kalan/1;
            if(bir_tl>0)
            kalan=kalan-1*bir_tl;
            printf("1 tl den gereken madeni para sayisi:%d\n",bir_tl);
        }
        if(kalan/0.50>=1 ||kalan/0.50<=1)
        {
            elli=kalan/0.50;
            if(elli>0)
            {
                kalan=kalan-0.50*elli;
            printf("50 kurustan den gereken madeni para sayisi:%d\n",elli);
           }
         }
          if(kalan/0.25<=1 || kalan/0.25>=1)
        {
            yirmibes=kalan/0.25;
            if(yirmibes>0)
            {
              kalan=kalan-0.25*yirmibes;
            printf("25 kurustan den gereken madeni para sayisi:%d\n",yirmibes);
            }
       }
         if(kalan/0.10<=1 || kalan/0.10>=1)
        {
           on=kalan/0.10;
           if(on>0)
           {
            kalan=kalan-0.10*on;
            printf("10 kurustan den gereken madeni para sayisi:%d\n",on);
           }

        }
        if(kalan/0.05<=1 || kalan/0.05>=1)
        {
            bes=kalan/0.05;
            if(bes>0)
            {
                kalan=kalan-0.05*bes;
            printf("5 kurustan den gereken madeni para sayisi:%d\n",bes);
            }
        }
        if(kalan/0.01<=1 || kalan/0.01>=1)
        {
            bir=kalan/0.01;
            if(bir>0)
            {
              kalan=kalan-0.01*bir;
              printf("1 kurustan den gereken madeni para sayisi:%d\n",bir);
            }
        }
        printf("Baska calisan girisi yapilacak mi  evet/hayir (e/E/h/H karakterleri):");
        scanf("%s",&secim);
        if(secim=='E'|| secim== 'e')
        {

        }
        calisan_sayisi++;
     evli_yuzde=(evli_sayisi*100)/calisan_sayisi;
     bekar_yuzde=(bekar_sayisi*100)/calisan_sayisi;
     calisanes_yuzdesi=(calisanes*100)/evli_sayisi;
    printf("------------------------------------------------------------------------");
    }while(secim !='h');
     printf("\n");
     printf("*****ISTATIKSEL BILGILER*****");
     printf("\n");
     printf("calisan  sayisi :%d\n" , calisan_sayisi);
     printf("Tum calisanlara bir ayda verilen toplam net ucret:%.2f\n",tum_net_toplam);
     printf("Devlete aktarilan aylik gelir vergisi toplami:%.2f\n",tum_net_gelir);
     printf("Tum calisanlarin aylik toplam brut ucretlerinin ortalamasi:%.2f\n",tum_brut_toplam/calisan_sayisi);
     printf("Tum calisanlarin aylik net ucretlerinin ortalamasi:%.2f\n",tum_net_toplam/calisan_sayisi);
     printf("2000 nin altinda net ucret alanlarin sayisi :%d\n",ikiBin_alti);
     printf("Vergi oranlarina gore calisan sayilari\n");
     printf("\n");
     printf("yuzde 15 vergi verenler = %4d\n",onbes_vergi);
     printf("yuzde 20 vergi verenler  = %4d\n",yirmi_vergi);
     printf("yuzde 27 vergi verenler = %4d\n",yirmiyedi_vergi);
     printf("yuzde 35 vergi verenler = %4d\n",otuzbes_vergi);
      printf("\n");
      printf("evli calisanlarin yuzdesi : %d\n",evli_yuzde);
      printf("bekar calisanlarin yuzdesi : %d\n",bekar_yuzde);
      printf("esleri calisanlarin calisanlarin yuzdesi : %d\n",calisanes_yuzdesi);
      printf("calisanlarin bakmakla yukumlu olduklari cocuk sayisinin ortalamasi:%4d\n",cocuk_ort);
      printf("3 den fazla cocugu olanlarin sayisi:%4d\n",ucden_Fazla);
      engelli_yuzdesi=(engelli_sayisi*100)/calisan_sayisi;
      printf("Engelli calisan sayisi ve tum calisanlar icinde yuzdesi:%4d %4d \n",engelli_sayisi,engelli_yuzdesi);
       printf("\n");
    printf("en yuksek net ucreti alan kisinin bilgileri\n");
     printf("adi : %s\n",yuksek_Ad);
     printf("soyadi: %s\n",yuksek_soyad);
     printf("tc no: %lf\n",yuksek_Tc);
      printf("vergi kesintisi:%.2f\n",yuksek_Vergi);
     printf("brut ucreti:%.2f\n",en_yuksek_brut);
     printf("net ucreti:%.2f\n",en_yuksek_net);
     printf("\n");
      printf("en yuksek brut ucreti alan kisinin bilgileri\n");
     printf("adi : %s\n",yuksek_Ad);
     printf("soyadi: %s\n",yuksek_soyad);
     printf("tc no: %lf\n",yuksek_Tc);
      printf("vergi kesintisi:%.2f\n",yuksek_Vergi);
     printf("brut ucreti:%.2f\n",en_yuksek_brut);
     printf("net ucreti:%.2f\n",en_yuksek_net);




return 0;

}

