// console_Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GF.h"
using namespace std;


// Galois field GF(2^m).

extern GF operator/(const GF& a, const GF& b);
extern ostream& operator<<(ostream& ostr, const GF& a);

void print_mult_table(int m)
{
	GF::construct_GFTable(m);
	GFTable* gft = GF::GFT_vec[m];
	int q = (1 << m);

	cout << "Multiplication table for GF(2^" << m << "):" << endl;
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < q; j++)
		{
			cout << gft->GFMT[i*q + j] << '\t';
		}
		cout << endl;
	}
	cout << "primitive element alpha = " << gft->primitive_chain[1] << endl;
	cout << "Generator matrix = ";
	for (int i = m; i >= 0; i--)
	{
		if (i > 0 && (gft->poly & (0x1 << i)))cout << "x^" << i << "+";
		if (i == 0 && (gft->poly & (0x1 << i)))cout << "1";
	}
	cout << endl;
}

int main()
{
	int m = 4;
	print_mult_table(m);
	


	return 0;
}

