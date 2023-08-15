# HelicityScalarsProject

Supplimentary code to help test the helicity functionality from the [hcana](https://github.com/mint42/hcana) repository.

## generate_asymmetry_hists.C
This code takes a replay file and generates a pdf full of histograms for all of the *rate variables in the TSHelH tree. These histograms group events by quartet (a group of four electron helicities in the format +--+ or -++-) and fills the histogram with that quartet's asymmetry (SUM(actualHelicity * variable)/SUM(variable)). Asymmetries should be centered near zero if helicity is working correctly.

### Usage: Option 1
Put your desired replay files in the ```replay_root_files``` folder, making sure they have the format ```hms_replay_production_####*``` (where #### is the run number) and run this script to do all files:

```$> ./analyze_asymmetries```

### Usage: Option 2
From the commandline, run either

```$> root generate_asymmetry_hists.C```

```$> root 'generate_asymmetry_hists.C("root_filename.root")'```

```$> root 'generate_asymmetry_hists.C("root_filename.root", "output_pdf_name.pdf")'```

the default root file comes from the THE_FILE macro inside generate_asymmetry_hists.C, and the default output is called c1.pdf


## compare_scalars.C
This code compares data from the TSHelH and TSH scalar trees from a given replay file. The comparison is done by plotting the variables the trees have in common onto the same histogram and saving those histograms as a pdf file.

### Usage: Option 1
Put your desired replay files in the ```replay_root_files``` folder, making sure they have the format ```hms_replay_production_####*``` (where #### is the run number) and run this script to do all files:

```$> ./analyze_asymmetries```

### Usage: Option 2
From the commandline, run either

```$> root compare_scalars.C```

```$> root 'compare_scalars.C("root_filename.root")'```

```$> root 'compare_scalars.C("root_filename.root", "output_pdf_name.pdf")'```

the default root file comes from the THE_FILE macro inside generate_asymmetry_hists.C, and the default output is called c1.pdf

## AUTHOR

[Riley Reedy](https://github.com/mint42)
