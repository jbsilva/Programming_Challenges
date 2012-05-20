// =====================================================================================
// 
//       Filename:  BigNum.h
// 
//    Description:  Biblioteca para operar com inteiros muito grandes.
//                  Podem existir bugs ainda
// 
//        Version:  1.0
//        Created:  04/15/2011 04:24:04 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio.forus@gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

// Tipos
typedef short int           SI;
typedef unsigned short int  USI;
typedef long long int       LLI;

// Constantes
const USI BASE         = 10;
const USI MAX_DIGITOS  = 600;
const bool MAIS        = 0;
const bool MENOS       = 1;

// =====================================================================================
//        Class:  BigNum
//  Description:  Armazena números com precisão arbritária
// =====================================================================================

#ifndef BIGNUM_H
#define BIGNUM_H

class BigNum
{
    private:
            char Digitos[MAX_DIGITOS];
            bool Sinal;
            SI UD;                   // Ultimo Dígito: Posição do dígito de maior ordem.

    public:
            BigNum();
            BigNum(const char*);
            BigNum(LLI);

            inline bool Get_Sinal();
            inline char* Get_Digitos();
            inline SI Get_UD();

            inline void Set_Sinal(bool);
            inline void Set_UD(SI);

            void zero_justify();
            void digit_shift(int);

            bool operator== ( const BigNum& ) const;
            bool operator!= ( const BigNum& ) const;
            bool operator< (const BigNum&) const;
            bool operator> (const BigNum&) const;
            bool operator<= (const BigNum&) const;
            bool operator>= (const BigNum&) const;

            BigNum operator+ (const BigNum&);
            BigNum operator- (const BigNum&);
            BigNum operator* (const BigNum&);
            BigNum operator/ (const BigNum&);

            BigNum &operator+= (const BigNum&);
            BigNum &operator-= (const BigNum&);

            BigNum operator++ ();               // Pré-incremento
            BigNum operator-- ();               // Pré-incremento
            BigNum operator++ (int);            // Pós-incremento
            BigNum operator-- (int);            // Pós-incremento

            friend ostream &operator<<( ostream&, const BigNum& );
            friend istream &operator>>( istream&, BigNum& );
};
#endif

BigNum::BigNum()
{
    USI i;

    // Zera vetor
    for (i=0; i<=MAX_DIGITOS; i++) 
       Digitos[i] = 0;

    Sinal = MAIS;

    UD = 0;
}

// Segundo construtor. Recebe uma string e converte para BigNum
// String:             +1234567890
// BigNum:
//      Sinal:          MAIS
//      Digitos:        09876543210000...
//      UD:  9
BigNum::BigNum(const char* num)
{
    USI i, j;
    USI tam = strlen(num);

    // Zera vetor
    for (i=0; i<=MAX_DIGITOS; i++) 
       Digitos[i] = 0;

    // Identifica o sinal
    Sinal = (num[0] == '-' ? MENOS : MAIS);

    // Preenche os dígitos
    for (i=tam-1, j=0; i>0; i--, j++)
        Digitos[j] = num[i] - '0';

    // Identifica a posição do último dígito
    UD = tam-2;
}

// Terceiro construtor. Recebe um inteiro e passa para BigNum
BigNum::BigNum(LLI num)
{
    int i;
    LLI t;

    // Zera vetor
    for (i=0; i<=MAX_DIGITOS; i++) 
       Digitos[i] = 0;

    // Identifica o sinal
    Sinal = (num>=0 ? MAIS : MENOS);

    t = num;
    if (Sinal == MENOS)
        t *= -1;

    UD = -1;
    while (t > 0)
    {
        UD++;
        Digitos[UD] = (t%BASE);
        t = t/BASE;
    }

    if (num == 0)
        UD = 0;
}

inline bool BigNum::Get_Sinal()
{
    return Sinal;
}

inline char* BigNum::Get_Digitos()
{
    return Digitos;
}

SI BigNum::Get_UD()
{
    return UD;
}

inline void BigNum::Set_Sinal(bool sinal)
{
    Sinal = sinal;
}

inline void BigNum::Set_UD(SI ud)
{
    if (ud >= 0)
        UD = ud;
}

// Sobrecarga do operador de igualdade
bool BigNum::operator== (const BigNum &direita) const
{
    USI i;

    // Sinais são diferentes
    if (direita.Sinal != Sinal)
        return false;

    // Tamanhos São diferentes
    if (direita.UD != UD)
        return false;

    // Algum dígito é diferente
    for (i=UD; i>=0; i--)
    {
        if (direita.Digitos[i] != Digitos[i])
            return false;
    }

    return true;
}

// Sobrecarga o operador de desigaldade. Retorna o oposto do do ==
bool BigNum::operator!= (const BigNum &direita) const
{
    return !( *this == direita );
}

