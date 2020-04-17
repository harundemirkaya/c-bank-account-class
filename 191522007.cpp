#include <iostream>
#include "hesap.h"
#include <ctime>
using namespace std;
struct ozet{ // Hesap hareketleri için bilgi kýsmý oluþturuyoruz.
	string tarih;
	double miktar;
	string bilgi;
};
int main(){
	setlocale(LC_ALL, "Turkish"); // Türkçe Karakter Kullanýmýný açýyoruz.
	string isim; // Hesap sahibinin adý soyadý için string tanýmlýyoruz.
	struct ozet kayit[10]; // Main'in dýþýnda tanýmladýðýmý struct ozet adlý bilgi deposu için bir deðiþken dizisi tanýmlýyoruz.
	int hesapno,tmp1=1,i=0; // Hesap numarasý, tuþlama girdisi, özet kaydý sayacý tanýmlýyoruz.
	double bakiye; // Hesap bakiyesi tanýmlýyoruz.
	cout << "Kayýtlý hesap bulunamadý. Lütfen hesap oluþturunuz." << endl; // Giriþte hesap bulunmadýðýnný belirtiyoruz.
	cout << "Ýsim Soyisim: "; // Hesap oluþturuyoruz.
	getline (cin, isim); // Boþluklarý saymasý için cin fonksiyonu yerine getline fonksiyonunu kullanýyoruz.
	cout << "Bakiye: ";
	cin >> bakiye;
	cout << "Hesap Numarasý: ";
	cin >> hesapno;
	hesap hesap(hesapno,isim,bakiye); // Kullanýcýdan aldýðýmýz bilgileri hesap sýnýfýmýza aktarýyoruz.
	time_t tarih = time(NULL); // Hesap hareketi için tarih tutucumuzu etkinleþtiriyoruz.
	if(isim == "") // Eðer isim girilmez ise hesap oluþturmasý baþarýsýz olsun. Bilgiler yine de gönderilir fakat tüm iþlemlerde isim sorgusu yaptýðýmýz için hesap inaktif olmuþ olur.
		cout << "\nBilgi eksikliðinden dolayý hesap oluþturulamadý.Lütfen iþlem yapmak için yeni hesap oluþturunuz." << endl;
	else
		cout << "\nHesabýnýz baþarýyla oluþturuldu.\n" << endl;
	kayit[i].bilgi = "Hesap oluþturuldu"; // Hesap özetinde yazdýrýlacak cümle.
	kayit[i].tarih = ctime(&tarih); // Hesap özetinde yazdýrýlacak tarih.
	i++; // Özet sayacýmýzý arttýrýyoruz. Bir sonraki hareketi kaydedebilmesi için.
	while(tmp1 !=0){ // Ýþlem seçeneklerimizi baþlatýyoruz. 0 -> Çýkýþ iþlemi.
		cout << "\nYapmak istediðiniz iþlemi tuþlayýnýz.\n1) Yeni Hesap Oluþturma\n2) Kayýtlý Hesabý Silme\n3) Para Yatýrma\n4) Para Çekme\n5) Bakiye Sorgulama" << endl;
		cout << "6) Hesap Özeti\n0) Çýkýþ" << endl << endl;
		cin >> tmp1;
		if(tmp1 == 1){ // Yeni hesap oluþturuyoruz.
			cout << "Ýsim: ";
			cin.ignore(); // Bir önceki oluþturmada getline kullandýðýmýz için cin fonksiyonu belleðini temizliyoruz. Bunu kullanmazsak getline fonksiyonunu atlar.
			getline (cin,isim); // Ýsim alýyoruz. Boþluk saymasý için getline kullanýyoruz.
			cout << "Bakiye: ";
			cin >> bakiye;
			cout << "Hesap Numarasý: ";
			cin >> hesapno;
			hesap.yenihesap(hesapno,isim,bakiye); // Yeni hesap bilgilerimizi hesap sýnýfýmýza gönderiyoruz.
			kayit[0].bilgi = "Yeni hesap oluþturuldu"; // Hesap özetinde yazdýrýlacak cümle.
			kayit[0].tarih = ctime(&tarih); // Hesap özetinde yazdýrýlacak tarih.
			if(isim == "") // Ýsim boþ geçilirse tekrardan hesap oluþturulamadý hatasý veriyoruz.
				cout << "\nBilgi eksikliðinden dolayý hesap oluþturulamadý.Lütfen iþlem yapmak için yeni hesap oluþturunuz." << endl;
			else
				cout << "\nHesabýnýz baþarýyla oluþturuldu.\n" << endl;
		}
		else if(tmp1 == 2){ // Hesap silme iþlemini gerçekleþtiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayýtlý Hesap Bulunamadý.\n" << endl;
			else{
				isim=""; // Ýsimi boþaltarak hesaba silinmiþ süsü veriyoruz. Diðer bilgileride sýfýrlýyoruz.
				bakiye=0;
				hesapno=0;
				hesap.hesapsil(hesapno,isim,bakiye); // Sýfýrlanmýþ halini mevcut sýnýfýmýzýn nesnesine gönderiyoruz.
				i = 0; // Sildiðimiz hesabýn hesap hareketlerinide sýfýrlamak için i sayacýný sýfýrlýyoruz.
			}
		}
		else if(tmp1 == 3){ // Para yatýrma iþlemi gerçekleþtiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayýtlý Hesap Bulunamadý.\n" << endl;
			else{
				cout << "Yatýrmak istediðiniz miktarý giriniz: ";
				double miktar; // Yatýrmak istenen miktarý tanýmlýyoruz.
				cin >> miktar;
				hesap.parayatir(miktar); // Hesap sýnýfýmýzýn para yatýrma iþlevini gören fonksiyonunu çalýþtýrýyoruz.
				time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yaptýðýmýz iþlemleri gönderiyoruz.
				kayit[i].bilgi = "Türk Lirasý Yatýrýldý.";
				kayit[i].miktar = miktar;
				kayit[i].tarih = ctime(&tarih);
				i++; // Bir sonraki iþlem için sayacý arttýrýyoruz.
			}
		}
		else if(tmp1 == 4){ // Para çekme iþlemini gerçekleþtiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayýtlý Hesap Bulunamadý.\n" << endl;
			else{
				cout << "Çekmek istediðiniz miktarý giriniz: ";
				double miktar; // Çekilecek miktarý tanýmlýyoruz.
				cin >> miktar;
				double tmp3 = hesap.bakiyegoster(); // tmp3 adlý deðiþkene hesaptaki parayý return ediyoruz.
				if(tmp3-miktar<0) // Çekmek istenen para hesapta var mý yok mu kontrol ediyoruz.
					cout << "Bu iþlem için yeterli miktarda bakiyeniz bulunmamaktadýr." << endl;
				else{
					hesap.paracek(miktar); // Hesap sýnýfýmýzýn para çekme iþlevini gören fonksiyonunu çalýþtýrýyoruz.
					time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yaptýðýmýz iþlemleri gönderiyoruz.
					kayit[i].bilgi = "Türk Lirasý Çekildi.";
					kayit[i].miktar = miktar;
					kayit[i].tarih = ctime(&tarih);
					i++; // Bir sonraki iþlem için sayacý arttýrýyoruz.
				}
			}
		}
		else if(tmp1 == 5){ // Bakiye sorma iþlemini gerçekleþtiriyoruz.
				hesap.bakiyesor(isim); // Hesap sýnýfýmýzýn bakiye sorgulama iþlevini gören fonksiyonunu çalýþtýrýyoruz.
		}
		else if(tmp1 == 6){ // Hesap özeti(hareketleri)'ni gösterme iþlemini gerçekleþtiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayýtlý Hesap Bulunamadý.\n" << endl;
			else{
				int tmp2 = i; // Bir sonraki hesap özeti iþlemi için þuan ki i sayacýný farklý bir deðiþkende tutuyoruz. Ýþlem bitiminde i'ye tekrar ayný deðerini vereceðiz.
				i--; // En son yapýlan iþlemde fazla olarak arttýrýlmýþ i sayacýný bir eksiltiyoruz.
				cout << "\nHesap Özetiniz: " << endl << endl; // Hesap özetini gösteriyoruz.
				for(;i>0; i--) // Hareketleri bir dizide tuttuðumuz için döngü kullanarak dizide ki hareketleri listeliyoruz.
					cout << kayit[i].tarih << kayit[i].miktar << " " << kayit[i].bilgi << endl << endl;
				cout << kayit[0].tarih << kayit[0].bilgi << endl; // Listemizin en sonuna hesap oluþturma tarihini ve bilgisini ekliyoruz.
				i = tmp2; // Döngüde deðiþtirilmiþ olan i sayacýný tekrardan eski haline döndürüyoruz ki bir sonraki hesap özeti sorgulamasýnda doðru çalýþsýn.
			}
		}
		else if(tmp1 == 0) // Çýkýþ iþlemini gerçekleþtiriyoruz.
			cout << "Ýyi günler";
		else // Listede olmayan iþlem tuþlarý için hatalý tuþlama hatasý veriyoruz.
			cout << "\nHatalý tuþlama." << endl;
	}
	return 0;
}
