#include <iostream>

using namespace std;

int main()
{
    cout << "Kandung Hidup Tarik Oke" << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main(){
    int inp;
    cin >> inp;
    cout << "Nilai = " << inp;
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int W, X, Y; float Z;
    X = 7; Y = 3; W = 1;
    Z = (X + Y)/(Y + W);
    cout << "Nilai Z = " << Z << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main(){
    double tot_pembelian, diskon;
    cout << "total pembelian: Rp.";
    cin >> tot_pembelian;
    diskon = 0;
    if(tot_pembelian >= 100000)
        diskon = 0.10*tot_pembelian;
    else
        diskon = 0;
    cout << "Besar diskon = Rp" <<diskon;
}

#include <stdio.h>
using namespace std;
int main(){
    int kode_hari;
    puts("Menentukan hari/n");
    puts("1=Senin,2=Selasa,3=Rabu");
    puts("4=Kamis,5=Jumat,6=Sabtu");
    puts("7=Minggu");


}

#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int i=1;
    int jum;
    cin >> jum;
    do{
        cout << "Baris ke-"<<i+1<<endl;
        i++;
    }while (i<jum);
    getch();
    return 0;
}

