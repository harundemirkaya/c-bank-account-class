#include <iostream>
#include "hesap.h"
#include <ctime>
using namespace std;
struct ozet{ // Hesap hareketleri için bilgi kısmı oluşturuyoruz.
	string tarih;
	double miktar;
	string bilgi;
};
int main(){
	setlocale(LC_ALL, "Turkish"); // Türkçe Karakter Kullanımını açıyoruz.
	string isim; // Hesap sahibinin adı soyadı için string tanımlıyoruz.
	struct ozet kayit[10]; // Main'in dışında tanımladığımı struct ozet adlı bilgi deposu için bir değişken dizisi tanımlıyoruz.
	int hesapno,tmp1=1,i=0; // Hesap numarası, tuşlama girdisi, özet kaydı sayacı tanımlıyoruz.
	double bakiye; // Hesap bakiyesi tanımlıyoruz.
	cout << "Kayıtlı hesap bulunamadı. Lütfen hesap oluşturunuz." << endl; // Girişte hesap bulunmadığınnı belirtiyoruz.
	cout << "İsim Soyisim: "; // Hesap oluşturuyoruz.
	getline (cin, isim); // Boşlukları sayması için cin fonksiyonu yerine getline fonksiyonunu kullanıyoruz.
	cout << "Bakiye: ";
	cin >> bakiye;
	cout << "Hesap Numarası: ";
	cin >> hesapno;
	hesap hesap(hesapno,isim,bakiye); // Kullanıcıdan aldığımız bilgileri hesap sınıfımıza aktarıyoruz.
	time_t tarih = time(NULL); // Hesap hareketi için tarih tutucumuzu etkinleştiriyoruz.
	if(isim == "") // Eğer isim girilmez ise hesap oluşturması başarısız olsun. Bilgiler yine de gönderilir fakat tüm işlemlerde isim sorgusu yaptığımız için hesap inaktif olmuş olur.
		cout << "\nBilgi eksikliğinden dolayı hesap oluşturulamadı.Lütfen işlem yapmak için yeni hesap oluşturunuz." << endl;
	else
		cout << "\nHesabınız başarıyla oluşturuldu.\n" << endl;
	kayit[i].bilgi = "Hesap oluşturuldu"; // Hesap özetinde yazdırılacak cümle.
	kayit[i].tarih = ctime(&tarih); // Hesap özetinde yazdırılacak tarih.
	i++; // Özet sayacımızı arttırıyoruz. Bir sonraki hareketi kaydedebilmesi için.
	while(tmp1 !=0){ // İşlem seçeneklerimizi başlatıyoruz. 0 -> Çıkış işlemi.
		cout << "\nYapmak istediğiniz işlemi tuşlayınız.\n1) Yeni Hesap Oluşturma\n2) Kayıtlı Hesabı Silme\n3) Para Yatırma\n4) Para Çekme\n5) Bakiye Sorgulama" << endl;
		cout << "6) Hesap Özeti\n0) Çıkış" << endl << endl;
		cin >> tmp1;
		if(tmp1 == 1){ // Yeni hesap oluşturuyoruz.
			cout << "İsim: ";
			cin.ignore(); // Bir önceki oluşturmada getline kullandığımız için cin fonksiyonu belleğini temizliyoruz. Bunu kullanmazsak getline fonksiyonunu atlar.
			getline (cin,isim); // İsim alıyoruz. Boşluk sayması için getline kullanıyoruz.
			cout << "Bakiye: ";
			cin >> bakiye;
			cout << "Hesap Numarası: ";
			cin >> hesapno;
			hesap.yenihesap(hesapno,isim,bakiye); // Yeni hesap bilgilerimizi hesap sınıfımıza gönderiyoruz.
			kayit[0].bilgi = "Yeni hesap oluşturuldu"; // Hesap özetinde yazdırılacak cümle.
			kayit[0].tarih = ctime(&tarih); // Hesap özetinde yazdırılacak tarih.
			if(isim == "") // İsim boş geçilirse tekrardan hesap oluşturulamadı hatası veriyoruz.
				cout << "\nBilgi eksikliğinden dolayı hesap oluşturulamadı.Lütfen işlem yapmak için yeni hesap oluşturunuz." << endl;
			else
				cout << "\nHesabınız başarıyla oluşturuldu.\n" << endl;
		}
		else if(tmp1 == 2){ // Hesap silme işlemini gerçekleştiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayıtlı Hesap Bulunamadı.\n" << endl;
			else{
				isim=""; // İsimi boşaltarak hesaba silinmiş süsü veriyoruz. Diğer bilgileride sıfırlıyoruz.
				bakiye=0;
				hesapno=0;
				hesap.hesapsil(hesapno,isim,bakiye); // Sıfırlanmış halini mevcut sınıfımızın nesnesine gönderiyoruz.
				i = 0; // Sildiğimiz hesabın hesap hareketlerinide sıfırlamak için i sayacını sıfırlıyoruz.
			}
		}
		else if(tmp1 == 3){ // Para yatırma işlemi gerçekleştiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayıtlı Hesap Bulunamadı.\n" << endl;
			else{
				cout << "Yatırmak istediğiniz miktarı giriniz: ";
				double miktar; // Yatırmak istenen miktarı tanımlıyoruz.
				cin >> miktar;
				hesap.parayatir(miktar); // Hesap sınıfımızın para yatırma işlevini gören fonksiyonunu çalıştırıyoruz.
				time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yaptığımız işlemleri gönderiyoruz.
				kayit[i].bilgi = "Türk Lirası Yatırıldı.";
				kayit[i].miktar = miktar;
				kayit[i].tarih = ctime(&tarih);
				i++; // Bir sonraki işlem için sayacı arttırıyoruz.
			}
		}
		else if(tmp1 == 4){ // Para çekme işlemini gerçekleştiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayıtlı Hesap Bulunamadı.\n" << endl;
			else{
				cout << "Çekmek istediğiniz miktarı giriniz: ";
				double miktar; // Çekilecek miktarı tanımlıyoruz.
				cin >> miktar;
				double tmp3 = hesap.bakiyegoster(); // tmp3 adlı değişkene hesaptaki parayı return ediyoruz.
				if(tmp3-miktar<0) // Çekmek istenen para hesapta var mı yok mu kontrol ediyoruz.
					cout << "Bu işlem için yeterli miktarda bakiyeniz bulunmamaktadır." << endl;
				else{
					hesap.paracek(miktar); // Hesap sınıfımızın para çekme işlevini gören fonksiyonunu çalıştırıyoruz.
					time_t tarih = time(NULL); // Tarihi not ederek hesap hareketlerine yaptığımız işlemleri gönderiyoruz.
					kayit[i].bilgi = "Türk Lirası Çekildi.";
					kayit[i].miktar = miktar;
					kayit[i].tarih = ctime(&tarih);
					i++; // Bir sonraki işlem için sayacı arttırıyoruz.
				}
			}
		}
		else if(tmp1 == 5){ // Bakiye sorma işlemini gerçekleştiriyoruz.
				hesap.bakiyesor(isim); // Hesap sınıfımızın bakiye sorgulama işlevini gören fonksiyonunu çalıştırıyoruz.
		}
		else if(tmp1 == 6){ // Hesap özeti(hareketleri)'ni gösterme işlemini gerçekleştiriyoruz.
			if(isim == "") // Zaten hesap yoksa hata veriyoruz.
				cout << "\nKayıtlı Hesap Bulunamadı.\n" << endl;
			else{
				int tmp2 = i; // Bir sonraki hesap özeti işlemi için şuan ki i sayacını farklı bir değişkende tutuyoruz. İşlem bitiminde i'ye tekrar aynı değerini vereceğiz.
				i--; // En son yapılan işlemde fazla olarak arttırılmış i sayacını bir eksiltiyoruz.
				cout << "\nHesap Özetiniz: " << endl << endl; // Hesap özetini gösteriyoruz.
				for(;i>0; i--) // Hareketleri bir dizide tuttuğumuz için döngü kullanarak dizide ki hareketleri listeliyoruz.
					cout << kayit[i].tarih << kayit[i].miktar << " " << kayit[i].bilgi << endl << endl;
				cout << kayit[0].tarih << kayit[0].bilgi << endl; // Listemizin en sonuna hesap oluşturma tarihini ve bilgisini ekliyoruz.
				i = tmp2; // Döngüde değiştirilmiş olan i sayacını tekrardan eski haline döndürüyoruz ki bir sonraki hesap özeti sorgulamasında doğru çalışsın.
			}
		}
		else if(tmp1 == 0) // Çıkış işlemini gerçekleştiriyoruz.
			cout << "İyi günler";
		else // Listede olmayan işlem tuşları için hatalı tuşlama hatası veriyoruz.
			cout << "\nHatalı tuşlama." << endl;
	}
	return 0;
}
