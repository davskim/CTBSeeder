#include "breaker.h"
#include <time.h>  
#include <algorithm>

Breaker::Breaker(string nam, int scor) {
	name = nam;
	score = scor;
	rank = 1;
}
Breaker::Breaker() {
	name = "";
	score = 0;
	rank = 1;
}

// Read
void Breaker::read(istream& ins) {
	double score1;
	double score2;
	double score3;

	ins >> name;
	ins >> score1;
	ins >> score2;
	ins >> score3;
	score = (score1 + score2 + score3) / 3;
}

// Write
void Breaker::write(ostream& outs) {
	outs << rank;
	outs << " ";
	outs << name;
	outs << " ";
	outs << score;
}



void makeranks(vector<Breaker>& bboys, int comps) {
	for (int i = 0; i < comps; i++) {
		for (int j = 0; j < comps; j++) {
			if (bboys[i].score < bboys[j].score && i != j) {
				bboys[i].rank++;
			}
		}
	}
}

void bracketscrapes(vector<Breaker>& bboys, ostream& outs, int comps, int passers) {
	outs << "prelim tiebreakers:" << endl;
	for (int i = 0; i < comps; i++) {
		if (bboys[i].rank == passers) {
			outs << bboys[i].name << endl;
		}
	}
	outs << endl;
}

void tieclear(vector<Breaker>& bboys, int comps) {
	int temp = 0;
	for (int i = 0; i < comps; i++) {
		temp = bboys[i].rank;
		for (int j = 0; j < comps; j++) {
			if (temp == bboys[j].rank && j != i) {
				bboys[j].rank++;
			}
		}
	}
}

void matwrite(vector<Breaker>& bboys, int r, ostream& outs, int comps) {
	for (int i = 0; i < comps; i++) {
		if (bboys[i].rank == r) {
			outs << bboys[i].name;
		}
	}
}

void random_pairing(vector<Breaker>& bboys, ostream& outs, int comps) {
	matwrite(bboys, 23, outs, comps);
	outs << " and ";
	matwrite(bboys, 19, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 2, outs, comps);
	outs << " and ";
	matwrite(bboys, 31, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 26, outs, comps);
	outs << " and ";
	matwrite(bboys, 11, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 15, outs, comps);
	outs << " and ";
	matwrite(bboys, 12, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 22, outs, comps);
	outs << " and ";
	matwrite(bboys, 18, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 30, outs, comps);
	outs << " and ";
	matwrite(bboys, 3, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 28, outs, comps);
	outs << " and ";
	matwrite(bboys, 5, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 10, outs, comps);
	outs << " and ";
	matwrite(bboys, 7, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 16, outs, comps);
	outs << " and ";
	matwrite(bboys, 14, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 13, outs, comps);
	outs << " and ";
	matwrite(bboys, 25, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 1, outs, comps);
	outs << " and ";
	matwrite(bboys, 32, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 20, outs, comps);
	outs << " and ";
	matwrite(bboys, 24, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 21, outs, comps);
	outs << " and ";
	matwrite(bboys, 17, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 4, outs, comps);
	outs << " and ";
	matwrite(bboys, 29, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 9, outs, comps);
	outs << " and ";
	matwrite(bboys, 8, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 6, outs, comps);
	outs << " and ";
	matwrite(bboys, 27, outs, comps);
	outs << '\n' << '\n';
}

void output_in_order(vector<Breaker>& bboys, ostream& outs, int comps) {
	for (int i = 0; i <= comps; i++) {
		for (int j = 0; j < comps; j++) {
			if (i == bboys[j].rank) {
				bboys[j].write(outs);
				outs << endl;
			}
		}
	}
}

void true_random_twovtwo(vector<Breaker>& bboys, ostream& outs, int comps) {
	vector<int> ordering;
	for (int i = 0; i < comps; i++) {
		ordering.push_back(i);
	}

	for (int i = 0; i < comps; i += 2) {
		cout << bboys[ordering[i]].name;
		cout << " and ";
		cout << bboys[ordering[i + 1]].name;
		cout << endl;
	}
}

