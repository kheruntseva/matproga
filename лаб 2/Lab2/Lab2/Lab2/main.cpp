#include"stdafx.h"
#include<iomanip>
#define N (sizeof(AA)/2)
#define S 5
#define M 3
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	//��������� �����������///////////////////////////////////////////////////////
	char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " - ��������� ��������� ���� ����������� -";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	clock_t st1 = clock();
	std::cout << std::endl << "��������� ���� �����������  ";
	combi::subset s1(sizeof(AA) / 2);         // �������� ����������   
	int  n1 = s1.getfirst();                // ������ (������) ������������    
	while (n1 >= 0)                          // ���� ���� ������������ 
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n1; i++)
			std::cout << AA[s1.ntx(i)] << ((i < n1 - 1) ? ", " : " ");
		std::cout << "}";
		n1 = s1.getnext();                   // c�������� ������������ 
	};
	clock_t end1 = clock();
	cout << "\n����������������� (�.�):   " << (end1 - st1);
	cout << "\n                  (���):   " << ((double)(end1 - st1)) / ((double)CLOCKS_PER_SEC);

	std::cout << std::endl << "�����: " << s1.count() << std::endl;
	///////////////////////////////////////////////////////////////////////////////

	//��������� ���������//////////////////////////////////////////////////////////
	std::cout << std::endl << " --- ��������� ��������� ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ��������� ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	std::cout << "�� " << xc.n << " �� " << xc.m;
	int  n2 = xc.getfirst();
	while (n2 >= 0)
	{
		std::cout << std::endl << xc.nc << ": { ";
		for (int i = 0; i < n2; i++)
			std::cout << AA[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		std::cout << "}";
		n2 = xc.getnext();
	};
	std::cout << std::endl << "�����: " << xc.count() << std::endl;

	///////////////////////////////////////////////////////////////////////////////


	/////////////////////��������� ������������////////////////////////////////////

	std::cout << std::endl << " --- ��������� ������������ ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)

		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ������������ ";
	combi::permutation p(sizeof(AA) / 2);
	__int64  n3 = p.getfirst();
	while (n3 >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";

		for (int i = 0; i < p.n; i++)

			std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

		std::cout << "}";

		n3 = p.getnext();
	};
	std::cout << std::endl << "�����: " << p.count() << std::endl;


	///////////////////////////////////////////////////////////////////////////////


	////////////////////////////////��������� ����������//////////////////////////

	std::cout << std::endl << " --- ��������� ���������� ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++)

		std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ����������  ��  " << N << " �� " << M;
	combi::accomodation s(N, M);
	int  n4 = s.getfirst();
	while (n4 >= 0)
	{

		std::cout << std::endl << std::setw(2) << s.na << ": { ";

		for (int i = 0; i < 3; i++)

			std::cout << AA[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");

		std::cout << "}";

		n4 = s.getnext();
	};
	std::cout << std::endl << "�����: " << s.count() << std::endl;



	////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////�����������(�� ������ ������������)////////////////////////////////
	clock_t start = clock();
	int d[S][S] = {
		{INF,26,34,INF,13},
		{13,INF,28,55,71},
		{15,39,INF,86,62},
		{30,45,52,INF,39},
		{80,79,52,26,INF}
	};


	int r[S];                     // ��������� 
	
	int s10 = salesman(
		S,          // [in]  ���������� ������� 
		(int*)d,          // [in]  ������ [n*n] ���������� 
		r           // [out] ������ [n] ������� 0 x x x x  
	);

	std::cout << std::endl << "-- ������ ������������ -- ";
	std::cout << std::endl << "-- ����������  �������: " << S;
	std::cout << std::endl << "-- ������� ���������� : ";

	for (int i = 0; i < S; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < S; j++)

			if (d[i][j] != INFINITY) std::cout << std::setw(3) << d[i][j] << " ";

			else std::cout << std::setw(3) << "INF" << " ";
	}
	std::cout << std::endl << "-- ����������� �������: ";
	for (int i = 0; i < S; i++) std::cout << r[i] << "-->"; std::cout << 0;
	std::cout << std::endl << "-- ����� ��������     : " << s10;
	std::cout << std::endl;
	int end = clock();
	cout << "\n����������������� (�.�):   " << (end - start);
	cout << "\n                  (���):   " << ((double)(end - start)) / ((double)CLOCKS_PER_SEC);
	//////////////////////////////////////////////////////////////////////////////


	system("pause");
}