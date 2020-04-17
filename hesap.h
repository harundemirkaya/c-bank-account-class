#include <iostream>
#ifndef HESAP_H
#define HESAP_H
using namespace std;
class hesap
{
	public:
		hesap(int,string,double); // Construtor'�m�z� tan�ml�yoruz.
		void yenihesap(int,string,double); // Yeni hesap olu�turma i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
		void hesapsil(int,string,double); // Hesap silme i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
		void paracek(double); // Para �ekme i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
		void parayatir(double); // Para yat�rma i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
		void bakiyesor(string isim); // Bakiye sorgulama i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
		double bakiyegoster(); // Bakiyeyi return etme i�levini g�ren fonksiyonumuzu tan�ml�yoruz.
	private:
		int hesapno; // Hesap numaram�z
		string isim; // Heasp sahibinin ismi
		double bakiye; // Hesaptaki bakiye
};

#endif