void seed_sixteen(vector<Breaker>& bboys, ostream& outs, int comps) {
	matwrite(bboys, 4, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 13, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 12, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 5, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 8, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 9, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 16, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 1, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 2, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 15, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 10, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 7, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 6, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 11, outs, comps);
	outs << '\n' << '\n';

	matwrite(bboys, 14, outs, comps);
	outs << '\n' << "vs" << '\n';
	matwrite(bboys, 3, outs, comps);
	outs << '\n' << '\n';
}

vector<Breaker> organize(vector<Breaker>& bboys, int comps) {
	vector<Breaker> organized;

	for (int i = 0; i <= comps; i++) {
		for (int j = 0; j < comps; j++) {
			if (bboys[j].rank == i) {
				organized.push_back(bboys[j]);
			}
		}
	}

	return organized;
}

/* Mike Wang's idea. We will assume that every 4 bboy increments have identical skill.
S tier = 1-4
A tier = 5-8
B tier = 9-12
C tier = 13-16
D tier = 17-20
E tier = 21-24
F tier = 25-28
F- tier = 29-32

The format will be to have all the S tier and half of the B tier in the final battle.
Same convention of each team picking up someone who would become their second best bboy.
*/
vector<vector<Breaker>> tierize(vector<Breaker>& bboys, int comps) {
	vector<vector<Breaker>> tier; // 2D array of all tiers. Holds multiple vectors of S,A,B, etc described as subtiers.
	vector<Breaker> subtier; //creates an empty subtier of S,A,etc. Used for pushing back initial tier vector

	for (int i = 0; i < 8; i++) {
		tier.push_back(subtier);
		for (int j = 0; j < 4; j++) {
			tier[i].push_back(bboys[j + (4 * i)]);
		}
	}

	return tier;
}

void tierbracket(vector<vector<Breaker>> tiers, ostream& outs, int comps) {
	int S = 0;
	int A = 1;
	int B = 2;
	int C = 3;
	int D = 4;
	int E = 5;
	int F = 6;
	int Fm = 7;

	int timee = 0;

	//randomize the tiers within themselves
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 101; j++) { // 100 times shuffle
			timee = time(NULL);
			srand(timee);
			random_shuffle(tiers[i].begin(), tiers[i].end());
		}
	}

	tiers;

	outs << tiers[E][0].name << " and " << tiers[B][0].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[D][0].name << " and " << tiers[F][0].name;

	outs << '\n' << '\n';

	outs << tiers[Fm][0].name << " and " << tiers[C][0].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[S][0].name << " and " << tiers[C][1].name;

	outs << '\n' << '\n';

	outs << tiers[F][1].name << " and " << tiers[D][1].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[E][3].name << " and " << tiers[A][1].name;

	outs << '\n' << '\n';

	outs << tiers[Fm][1].name << " and " << tiers[A][0].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[S][1].name << " and " << tiers[B][1].name;

	outs << '\n' << '\n';

	outs << tiers[E][2].name << " and " << tiers[B][3].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[D][3].name << " and " << tiers[F][2].name;

	outs << '\n' << '\n';

	outs << tiers[S][3].name << " and " << tiers[C][2].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[C][3].name << " and " << tiers[F][3].name;

	outs << '\n' << '\n';

	outs << tiers[E][1].name << " and " << tiers[D][2].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[A][2].name << " and " << tiers[Fm][2].name;

	outs << '\n' << '\n';

	outs << tiers[S][2].name << " and " << tiers[B][2].name;
	outs << '\n' << "vs" << '\n';
	outs << tiers[A][3].name << " and " << tiers[Fm][3].name;

	return;
}


istream& operator >> (istream& ins, Breaker& breaker) {
	breaker.read(ins);
	return ins;
}