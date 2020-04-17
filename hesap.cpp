#include "hesap.h"
#include <iostream>
using namespace std;
hesap::hesap(int no, string name, double money) { // Constructor i�in s�n�ftaki de�i�kenleri maindeki de�i�kenler ile tan�ml�yoruz.
	hesapno = no;
	isim = name;
	bakiye = money;
}
void hesap::bakiyesor(string name){ // Bakiye sorgulama
	if(name == "") // Hesap silinmi�se bulunamad� hatas� veriyoruz.
		cout << "\nKay�tl� Hesap Bulunamad�.\n" << endl;
	else
		cout << "\nSay�n " << isim << ", Bakiyeniz : " << bakiye << " T�rk Liras�d�r.\n" << endl; // Hesaptaki bakiyeyi g�steriyoruz.
		
}
void hesap::paracek(double miktar){ // Para �ekme
	bakiye -= miktar; // Hesaptaki bakiyeyi kullan�c�dan al�nd��� kadar �ekiyoruz.
	cout << "\nHesab�n�zdan " << miktar << " T�rk Liras� �ekildi." << endl;
	cout << "Yeni bakiyeniz : " << bakiye << " T�rk Liras� olarak g�ncellendi\n" << endl;
}
void hesap::parayatir(double miktar){ // Para yat�rma
	bakiye += miktar; // Hesaptaki bakiyeye kullan�c�dan al�nd��� kadar yat�r�yoruz.
	cout << "\nHesab�n�za " << miktar << " T�rk Liras� yat�r�ld�." << endl;
	cout << "Yeni bakiyeniz : " << bakiye << " T�rk Liras� olarak g�ncellendi\n" << endl;
}
void hesap::yenihesap(int no, string name, double money){ // Yeni hesap olu�turma
	hesapno = no; // Yeni hesab�n s�n�ftaki bilgilerini g�ncelliyoruz.
	isim = name;
	bakiye = money;
}
void hesap::hesapsil(int no, string name, double money){ // Hesap silme
	hesapno = no; // Mevcut hesab�n bilgilerini mainde s�f�rlad���m�z bilgiler ile g�ncelliyoruz.
	isim = name;
	bakiye = money;
	cout << "\nHesap bilgileri silinmi�tir.\n" << endl;
}
double hesap::bakiyegoster(){ // Bakiye d�nd�rme
	return bakiye; // Hesaptaki mevcut bakiyeyi return ediyoruz.
}
