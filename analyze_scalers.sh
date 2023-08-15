
#!/bin/sh

# Folder with the root files
root_files="./replay_root_files"

# Folder where the output PDFs will go
output_folder="./scaler_outfiles"
# Create it if it doesn't exist
[ ! -d "$output_folder" ] && mkdir -p -- "$output_folder"

for file in "$root_files"/*; do
	# Start subshell, because I'm new to changing IFS so I don't know all the
	# side effects. This avoids them entirely, by only changing IFS for the
	# part I need.
	run_number=$(
	# Set the In Field Separator to underscore, so the filename can be
	# easily split into pieces
	IFS=_
	
	# Converts the variable into positional parameters, so we can
	# slice out the desired value. Trim the leading path as well, so we
	# only get the filename.
	set ${file##*/}
	
	# Echo only the run number, captured by the command substitutuon
	echo "$4"
	)

	# Construct the output PDF name
	output_pdf="$output_folder/run_${run_number}_scaler.pdf"

	# Run root on the original filename, and pass the output PDF
	root -q "compare_scalers.C(\"$file\", \"$output_pdf\")"
done
