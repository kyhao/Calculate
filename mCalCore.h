// mCalCore.h: interface for the mCalCore class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCALCORE_H__7B00C42C_FF57_431C_8F7D_544A916FF4C4__INCLUDED_)
#define AFX_MCALCORE_H__7B00C42C_FF57_431C_8F7D_544A916FF4C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <stack>
using namespace std;
#include <cstdlib>
#include <cmath>
#define _IN_
#define _OUT_

class mCalCore  
{
public:
	mCalCore();
	virtual ~mCalCore();

public:
	int calculate(_IN_ const char *buf, _OUT_ double &r);
	int niToPost(_IN_ const char *buf);
	int getAnswer();
	void init();

private:
	stack<string> postfix;
	stack<string> tmp; 
	bool flag;
	int l_bracket;
	int err;
	double res;
	//err:1 lose brackets
	//err:2 illegel symbol
	//err:3 too more symbol
};

#endif // !defined(AFX_MCALCORE_H__7B00C42C_FF57_431C_8F7D_544A916FF4C4__INCLUDED_)
