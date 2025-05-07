#include <iostream>
using namespace std;

int element[10];
int nPanjang;
int x;

void input()
{
    while (true)
    {
        cout << "masukkan banhyaknya elemen pada array (maksimal 10) : ";
        cin >> nPanjang;
        if (nPanjang <= 10)
        {
            break;
        }
        else
        {
            cout << "\n[!] jumlah elemen tidak boleh lebih dari 10. silahkan coba lagi.\n";
        }
    }

    cout << "\n==============================\n";
    cout << "      masukkan elemen array     \n";
    cout << "==============================\n";
    for (int i = 0; i < nPanjang; i++)
    {
        cout << "data ke-" << (i + 1) << " = ";
        cin >> element[i];
    }
}

void bubbleSortArray()
{
    int pass = 1;
    do
    {
        for (int j = 0; j <= nPanjang - 1 - pass; j++)
        {
            if (element[j] > element[j + 1])
            {
                int temp = element[j];
                element[j] = element[j + 1];
                element[j + 1] = temp;
            }
        }
        pass++;
    } while (pass <= nPanjang - 1);
    
}

void display()
{
    cout << "\n=============================================\n";
    cout << "     elemen array setelah diurutkan (asc)    \n";
    cout << "=============================================\n";
    for (int j = 0; j < nPanjang; j++)
    {
        cout << element[j];
        if (j < nPanjang - 1)
        {
            cout << " --> ";
        }
    }
    cout << endl;
}

void binarySearch()
{
    char ulang;
    do
    {
        cout << "\n===================================\n";
        cout << "       pencarian binary search     \n";
        cout << "===================================\n";
        cout << "masukkan elemen yang ingin dicari : ";
        cin >> x;

        int low = 0;
        int high = nPanjang -1;

        do
        {
            int mid = (low + high) / 2;
            if (element[mid] == x)
            {
                cout << "\n[✔] elemen " << x << " ditemukan pada indeks " << mid << ".\n";
                return;
            }
            if (x < element[mid])
            {
                high = mid - 1;
            }
            if (x > element[mid])
            {
                low = mid + 1;
            }
        } while (low <= high);
        
        if (low > high)
        {
            cout << "\n[✘] elemen " << x << "tidak ditemukan dalam array.\n";
        }
        cout << "\ningin mencari lagi? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y'); 
    
}

int main()
{
    input();
    bubbleSortArray();
    display();
    binarySearch();
}