// ============================================================================
// 
//       Filename:  01040-media_3.cpp
// 
//    Description:  URI 1040 - Média 3
// 
//        Version:  1.0
//        Created:  09/27/2012 08:12:00 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double n[4], exame;
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    
    double media = (2*n[0] + 3*n[1] + 4*n[2] + n[3]) / 10;
    
    cout << fixed << setprecision(1);
    cout << "Media: " << media << endl;
    
    if (media >= 7.0)
        cout << "Aluno aprovado." << endl;
    else if (media >= 5.0)
    {
       cout << "Aluno em exame." << endl;
       cin >> exame;
       cout << "Nota do exame: " << exame << endl;
       media = (media+exame)/2;
       
       if (media >= 5.0)
           cout << "Aluno aprovado." << endl;
       else
           cout << "Aluno reprovado." << endl;
    }
    else
        cout << "Aluno reprovado." << endl;
    
    cout << "Media final: " << media << endl;
    
    return 0;
}
