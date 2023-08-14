
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
#include <iostream>
#include <fstream>
#include <iomanip>

#include "tree_variables.h"

using namespace std;

#define NUM_BINS 500
#define NUM_VARS_PRINT 22

#define HELI_TREE_NAME "TSHelH"
#define THE_FILE "replay_root_files/hms_replay_production_1035_50000.root"

// hms_replay_production_1035_50000.root
// hms_replay_production_1036_120000.root
// hms_replay_production_1037_1700000.root
// hms_replay_production_1038_125000.root
// hms_replay_production_1039_50000.root

void 	generate_asymmetry_hists(string root_file = THE_FILE, string pdf_name = "hists2")
{
	// loads the root files, trees, and set up tree readers
	TFile		*t_file = TFile::Open(root_file.c_str());
	TTreeReader	*tree_reader = new TTreeReader(HELI_TREE_NAME, t_file);

	TCanvas		*canvases = new TCanvas[NUM_VARS_PRINT/16 + 1];
	size_t		canvas_index = 0;
	size_t		display_index = 0;
	canvases[canvas_index].Divide(4, 4, 0.01, 0.01);

	double	*asym = new double [tree_reader->GetEntries() / 4];
	int	proper_quartet[4] = {1, -1, -1, 1};
	size_t	size;
	double	min;
	double	max;
	int	polarity;
	double	sum_top;
	double	sum_btm;
	int	j;


	TTreeReaderValue<Double_t> actual_helicity = {*tree_reader, "actualHelicity"};
	TTreeReaderValue<Double_t> quartet_phase = {*tree_reader, "quartetPhase"};
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

		// create pointers to the tree variables
		TTreeReaderValue<Double_t> var = {*tree_reader, HELI_VARS(i)};

		size = 0;
		min = 0;
		max = 0;
		sum_top = 0;
		sum_btm = 0;
		polarity = 1;
		j = -1;

		// loading in helicity histogram
		while (tree_reader->Next())
		{
			if (*actual_helicity == 0)
				continue ;

			if (*quartet_phase == 0)
			{
				polarity = *actual_helicity;
				sum_top = *actual_helicity * *var;
				sum_btm = *var;
				j = 1;
			}
			else if (*quartet_phase == j && *actual_helicity == polarity*proper_quartet[j])
			{	
				sum_top += *actual_helicity * *var;
				sum_btm += *var;
				++j;
				if (*quartet_phase == 3 && sum_btm != 0)
				{
					asym[size] = sum_top/sum_btm;
					if (asym[size] > max)
						max = asym[size];
					if (asym[size] < min)
						min = asym[size];
					++size;
				}
			}
			else
				j = -1;
		}

		TH1D		*asym_hist = new TH1D(HELI_VARS(i), HELI_VARS(i), NUM_BINS, min - .05, max + .05);
		for (size_t i = 0; i < size; ++i)
			asym_hist->Fill(asym[i]);
		asym_hist->SetLineColor(kGreen);
		asym_hist->Draw();

      		// resets reader to the beginning
		tree_reader->Restart();
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
	delete [] asym;
	delete [] canvases;
	delete tree_reader;
}
