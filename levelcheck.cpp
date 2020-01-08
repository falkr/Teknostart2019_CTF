#include <iostream>
#include <fstream>
#include <dirent.h>
#include <errno.h>
#include<stdio.h> 
#include<bits/stdc++.h> 
#include <string>
#include <iostream>
#include <stddef.h>

using namespace std;

int checkFolderExists(const char *folder) {
  DIR* dir = opendir(folder);
  if (dir) {
      /* Directory exists. */
      closedir(dir);
      return 1;
  } else if (ENOENT == errno) {
      return 0;
  } else {
      /* opendir() failed for some other reason. */
      cout << "failed.";
      return 0;
  }
}

int checkFileExists(string filename) {
  ifstream File;
  File.open(filename);
  if(!File.is_open()){
    return 0;
  } else {
	return 1;
  }

}

//Trivial mitigation for preventing answer strings in the binary
void  hextostring(string &hex){
  int len = hex.length();
  string newString;
  for(int i=0; i< len; i+=2)
  {
      string byte = hex.substr(i,2);
      char chr = (char) (int)strtol(byte.c_str(), nullptr, 16);
      newString.push_back(chr);
  }
  	hex = newString;
}

int main (int argc, char *argv[]) {

  string* ans;
  string ans1= "6d616b696e675f666f6c646572735f69735f66756e";
  string ans2= "77656c6c5f646f6e655f6b6565705f676f696e67";
  string ans3= "62655f676f6e655f74686f75676874";
  string ans4= "636c65616e696e675f75705f69735f696d706f7274616e74";

  hextostring(ans1);
  hextostring(ans2);
  hextostring(ans3);
  hextostring(ans4);
  string fileToCheck;


  //Store level in local variable
  ifstream infile(".level");
  int a;
  infile >> a;


  //One case for each level that requires it
  switch (a)
  {
   case 7: 
	 {
  		const char* folder= "/home/pi/teknostart_ctf/komtek/myfolder/inception";
	    if (checkFolderExists(folder)) {
		  
		  cout << "\n" << "Well done!" << "\n" << "Your flag is: " << ans1 << "\n";
		} else {
		  cout << "The folder does not exists, make sure you created it in the right location." << "\n";
		}
	 }
        break;
   case 8:  
     {
		string filename = "/home/pi/teknostart_ctf/komtek/myfolder/flag/helloworld.txt";
		if (checkFileExists(filename)) {
		  cout << "\n" << "Well done!" << "\n" << "Your flag is: " << ans2 << "\n";
		} else {
 		  cout << "The file does not exist, make sure you put it in the right location." << "\n";
		}
    }

        break;
   case 9: 
	 {
  		const char* folder= "/home/pi/teknostart_ctf/deleteme";
	    if (!checkFolderExists(folder)) {
		  
		  cout << "\n" << "Well done!" << "\n" << "Your flag is: " << ans3<< "\n";
		} else {
		  cout << "The folder still exists, make sure it is actually deleted." << "\n";
		}
	 }
        break;
   case 10: // code to be executed if n = 2;
     {
		string filename = "/home/pi/teknostart_ctf/komtek/myfolder/flag/helloworld.txt";
		if (!checkFileExists(filename)) {
		  cout << "\n" << "Well done!" << "\n" << "Your flag is: " << ans4 << "\n";
		} else {
 		  cout << "The file still exists, make sure you have deleted it." << "\n";
		}
    }

        break;
   default:
		cout << "This level does not need to be checked." << "\n";
  }

  return 0;
}

