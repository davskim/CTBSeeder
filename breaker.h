#pragma once
#ifndef BREAKER_H
#define BREAKER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Breaker {
public:
	string name;
	double score;
	int rank;

	// Constructor
	Breaker(string nam, int scor);
	Breaker();

	// Read
	void read(istream& ins);

	// Write
	void write(ostream& outs);
};

void makeranks(vector<Breaker>& bboys, int comps);

void bracketscrapes(vector<Breaker>& bboys, ostream& outs, int comps, int passers);

void tieclear(vector<Breaker>& bboys, int comps);

void matwrite(vector<Breaker>& bboys, int r, ostream& outs, int comps);

void random_pairing(vector<Breaker>& bboys, ostream& outs, int comps);

void output_in_order(vector<Breaker>& bboys, ostream& outs, int comps);

void true_random_twovtwo(vector<Breaker>& bboys, ostream& outs, int comps);

void seed_sixteen(vector<Breaker>& bboys, ostream& outs, int comps);

/*
Modifies the bboys vector to have them all in order
*/
vector<Breaker> organize(vector<Breaker>& bboys, int comps);

vector<vector<Breaker>> tierize(vector<Breaker>& bboys, int comps);

void tierbracket(vector<vector<Breaker>> tiers, ostream& outs, int comps);

istream& operator >> (istream& ins, Breaker& breaker);


#endif 