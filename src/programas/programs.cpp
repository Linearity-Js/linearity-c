using namespace std;

#include <iostream>
#include <math.h>
#include <string>

void limpiarPantalla()
{
// Hay mejores formas de limpiar la pantalla
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}

void printMenu();

void printBasesMenu();

void printSumaMenu();
float sumarRecursiva(int x, int i);
float sumarIterando(int x, int n);

void printBasesMenu();
string IntToString(int a);
int ABinario(int numero);
int AOctal(int numero);
int AHexa(int numero);
int cambioBase(int numero, int base);

void printSumaMenu()
{
    int n, x;
    cout << "*********************************\n";
    cout << "************ SUMAS  *************\n";
    cout << "*********************************\n";
    cout << "\n1 + 2x + 3x^2 + 4x^3 + ... + (n + 1) x^n";
    cout << "\nIngresa x (int):";
    cin >> x;
    cout << "Ingresa n (int):";
    cin >> n;
    cout << "*********************************\n";
    cout << "\nSFx (iteraciones):" << sumarIterando(x, n);
    cout << "\n*********************************";
    cout << "\nSFx (recusividad):" << sumarRecursiva(x, n);
    cout << "\nRegresar al menu principal? S/N. (N terminara el programa): ";
    char res;
    cin >> res;
    if (res == 'S' || res == 's' || res == '1')
    {
        limpiarPantalla();
        printMenu();
    }
}

float sumarRecursiva(int x, int i)
{
    float fx = (i + 1) * pow(x, i);
    if (i == 1)
        return fx;
    else
    {
        float z = fx + sumarRecursiva(i - 1, x);
        return z;
    }
}

float sumarIterando(int x, int n)
{
    float z = 0;
    for (int i = 0; i <= n; i++)
    {
        float fx = (i + 1) * pow(x, i);
        cout << "\nf(" << i << "): (" << i << " + 1) " << x << "^" << i << " = " << fx;
        z += fx;
    }
    cout << "\n*********************************";
    return z;
}

void printBasesMenu()
{

    int n, x;
    cout << "*********************************\n";
    cout << "************ BASES  *************\n";
    cout << "*********************************\n";
    cout << "\nIngresa un numero(int) x:";
    cin >> x;

    cout << "*********************************\n";
    cout << "1. Convertir a base 2 (binaria)\n";
    cout << "2. Convertir a base 8 (octal)\n";
    cout << "3. Convertir a base 16 (hexadecimal)\n";
    cout << "4. Otras bases\n";
    cout << "Selecciona una opcion:";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "numero " << x << " convertido a base 2: " << ABinario(x);
        break;
    case 2:
        cout << "numero " << x << " convertido a base 8: " << AOctal(x);
        break;
    case 3:
        cout << "numero " << x << " convertido a base 16: " << AHexa(x);
        break;
    case 4:
        int base;
        cout << "Ingresa la base: ";
        cin >> base;
        cout << "numero " << x << " convertido a base " << base << ": " << cambioBase(x, base);
        break;
    default:
        cout << "Opcion no valida";
        break;
    }

    cout << "\nRegresar al menu principal? S/N. (N Volver a repetir programa): ";
    char res;
    cin >> res;
    limpiarPantalla();
    if (res == 'S' || res == 's' || res == '1')
        printMenu();
    else
        printBasesMenu();
}

#include <sstream>

string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

int cambioBase(int numero, int base)
{
    string binario = "";
    while (numero != 0)
    {
        int res = (int)(numero % base);
        binario = IntToString(res) + binario;
        numero /= base;
    }
    return stoi(binario);
}

int ABinario(int numero)
{
    return cambioBase(numero, 2);
}

int AOctal(int numero)
{
    return cambioBase(numero, 8);
}

int AHexa(int numero)
{
    return cambioBase(numero, 16);
}

// PROGRAMS
void printMenu()
{
    cout << "*********************************\n";
    cout << "********** PROGRAMAS  ***********\n";
    cout << "*********************************\n";
    cout << "\nIngresa que tipo operacion deseas:\n";
    cout << "1 Suma Iterativa | Recursiva\n";
    cout << "2 Convertidor de Base\n";
    cout << "0 Salir\n";

    int option;
    cout << "Ingesa una opcion: ";
    cin >> option;
    limpiarPantalla();
    switch (option)
    {
    case 0:
        break;
    case 1:
        printSumaMenu();
        break;
    case 2:
        printBasesMenu();
        break;
    default:
        cout << "\nHas ingresado una opcion no valida";
        break;
    }
}

int main(int argc, char const *argv[])
{
    printMenu();
    return 0;
}
