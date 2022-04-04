#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("date.in");
ofstream fout("date.out");
int main()
{

	int xLength, yLength;
	char x[100], y[100];
	fin >> x >> y;
	fout << x << " " << y << endl;

	for (int i = 0; i < 100; i++) {
		//fout << int(x[i]-'0')<<" ";
		if (x[i] == '\0') {
			xLength = i;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (y[i] == '\0') {
			yLength = i;
		}
	}
	fout << xLength << " " << yLength << endl;
	fout << "---------" << endl;


	//============================
	int apparenceCount = 0;
	if (xLength > yLength) {
		apparenceCount = xLength - yLength;
	}
	if (yLength > xLength) {
		apparenceCount = yLength - xLength;
	}
	if (xLength == yLength) {
		apparenceCount = 2;
	}
	fout << "app:" << apparenceCount << endl;

	int halfSquareCount = 1, lim = 1;

	if (xLength != yLength) {
		halfSquareCount++;
	}
	if (xLength > yLength) {
		lim = yLength;
	}
	if (xLength <= yLength) {
		lim = xLength;
	}
	for (int i = 1; i < lim; i++) {
		halfSquareCount += 2;
	}



	fout << "max:" << halfSquareCount << endl;

	int stepsNum = xLength + yLength;
	fout << "step:" << stepsNum << endl;
	fout << "---------" << endl;


	int a[100][100] = { 0 };
	for (int i = 0; i < xLength; i++) {
		for (int j = 0; j < yLength; j++) {
			a[i][j] = int(x[i] - '0') * int(y[j] - '0');
		}
	}

	//TEST
	for (int i = 0; i < xLength; i++) {
		for (int j = 0; j < yLength; j++) {
			fout << a[i][j] << " ";
		}fout << endl;
	}

	struct queuePosition {
		int xPos;
		int yPos;
	}qPos[10000] = { 0 };


	/*
	//First Top Half
	qPos[0].xPos = 1;
	qPos[0].yPos = 1;
	int qLastPos = 1;
	int qInitalPos = 0;
	int deleteAmount = 0;
	*/

	/*
	for (int j = 0; j < ; j++) {
		for (int k = qInitalPos; k < qLastPos; k++) {
			qPos[qLastPos + k].xPos = qPos[k].xPos;
			qPos[qLastPos + k].yPos = qPos[k].yPos + 1;
			qPos[qLastPos + k].xPos = qPos[k].xPos + 1 ;	
			qPos[qLastPos + k].yPos = qPos[k].yPos;
		}

	}

	for (int j = 0; j < yLength; j++) {
		sumFirstHalf = sumFirstHalf * 10 + ;
		for (int k = ; k < ; k++) {
			qPos[k]=
		}

		//del amount
	}*/
	fout << "---------" << endl;

	int firstHalfSum = 0;
	int sumRest = 0;
	for (int J = 0; J < yLength; J++) {
		int j = J;
		int I = 0;
		int sumDiag = 0;

		firstHalfSum = firstHalfSum + sumRest;
		sumRest = 0;

		while (I >= 0 && I<xLength && j>=0 && j<yLength) {
			sumDiag += a[I][j]/10%10;
			sumRest += a[I][j] % 10;

			I++;
			j--;
		}
		fout << sumDiag << " " << sumRest<<" ";

		firstHalfSum = firstHalfSum + sumDiag;
		fout << firstHalfSum << endl;
		firstHalfSum *= 10;
	}
	fout << "---------" << endl;
	firstHalfSum /= 10;
	int secondHalfSum = 0;
	/*
	for (int I = 0; I < xLength; I++) {
		int i = I;
		int J = 0;
		int sumDiag = 0;

		secondHalfSum = secondHalfSum + sumRest;
		sumRest = 0;

		while (i >= 0 && i < xLength && J >= 0 && J < yLength) {
			sumDiag += a[i][J]  % 10;
			sumRest += a[i][J] / 10 % 10;

			i++;
			J--;
		}
		fout << sumDiag << " " << sumRest << " ";

		secondHalfSum = secondHalfSum + sumDiag;
		fout << secondHalfSum << endl;
		secondHalfSum *= 10;
	}
	*/
	fout << "---------" << endl;//HERE START -- NOPE
	secondHalfSum = 0;
	for (int I = xLength-1; I>=0; I--) {
		int i = I;
		int J = yLength-1;
		int sumDiag = 0;

		secondHalfSum = secondHalfSum + sumRest;
		sumRest = 0;

		while (i >= 0 && i < xLength && J >= 0 && J < yLength) {
			//fout << i << " " << J << endl;
			sumDiag += a[i][J] % 10;
			sumRest += a[i][J] /10 % 10;

			i++;
			J--;
		}
		fout << sumDiag << " " << sumRest << " " <<endl;
		//fout << "-" << endl;
		/*
		secondHalfSum = secondHalfSum + sumDiag;
		fout << secondHalfSum << endl;
		secondHalfSum *= 10;*/
	}//HERE END

	secondHalfSum /= 10;
	fout << "*" << firstHalfSum << endl << secondHalfSum << endl;
	fout << "---------" << endl;
}