#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List.h"

using namespace std;

/*bool file_exists(const string& s) {
	ifstream iff(s.c_str());
	return iff.is_open();
}
*/
int main() {
	List ListOfNumbers;
	
	while (!ListOfNumbers.MenuList()) {}
	
	system("pause");
}
