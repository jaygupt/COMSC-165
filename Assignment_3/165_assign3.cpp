#include <iostream>
#include <iomanip>
using namespace std;

void getJudgeData(double &score);
void calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

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
	getJudgeData(score2);
	getJudgeData(score3);
	getJudgeData(score4);
	getJudgeData(score5);

	calcScore(score1, score2, score3, score4, score5);

	system("PAUSE");
  return 0;
}

void getJudgeData(double &score) {
	cout << "Enter a judge's score: ";
	cin >> score;

	while (score < lowerBound || score > upperBound) {
		cout << "The score must be between " << lowerBound << " to " << upperBound << "." << endl;
		cout << "Enter a judge's score: ";
		cin >> score;
	}
}

void calcScore(double score1, double score2, double score3, double score4, double score5) {
	double lowest = findLowest(score1, score2, score3, score4, score5);
 	double highest = findHighest(score1, score2, score3, score4, score5);

	double totalOfRemainingThree = (score1 + score2 + score3 + score4 + score5) - (highest + lowest);
	double averageOfRemainingThree = totalOfRemainingThree / 3.0;

	cout << endl << "After dropping the lowest and highest scores, the average score was: "
	<< averageOfRemainingThree << "." << endl << endl;
}

double findLowest(double score1, double score2, double score3, double score4, double score5) {
	double lowest = score1;
	if (lowest > score2) {
		lowest = score2;
	}
	if (lowest > score3) {
		lowest = score3;
	}
	if (lowest > score4) {
		lowest = score4;
	}
	if (lowest > score5) {
		lowest = score5;
	}
	return lowest;
}

double findHighest(double score1, double score2, double score3, double score4, double score5) {
	double highest = score1;
	if (highest < score2) {
		highest = score2;
	}
	if (highest < score3) {
		highest = score3;
	}
	if (highest < score4) {
		highest = score4;
	}
	if (highest < score5) {
		highest = score5;
	}
	return highest;
}
