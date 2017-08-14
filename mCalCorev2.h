// mCalCorev2.h: interface for the mCalCorev2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCALCOREV2_H__1F4210D7_8FBD_4DA9_BA96_9857E3A4BA3D__INCLUDED_)
#define AFX_MCALCOREV2_H__1F4210D7_8FBD_4DA9_BA96_9857E3A4BA3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "mCalCore.h"
#include <cmath>

#define SIN "sin("
#define COS "cos("
#define	TAN "tan("
#define SQRT "sqrt("
#define FAC "!("
#define LOG "log("
#define LN "ln("

//USE to 
class mCalCorev2 : public mCalCore  
{
public:
	mCalCorev2();
	virtual ~mCalCorev2();

public:
	int cal(_IN_ const char * buf,_OUT_ double &res);
	int proUnary(_IN_ const char * buf);
	int change(string &str,const char *sym);
	int change(string &str);
	char *errInfo();

private:
	int err;
	char *errStr;
	string tmpStr;
};

#endif // !defined(AFX_MCALCOREV2_H__1F4210D7_8FBD_4DA9_BA96_9857E3A4BA3D__INCLUDED_)
