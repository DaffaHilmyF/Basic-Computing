#include "DokterAndPasien.h"
using namespace std;

int idP,idD;

void inisialisi(listDokter &LD,listPasien &LP){
    createListDokter(LD);
    createListPasien(LP);
    int idP = 0;
    int idD = 0;
}

int masukanPilihan(){
    cout<<"Masukkan Pilihan Anda : ";
    int pil;
    cin>>pil;
    cin.ignore();
    cout<<endl;
    return pil;
}


int SubmenuInput(listDokter &LD, listPasien &LP){
    cout<<"=========== Menu Input Data ==========="<<endl;
    cout<<" 1. Tambahkan Dokter"<<endl;
    cout<<" 2. Tambahkan Pasien"<<endl;
    cout<<" 3. Tambahkan Hubungan Pasien Dokter"<<endl;
    cout<<" 4. Menu Utama"<<endl;
    int pil = masukanPilihan();
    string name,stat;
    switch (pil){
    case 1:
        cout<<"Nama Dokter : ";
        getline(cin,name);
        cout<<"Keahlian : ";
        getline(cin,stat);
        if(searchDokter(LD,name) == NULL)
            addDokter(LD,createDokter(++idD,name,stat));
        else
            cout<<"Dokter Telah Terdaftar"<<endl;
        break;
    case 2:
        cout<<"Nama Pasien : ";
        getline(cin,name);
        cout<<"Status : ";
        getline(cin,stat);
        if(searchPasien(LP,name) == NULL)
            addPasien(LP,createPasien(++idP,name,stat));
        else
            cout<<"Pasien Telah terdaftar"<<endl;
        break;
    case 3:
        cout<<"Nama Dokter : ";
        getline(cin,name);
        cout<<"Nama Pasien : ";
        getline(cin,stat);
        relationshipDokterPasien(LD,LP,name,stat);
        break;
    }
    return pil;
}

int cariData(listDokter LD,listPasien LP){
    cout<<"=========== Menu Cari Data ==========="<<endl;
    cout<<" 1. Cari Dokter"<<endl;
    cout<<" 2. Cari Pasien"<<endl;
    cout<<" 3. Menu Utama"<<endl;
    int pil = masukanPilihan();
    string name;
    addressDokter D;
    switch (pil){
    case 1:
        cout<<"Nama Dokter : ";
        getline(cin,name);
        D = searchDokter(LD,name);
        if(D != NULL)
            printDokter(D);
        else
            cout<<"Tidak Ada"<<endl;
        break;
    case 2:
        cout<<"Nama Pasien : ";
        getline(cin,name);
        addressPasien P = searchPasien(LP,name);
        if(P != NULL)
            printPasien(P);
        else
            cout<<"Tidak Ada"<<endl;
        break;
    }
    return pil;
}

int Hapusdata(listDokter &LD, listPasien &LP){
    cout<<"=========== Menu Hapus Data ==========="<<endl;
    cout<<" 1. Hapus Pasien"<<endl;
    cout<<" 2. Hapus Dokter"<<endl;
    cout<<" 3. Hapus Hubungan Pasien dan Dokter"<<endl;
    cout<<" 4. Menu Utama"<<endl;
    int pil = masukanPilihan();
    string name;
    switch (pil){
    case 1:
        cout<<"Nama Pasien : ";
        getline(cin,name);
        deleteRelationship(LD,LP,name);
        deletePasien(LP,name);
        break;
    case 2:
        cout<<"Nama Dokter : ";
        getline(cin,name);
        deleteDokter(LD,LP,name);
        break;
    case 3:
        cout<<"Nama Pasien : ";
        getline(cin,name);
        deleteRelationship(LD,LP,name);
        break;
    }
    return pil;
}

int Tampilandata(listDokter LD, listPasien LP){
    cout<<"=========== Menu Tampilkan Data ==========="<<endl;
    cout<<" 1. Tampilan Dokter Terbaik"<<endl;
    cout<<" 2. Tampilan Pasien Terbanyak dokternya"<<endl;
    cout<<" 3. Tampilkan Semua Pasien"<<endl;
    cout<<" 4. Tampilkan Semua Dokter"<<endl;
    cout<<" 5. Tampilkan Semua Dokter dan Pasien"<<endl;
    cout<<" 6. Tampilkan Pasien dan Dokternya"<<endl;
    cout<<" 7. Menu Utama"<<endl;
    int pil = masukanPilihan();
    switch (pil){
    case 1:
        showGoodDokter(LD);
        break;
    case 2:
        showIllPasien(LP);
        break;
    case 3:
        printAllPasien(LP);
        break;
    case 4:
        printAllOnlyDokter(LD);
        break;
    case 5:
        printAllDokterPasien(LD);
        break;
    case 6:
        string name;
        cout<<"Masukan Nama Pasien : ";
        getline(cin,name);
        printPasienAndDokter(LD,LP,name);
        break;
    }
    return pil;
}

int sortingData(listDokter &LD,listPasien &LP){
    cout<<"=========== Menu Sorting Data ==========="<<endl;
    cout<<" 1. Sorting Dokter Berdasarkan Nama"<<endl;
    cout<<" 2. Sorting Pasien Berdasarkan Nama"<<endl;
    cout<<" 3. Sorting Pasien Berdasarkan Jumlah Dokter"<<endl;
    cout<<" 4. Menu Utama"<<endl;
    int pil = masukanPilihan();
    switch (pil){
    case 1:
        sortDokterName(LD);
        cout<<"data tealh tersorting"<<endl;
        break;
    case 2:
        sortPasien(LP,"NAME");
        cout<<"data tealh tersorting"<<endl;
        break;
    case 3:
        sortPasien(LP,"SUMPASIEN");
        cout<<"data tealh tersorting"<<endl;
        break;
    }
    return pil;
}

int main(){
    listDokter LD;
    listPasien LP;
    int pil;
    inisialisi(LD,LP);
    do{
        cout<<"=========== Menu Utama ==========="<<endl;
        cout<<" 1. Tambahkan Data"<<endl;
        cout<<" 2. Cari Data"<<endl;
        cout<<" 3. Hapus Data"<<endl;
        cout<<" 4. Tampilkan Data"<<endl;
        cout<<" 5. Sorting Data"<<endl;
        cout<<" 6. Exit"<<endl;
        pil = masukanPilihan();
        switch (pil){
        case 1:
            while(SubmenuInput(LD,LP) != 4);
            break;
        case 2:
            while(cariData(LD,LP) != 3);
            break;
        case 3:
            while(Hapusdata(LD,LP) != 4);
            break;
        case 4:
            while(Tampilandata(LD,LP) != 7);
            break;
        case 5:
            while(sortingData(LD,LP) != 4);
            break;
        }
        if(pil != 6)
            system("CLS"); // clean screen kembali kemenu utama agar tampilan ke kemenu utama
    }while(pil != 6);
    cout<<"Thank You"<<endl;
    return 0;
}