bool BigNum::operator< (const BigNum& direita) const
{
    int i;

    // Sinais diferentes
    if (Sinal == MAIS && direita.Sinal == MENOS)
        return false;

    if (Sinal == MENOS && direita.Sinal == MAIS)
        return true;

    // Tamanhos diferentes
    if (UD < direita.UD)
        return true;

    if (UD > direita.UD)
        return false;

    // Tamanho e sinais iguais

    i=UD;
    while ( Digitos[i] == direita.Digitos[i] && i>=0 )
        i--;

    // São iguais
    if (i == -1)
        return false;

    if (Digitos[i] < direita.Digitos[i])
        return true;
    else
        return false;
}

// Inverte a ordem dos operandos e comparara usando <
bool BigNum::operator > (const BigNum& direita) const
{
    return (direita < *this);
}

// <= é equivalente a não maior
bool BigNum::operator <= (const BigNum& direita) const
{
    return !(direita  < *this);
}

// >= é equivalente a não menor
bool BigNum::operator >= (const BigNum& direita) const
{
    return !(*this < direita);
}

//#if 0
// Operação de soma mais eficiente
inline BigNum BigNum::operator+(const BigNum& direita)
{
    BigNum num;
    USI i, carry;

    if(Sinal == direita.Sinal)
        num.Set_Sinal(Sinal);
    else
    {
        BigNum dir = direita;           // Como direita é const, não poderia modificá-la
        // ex.: -2 + 5
        if(Sinal == MENOS)
        {
            Sinal = MAIS;
            num = (dir - *this);
            Sinal = MENOS;
        }
        // ex.: 5 + (-2)
        else
        {
            dir.Set_Sinal(MAIS);
            num = (*this - dir);
            dir.Set_Sinal(MENOS);
        }

        return num;
    }

    num.Set_UD( max(UD, direita.UD) + 1 );

    carry = 0;
    for (i=0; i<=num.UD; i++)
    {
        num.Digitos[i] = (carry + Digitos[i] + direita.Digitos[i]);

        if (num.Digitos[i] >= BASE)
        {
            num.Digitos[i] -= BASE;
            carry = 1;
        }
        else
            carry = 0;
    }

    num.zero_justify();

    return num;
}
//#endif

#if 0
inline BigNum BigNum::operator+(const BigNum& direita)
{
    BigNum num;
    USI i, carry;

    if(Sinal == direita.Sinal)
        num.Set_Sinal(Sinal);
    else
    {
        BigNum dir = direita;           // Como direita é const, não poderia modificá-la
        // ex.: -2 + 5
        if(Sinal == MENOS)
        {
            Sinal = MAIS;
            num = (dir - *this);
            Sinal = MENOS;
        }
        // ex.: 5 + (-2)
        else
        {
            dir.Set_Sinal(MAIS);
            num = (*this - dir);
            dir.Set_Sinal(MENOS);
        }

        return num;
    }

    num.Set_UD( max(UD, direita.UD) + 1 );

    carry = 0;
    for (i=0; i<=num.UD; i++)
    {
        num.Digitos[i] = (carry + Digitos[i] + direita.Digitos[i]) % BASE;

        carry = (carry + Digitos[i] + direita.Digitos[i])/BASE;
    }

    num.zero_justify();

    return num;
}
#endif


inline BigNum BigNum::operator-(const BigNum& direita)
{
    BigNum num;
    BigNum dir=direita;         // Pois direita é const
    USI i;
    bool empresta;
    int v;

    if ( (Sinal == MENOS) || (dir.Sinal == MENOS) )
    {
        // Inverte o sinal do operando à dir
        dir.Set_Sinal(!dir.Sinal);

        // (a-b) = a + (-b)
        num = *this + dir;

        // Volta como era antes
        dir.Set_Sinal(!dir.Sinal);

        return num;
    }

    // É melhor subtrair um número pequeno de um número grande
    // (a - b) = -(b - a)
    if ( *this < dir)
    {
        num = dir - *this;
        num.Sinal = MENOS;

        return num;
    }

    num.UD = max( UD,dir.UD ); 
    empresta = 0;

    for (i=0; i<= num.UD; i++)
    {
        v = (Digitos[i] - empresta - dir.Digitos[i]);

        if (Digitos[i] > 0)
            empresta = 0;

        if (v<0)
        {
            v += BASE;
            empresta = 1;
        }

        num.Digitos[i] = v % BASE;
    }

    num.zero_justify();

    return num;
}

#if 0 
// Operação de multiplicação mais eficiente. Tem erro...
inline BigNum BigNum::operator*(const BigNum& direita)
{
    BigNum num;
    int i, j;

    // Se estiver multiplicando por 0 já retorna 0
    if (direita != num)
    {
        num.UD = UD + direita.UD;

        for(i=0; i <= UD; i++)
        {
            for (j=0; j <= direita.UD; j++)
                if ( (num.Digitos[i+j] += Digitos[i] * direita.Digitos[j]) >= BASE )
                {
                    num.Digitos[i+j+1] += num.Digitos[i+j] / BASE;
                    num.Digitos[i+j] = num.Digitos[i+j] % BASE;
                }
        }

        // Define o sinal do resultado.
        // Sinais iguais resulta em positivo e sinais diferentes resulta em negativos
        num.Sinal = (Sinal == direita.Sinal ? MAIS : MENOS);

        num.zero_justify();
    }

    return num;
}
#endif

