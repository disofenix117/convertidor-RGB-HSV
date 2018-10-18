#include<iostream>
#include<string.h>
#include <string>
#include <math.h>
using namespace std;
struct color
{
	int c1, c2, c3;

};

color Color;

color RGB2HSV(float R, float G, float B)
{
	//variables locales
	float R1, G1, B1,delta;
	R1 = R / 255;
	G1 = G / 255;
	B1 = B / 255;
	float Max, Min;
	Max = fmaxf(R1, fmaxf(G1, B1));
	Min = fminf(R1, fminf(G1, B1));
	delta = Max - Min;
	// Calculo H
	if (Max == Min)
	{
		Color.c1 = 0;
	}
	else if (Max == R1 && G1 >= B1)
	{
		Color.c1 = 60 * ((G1 - B1) / (delta)) + 0;
	}
	else if (Max == R1 && G1 < B1)
	{
		Color.c1 = 60 * ((G1 - B1) / (delta)) + 360;
	}
	else if (Max == G1)
	{
		Color.c1 = 60 * ((B1 - R1) / (delta)) + 120;
	}
	else if (Max == B1)
	{
		Color.c1 = 60 * ((R1- G1) / (delta)) + 240;
	}
	//Calculo S
	if (Max == 0)
	{
		Color.c2 = 0;
	}
	else
	{
		Color.c2 = (delta/Max)*100;
	}
	//Calculo V
	Color.c3 = Max*100;
	return (Color);
}
color HSV2RGB(float H, float S, float V)
{
	//variables locales
	int R, G, B, H[360],C,X,m,V[1];
	C = V * S;
	X = C * (1 - abs((H / 60)/  2 - 1));
	m = V - C;
	if (H >= 0 && H <= 60)
	{
		R = C;
		G = X;
		B = 0;
	}
	else if (H >= 60 && H <= 120)
	{
		R = C;
		G = X;
		B = 0;
	}
}
int main()
{
	int  opc;
	int  H, S, V,C,X,M;
	int R,G,B,r,g,b;
	int index = 1;
	do
	{
		cout << ". : : C O N V E R T I D O R   D E   C O L O R   R G B - H S V : : . " << endl << endl;
		cout << "Que quiere convertir?" << endl << endl;

		cout << "1) H S V - R G B." << endl;
		cout << "2) R G B - H S V." << endl;
		cout << "0) Salir." << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			system("cls");
			{
				cout << "Ingrese el valor de H:";
				cin >> H;
				cout << "Ingrese el valor de S:";
				cin >> S;
				cout << "Ingrese el valor de V:";
				cin >> V;
				if (H >= 0 && H < 360 && S >= 0 && S <= 1 && V >= 0 && V <= 1)
				{
					C = V * S;
					//X = C * (1 - (abs( H / (pi / 3) % 2 - 1)));
					M = V - C;




				}
			}
		case 2:
			system("cls");
			{
				cout << "Ingrese el valor de R:";
				cin >> R;
				cout << "Ingrese el valor de G:";
				cin >> G;
				cout << "Ingrese el valor de B:";
				cin >> B;
				RGB2HSV(R, G, B);
				H = Color.c1;
				S = Color.c2;
				V = Color.c3;
												
				cout << "EL VALOR DE COLOR PARA HSV ES:"<<endl;
				cout << "H:" << H << "\t" << "S:" << S << "\t" << "V:" << V << "\t" << endl;
			
			}
		default:
			break;
		}

	} while (index == 1);

	system("pause");
}