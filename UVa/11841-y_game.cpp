// ============================================================================
//
//       Filename:  11841-y_game.cpp
//
//    Description:  UVa 11841 - Y-game
//
//        Version:  1.0
//        Created:  25/Jan/2014 19:56:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


struct ponto
{
    int x, y, z;
    ponto(int x, int y, int z) : x(x), y(y), z(z) {}
};


bool visitado[21][21][21];
bool tem_x0, tem_y0;
bool grid[21][21][21];
bool benny_ganhou;
int n, m;
vector<ponto> preto;
vector<ponto>::iterator it;


// Verifica se coordenada (x,y,z) é válida
inline bool v_xyz(int x, int y, int z)
{
    if (x >= 0 && y >= 0 && z >= 0 && x <= n && y <= n && z <= n)
        return true;
    return false;
}


void dfs(ponto p)
{
    visitado[p.x][p.y][p.z] = 1;

    if (p.x == 0) tem_x0 = true;
    if (p.y == 0) tem_y0 = true;
    // Existe pontos em todos os lados, então Benny ganhou
    if (tem_x0 && tem_y0)
        benny_ganhou = true;

    int x, y, z;
    x = p.x - 1; y = p.y; z = p.z + 1;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
    x = p.x - 1; y = p.y + 1; z = p.z;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
    x = p.x; y = p.y - 1; z = p.z + 1;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
    x = p.x; y = p.y + 1; z = p.z - 1;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
    x = p.x + 1; y = p.y - 1; z = p.z;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
    x = p.x + 1; y = p.y; z = p.z - 1;
    if (!benny_ganhou && v_xyz(x, y, z) && grid[x][y][z] && !visitado[x][y][z])
        dfs(ponto(x, y, z));
}


int main()
{
    while (scanf("%d %d", &n, &m) && (n || m))
    {
        memset(grid, 0, sizeof(grid));
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            grid[x][y][z] = 1;
            // Só precisa verificar os caminhos que tiverem pontos no lado z
            if (z == 0)
                preto.push_back(ponto(x, y, z));
        }

        memset(visitado, 0, sizeof(visitado));
        benny_ganhou = false;
        for (it = preto.begin(); it != preto.end() && !benny_ganhou; it++)
        {
            tem_x0 = tem_y0 = false;
            if (!visitado[it->x][it->y][it->z])
                dfs(*it);
        }
        puts(benny_ganhou ? "Benny" : "Willy");
        preto.clear();
    }
    return 0;
}

