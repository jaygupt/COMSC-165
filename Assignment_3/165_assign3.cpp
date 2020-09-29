#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double &score);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

const int lowerBound = 0.0;
const int upperBound = 10.0;

int main()
{
	double score1;
	double score2;
	double score3;
	double score4;
	double score5;


	getJudgeData(score1);

	//IMPLEMENT THE REST OF THE MAIN FUNCTION

	system("PAUSE");
  return 0;
}

void getJudgeData(double &score) {
	cout << "Enter a judge's score: ";
	cin >> score;

	if (score < lowerBound || score > upperBound) {
		cout << "The score must be from " << lowerBound << " to " << upperBound << ".";
	}
}

void calcScore(double, double, double, double, double) {

}

double findLowest(double, double, double, double, double) {

}

double findHighest(double, double, double, double, double) {

}
