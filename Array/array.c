//#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<Windows.h>

//get pivot row is GPR
//PCO preform column operations
// rrwo refrremce row for swapping
//scol reffrence colom for swaping
//srow the row t be swapped
// scol column to be swaped 
//int _tmain(int argc, _TCHAR* argv[])
//int m[100][100] , copy[100][100];
//int r , c , row=4 , col=4 ;
int r , c , row=3 , col=3 ;
int rrow=0 , rcol = 0;
int srow , scol ; 
//float m[4][4]={-2 , 2 , 1 , -1, 4 , 8 , 4 , -8 , 1, 2 , 0 , -1 , 0, 6 ,2 ,-4};
float m[3][3]={2 , 1 , 0 , 2 , 0 ,-2, 2 , -1 , -4};
//float copy[4][4];
float copy[3][3];

int GPR(int c);
void swaprows(int r2 , int r1);
void PRO(int c , int r);
void PCO(int c , int r);
void displayC();
void displayM();

int main()
 
{
	//printf("Input matrix");
	//displayM();
	//printf("Flag");
	/*printf("Enter the dimenssions of the matrix:\n");
	scanf("%.2f%.2f" , & row , &col);
	printf("Enter elemnts\n");*/
	for(r=0;r<row; r++)
		for(c=0 ; c<col ; c++)
		{ 
			//scanf("%.2f" ,& m[r][c]);
			copy[r][c] = m[r][c];
		}

		
		//displayM();
		for(c=0 ; c<col-1 ; c++)
		{
			srow = GPR(c);
			//printf("\n\ %.2f th swap row is %.2f \n" , c , srow);
			//displayC();
			if(srow != -1)
			{
				if(srow != rrow)
				{
					swaprows(srow , rrow);
					//displayC();
				}
				//printf("\nbefore PCO:\n");
				//displayC();
				PCO(c, rrow );
				//printf("\nafter PCO:\n");
				//displayC();
				
				//printf("\nafter PRO:\n");
				PRO(c , rrow);
				//displayC();
				rrow++;
			}

		}
		printf("Input matrix:\n");
		displayM();
		printf("\n\nOutput Mtrix:\n");
		displayC();
		getch();
		system("cls");
	return 0;
}

int GPR(int c)
{
	int r;
	for(r=c ; r<row ; r++)
	{
		if(copy[r][c] !=0)
			return r;
	}
	return -1;
}

void swaprows(int r2 , int r1)
{
	int temp[100];
	for(c=0 ; c<col ; c++)
	{
		temp[c] = copy[r2][c];
		copy[r2][c] = copy[r1][c];
		copy[r1][c] = temp[c];
	}
}

void PRO(int c , int r)
{
	int i , j;
	float x;
	//printf("\nin PRO\n");
	//displayC();
	//printf("\nvalue of copy[r][c] %.2f\n" , copy[r][c]);
	
	for(i=0 ; i< row ; i++)
	{
		
		
		if( i != r/* && copy[i][c]!=0 && copy[r][c]!=0 */)
		{
			x=copy[i][c];
		//	printf("\nx=%.2f\n" , x);
			//printf("\nrow no:%d\n" ,i);
			for(j=0 ; j<col ; j++)
			{
				//if(copy[i][j]!=0)
				//{
				//printf("\n%.2f - (%.2f*%.2f)\t" , copy[i][j]  ,x, copy[r][j]);
				copy[i][j] = copy[i][j] - ((x*copy[r][j]));
				//printf("\n%.2f\n" , copy[i][j] );
				//}
			}
		}
		//printf("\n");
		//printf("\n");
		//printf("\n");
	}
}

void PCO(int c , int r)
{
	int i;
	float x;
	x=copy[r][c];
	//printf("\nin pco\n");
	for(i=0; i<col ; i++)
	{
		if(copy[r][c]!=0)
		{
			//printf("\n%.2lf / %.2lf\n" , copy[r][i] , x);
			copy[r][i] = copy[r][i] / x ;
		}
	}
}

void displayM()
{
	printf("\n");
	printf("\n");
	for(r=0; r<row;r++)
	{
		for(c=0;c<col;c++)
		{
			printf("%.2f \t" , m[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void displayC()
{
	printf("\n");
	printf("\n");
	for(r=0; r<row;r++)
	{
		for(c=0;c<col;c++)
		{
			printf("%.2f \t" , copy[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}