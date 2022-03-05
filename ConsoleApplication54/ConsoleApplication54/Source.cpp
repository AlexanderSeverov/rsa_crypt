#include <time.h>
#include <tuple>
#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
#include "Source.h"


using namespace std;
int proizc,ec;
string *strokDCrypt=new string[9999];
int d = 1;


char *symbol[37][2] =
{

	{ "а","0" },
	{ "б","1" },
	{ "в","2" },
	{ "г","3" },
	{ "д","4" },
	{ "ё","5" },
	{ "е","6" },
	{ "ж","7" },
	{ "з","8" },
	{ "й","9" },
	{ "и","10" },
	{ "к","11" },
	{ "л","12" },
	{ "м","13" },
	{ "н","14" },
	{ "о","15" },
	{ "п","16" },
	{ "р","17" },
	{ "с","18" },
	{ "т","19" },
	{ "у","20" },
	{ "ф","21" },
	{ "х","22" },
	{ "ц","23" },
	{ "ч","24" },
	{ "ш","25" },
	{ "щ","26" },
	{ "ъ","27" },
	{ "ь","28" },
	{ "ы","29" },
	{ "э","30" },
	{ "ю","31" },
	{ "я","32" },
	{ "-","33" },
	{ ",","34" },
	{ ".","35" },
	{ " ","36" },
};

long prost()
{
	bool checkNUM = true, checkNUM2 = true;
	int x=0;
	
	while (checkNUM == true)
	{
		if (checkNUM != false)
		{
			x = rand()%11;
		}


		if (checkNUM != false)
		{

			checkNUM2 = true;
			for (long int i = 2; i < x; i++)
			{
				if (x % i == 0)
				{
					checkNUM2 = false;
					break;
				}
				if ((i == x - 1) && (checkNUM2 == true))
				{
					checkNUM = false;
					break;
				}
			}
		}
	}

	return x;
}

std::tuple<int, int> key(int e, int proiz)
{
	//bool checkNUM= true,checkNUM1 = true, checkNUM2 = true,checkNUM3 = true;
	long p, q, modulP, modulQ, eiler, test;



	p = prost();
	q = prost();
	

	//modulP = abs(p);
	//modulQ = abs(q);
	//proiz = modulP*modulQ;
	proiz = p*q;
	proizc = proiz;
	eiler = (p - 1)*(q - 1);
	e = prost();
	
	while ((e > eiler) && ((eiler%e) == 0))
	{
		e = prost();
	}
	ec = e;



	while ((d*e) % eiler != 1)
	{
		d++;
		
	}
	if (d > 10)
		tie(e, proiz) = key(0, 0);//key(0, 0);
	return std::make_tuple(e, proiz);
}

//std::tuple<long, long> key(long e, long proiz)
//int crypt(string &TEXTc)
std::tuple<string> crypt(string &TEXTc)
{
	int numCrypt = 0;
	int i = 0;
	int  numstrok = 0;

	

	/*char *strokCrypt = new char[(TEXTc.length())*2];
	delete[] strokCrypt;*/

	std::string strokCrypt[9999];

	
	int w = 0;

	for (int k = 0; k < TEXTc.length(); k++)
	{
		int j = 1;
		int i = 0;
		
		while (i < 36)
		{
			i++;
			
		
			if (TEXTc[k] == *symbol[i][0])
			{
				if (i == 0)
				{
					strokCrypt[w] = *symbol[i][j];

				}
				
				strokCrypt[w] = symbol[i][j];
				w++;
				i = 36;
			}
			

		}
		
	}
	
	
	//tie(e,proiz) = key(0,0);

	//auto t = std::make_tuple(e, proiz);
	

	string strokCrypted[9999];
	

	while(strokCrypt[i] != "")
	{
		
		numstrok = stoi(strokCrypt[i]);
		numCrypt=pow(numstrok, ec);
		numCrypt=numCrypt%proizc;
		strokCrypted[i] = to_string(numCrypt);
		cout << "зашифрованный текст";
		cout << "\n";
		cout << strokCrypted[i];
	/*	if (strokCrypted[i] > stoi(proizc))
		{
			cout << "слишком большие цифры невозможно зашифровать";
			system("pause");
			
		}*/
		strokDCrypt[i] = strokCrypted[i];
		cout << "\n";
		i++;
	}


	/*for (int i = 0; i <= 999999; i++)
	{
		int z = 0;
		while (z <= 36)
		{
			if (strokCrypt[i] == symbol[z][1])
			{
				cout << symbol[z][0];
			}
			z++;
		}


	}*/


	return std::make_tuple(TEXTc);
	//return 0;
}


int decoding()
{
	long proizd,numddd;
	int l = 0, numdd = 0;
	int numD=0;
	//long double numD = 0;
	

	std::string strokAD[9999], strokADD[9999];
	//string *strokADD = new string[9999];
	proizd = proizc;
	

	if (d < 0)
		exit(0);


	while (strokDCrypt[l] != "")
	{
		
		numdd = stoi(strokDCrypt[l]);
		numdd = pow(numdd, d);
		numD=numdd%proizd;
		numddd = numD;
		strokAD[l] = to_string(numddd);	
		l++;
	}

	int h = 0;
	int i = 0;
	int j = 1;
	

	for (int k = 0; k < 9999; k++)
	{
		
		
		i = 0;
		while (i < 36)
		{
			

			
			if (strokAD[k] == string(symbol[i][1]))
			{
				if (i == 0)
				{
					strokADD[h] = *symbol[i][j];

				}

				strokADD[h] = *symbol[i][0];
				h++;
				i = 35;
			}
			i++;
		}
		
	}
	cout << "расшифрованная";
	cout << "\n";
	for (int v = 0; strokADD[v] != ""; v++)
	{
		
		cout << strokADD[v];

	}

	

	return 0;
}

void text()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string textC;
	

	cout << "vvod text";
	getline(cin,textC);
	tie(textC) = crypt(textC);
	//crypt(textC);
}

int main() 
{
	srand(time(0));
	key(0, 0);
	int o = 0;
	text();

	cout << "расшифровать 1-да  2-нет\n";
	cin >> o;

	if (o == 1)
	{
		decoding();
	}


//	auto t = std::make_tuple(d, proiz);
	//test = get<0>(t);

	//cout << "secret" << d << "scret" << proiz;
	system("pause");
	return 0;
}