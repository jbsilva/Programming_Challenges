// =====================================================================================
// 
//       Filename:  10138-cdvii.cpp
// 
//    Description:  UVA 10138
// 
//        Version:  1.0
//        Created:  04/04/2011 12:41:36 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <list>
using namespace std;

#define USI unsigned short int

// Funçao para normalizar o delimitador
// Converte ':' para ' '
string dp_spc( string &texto) 
{ 
    replace( texto.begin(), texto.end(), ':', ' ' );

    return texto; 
}

// =====================================================================================
//        Class:  Foto
//  Description:  
// =====================================================================================
#ifndef FOTO_H
#define FOTO_H
class Foto
{
    public:
            USI Mes;
            USI Dia;
            USI Hora;
            USI Minuto;
            bool Sentido;
            USI Km;

            Foto(USI, USI, USI, USI, string, USI);
};

Foto::Foto(USI mes, USI dia, USI hora, USI minuto, string sentido, USI km)
    : Mes(mes), Dia(dia), Hora(hora), Minuto(minuto), Km(km)
{
    if (sentido == "enter")
        Sentido = 1;
    else
    {
        if (sentido == "exit")
            Sentido = 0;
    }
}
#endif

// Funcão que diz qual das fotos foi tirada antes
bool compara_fotos(Foto a, Foto b)
{
    if (a.Mes < b.Mes)
        return true;

    if (a.Mes > b.Mes)
        return false;

    // Se chegou aqui é pq a.Mes == b.Mes
    
    if (a.Dia < b.Dia)
        return true;

    if (a.Dia > b.Dia)
        return false;

    // Se chegou aqui é pq a.Dia == b.Dia

    if (a.Hora < b.Hora)
        return true;

    if (a.Hora > b.Hora)
        return false;

    // Se chegou aqui é pq a.Hora == b.Hora

    if (a.Minuto < b.Minuto)
        return true;

    if (a.Minuto > b.Minuto)
        return false;

    // Nunca deve chegar aqui, mas
    // caso a.Minuto == b.Minuto considerarei a menor
    return true;
}

int main()
{
    USI cases, i, pedagio[24], percorrido; 
    int taxa;
    string temp;
    istringstream linha;

    USI mes, dia, hora, minuto, km;
    string licensa, sentido;

    map< string, list<Foto> > registros;
    map< string, list<Foto> >::iterator it;

    list<Foto>::iterator it2, it3;

    cin >> cases;

    while (cases--)
    {
        for (i=0; i<24; i++)
            cin >> pedagio[i];

        // Ignora o enter após entrar os pedágios
        cin.ignore(1);

        while( getline(cin,temp) && !temp.empty() )
        {
            linha.clear();
            linha.str( dp_spc(temp) );

            linha >> licensa >> mes >> dia >> hora >> minuto >> sentido >> km;

            registros[licensa].push_back( Foto(mes, dia, hora, minuto, sentido, km) );
        }

        for (it = registros.begin(); it != registros.end(); it++)
        {
            // Por algum motivo a câmera não registra sempre cronologicamente.
            // Ordena a lista associada a cada licensa cronologicamente
            (it->second).sort(compara_fotos);

            it2 = it3 = it->second.begin();
            it3++;

            taxa = 200;

            for (; it3 != it->second.end(); it2++, it3++)
            {
                if (it2->Sentido && !it3->Sentido)
                {
                    percorrido = abs(it3->Km - it2->Km);
                    taxa += pedagio[it2->Hora] * percorrido + 100;
                }
            }
            
            // Não combinou nenhuma entrada com saída
            if (taxa != 200)
                cout << it->first << " $" << fixed << setprecision(2) << (float)taxa/100 << endl;
        }

        registros.clear();

        if (cases)
            cout << endl;
    }

    return 0;
}
