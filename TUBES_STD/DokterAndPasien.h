#ifndef DOKTERANDPASIEN_H_INCLUDED
#define DOKTERANDPASIEN_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

typedef struct Dokter *addressDokter;
typedef struct Pasien *addressPasien;

struct listDokter{
    addressDokter first,last;
};
struct listPasien{
    addressPasien first,last;
};

struct infotypeDokter{
    int id,sumPasien;
    listPasien namePasien;
    string name,special;
};
struct infotypePasien{
    int id,sumDokter;
    string name,status;
};
struct Dokter{
    infotypeDokter info;
    addressDokter next,prev;
};
struct Pasien{
    infotypePasien info;
    addressPasien next,prev;
};

//Inisialisasi
void createListDokter(listDokter &L);
void createListPasien(listPasien &L);
addressDokter createDokter(int id,string name,string special);
addressPasien createPasien(int id,string name,string status);

//Create
void addDokter(listDokter &L,addressDokter P);
void addPasien(listPasien &L,addressPasien P);

// search
addressPasien searchPasien(listPasien L,string name);
addressDokter searchDokter(listDokter L,string name);

//Main Project
void relationshipDokterPasien(listDokter &L1,listPasien &L2,string nameDokter,string namePasien);
void deleteRelationship(listDokter &L1, listPasien &L2, string namePasien);
void deleteDokter(listDokter &L1,listPasien &L2,string nameDokter);
void deleteAddressPasien(listPasien &L,addressPasien &P);
void deletePasien(listPasien &L,string namePasien);

//Print
void printPasien(addressPasien P);
void printDokter(addressDokter P);
void printAllPasien(listPasien L);
void printAllDokterPasien(listDokter L);
void printAllOnlyDokter(listDokter L);
void printDokterAndPasien(addressDokter P);
void printPasienAndDokter(listDokter L,listPasien LP,string Pasien);
void showGoodDokter(listDokter L);
void showIllPasien(listPasien L);

//Sorting
bool comperatorPasien(infotypePasien a, infotypePasien b,string chain);
void sortPasien(listPasien &L,string chain);
void sortDokterName(listDokter &L);

#endif // DOKTERANDPASIEN_H_INCLUDED
