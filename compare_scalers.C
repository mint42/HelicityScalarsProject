// This program compares a tree of scaler data to the subset tree
// for helicity specific things
// 

#include <string>
#include <cstring>
#include "TFile.h"
#include "TTree.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"
#include "TH1D.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TMath.h"
#include <cstdlib>

#include "tree_variables.h"

using namespace std;

#define PDF_NAME "generage_asymmetry_hists.pdf"
#define FILE_NAME "replay_root_files/hms_replay_production_1038_125000.root"
#define NUM_BINS 500
#define NUM_VARS_PRINT 22
#define HELI_TREE_NAME "TSHelH" // do not change
#define SCAL_TREE_NAME "TSH" // do not change

// hms_replay_production_1035_50000.root
// hms_replay_production_1036_120000.root
// hms_replay_production_1037_1700000.root
// hms_replay_production_1038_125000.root
// hms_replay_production_1039_50000.root

#include <iostream>
#include <fstream>
#include <iomanip>

/*
 *	Funtion:		compare_scalers
 *				controlls program which compares data from two trees in a root file
 *	@param(pdf_name):	string with pdf name. (excluding ".pdf" extension.
 *	@return:		N/A
 *
 */
void 	compare_scalers(string root_file = FILE_NAME, string pdf_name = PDF_NAME)
{
	// loads the root files, and trees
	TFile	*t_file = TFile::Open(root_file.c_str());

	TTree	*scal_tree;
	TTree	*heli_tree;
	t_file->GetObject(SCAL_TREE_NAME, scal_tree);
	t_file->GetObject(HELI_TREE_NAME, heli_tree);

	// canvas management
	TCanvas		*canvases = new TCanvas[NUM_VARS_PRINT/16 + 1];
	size_t		canvas_index = 0;
	size_t		display_index = 0;
	canvases[canvas_index].Divide(4, 4, 0.01, 0.01);

	TH1D		*scal_hist;
	TH1D		*heli_hist;

	// loop over all tree variables to compare
	for (size_t i = 0; i < NUM_VARS_PRINT; ++i)
	{
		if (display_index == 16)
		{
			display_index = 0;
			++canvas_index;
			canvases[canvas_index].Divide(4, 4, 0.01, 0.01);
		}
		++display_index;
		canvases[canvas_index].cd(display_index);

		gPad->SetLogy(1);
		scal_tree->Draw((SCAL_VARS(i) + string(">> scal(500)")).c_str());
		scal_hist = new TH1D(*((TH1D *)gPad->GetPrimitive("scal")));
		scal_hist->SetTitle(SCAL_VARS(i));
		scal_hist->SetLineColor(kRed);

		//gPad->SetLogy(1);
		heli_tree->Draw((HELI_VARS(i) + string(">> heli(500)")).c_str());
		heli_hist = new TH1D(*((TH1D *)gPad->GetPrimitive("heli")));
		heli_hist->SetTitle(HELI_VARS(i));
		heli_hist->SetLineColor(kBlue);

		// add hists to stack, draw, and zoom
		THStack		*comparison_hist = new THStack("hists", SCAL_VARS(i));
		comparison_hist->Add(heli_hist);
		comparison_hist->Add(scal_hist);
		comparison_hist->Draw("NOSTACK");

		double		scal_peak = scal_hist->GetBinCenter(scal_hist->GetMaximumBin());
		double		heli_peak = heli_hist->GetBinCenter(heli_hist->GetMaximumBin());

		// creating and drawing a legend for quick info
		TLegend		*leg = new TLegend();
	//	leg->AddEntry(heli_hist, (string("num_events(heli): ") + to_string(heli_tree->GetEntries())).c_str());
	//	leg->AddEntry(scal_hist, (string("num_events(scal): ") + to_string(scal_tree->GetEntries())).c_str());
		leg->AddEntry(heli_hist, (string("peak(heli): ") + to_string(heli_peak)).c_str());
		leg->AddEntry(scal_hist, (string("peak(scal): ") + to_string(scal_peak)).c_str());
		leg->AddEntry(heli_hist, (string("mean(heli): ") + to_string(heli_hist->GetMean())).c_str());
		leg->AddEntry(scal_hist, (string("mean(scal): ") + to_string(scal_hist->GetMean())).c_str());
		leg->Draw();

	}

	// save canvases to a file
	for (size_t i = 0; i <= canvas_index; ++i)
	{
		if (canvas_index == 0) // edge case
			canvases[i].Print(pdf_name.c_str());
		else if (i == 0)
			canvases[i].Print((pdf_name + "(").c_str()); // keep pdf open
		else if (i == canvas_index)
			canvases[i].Print((pdf_name + ")").c_str()); // close pdf
		else
			canvases[i].Print(pdf_name.c_str());
	}
	delete [] canvases;
}

//		cout << SCAL_VARS(i) << endl;
//		cout << "num_events(heli): " << heli_tree->GetEntries() << endl;
//		cout << "num_events(scal): " << scal_tree->GetEntries() << endl;
//		cout << "peak(heli): " << heli_peak << endl;
//		cout << "peak(scal): " << scal_peak << endl;
//		cout << "heli/scal: " << heli_peak/scal_peak << endl;
//		cout << "mean(heli): " << heli_hist->GetMean() << endl;
//		cout << "mean(scal): " << scal_hist->GetMean() << endl;
//		cout << "heli/scal: " << heli_hist->GetMean()/scal_hist->GetMean() << endl;
//		cout << endl << endl;
