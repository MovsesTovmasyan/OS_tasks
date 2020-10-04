#include<iostream>
#include<fstream>
#include<stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout<<"wrong argument count, please check and run again\n";
        return 1;
    }

    char ch;
	std::ifstream source_file;
	std::ofstream dest_file;
    
	source_file.open(argv[1]);
	if(!source_file)
	{
		std::cout<<"Error in opening source file..!!";
		return 1;
	}

	dest_file.open(argv[2]);
	if(!dest_file)
	{
		std::cout<<"Error in opening target file..!!";
		source_file.close();
		return 1;
	}

	while(source_file.eof()==0)
	{
		source_file>>ch;
		dest_file<<ch;
	}

	std::cout<<"File copied successfully..!!";
	source_file.close();
	dest_file.close();
    return 0;
}