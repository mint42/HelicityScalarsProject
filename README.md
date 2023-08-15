# Helicity Scalers Project

Supplimentary code to help test the helicity functionality from the [hcana](https://github.com/mint42/hcana) repository.

## generate_asymmetry_hists.C
This code takes a replay file and generates a pdf full of histograms for all of the *rate variables in the TSHelH tree. These histograms group events by quartet (a group of four electron helicities in the format +--+ or -++-) and fills the histogram with that quartet's asymmetry (SUM(actualHelicity * variable)/SUM(variable)). Asymmetries should be centered near zero if helicity is working correctly.

### Usage: Option 1
Put your desired replay files in the ```replay_root_files``` folder, making sure they have the format ```hms_replay_production_####*``` (where #### is the run number) and run this script to do all files:

```$> ./analyze_asymmetries.sh```

This will put the files in ./asymmetry_outfiles. If this script hangs on a single file for too long, try ctrl+\ and that should fix it.

### Usage: Option 2

To start, set the FILE_NAME macro in the generate_asymmetries_hist.C file to the full path to your replay file.

```#define "./full_or_relative_path/your_root_file_name.root"```

Then set the PDF_FILE macro in the same way to set the destination file name, and run:

```$> root generate_asymmetry_hists.C```

These variables can also be overwritten from the commandline directly.

```$> root 'generate_asymmetry_hists.C("root_filename.root")'```

```$> root 'generate_asymmetry_hists.C("root_filename.root", "output_pdf_name.pdf")'```

The program may take a minute to run.

## compare_scalers.C
This code compares data from the TSHelH and TSH scalar trees from a given replay file. The comparison is done by plotting the variables the trees have in common onto the same histogram and saving those histograms as a pdf file.

### Usage: Option 1 (Not implemented yet)
Put your desired replay files in the ```replay_root_files``` folder, making sure they have the format ```hms_replay_production_####*``` (where #### is the run number) and run this script to do all files:

```$> ./analyze_scalers```

### Usage: Option 2

Using the same set up from generate_asymmetry_hists.C, from the commandline, run either:

```$> root compare_scalars.C```

```$> root 'compare_scalars.C("root_filename.root")'```

```$> root 'compare_scalars.C("root_filename.root", "output_pdf_name.pdf")'```

## AUTHOR

[Riley Reedy](https://github.com/mint42)
