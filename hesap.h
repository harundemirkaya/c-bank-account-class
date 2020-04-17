#include <iostream>
#ifndef HESAP_H
#define HESAP_H
using namespace std;
class hesap
{
	public:
		hesap(int,string,double); // Construtor'ümüzü tanýmlýyoruz.
		void yenihesap(int,string,double); // Yeni hesap oluþturma iþlevini gören fonksiyonumuzu tanýmlýyoruz.
		void hesapsil(int,string,double); // Hesap silme iþlevini gören fonksiyonumuzu tanýmlýyoruz.
		void paracek(double); // Para çekme iþlevini gören fonksiyonumuzu tanýmlýyoruz.
		void parayatir(double); // Para yatýrma iþlevini gören fonksiyonumuzu tanýmlýyoruz.
		void bakiyesor(string isim); // Bakiye sorgulama iþlevini gören fonksiyonumuzu tanýmlýyoruz.
		double bakiyegoster(); // Bakiyeyi return etme iþlevini gören fonksiyonumuzu tanýmlýyoruz.
	private:
		int hesapno; // Hesap numaramýz
		string isim; // Heasp sahibinin ismi
		double bakiye; // Hesaptaki bakiye
};

#endif
