#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    string text, line;
    vector<string> words; 
    ifstream file;
    //Opening user's input and subtly changing it
    file.open("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\input.txt");
    if (!file) 
    {
       cerr << "No file." << endl;
       exit(1);
    }
    if (file.is_open()) 
    {
       while (file.good()) 
       {
             getline(file, line);
             istringstream iss(line);
             do
             {
               string sub;
               iss >> sub;
               words.push_back(sub); 
             } 
             while (iss);
             replace(line.begin(), line.end(), ' ', '&');
       }
    }
    file.close();

    line = "debug exec ("+line+")[1]";
    
    //Copying Millstream.grs to copy.grs
    vector<string> v; 
    string sentence, l; 
    ifstream fin; 
    int cnt = 0, num = 0; 
    ifstream myfile("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\Millstream.grs");
    while (getline(myfile, l))
	{
        ++num;
	}
	myfile.close(); 
    fin.open("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\Millstream.grs");
    if (!fin) 
    {
       cerr << "No file." << endl;
       exit(1);
    }

    if (fin.is_open()) 
    {
       while (fin.good() && cnt < (num-1)) {
             getline(fin, sentence);
             v.push_back(sentence);
             cnt++;  
             }
    }
    fin.close(); 
    //Copying vector into copy.grs with modified line submitted by user
    ofstream fout; 
    fout.open("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\copy.grs");
    ostream_iterator<string> output_iterator(fout, "\n");
    copy(v.begin(), v.end(), output_iterator);
    fout << line; 
    fout.close(); 
    //Deletion and renaming
    int a = remove("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\Millstream.grs");
    char oldname[] ="C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\copy.grs";
    char newname[] ="C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\Millstream.grs";
    int result = rename(oldname, newname);
    if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );
  return 0;
    //Running the batch
    system("C:\\Users\\hp\\Desktop\\GrGenNet\\examples\\Mill\\GrGen.bat");
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
