// ============================================================================
// 
//       Filename:  00623-500_fatorial.java
// 
//    Description:  UVa 623 - 500!
//                  Treino de BigInt com Java
// 
//        Version:  1.0
//        Created:  09/25/2012 07:04:36 PM
//       Revision:  none
//       Compiler:
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
import java.math.*;
import java.util.*;

// Não deixei publico, pois o nome do arquivo é diferente da classe
class Main
{	
	public static void main(String[] args)
	{
		BigInteger[] fat = new BigInteger[1002];
		BigInteger i = BigInteger.ONE;
		
		fat[0] = fat[1] = i;
		
		for (int j = 2; j <= 1000; j++)
		{
			i = i.multiply(BigInteger.valueOf(j));
			fat[j] = i;
		}
		
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextInt())
		{
			int n = sc.nextInt();
			System.out.println(n + "!");
			System.out.println(fat[n]);
		}
	}
}
