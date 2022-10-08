#include<math.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

//BAŞTA SORULAN PAROLA 1234 OLARAK GİRİLECEKTİR

int main()
{
 setlocale(LC_ALL,"Turkish");
 char isim [155];
 int parola , bakiye=1000,i=1,*kayit;
 char sec, sec1, sec2, sec3, sec4, sec5;
 
 time_t zaman;
 struct tm *tarih[15];
 char buffer[80];
 time( &zaman );
 kayit=calloc(15,sizeof(int));
 
 system("cls");
 printf("\n \n \t\t\t TÜRKBANK İNTERNET BANKACILIĞI \n\n \t\t\t ONLİNE ATM HİZMETİ  \n");
 printf("\n Lütfen Isminizi Giriniz :");
 scanf("%s",&isim);
 printf("\n Hoşgeldiniz sayın %s , Lütfen Parola Girin:",isim);
 scanf("%d",&parola);
 if(parola==1234)
 {
	 printf("\n \n Hesabınıza 1000 lira hoşgeldin avansı yatırılmıştır \n\n");
	 printf("  \n  İşlem yapmak herhangi bir tuşa basınız  ");
	 getch();
	 menu:
	 system("cls");
	 printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
	 printf("\n \t ATM İŞLEMLERİ\n\n");
	 printf("\t ------------------\n\n");
	 printf("\t 1) Hesap İşlemleri \n\n");
	 printf("\t 2) Para Transferi \n\n");
	 printf("\t 3) Ödemeler \n\n");
	 printf("\t 4) Başvuru İşlemleri \n\n");
	 printf("\t 5) Cikis\n\n");
	 printf("Sayın %s lütfen yapmak istediğiniz işlemi seçiniz: \n",isim);
	 scanf("%s",&sec);
	 switch(sec)
	 {  
		  case '1':
		  {
		   menu1 :
		   system("cls");
		   printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
		   {
		   	 printf("\n \t HESAP İŞLEMLERİ \n\n");
		   	 printf("\t -------------------\n\n");
		     printf("\t 1) Para Çekme \n\n");
			 printf("\t 2) Para Yatırma \n\n");
			 printf("\t 3) Bakiye-Bilgi Sorgu \n\n");
	 		 printf("\t 4) Hesap Özeti \n\n");
	 		 printf("\t 5) IBAN Sorgulama \n\n");
	 		 printf("Sayın %s lütfen yapmak istediğiniz işlemi seçiniz: \n",isim);
			 scanf("%s",&sec1);
						switch(sec1)
						{
						case '1':
						{	
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						int cek;
						printf("\n\n \t PARA ÇEKME \n\n");
						printf("\t -------------------\n\n");
						printf("Çekmek istediğiniz para miktarını girin \n");
						scanf("%d",&cek);
						printf("Sayın %s , para çekme işleminiz gerçekleşmiştir. \n",isim);
						bakiye=bakiye-cek;
						printf("Hesabınızdaki kalan tutar %d tl'dir \n",bakiye);
						tarih[i] = localtime( &zaman );
						kayit[i]=-cek;
						i++;
						if(i>15)
						i=1;	
						}
					 	break;
						case '2' :
						{										
						int yat;
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t PARA YATIRMA \n\n");
						printf("\t -------------------\n\n");
						printf("Lütfen yatırmak istediğiniz para miktarını girin \n");
						scanf("%d",&yat);
						printf("Sayın %s ,para yatırma işleminiz gerçekleşmiştir. \n",isim);
						bakiye=bakiye+yat;
						printf("Hesabınızdaki kalan tutar %d tl'dir \n",bakiye);
						tarih[i] = localtime( &zaman );
						kayit[i]=yat;
						i++;
						if(i>15)
						i=1;
						}
						break;
						case '3' :
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t BAKİYE-BİLGİ SORGU \n\n");
						printf("\t ------------------------\n\n");
						printf("Sayın %s , hesap bakiyeniz %d tl'dir \n",isim,bakiye);
						}
						break;
						case '4' :
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t HESAP ÖZETİ \n\n");
						printf("\t --------------------------------\n\n");
						printf(" Tutar   \tİşlem Tipi  \tTarih\n");
						printf(" --------\t----------  \t-----\n");
						for(i=1;i<=15;i++)
						{
						if(kayit[i]<0)
						{
							kayit[i]=-kayit[i];
							printf("%4.d Lira\tPara Çekme  \t%s",kayit[i],asctime(tarih[i]));
						}
						else if(kayit[i]>0)
						{
							printf("%4.d Lira\tPara Yatırma\t%s",kayit[i],asctime(tarih[i]));
						}
						}
						}
						break;
						case '5' :
						{
													
						double hesno;
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t IBAN SORGULAMA \n\n");
						printf("\t --------------------\n\n");
						printf("\n Sayın %s , Kartınızın üstündeki 16 haneli numarayı boşluksuz girin \n",isim);
						scanf("%lf",&hesno);		
						if(1010000000000000<=hesno&&hesno<=9990000000000000)
						printf("\n IBAN NO = TR56 00061 0 %.0f \n",hesno);
						else
						printf("Giriginiz numara XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");												
						}
						break;
						}		
		   }
						secenekler1:
						printf("\n >>>  (A=Ana Menü/M=Seçim Menüsü/C=Çıkış):");
						scanf("%s",&sec);
						if(sec=='a'||sec=='A')
						{system("cls");
						goto menu;}
						else if(sec=='m'||sec=='M')														   
						{system("cls");
						goto menu1;}
						else if(sec=='c'||sec=='C')
						{exit(0);}
						else
						{printf("Lutfen varolan bir secenegi giriniz\n");
						getch();
						system("cls");
						goto secenekler1;}
						}
						break;												  
						case '2':
						{
						menu2 :
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						{								   
						printf("\n \t  PARA TRANSFERİ \n\n");
						printf("\t -------------------\n\n");
						printf("\t 1) Havale İşlemleri \n\n");
						printf("\t 2) Cebe Havale  \n\n");
						printf("\t 3) Hesaba EFT \n\n");
						printf("Sayın %s , Lütfen yapmak istediğiniz işlemi seçiniz: \n",isim);
						scanf("%s",&sec2);
						switch(sec2)
						{
						case '1':
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t HAVALE İŞLEMLERİ \n\n");
						printf("\t ----------------------\n\n");
						printf("\n Sayın %s Başka bir bankaya ait hesaba havale için lütfen önceki menüden \n EFT işlemini seçiniz. \n \n",isim);
						double hesno;
						int havale;																
						printf("\n Havale etmek istediğiniz miktarı tl cinsinden girin \n");
						scanf("%d",&havale);
						printf("\n Para havale etmek istediğiniz 16 haneli hesap numarasını girin \n");
						scanf("%lf",&hesno);																								
						if(1010000000000000<=hesno&&hesno<=9990000000000000)
						{
						printf("\n Sayın %s %16.0f nolu hesaba %d lira havale işleminiz gerçekleşmiştir. \n",isim,hesno,havale);
						printf("\n Havale işleminiz hesap özetinize işlenememektedir.\n Lütfen banka ile iletişime geçin. \n");
						}					
						else
						printf("Giriginiz numara XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");								
						}
						break;
						case '2' :
						{
						double deneme;
						int havale;
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n \t CEBE HAVALE \n\n");
						printf(" \t --------------- \n\n");
						printf("\n Havale etmek istediğiniz miktarı tl cinsinden girin \n");
						scanf("%d",&havale);
						printf("Havale yapmak istediğiniz cep numarasını girin\n ");
						printf("Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");	
						scanf("%lf",&deneme);
						if(5010000000<=deneme&&deneme<=5550000000)
						printf("Sayın %s , %.0lf numarasına %d lira havale işleminiz gerçekleşmiştir.  ",isim,deneme,havale);
						else
						printf("HATALI GİRİŞ ! \n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
						}
						break;
						case '3' :
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t HESABA EFT \n\n");
						printf("\t -------------------\n\n");
						double hesno;
						int havale;
						char bankad[111];																					
						printf("\n Sayın %s EFT yapmak istediğiniz hesabın ait olduğu bankanın 'yalnızca ismini' girin \n",isim);
						printf(" 'XXX bankası' şeklinde girişler kabul edilmemektedir, sadece XXX kısmını yazın. \n");
						scanf("%s",&bankad);
						printf("\n Havale etmek istediğiniz miktarı tl cinsinden girin \n");
						scanf("%d",&havale);
						printf("\n Para havale etmek istediğiniz 16 haneli hesap numarasını girin \n");
						scanf("%lf",&hesno);
						if(1010000000000000<=hesno &&hesno <=9990000000000000)
						{
							printf("\n Sayın %s , %s bankasına ait %16.0f nolu hesaba \n %d lira havale işleminiz gerçekleşmiştir. \n",isim,bankad,hesno,havale);
							printf("\n EFT işleminiz hesap özetinize işlenememektedir. \n Lütfen banka ile iletişime geçin. \n");
						}																													
						else
							printf("Giriginiz hesap numarası XXXXXXXXXXXXXXX formatinda 16 haneli olmalidir.\n");																																																																														
						}
						break;							
						}									 		 	
						}
						secenekler2:
						printf("\n >>>  (A=Ana Menü/M=Seçim Menüsü/C=Çıkış):");
						scanf("%s",&sec);
						if(sec=='a'||sec=='A')
						{system("cls");
						goto menu;}
						else if(sec=='m'||sec=='M')
						{system("cls");
						goto menu2;}
						else if(sec=='c'||sec=='C')
						{exit(0);}
						else
						{printf("Lutfen varolan bir secenegi giriniz\n");
						getch();
						system("cls");
						goto secenekler2;}
						}
						break;										  
						case '3':
						{
						menu3 :
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						{																  
						printf("\n \t  ÖDEMELER \n\n");
						printf("\t -------------\n\n");
						printf("\t 1) TL Yükleme ( TC, KKTC tüm operatörler) \n\n");  	  
						printf("\t 2) Üniversite Katkı Payı ödeme  \n\n");															      
						printf("Sayın %s Lütfen yapmak istediğiniz işlemi seçiniz: \n",isim);
						scanf("%s",&sec3);
						switch(sec3)
						{
						case '1':
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t TL YÜKLEME ( TC, KKTC tüm operatörler)\n");
						printf("\t --------------------------------\n\n");
						double deneme;
						int yukleme;
						printf("\n Sayın %s Yüklemek istediğiniz miktarı tl cinsinden girin \n",isim);
						scanf("%d",&yukleme);
						printf("Yükleme yapmak istediğiniz cep numarasını girin\n ");
						printf("Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
						scanf("%lf",&deneme);
						if(5010000000<=deneme&&deneme<=5550000000)
						printf("%.0lf numarasına %d lira havale işleminiz gerçekleşmiştir.  ",deneme,yukleme);
						else
						printf("HATALI GİRİŞ ! \n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
						}
						break;
						case '2' :
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t 2) ÜNİVERSİTE KATKI PAYI ÖDEME \n");
						printf("\t --------------------------------\n\n");
						double deneme;
						int yukleme;
						char uni [155];
						char fak [155];
						printf(" Sayın %s Lütfen üniversitenizin 'yalnızca ismini' girin \n",isim);
						printf(" 'XXX üniversitesi' şeklinde girişler kabul edilmemektedir, sadece XXX kısmını yazın. \n");
						scanf("%s",&uni);
						printf("Lütfen fakültenizin 'yalnızca ismini' girin \n");
						printf(" 'XXX fakültesi' şeklinde girişler kabul edilmemektedir, sadece XXX kısmını yazın. \n");
						scanf("%s",&fak);
						printf("\n Yatırmak istediğiniz katkı payı miktarını tl cinsinden girin \n");
						scanf("%d",&yukleme);
						printf("Lütfen okul Numaranızı girin\n ");
						printf("Giriginiz numara XXXXXXXXX formatinda 9 haneli olmalidir.\n");
						scanf("%lf",&deneme);
						if(101000000<=deneme&&deneme<=999000000)
						printf(" %s Üniversitesi %s Fakültesi %.0lf numaralı öğrenci adına \n %d lira havale işleminiz gerçekleşmiştir.  ",uni,fak,deneme,yukleme);
						else
						printf("HATALI GİRİŞ ! \n Giriginiz numara XXXXXXXXX formatinda ve 9 haneli olmalidir.\n");														      							
						}
						break;						
						}			  
						}
						secenekler3:
						printf("\n >>>  (A=Ana Menü/M=Seçim Menüsü/C=Çıkış):");
						scanf("%s",&sec);
						if(sec=='a'||sec=='A')
						{system("cls");
						goto menu;}
						else if(sec=='m'||sec=='M')
						{system("cls");
						goto menu3;}
						else if(sec=='c'||sec=='C')
						{exit(0);}
						else
						{printf("Yanlış seçim yaptınız.\n");
						getch();
						system("cls");
						goto secenekler3;}
						}
						break;
						menu5 :
						case '4':
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						{
						printf("\n \t  BAŞVURU İŞLEMLERİ \n\n");
						printf("\t ----------------------\n\n");
						printf("\t 1) Bireysel Kredi Başvuru \n\n");
						printf("\t 2) Kredi Kartı Başvurusu \n\n");
						printf("Sayın %s Lütfen yapmak istediğiniz işlemi seçiniz: \n",isim);
						scanf("%s",&sec5);
						switch(sec5)
						{
						case '1':
						{	menukredi :
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t BİREYSEL KREDİ BAŞVURUSU \n\n");
						printf("\t --------------------------------\n\n");
						double tcno , tel;
						int gun,ay,yil;
						basla:
						printf("\n Sayın %s TC Kimlik Numaranızı girin \n\n",isim);
						scanf("%lf",&tcno);
						if(10000000000<=tcno&&tcno <=99999999999)
						{
						basla2:
						printf("\n Cep telefonu Numaranızı girin \n\n");
						scanf("%lf",&tel);
						if(5010000000<=tel&&tel<=5550000000)	
						{
							//	printf("doğru") ;
						}
						else
						{
						printf("\n Giriginiz numara 5XXXXXXXXX formatinda 10 haneli olmalidir.\n");
						goto basla2 ;
						}		
						}	
						else
						{
						printf("\n Giriginiz numara XXXXXXXXXXX formatinda 11 haneli olmalidir.\n");
						goto basla;
						}		
						def :
						printf("\n Doğum tarihinizin gününü girin \n\n");
						scanf("%d",&gun);
						printf("\n Doğum tarihinizin ayını rakamla girin \n\n");
						scanf("%d",&ay);
						printf("\n Doğum tarihinizin yılını girin \n\n");
						scanf("%d",&yil);		
						system("cls");	
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");							
						printf("\n Sayın %s Bilgilerinizin doğruluğunu lütfen kontrol edin. \n\n",isim);
						printf("\n TC Kimlik Numaranız = %.0lf \n\n",tcno);
						printf("\n Cep telefonu Numaranız = %.0lf \n\n",tel);
						printf("\n Doğum tarihiniz = %d/%d/%d \n\n",gun,ay,yil);
						seceneklerk :
						printf("\n >>> Bilgileriniz doğru mu?  (Y=Yanlış/D=Doğru):");
						scanf("%s",&sec);
						if(sec=='y'||sec=='Y')
						{system("cls");
						goto basla;}
						else if(sec=='d'||sec=='D')													   
						{system("cls");
						goto devam;}
						else
						{printf("Lutfen varolan bir secenegi giriniz\n");
						getch();
						system("cls");
						goto seceneklerk;}
						devam:
						printf("\n Sayın %s Faizsiz Kredi başvurunuz alınmıştır.\n\n Bizi tercih ettiğiniz için teşekkür ederiz. \n",isim);																											
						}
						break;
						case '2' :
						{
						system("cls");
						printf("\n -------------------Türkbank - Faizsiz Helal Bankacılık----------------------- \n\n");
						printf("\n\n \t KREDİ KARTI BAŞVURUSU \n\n");
						printf("\t --------------------------------\n\n");
						printf(" Sayın %s Lütfen TC kimlik numaranızı giriniz. \n",isim);
						double deneme;
						scanf("%lf",&deneme);
						if(10000000000<=deneme&&deneme<=99999999999)
						printf("Kredi kartı başvurunuz alınmıştır. \n Teşekkür ederiz.");
						else
						printf(" Hatalı Giriş ! \n TC kimlik numarası XXXXXXXXX formatında ve 11 haneli olmalidir.\n");		
						}
						break;									
						}
						}
						secenekler5:
						printf("\n >>>  (A=Ana Menü/M=Seçim Menüsü/C=Çıkış):");
						scanf("%s",&sec);
						if(sec=='a'||sec=='A')
						{system("cls");
						goto menu;}
						else if(sec=='m'||sec=='M')
						{system("cls");
						goto menu5;}
						else if(sec=='c'||sec=='C')
						{exit(0);}
						else
						{printf("Lutfen varolan bir secenegi giriniz\n");
						getch();
						system("cls");
						goto secenekler5;}
						}
						break;
						case '5':
						{exit(0);}
						break;
						default:
						{printf("Lutfen varolan bir secenegi giriniz\n");
						getch();
						goto menu;}
	}
}
						else
						printf("\n Sayın %s Üzgünüz, parolayı yanlış girdiniz.\n Lütfen banka ile iletişime geçin.\n",isim);
						return 0;
}
