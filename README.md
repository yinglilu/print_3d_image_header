
## Purpose

print meta-data of medical image file(support:mha/mhd/nrrd/nii/hdr)

## Usage 

```bash
printh filename 
```

## Compile

```bash
#note: for windows, need MinGW installed.
gcc -o printh printh.c nifti1_io.c znzlib.c -lm 
```

or use cMakeLists.txt if you prefer cMake.
