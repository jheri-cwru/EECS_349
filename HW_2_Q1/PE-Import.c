#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*------------------ Windows specific libraries and methods. ------------------*/
#ifdef _WIN32

	#include <windows.h>
	#include <shlwapi.h>
	#define MAX_PATH_LEN 260
	
	char *getAppPath()
	{
		static char rootPath[MAX_PATH_LEN];
		GetModuleFileName(NULL, rootPath, MAX_PATH_LEN);
		PathRemoveFileSpecA(rootPath);
		return rootPath;
	}
		
#endif
/*-----------------------------------------------------------------------------*/

/*------------------- Linux specific libraries and methods. -------------------*/
#ifdef linux

	#define MAX_PATH_LEN 4096
	
	char *getAppPath()
	{
		// Not yet implemented.
		// static char exePath[MAX_PATH_LEN];
		// readlink("/proc/self/exe", exePath, MAX_PATH_LEN);
	}
	
#endif
/*-----------------------------------------------------------------------------*/

#define STRING "I want to learn PE file format!"

int main(int argc, char *argv[]) 
{
	char txtPath[MAX_PATH_LEN];
	strcpy(txtPath, getAppPath());
	strcat(txtPath, "\\PE-1.txt");
	
	FILE *txtFile = NULL;
	
	// Check if accompanying text file exists. If it does open the file and begin analysis.
	if((access(txtPath, F_OK)) == 0)
	{
		txtFile = fopen(txtPath, "r+");

	    if(txtFile != NULL)
	    {
		    // Go to the end of the file.
		    if (fseek(txtFile, 0L, SEEK_END) == 0) 
			{
		        // Calculate its size.
		        long bufsize = ftell(txtFile);
		
		        // Allocate memory of proportinal size to store file.
				char *buffer = malloc(sizeof(char) * (bufsize + 1));
		
		        // Head back to the begining of the file to prepare to read it.
		        fseek(txtFile, 0L, SEEK_SET);
		
		        // Read the file to memory.
		        size_t inputSize = fread(buffer, sizeof(char), bufsize, txtFile);
		        
		        // Clean up buffer garbage.
				buffer[inputSize++] = '\0';
		        
		        // Check if compiler defined string is present.
				if(strstr(buffer, STRING) != NULL)
				{
					// Print file if it is.
					printf("%s", buffer);
				}
				// If it is not, re-open the file in append mode and write the compiler defined string.
				else
				{
					fprintf(txtFile, "%s", STRING);  
				}
		    }
		}
	}
	// If not create one using the comp[iler-defined string.
	else
	{
		txtFile = fopen(txtPath, "a");
		fprintf(txtFile, STRING);
	}
	
	fclose(txtFile);
	return(0);	
}
