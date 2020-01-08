#include <bits/stdc++.h> 
#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h> 

using namespace std; 

int createfolder(const char* fpath) {
	if (mkdir(fpath, 0777) == -1) {
		cerr << "Error : " << strerror(errno) << endl;
		cout << "But it's ok.." << "\n";
	}
	else
		cout  << "Working..." << "\n";
}

  
int main() {
    /* Creates necessary folders*/
    const char *folder = "/home/pi/teknostart_ctf/hidden";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/openme";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/deleteme";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/check_here";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/check_here/open_me";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/here";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/here/not_here";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/here/this_way";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/here/this_way/in_here";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/not_here";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/not_here/found_me";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/hidden/findme/not_here/stay_away";
	createfolder(folder);
    folder = "/home/pi/teknostart_ctf/komtek/";
	createfolder(folder);


	/* Create necessary file */
	fstream file;
	file.open("/home/pi/teknostart_ctf/hidden/findme/here/this_way/in_here/youfoundme.txt",ios::out);
	if(!file)
	{
		cout << "Error creating file!";
	}
	file.close();

	file.open("/home/pi/teknostart_ctf/komtek/first_flag.txt",ios::out);
	if(!file)
	{
		cout << "Error creating file!";
	}
	file.close();

	file.open("/home/pi/teknostart_ctf/openme/flag.txt",ios::out);
	if(!file)
	{
		cout << "Error creating file!";
	}
	file << "you_did_it!" << endl;
	file.close();


	cout << "Install complete";
	return 0;
} 
