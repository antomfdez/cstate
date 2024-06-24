#include <iostream>
#include <cstdlib>
#include "../include/argparse.h"

using namespace std;
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char *argv[]) {
	argparse::ArgumentParser program("cstate");
	program.add_argument("-hi", "--hibernate")
		.help("Save the state of the system in swap and shutdown.")
		.flag();
	program.add_argument("-sl", "--sleep")
		.help("Save the state of the system in ram and put the system in sleep mode.")
		.flag();
	program.add_argument("-fr", "--freeze")
		.help("The freeze option, when set, will initiate a lightweight \
software-based-only sleep state.")
		.flag();

	try {
  	program.parse_args(argc, argv);
	}
	catch (const exception& err) {
  	cerr << err.what() << endl;
  	cerr << program;
  	exit(1);
	}
	
	if (argc > 2 | argc == 1) {
		cerr << ANSI_COLOR_RED << "Invalid: " << ANSI_COLOR_RESET << argv[0] << " -<arg>" << endl;
		cerr << program;
		exit(1);
	} else {
		if (program["--hibernate"] == true) {
			cout<<ANSI_COLOR_GREEN<<"\nHibernating...\n"<<ANSI_COLOR_RESET<<endl;
			system("/bin/sh -c \"echo disk | sudo tee /sys/power/state\"");
		} if (program["--sleep"] == true) {
			cout<<ANSI_COLOR_GREEN<<"\nSleeping...\n"<<ANSI_COLOR_RESET<<endl;
			system("/bin/sh -c \"echo deep | sudo tee /sys/power/mem_sleep && echo mem | sudo tee /sys/power/state\"");
		} if (program["--freeze"] == true) {
			cout<<ANSI_COLOR_GREEN<<"\nFreezing...\n"<<ANSI_COLOR_RESET<<endl;
			system("/bin/sh -c \"echo freeze | sudo tee /sys/power/state\"");
		}
	}
}
