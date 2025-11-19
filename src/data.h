#include <iostream>
# define PI           3.14159265358979323846



const int lightSpeed = 2.99792458e8;


double R = 1000; //distance m

//Noise
const double kB = 1.38e-23; //Boltzmann's constant
double Tsys = 290;    //System temperature (Kelvin)     
double B = 1e6; //Receiver Bandwidth


struct bogey{
    double RCS; // RCS


};

struct radar {
    double freq;    //Frequency
    double Pt;      // W
    double G;       // strengthening
    double lambda;  // λ
    double L;       // linear losses


    int SNRmax; 


    int D;
    double eta;

    void initialize() {
        lambda = lightSpeed / freq;
        double A = eta * (PI * D * D / 4);
        G = 4 * PI * A / (lambda * lambda);
    }
};




bogey bTest = {1};
radar rTest = { 5e9, 1000, 0, 0, 0.79, 13, 1, 0.6 };