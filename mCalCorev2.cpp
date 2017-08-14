// mCalCorev2.cpp: implementation of the mCalCorev2 class.
//
//////////////////////////////////////////////////////////////////////

#include "mCalCorev2.h"

#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

mCalCorev2::mCalCorev2()
{
	err = 0;
}

mCalCorev2::~mCalCorev2()
{

}

int mCalCorev2::cal(const char * buf, double &res)
{
	proUnary(buf);
	err |= calculate(tmpStr.c_str(),res);
	//cout << err;
	return 0;
}

int mCalCorev2::proUnary(const char * buf)
{
	string str = buf;
	err |= change(str,SIN);
	err |= change(str,COS);
	err |= change(str,TAN);
	err |= change(str,SQRT);
	err |= change(str,FAC);
	err |= change(str,LOG);
	err |= change(str,LN);
	err |= change(str);
	tmpStr = str;
	return err;
}

int mCalCorev2::change(string &str,const char *sym)
{
	size_t pos = 0;
	while(pos != string::npos)
	{
		int flag = 0;
		pos = str.find(sym,pos);
		if(pos == string::npos)return 0;
		int ps = pos;
		int pe = pos;
		while(pe < str.length())
		{	
			if(str[pe] == '(') 
			{
				flag++;
				if(flag == 1) ps = pe;
			}
			if(str[pe] == ')') 
			{
				flag--;
				if(flag == 0)break;
			}
			pe++;
			if(pe == str.length() && flag != 0)return 1;
		}
		string s = str.substr(ps + 1,pe - ps - 1);			//get inside sin(******) 
		double an = 0;
		
		//***************caution*******************//
		if(proUnary(s.c_str()) == 0)s = tmpStr;				//inoder to find include double sin/cos/tan;
		//if(s.find(sym,0) != string::npos)cal(s.c_str(),an);	//inoder to find include double sin/cos/tan;

		err |= calculate(s.c_str(),an);	//calculate simple formula

		switch(sym[0])				//dispatch sym
		{
		case 's':an = (sym[1] == 'q')?sqrt(an):sin(an);break;
		case 'c':an = cos(an);break;
		case 't':an = tan(an);break;
		case 'l':an = (sym[1] == 'o')?log10(an):log(an);break;
		case '!':{
					int i = an - 1;
					for(;i > 0; i--)an *= i;
				 };break;
		default:an = 8888; break;
		}

		char st[256];
		sprintf(st, "%c%lf%c",'(', an, ')');
		str.replace(pos, pe - pos + 1, st);	//change str value directly;

		//cout << str << endl;
		//cout << sym << s << "=" << an << endl;
		//cout << ps << " " << pe <<endl;
	}
	return 0;
}

int mCalCorev2::change(string &str)
{
	size_t pos = 0;
	while(pos != string::npos)
	{
		pos = str.find("(-",pos);
		if(pos == string::npos)break;
		str.insert(pos + 1,"0");
		//cout << str << endl;;
	}
	pos = 0;
	while(pos != string::npos)
	{
		pos = str.find("pi",pos);
		if(pos == string::npos)break;
		str.replace(pos, 2, "3.14159");
		//cout << str << endl;;
	}
	pos = 0;
	while(pos != string::npos)
	{
		pos = str.find("e",pos);
		if(pos == string::npos)break;
		str.replace(pos , 1 , "2.71828");
		//cout << str << endl;;
	}

	return 0;
}

char * mCalCorev2::errInfo()
{
	switch(err)
	{
	case 0:errStr = "" ;break ;
	case 1:errStr = "ERROR_1:lose bracket";break;
	case 2:errStr = "ERROR_2:illegal input";break;
	case 3:errStr = "ERROR_3:symbol error";break;
	default:errStr = "ERROR_X:UNKNOW ERROR";break;
	}
	return errStr;
}