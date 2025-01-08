#pragma once
#include<iostream>
using namespace std;
class Player {
	string name;
	int label;
	float temps;
	public: Player(string name, int label) {
		this->name = name;
		this->label = label;
		this->temps = 0;
	}
	public: void ajout_temps(float temps) {
		this->temps += temps;
	}
	public: float getTime() {
		return this->temps;
	}
	public: Player() {}
	public:void setName(string name) {
		this->name = name;
	}
	public: string getName() { return name; }
	public: int getLabel() { return label; }
};