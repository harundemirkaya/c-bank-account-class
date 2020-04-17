#include "hesap.h"
#include <iostream>
using namespace std;
hesap::hesap(int no, string name, double money) { // Constructor için sýnýftaki deðiþkenleri maindeki deðiþkenler ile tanýmlýyoruz.
	hesapno = no;
	isim = name;
	bakiye = money;
}
void hesap::bakiyesor(string name){ // Bakiye sorgulama
	if(name == "") // Hesap silinmiþse bulunamadý hatasý veriyoruz.
		cout << "\nKayýtlý Hesap Bulunamadý.\n" << endl;
	else
		cout << "\nSayýn " << isim << ", Bakiyeniz : " << bakiye << " Türk Lirasýdýr.\n" << endl; // Hesaptaki bakiyeyi gösteriyoruz.
		
}
void hesap::paracek(double miktar){ // Para çekme
	bakiye -= miktar; // Hesaptaki bakiyeyi kullanýcýdan alýndýðý kadar çekiyoruz.
	cout << "\nHesabýnýzdan " << miktar << " Türk Lirasý çekildi." << endl;
	cout << "Yeni bakiyeniz : " << bakiye << " Türk Lirasý olarak güncellendi\n" << endl;
}
void hesap::parayatir(double miktar){ // Para yatýrma
	bakiye += miktar; // Hesaptaki bakiyeye kullanýcýdan alýndýðý kadar yatýrýyoruz.
	cout << "\nHesabýnýza " << miktar << " Türk Lirasý yatýrýldý." << endl;
	cout << "Yeni bakiyeniz : " << bakiye << " Türk Lirasý olarak güncellendi\n" << endl;
}
void hesap::yenihesap(int no, string name, double money){ // Yeni hesap oluþturma
	hesapno = no; // Yeni hesabýn sýnýftaki bilgilerini güncelliyoruz.
	isim = name;
	bakiye = money;
}
void hesap::hesapsil(int no, string name, double money){ // Hesap silme
	hesapno = no; // Mevcut hesabýn bilgilerini mainde sýfýrladýðýmýz bilgiler ile güncelliyoruz.
	isim = name;
	bakiye = money;
	cout << "\nHesap bilgileri silinmiþtir.\n" << endl;
}
double hesap::bakiyegoster(){ // Bakiye döndürme
	return bakiye; // Hesaptaki mevcut bakiyeyi return ediyoruz.
}
