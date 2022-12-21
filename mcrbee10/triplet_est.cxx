// This code uses ROOT 5
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "wep.h"
#include "processor_code.h"
#include "TH1F.h"
#include "TH1.h"
#include "TF1.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TMath.h"

// using namespace std;
int main(int argc, char** argv) 
{
	// TFile* in_file = TFile::Open("/home/sarthak/Documents/Out-R6_Module_0_3.root");
	TFile* in_file = TFile::Open(argv[1]);

	TH1D* in_hist = (TH1D*)in_file->Get("Stackwaveform_CH1"); // Histogram name needs to change

	// TF1* fit_function = new TF1("fit_function", "[0]*exp([1]*(x+[2]))", atof(argv[2]), atof(argv[3]));
	TF1* fit_function = new TF1("fit_function", "([0]/[1])*exp(-(x-[2])/[1])", atof(argv[2]), atof(argv[3]));
	fit_function->SetParameters(1000, 1.0, 0.5);
	TFitResultPtr fit_result = in_hist->Fit("fit_function", "SR");
	// Double_t fit_function->GetChisquare();
	cout <<  "Chi2: " << '\n' << fit_function->GetChisquare() << endl;
	return 0;
}
