#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes 
void getJudgeData(double &score);
void calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

// 1. create constant bounds for user input, to be used 
// throughout the program.  
const int lowerBound = 0.0;
const int upperBound = 10.0;

int main()
{
	// declare score variables
	double score1;
	double score2;
	double score3;
	double score4;
	double score5;

	// new line before program starts
	cout << endl; 


	// 2. Get judge scores, and store values in 
	// the respective score variable using references
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

	// 3. This while loop runs until the user gives an input
	// between the bounds specified near the top of the program. 
	while (score < lowerBound || score > upperBound) {
		cout << "The score must be between " << lowerBound << " to " << upperBound << "." << endl;
		cout << "Enter a judge's score: ";
		cin >> score;
	}
}

// 4. Calculates the average of the middle 3 values (excludes 
// lowest and highest)
void calcScore(double score1, double score2, double score3, double score4, double score5) {
	// 5. Find the lowest and highest values using external functions
	double lowest = findLowest(score1, score2, score3, score4, score5);
 	double highest = findHighest(score1, score2, score3, score4, score5);

	// 6. To calculate the middle 3's total, take the sum of all 5 
	// values, and subtract the sum of the lowest and highest. This 
	// leaves us with the sum of the middle 3
	double totalOfRemainingThree = (score1 + score2 + score3 + score4 + score5) - (lowest + highest);
	double averageOfRemainingThree = totalOfRemainingThree / 3.0;

	// 7. Display the average to the user, after explaining the procedure. 
	cout << endl << "After dropping the lowest and highest scores, the average score was: "
	<< averageOfRemainingThree << "." << endl << endl;
}

// 8. findLowest and findHighest will return the lowest and highest of the 
// 5, respectively. Not using arrays since it wasn't covered yet; however, 
// if it were used, it would contribute to a much cleaner solution.
double findLowest(double score1, double score2, double score3, double score4, double score5) {
	double lowest = score1;
	// 9. Find the lowest by comparing the current lowest to each value, 
	// and setting it to that value, if the lowest is greater than it. 
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
	// 10. Find the highest by comparing the current highest to each value, 
	// and setting it to that value, if the highest is less than it. 
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
