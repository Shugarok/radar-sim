#include "data.h"
#include <iomanip>



//RRE - Radar Range Equation
double RRE() {
	return (rTest.Pt * (rTest.G*rTest.G) * (rTest.lambda*rTest.lambda) * bTest.RCS) /
		(std::pow(4*PI,3) * std::pow(R, 4) * rTest.L);
}

double Rmax() {
	return pow((rTest.Pt * pow(rTest.G, 2) * pow(rTest.lambda, 2) * bTest.RCS) /
		(pow(4 * PI, 3) * rTest.L * kB * Tsys * B), 0.25);
}

double noise() {
	return  kB * Tsys * B;
}



int main() {


	rTest.initialize();

	double Pr = RRE();
	std::cout << std::fixed << std::setprecision(10) << Pr << " W\n";


	double Pn = noise();
	std::cout << "Noise power: " << Pn << " W\n";


	std::cout << "Max detection range: " << Rmax() << " m\n";

	

	double SNR = Pr / Pn; //Signal-to-Noise Ratio
	std::cout << "SNR = " << 10 * log10(SNR) << " dB\n";
	if (SNR > rTest.SNRmax)
		std::cout << "Detected\n";
	else
		std::cout << "Not detected\n";
}
