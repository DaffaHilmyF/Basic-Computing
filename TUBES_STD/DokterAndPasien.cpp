#include"DokterAndPasien.h"
//Inisialisasi
void createListDokter(listDokter &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createListPasien(listPasien &L){
    first(L) = NULL;
    last(L) = NULL;
}
addressDokter createDokter(int id,string name,string special){
    addressDokter P = new Dokter;
    info(P).name = name;
    info(P).id = id;
    info(P).special = special;
    info(P).sumPasien = 0;
    createListPasien(info(P).namePasien);
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
addressPasien createPasien(int id,string name,string status){
    addressPasien P = new Pasien;
    info(P).name = name;
    info(P).id = id;
    info(P).sumDokter = 0;
    info(P).status = status;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

//MAIN
void addDokter(listDokter &L,addressDokter P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
void addPasien(listPasien &L,addressPasien P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}
addressPasien searchPasien(listPasien L,string name){
    addressPasien P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}
addressDokter searchDokter(listDokter L,string name){
    addressDokter P = first(L);
    while(P != NULL && info(P).name != name)
        P = next(P);
    return P;
}
void relationshipDokterPasien(listDokter &L1,listPasien &L2,string nameDokter,string namePasien){
    addressDokter P = searchDokter(L1,nameDokter);
    addressPasien Q = searchPasien(L2,namePasien);
    if(P != NULL && Q != NULL){
        if(searchPasien(info(P).namePasien,namePasien) == NULL){
            addressPasien R = createPasien(info(Q).id,info(Q).name,info(Q).status);
            addPasien(info(P).namePasien,R);
            info(P).sumPasien++;
            info(Q).sumDokter++;
        }else
        cout<<"Relasi Telah ada"<<endl;
    }else{
        if(P == NULL)
            cout<<"Dokter belum ada"<<endl;
        if(Q == NULL)
            cout<<"Pasien belum ada"<<endl;
    }
}
void deleteRelationship(listDokter &L1, listPasien &L2, string namePasien){
    addressPasien P = searchPasien(L2,namePasien);
    if(P != NULL){
        addressDokter D = first(L1);
        while(D != NULL){
            addressPasien tmp = searchPasien(info(D).namePasien,namePasien);
            if(tmp != NULL){
                info(D).sumPasien--;
                deleteAddressPasien(info(D).namePasien,tmp);
            }
            D = next(D);
        }
    }
    deleteAddressPasien(L2,P);
    delete P;
}
void deleteDokter(listDokter &L1,listPasien &L2,string nameDokter){
    addressDokter P = searchDokter(L1,nameDokter);
    if(P != NULL){
        while(info(P).sumPasien != 0){
            addressPasien Q = first(info(P).namePasien);
            Q = searchPasien(L2,info(Q).name);
            info(Q).sumDokter--;
            deletePasien(info(P).namePasien,info(Q).name);
            info(P).sumPasien--;
        }
        if(first(L1) == last(L1)){
            createListDokter(L1);
        }else if(P == first(L1)){
            first(L1) = next(P);
            prev(first(L1)) = NULL;
        }else if(P == last(L1)){
            last(L1) = prev(P);
            next(last(L1)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
    delete P;
}

//InADT
void deleteAddressPasien(listPasien &L,addressPasien &P){
    if(P != NULL){
        if(first(L) == last(L)){
            createListPasien(L);
        }else if(P == first(L)){
            first(L) = next(P);
            prev(first(L)) = NULL;
        }else if(P == last(L)){
            last(L) = prev(P);
            next(last(L)) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deletePasien(listPasien &L,string namePasien){
    addressPasien P = searchPasien(L,namePasien);
    deleteAddressPasien(L,P);
    delete P;
}
//Print
void printPasien(addressPasien P){
    cout<<"ID \t\t : "<<info(P).id<<endl;
    cout<<"NAME \t\t : "<<info(P).name<<endl;
    cout<<"Status \t\t : "<<info(P).status<<endl;
    cout<<"Jumlah Dokter \t : "<<info(P).sumDokter<<endl;
}
void printDokter(addressDokter P){
    cout<<"Id Dokter    : "<<info(P).id<<endl;
    cout<<"Nama Dokter  : "<<info(P).name<<endl;
    cout<<"Keahlian  : "<<info(P).special<<endl;
    cout<<"Jumlah Pasien : "<<info(P).sumPasien<<endl;
}
void printAllPasien(listPasien L){
    addressPasien P = first(L);
    while(P != NULL){
        printPasien(P);
        cout<<endl;
        P = next(P);
    }
}
void printAllDokterPasien(listDokter L){
    addressDokter P = first(L);
    while(P != NULL){
        printDokterAndPasien(P);
        cout<<endl;
        P = next(P);
    }
}
void printAllOnlyDokter(listDokter L){
    addressDokter P = first(L);
    while(P != NULL){
        printDokter(P);
        P = next(P);
    }
}
void printDokterAndPasien(addressDokter P){
    int i = 1;
    cout<<"Id Dokter    : "<<info(P).id<<endl;
    cout<<"Nama Dokter  : "<<info(P).name<<endl;
    cout<<"Specialized  : "<<info(P).special<<endl;
    addressPasien Q = first(info(P).namePasien);
    cout<<"Daftar Pasien : ";
    while(Q != NULL){
        cout<<i<<".  "<<info(Q).name;
        Q = next(Q);
        if(Q != NULL)
            cout<<endl<<"\t\t";
        i++;
    }
    cout<<endl<<endl;
}
void printPasienAndDokter(listDokter L,listPasien LP,string Pasien){
    if(searchPasien(LP,Pasien) != NULL){
        cout<<"Nama Pasien \t: "<<Pasien<<endl;
        cout<<"List Dokternya \t: ";
        addressDokter D = first(L);
        int i = 1;
        while(D != NULL){
            if(searchPasien(info(D).namePasien,Pasien) != NULL){
                cout<<i++<<".  "<<info(D).name;
            }
            D = next(D);
            if(D != NULL)
                cout<<endl<<"\t\t  ";
        }
        cout<<endl;
    }else
        cout<<"Pasien Tak ditemukan"<<endl;
}
void showGoodDokter(listDokter L){
    int maks = 0;
    addressDokter P = NULL;
    addressDokter Q = first(L);
    while(Q !=  NULL){
        if(info(Q).sumPasien > maks){
            maks = info(Q).sumPasien;
            P =Q;
        }
        Q = next(Q);
    }
    if(P != NULL)
        printDokter(P);
}
void showIllPasien(listPasien L){
    addressPasien P = first(L);
    while(P != NULL){
        if(info(P).sumDokter > 1)
            cout<<"Nama : "<<info(P).name<<"      Jumlah Dokter : "<<info(P).sumDokter<<endl;
        P = next(P);
    }
}

bool comperatorPasien(infotypePasien a, infotypePasien b,string chain){
    if(chain == "NAME")
        return(a.name < b.name);
    return(a.sumDokter > b.sumDokter); //fungsi ini dibuat untuk bisa melakukan 2 sorting tergantung keininan user
}

void sortPasien(listPasien &L,string chain){
    addressPasien P = first(L);
    while(P != last(L)){
        addressPasien Q = P;
        addressPasien R = next(P);
        while(R != NULL){
            if(comperatorPasien(info(R),info(Q),chain)) // fungsi ini melakukan sorting data berdasarkan keinginanuser pasien menggunakan fungsi comperator yang telah dibuat
               Q = R;
            R = next(R);
        }
        infotypePasien tmp = info(P);
        info(P) = info(Q);
        info(Q) = tmp;
        P = next(P);
    }
}
void sortDokterName(listDokter &L){
    addressDokter P = first(L);
    while(P != last(L)){
        addressDokter Q = P;
        addressDokter R = next(P);
        while(R != NULL){
            if(info(R).name < info(Q).name)
               Q = R;
            R = next(R);
        }
        infotypeDokter tmp = info(P);
        info(P) = info(Q);
        info(Q) = tmp;
        sortPasien(info(P).namePasien,"NAME");
        P = next(P);
    }
}
