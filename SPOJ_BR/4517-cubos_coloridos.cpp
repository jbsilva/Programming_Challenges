// ============================================================================
//
//       Filename:  4517-cubos_coloridos.cpp (SPOJ BR)
//                  01368-cubos_coloridos.cpp (URI)
//
//    Description:  SPOJ BR 4517 - Cubos Coloridos
//                  URI 1368 - Cubos Coloridos
//
//                  br.spoj.com/problems/CUBOS/
//                  Primeira fase da Maratona de Programação - 2005
//
//        Version:  1.0
//        Created:  08/May/2013 12:39:56
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;


struct cubo
{
    int f[6];

    inline bool operator<(const cubo &c) const
    {
        return memcmp(f, c.f, sizeof(f)) < 0 ? true : false;
    }
};


cubo c;
set<cubo> cubos;


inline void rot_x()
{
    int temp = c.f[0];
    c.f[0] = c.f[1];
    c.f[1] = c.f[5];
    c.f[5] = c.f[3];
    c.f[3] = temp;
}


inline void rot_y()
{
    int temp = c.f[1];
    c.f[1] = c.f[2];
    c.f[2] = c.f[3];
    c.f[3] = c.f[4];
    c.f[4] = temp;
}


inline void rot_z()
{
    int temp = c.f[0];
    c.f[0] = c.f[2];
    c.f[2] = c.f[5];
    c.f[5] = c.f[4];
    c.f[4] = temp;
}


// Verifica se uma rotação de 'c' já está no set 'cubos'
inline bool tem_rotacao()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            rot_y();
            for (int z = 0; z < 4; z++)
            {
                rot_z();
                if (cubos.count(c))
                    return true;
            }
        }
        rot_x();
    }
    return false;
}


int main()
{
    int N;
    while (scanf("%d", &N) && N)
    {
        int unicos = 0;
        for (int i = 0; i < N; i++)
        {
            for (int i = 0; i < 6; i++)
                scanf("%d", &c.f[i]);
            if (!tem_rotacao())
            {
                unicos++;
                cubos.insert(c);
            }
        }
        printf("%d\n", unicos);
        cubos.clear();
    }
    return 0;
}

