#include <stdio.h>
#include <string.h>
#include "nifti1_io.h"

#define MAX_CHAR_EACH_LINE 1024

int main(int argc, char*argv[])
{
	char filename[1024]={0};
	char ext[5]={0};
	char line[MAX_CHAR_EACH_LINE];
	FILE *fp = NULL;
	int num_of_lines_to_read = 0;
	int n = 0;
	nifti_1_header *nh = NULL;		

	/*print usage*/
	if (argc < 2)
	{
		printf("Usage: printheader filename\n");
		printf("       support format: mha,mhd,nii,nrrd,and hdr.\n");
		return 0;
	}

	/*open file*/
	strcpy(filename,argv[1]);
	fp=fopen(filename,"r");
	if(!fp)
	{
		printf("Open file error!");
		return -1;
	}

	/*get extension name*/
	strncpy(ext,&filename[strlen(filename)-4],4);

	/*number of lines to read
		mha:11
		mhd:10
		nrrd:13
	*/
	if (strcmp(ext,".mha") == 0)
	{
		num_of_lines_to_read = 14;
	}
	else if (strcmp(ext,".mhd") == 0)
	{
		num_of_lines_to_read = 20;
	}
	else if (strcmp(ext,"nrrd") == 0)
	{
		num_of_lines_to_read = 20;
	}
	else if (strcmp(ext,".nii") == 0 || strcmp(ext,".hdr") == 0)
	{
		nh = nifti_read_header(filename, NULL, 1);
		disp_nifti_1_header( "", nh );
		return 0;
	}
	else
	{
		printf("unknown format! Support mha,mhd,nii,nrrd,and hdr only! \n");
		return -1;
	}

	//read first n lines and print it
	while( fgets(line, MAX_CHAR_EACH_LINE, fp) != NULL && n < num_of_lines_to_read) 
	{
		printf(line);
		n++;
	}

	fclose(fp);

	return 0;
}



