#include "mCalCorev2.h"
#include <iostream>
using namespace std;
#include <fstream>

#define PATH "F:\\me.txt"

int main()
{
	mCalCorev2 cal;
	double r = 0;
	ifstream fi(PATH);

	char buf[300];
	fi >> buf;
	cal.cal(buf,r);
	ofstream fo(PATH);
	if(cal.errInfo() != "")
	{
		fo << cal.errInfo() << endl;
		return 1;
	}
	else
	{
		fo << r << endl;
	}
	return 0;
}