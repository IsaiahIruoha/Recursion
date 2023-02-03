//I attest to the originality of my work
#include <stdio.h> //input & output functions
#include <math.h> //math function library
#define k ((9.65)*(pow(10, -2))) //rate constant for given reaction

float reaction(float concentrationAmmonia, float concentrationOxygen, float concentrationNitrogen, float concentrationWater, float time); //function is declared

int main () { //prompts user for reactant concentrations and calls function which displays final concentrations and time elapsed upon reaching a rate of 0.001 M/s for the oxidation of ammonia
    float concentrationAmmonia, concentrationOxygen; //concentration of reactants to be input through by user
    float concentrationNitrogen = 0; //concentration of products, initially zero
    float concentrationWater = 0;
    float time = 0; //time variable which is initially zero
    printf("Enter initial ammonia and oxygen concentrations: "); //prompt for reactants concentration
    scanf("%f %f", &concentrationAmmonia, &concentrationOxygen); //scans for concentration
    time = reaction(concentrationAmmonia, concentrationOxygen, concentrationNitrogen, concentrationWater, time); //calls the reaction function
    printf("The reaction will take %.2f seconds to reach a rate 0.001 M/s\n", time);
}
float reaction(float concentrationAmmonia, float concentrationOxygen, float concentrationNitrogen, float concentrationWater, float time) { //reaction function defined
    float rate = k*concentrationAmmonia*(pow(concentrationOxygen, 2)); //rate is declared so that it changes depending on varying concentrations input
    concentrationAmmonia += (float)(-1*rate*4*0.01); //Uses provided equation #2 to determine the concentration based on the rate and time interval of 0.01s
    concentrationOxygen += (float)(-1*rate*3*0.01);
    concentrationNitrogen += (float)(rate*2*0.01);
    concentrationWater += (float)(rate*6*0.01);
    if(rate < 0.001) { //if the rate is below 0.001 M/s exit function and the print concentrations & time elapsed
        printf("Final Reaction Molarities: \n");
        printf("NH3: %.2f M\n", concentrationAmmonia);
        printf("O2:  %.2f M\n", concentrationOxygen);
        printf("N2:  %.2f M\n", concentrationNitrogen);
        printf("H2O: %.2f M\n", concentrationWater);
        return time;
    }
   return reaction(concentrationAmmonia, concentrationOxygen, concentrationNitrogen, concentrationWater, time += (float)(0.01)); //recursion to recalculate values with increase in time
}