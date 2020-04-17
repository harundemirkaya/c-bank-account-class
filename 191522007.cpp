#include <iostream>
#include "hesap.h"
#include <ctime>
using namespace std;
struct ozet{ // Hesap hareketleri i�in bilgi k�sm� olu�turuyoruz.
	string tarih;
	double miktar;
	string bilgi;
};
int main(){
	setlocale(LC_ALL, "Turkish"); // T�rk�e Karakter Kullan�m�n� a��yoruz.
	string isim; // Hesap sahibinin ad� soyad� i�in string tan�ml�yoruz.
	struct ozet kayit[10]; // Main'in d���nda tan�mlad���m� struct ozet adl� bilgi deposu i�in bir de�i�ken dizisi tan�ml�yoruz.
	int hesapno,tmp1=1,i=0; // Hesap numaras�, tu�lama girdisi, �zet kayd� sayac� tan�ml�yoruz.
	double bakiye; // Hesap bakiyesi tan�ml�yoruz.
	cout << "Kay�tl� hesap bulunamad�. L�tfen hesap olu�turunuz." << endl; // Giri�te hesap bulunmad���nn� belirtiyoruz.
	cout << "�sim Soyisim: "; // Hesap olu�turuyoruz.
	getline (cin, isim); // Bo�luklar� saymas� i�in cin fonksiyonu yerine getline fonksiyonunu kullan�yoruz.
	cout << "Bakiye: ";
	cin >> bakiye;
	cout << "Hesap Numaras�: ";
	cin >> hesapno;
	hesap hesap(hesapno,isim,bakiye); // Kullan�c�dan ald���m�z bilgileri hesap s�n�f�m�za aktar�yoruz.
	time_t tarih = time(NULL); // Hesap hareketi i�in tarih tutucumuzu etkinle�tiriyoruz.
	if(isim == "") // E�er isim girilmez ise hesap olu�turmas� ba�ar�s�z olsun. Bilgiler yine de g�nderilir fakat t�m i�lemlerde isim sorgusu yapt���m�z i�in hesap inaktif olmu� olur.
		cout << "\nBilgi eksikli�inden dolay� hesap olu�turulamad�.L�tfen i�lem yapmak i�in yeni hesap olu�turunuz." << endl;
	else
		cout << "\nHesab�n�z ba�ar�yla olu�turuldu.\n" << endl;
	kayit[i].bilgi = "Hesap olu�turuldu"; // Hesap �zetinde yazd�r�lacak c�mle.
	kayit[i].tarih = ctime(&tarih); // Hesap �zetinde yazd�r�lacak tarih.
	i++; // �zet sayac�m�z� artt�r�yoruz. Bir sonraki hareketi kaydedebilmesi i�in.
	while(tmp1 !=0){ // ��lem se�eneklerimizi ba�lat�yoruz. 0 -> ��k�� i�lemi.
		cout << "\nYapmak istedi�iniz i�lemi tu�lay�n�z.\n1) Yeni Hesap Olu�turma\n2) Kay�tl� Hesab� Silme\n3) Para Yat�rma\n4) Para �ekme\n5) Bakiye Sorgulama" << endl;
		cout << "6) Hesap �zeti\n0) ��k��" << endl << endl;
		cin >> tmp1;
		if(tmp1 == 1){ // Yeni hesap olu�turuyoruz.
			cout << "�sim: ";
			cin.ignore(); // Bir �nceki olu�turmada getline kulland���m�z i�in cin fonksiyonu belle�ini temizliyoruz. Bunu kullanmazsak getline fonksiyonunu atlar.
			getline (cin,isim); // �sim al�yoruz. Bo�luk saymas� i�in getline kullan�yoruz.
			cout << "Bakiye: ";
			cin >> bakiye;
			cout << "Hesap Numaras�: ";
			cin >> hesapno;
			hesap.yenihesap(hesapno,isim,bakiye); // Yeni hesap bilgilerimizi hesap s�n�f�m�za g�nderiyoruz.
			kayit[0].bilgi = "Yeni hesap olu�turuldu"; // Hesap �zetinde yazd�r�lacak c�mle.
			kayit[0].tarih = ctime(&tarih); // Hesap �zetinde yazd�r�lacak tarih.
			if(isim == "") // �sim bo� ge�ilirse tekrardan hesap olu�turulamad� hatas� veriyoruz.
				cout << "\nBilgi eksikli�inden dolay� hesap olu�turulamad�.L�tfen i�lem yapmak i�in yeni hesap olu�turunuz." << endl;
			else
				cout << "\nHesab�n�z ba�ar�yla olu�turuldu.\n" << endl;
		}
		else if(tmp1 == 2){ // Hesap silme i�lemini ger�ekle�tiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKay�tl� Hesap Bulunamad�.\n" << endl;
			else{
				isim=""; // �simi bo�altarak hesaba silinmi� s�s� veriyoruz. Di�er bilgileride s�f�rl�yoruz.
				bakiye=0;
				hesapno=0;
				hesap.hesapsil(hesapno,isim,bakiye); // S�f�rlanm�� halini mevcut s�n�f�m�z�n nesnesine g�nderiyoruz.
				i = 0; // Sildi�imiz hesab�n hesap hareketlerinide s�f�rlamak i�in i sayac�n� s�f�rl�yoruz.
			}
		}
		else if(tmp1 == 3){ // Para yat�rma i�lemi ger�ekle�tiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKay�tl� Hesap Bulunamad�.\n" << endl;
			else{
				cout << "Yat�rmak istedi�iniz miktar� giriniz: ";
				double miktar; // Yat�rmak istenen miktar� tan�ml�yoruz.
				cin >> miktar;
				hesap.parayatir(miktar); // Hesap s�n�f�m�z�n para yat�rma i�levini g�ren fonksiyonunu �al��t�r�yoruz.
				time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yapt���m�z i�lemleri g�nderiyoruz.
				kayit[i].bilgi = "T�rk Liras� Yat�r�ld�.";
				kayit[i].miktar = miktar;
				kayit[i].tarih = ctime(&tarih);
				i++; // Bir sonraki i�lem i�in sayac� artt�r�yoruz.
			}
		}
		else if(tmp1 == 4){ // Para �ekme i�lemini ger�ekle�tiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKay�tl� Hesap Bulunamad�.\n" << endl;
			else{
				cout << "�ekmek istedi�iniz miktar� giriniz: ";
				double miktar; // �ekilecek miktar� tan�ml�yoruz.
				cin >> miktar;
				double tmp3 = hesap.bakiyegoster(); // tmp3 adl� de�i�kene hesaptaki paray� return ediyoruz.
				if(tmp3-miktar<0) // �ekmek istenen para hesapta var m� yok mu kontrol ediyoruz.
					cout << "Bu i�lem i�in yeterli miktarda bakiyeniz bulunmamaktad�r." << endl;
				else{
					hesap.paracek(miktar); // Hesap s�n�f�m�z�n para �ekme i�levini g�ren fonksiyonunu �al��t�r�yoruz.
					time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yapt���m�z i�lemleri g�nderiyoruz.
					kayit[i].bilgi = "T�rk Liras� �ekildi.";
					kayit[i].miktar = miktar;
					kayit[i].tarih = ctime(&tarih);
					i++; // Bir sonraki i�lem i�in sayac� artt�r�yoruz.
				}
			}
		}
		else if(tmp1 == 5){ // Bakiye sorma i�lemini ger�ekle�tiriyoruz.
				hesap.bakiyesor(isim); // Hesap s�n�f�m�z�n bakiye sorgulama i�levini g�ren fonksiyonunu �al��t�r�yoruz.
		}
		else if(tmp1 == 6){ // Hesap �zeti(hareketleri)'ni g�sterme i�lemini ger�ekle�tiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKay�tl� Hesap Bulunamad�.\n" << endl;
			else{
				int tmp2 = i; // Bir sonraki hesap �zeti i�lemi i�in �uan ki i sayac�n� farkl� bir de�i�kende tutuyoruz. ��lem bitiminde i'ye tekrar ayn� de�erini verece�iz.
				i--; // En son yap�lan i�lemde fazla olarak artt�r�lm�� i sayac�n� bir eksiltiyoruz.
				cout << "\nHesap �zetiniz: " << endl << endl; // Hesap �zetini g�steriyoruz.
				for(;i>0; i--) // Hareketleri bir dizide tuttu�umuz i�in d�ng� kullanarak dizide ki hareketleri listeliyoruz.
					cout << kayit[i].tarih << kayit[i].miktar << " " << kayit[i].bilgi << endl << endl;
				cout << kayit[0].tarih << kayit[0].bilgi << endl; // Listemizin en sonuna hesap olu�turma tarihini ve bilgisini ekliyoruz.
				i = tmp2; // D�ng�de de�i�tirilmi� olan i sayac�n� tekrardan eski haline d�nd�r�yoruz ki bir sonraki hesap �zeti sorgulamas�nda do�ru �al��s�n.
			}
		}
		else if(tmp1 == 0) // ��k�� i�lemini ger�ekle�tiriyoruz.
			cout << "�yi g�nler";
		else // Listede olmayan i�lem tu�lar� i�in hatal� tu�lama hatas� veriyoruz.
			cout << "\nHatal� tu�lama." << endl;
	}
	return 0;
}
