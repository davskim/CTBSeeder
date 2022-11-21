#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "breaker.h"

using namespace std;
const int PASSERS = 32;

void CaptureSeed(vector<Breaker>& bboys, ostream& output, int i);
void SixteenSeed(vector<Breaker>& bboys, ostream& output, int i);
void TierCTB(vector<Breaker>& bboys, ostream& output, int i);

int main() {
	vector<Breaker> bboys;
	ifstream input;
	ofstream output;

	input.open("CTBBboys.txt");
	if (input.is_open()) {
		cout << "file is open" << endl;
	}
	else {
		cout << "FILE NOT OPEN JACKASS" << endl << endl;
	}

	Breaker temp;
	for (int i = 0; input >> temp; i++) { // input reading
		bboys.push_back(temp);
	}
	output.open("NECTBBracket.txt");
	if (output.is_open()) { 
		cout << "file is open" << endl; 
	}
	else {
		cout << "FILE IS NOT OPEN" << endl;
	}

	int i = bboys.size();

	cout << "Breaking competition seeder" << endl
		<< "Which seeding would you like to do?" << endl;
	cout << "1: Random 2 v 2" << endl;
	cout << "2: Capture the Breaker (top 32)" << endl;
	cout << "3: Top 16 seeding" << endl;
	cout << "4: Tier style CTB" << endl;

	int choice;
	cin >> choice;

	switch (choice) {
	case 1:
		true_random_twovtwo(bboys, output, i);
		break;
	case 2:
		CaptureSeed(bboys, output, i);
		break;
	case 3:
		SixteenSeed(bboys, output, i);
		break;
	case 4:
		TierCTB(bboys, output, i);
	default:
		break;
	}

	input.close();
	output << flush;
	output.close();
	return 0;
}

void CaptureSeed(vector<Breaker>& bboys, ostream& output, int i) {
	makeranks(bboys, i); //initial rankings with ties
	bracketscrapes(bboys, output, i, PASSERS); //displays the tiebreaker for 32nd place
	tieclear(bboys, i); //tie clearer
	random_pairing(bboys, output, i); //'random' pairing
	if (1) //make this number 1 to make program output the bboys in order, 0 to make it not
		output_in_order(bboys, cout, i);

}

void SixteenSeed(vector<Breaker>& bboys, ostream& output, int i) {
	makeranks(bboys, i); //initial rankings with ties
	bracketscrapes(bboys, output, i, 16); //displays the tiebreaker for 16th place
	tieclear(bboys, i); //tie clearer
	seed_sixteen(bboys, output, i);
	output_in_order(bboys, output, i);
}

void TierCTB(vector<Breaker>& bboys, ostream& output, int i) {
	makeranks(bboys, i); //initial rankings with ties
	bracketscrapes(bboys, output, i, PASSERS); //displays the tiebreakers for 32nd place
	tieclear(bboys, i); //clears the ties, so there are 1-32 seeds

	bboys = organize(bboys, i); //organizes the bboys vector
	vector<vector<Breaker>> tier = tierize(bboys, i);
	tierbracket(tier, output, i);
	if (1) //make this number 1 to make program output the bboys in order, 0 to make it not
		output_in_order(bboys, cout, i);

}