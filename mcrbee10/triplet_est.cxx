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

int main(int argc, char **argv) 
{
	TFile* in_file = TFile::Open("/home/sarthak/Documents/Out-R6_Module_0_3.root");
	TH1D* in_hist = (TH1D*)in_file->Get("Stackwaveform_CH1");
	TF1* fit_function = new TF1("fit_function", "[0]*exp([1]*(x+[2]))", 0.45+0.81, 2.0+0.81);
	TFitResultPtr fit_result = in_hist->Fit("fit_function", "SR");
	// Double_t fit_function->GetChi2();
	Double_t tau3 = -fit_function->GetParameter(1);
	cout <<  "Triplet lifetime in us: " << '\n' <<
	1/tau3 << endl;
	return 0;
}
