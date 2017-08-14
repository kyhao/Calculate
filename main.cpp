/**This is a Demo**/
#include "mCalCorev2.h"
#include <iostream>

int main()
{
	//Creat Object
	mCalCorev2 cal;
	double ans = 0;
	
	//use cal Method
	cal.cal("1+2*(3+4)",ans);
	
	//print answer
	std::cout << ans;
	
	return 0;
}
