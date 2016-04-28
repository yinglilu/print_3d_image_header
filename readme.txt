There are 4 options to see the meta-data: 
	1. use notepad/notepad++ to open a mha file. 
	   drawback: slow and may cause notepad to dead if load large mha file. 
	2. use itk-snap to open it and check the information section. 
	   drawback: slow, many button clicks. 
	3. use c3d(http://www.itksnap.org/pmwiki/pmwiki.php?n=Convert3D.Documentation) 
	   c3d mha_file -info-full 
	   drawback: no.
	4. use this tool: printh.exe 
	   drawback: no. It is super fast, no itk dlls dependency.

Usage: printh filename 
support format: mha,mhd,nrrd,nii,hdr

compile: windows or Linux:
gcc -o printh printh.c nifti1_io.c znzlib.c -lm note: for windows, need MinGW installed.

or use cMakeLists.txt if you know cmake.