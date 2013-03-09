// ============================================================================
//
//       Filename:  01049-animal.cpp
//
//    Description:  URI 1049 - Animal
//
//        Version:  1.0
//        Created:  09/28/2012 09:27:20 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
using namespace std;

int main()
{
    string n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    if (n1 == "vertebrado")
    {
        if (n2 == "ave")
        {
            if (n3 == "carnivoro")
                cout << "aguia" << endl;
            else
                cout << "pomba" << endl;
        }
        else if (n2 == "mamifero")
        {
            if (n3 == "onivoro")
                cout << "homem" << endl;
            else
                cout << "vaca" << endl;
        }
    }
    else
    {
        if (n2 == "inseto")
        {
            if (n3 == "hematofago")
                cout << "pulga" << endl;
            else
                cout << "lagarta" << endl;
        }
        else if (n3 == "hematofago")
            cout << "sanguessuga" << endl;
        else
            cout << "minhoca" << endl;
    }
    return 0;
}