//#if 0
// Sobrecarga do operador de multiplicação. Como é feito no papel
// ex.: 54 * -32 = -( 54+54  +  540+540+540) = -1728
inline BigNum BigNum::operator*(const BigNum& direita)
{
    BigNum num;
    BigNum row;
    int i, j;

    row = *this;

    for(i=0; i <= direita.UD; i++)
    {
        // Adiciona digitos[i] vezes equivale a múltiplicar por digitos[i]
        for (j=1; j <= direita.Digitos[i]; j++)
            num += row;

        row.digit_shift(1);
    }

    // Define o sinal do resultado.
    // Sinais iguais resulta em positivo e sinais diferentes resulta em negativos
    num.Sinal = (Sinal == direita.Sinal ? MAIS : MENOS);

    num.zero_justify();

    return num;
}
//#endif

inline BigNum BigNum::operator/(const BigNum& direita)
{
    BigNum num;
    BigNum dir = direita;       // Pois direita é const
    BigNum row;
    int asign, bsign;
    int i,j;

    // Define o sinal do resultado.
    // Sinais iguais resulta em positivo e sinais diferentes resulta em negativos
    num.Sinal = (Sinal == dir.Sinal ? MAIS : MENOS);

    asign = Sinal;
    bsign = dir.Sinal;

    Sinal = MAIS;
    dir.Set_Sinal(MAIS);

    num.Set_UD(UD);

    // Vai "abaixando" dígitos do dividendo até serem maior que o divisor
    for (i=UD; i >= 0; i--)
    {
        row.digit_shift(1);

        row.Digitos[0] = Digitos[i];

        num.Digitos[i] = 0;

        // Se abaixou dígitos suficientes, realiza uma parte da divisão
        // utilizando sucessivas subtrações. O resto é descartado
        while( row >= dir )
        {
            num.Digitos[i]++;
            row -= dir;
        }
    }

    num.zero_justify();

    Sinal = asign;
    dir.Set_Sinal(bsign);

    return num;
}

inline BigNum &BigNum::operator+=(const BigNum &direita)
{
    *this = *this + direita;

    return *this;
}

#if 0
inline BigNum &BigNum::operator+=(const BigNum &direita)
{
    *this = *this + direita;

    return *this;
}
#endif

// Não pode ser const pois minha adição altera o sinal do operando da direita
inline BigNum &BigNum::operator-=(const BigNum &direita)
{
    *this = *this - direita;

    return *this;
}

// Soma 1 ao BigNum antes de usá-lo
inline BigNum BigNum::operator++ ()
{
    BigNum um(1);

    *this = *this + um;

    return *this;
}

// Subtrai 1 ao BigNum antes de usá-lo
inline BigNum BigNum::operator-- ()
{
    BigNum um(1);

    *this - *this - um;

    return *this;
}

inline BigNum BigNum::operator++(int)
{
    BigNum um(1);
    BigNum temp = *this;

    *this += um;

    return temp;
}

inline BigNum BigNum::operator--(int)
{
    BigNum um(1);
    BigNum temp = *this;

    *this -= um;

    return temp;
}

// Sobrecarga do operador de saída
ostream &operator<<( ostream &output, const BigNum &num )
{
    int i;

    if (num.Sinal == MENOS)
        output << "-";

    for (i = num.UD; i >= 0; i--)
        output << (char)('0' + num.Digitos[i]);

    return output;
}

// Sobrecarga do operador de entrada
// A entrada consiste de vários dígitos precedido ou não de sinal
istream &operator>>( istream &input, BigNum &num)
{
    string temp;
    USI i, j, inicio;

    input >> temp;

    if (temp.at(0) == '-')
    {
        num.Sinal = MENOS;
        // Serve para ignorar o sinal
        inicio = 1;
        num.UD = temp.length()-2;
    }
    else
    {
        num.Sinal = MAIS;
        inicio = 0;
        num.UD = temp.length()-1;
    }

    for (i = inicio, j = num.UD; i<temp.length(); i++, j--)
        num.Digitos[i] = temp.at(j) - '0';

    return input;
}

// Ajusta a posição do último dígito, para evitar zeros a esquerda
void BigNum::zero_justify()
{
   while ( (UD > 0) && (Digitos[UD] == 0) ) 
       UD--;

   // Evita -0
   if ( (UD == 0) && (Digitos[0] == 0) )
       Sinal = MAIS;
}

// Multiplica n por BASE^d -> desloca algarismos d dígitos para a direita
// Ex.: d=2; 384500000 -> 003845000
void BigNum::digit_shift(int d)
{
    int i;

    // Se já for tudo 0 não faz sentido deslocar
    if ( (UD == 0) && (Digitos[0] == 0) )
        return;

    for (i=UD; i>=0; i--)
        Digitos[i+d] = Digitos[i];

    // Preenche os d primeiros dígitos com 0, pois eles já foram deslocados
    for (i=0; i<d; i++)
        Digitos[i] = 0;

    UD += d;
}
