#include "stdafx.h"
#include "Forest.h"
#include <iostream>

void ForestT::SetPopulation(std::string season) {
	float fedPercentage;
	int neededFood;
	int reproduction;

	if (season == "Winter")
		neededFood = population * WINTER_CONSUMPTION;
	else if (season == "Fall")
		neededFood = population * FALL_CONSUMPTION;
	else
		neededFood = population * CONSUMPTION;

	if (neededFood  > food) {
		fedPercentage = float(food) / neededFood;
		population = population * fedPercentage;
	}
	food = food - neededFood;
	if (food < 0)
		food = 0;
	if (season == "Winter") {
		reproduction = population * REPRODUCTION_RATE - .5;
		population = population + reproduction;
	}
	if (population > POPULATION_LIMIT)
		population = POPULATION_LIMIT;

}

void ForestT::SetResources(std::string season) {

}

void ForestT::SetCharacter() {
	character = 'F';
}
