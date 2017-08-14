// mCalCore.cpp: implementation of the mCalCore class.
//
//////////////////////////////////////////////////////////////////////

#include "mCalCore.h"

//****Use To DeBug*******//
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

mCalCore::mCalCore()
{
	flag = false;
	l_bracket = 0;
}

mCalCore::~mCalCore()
{

}

int mCalCore::calculate(const char *buf, double &r)
{
	init();
	err |= niToPost(buf);
	if(err)
	{
		r = 0;
		return err;
	}
	err |= getAnswer();
	if(err)
	{
		r = 0;
		return err;
	}
	r = atof(postfix.top().c_str());
	return err;
}

//
//make infix to postfix stored into postfix.//
//
int mCalCore::niToPost(_IN_ const char *buf)
{
	int len = strlen(buf);
	for(int index = 0; index <= len; index++)
	{	
		//Symbol Priority
		string t = "0";
		t[0] = buf[index];
		if(buf[index] <= '9' &&  buf[index] >= '0' | buf[index] == '.')
		{
			/*********judge if long number*************/

			if(flag)
			{
				string t2 = postfix.top() + t;
				postfix.pop();
				postfix.push(t2);
			}
			else
			{
				flag = true;
				postfix.push(t);
			}	
			/****************************************/
		}
		else if(buf[index] >= '(' && buf[index] <= '/' | buf[index] == '^')
		{
			/********judge "(" or ")"*******/
			if(!flag)		//judge double 
			{
				if(buf[index] == '+' && buf[index-1] != ')')continue;
			}
			flag = false;
			if(buf[index] == '(')
			{
				tmp.push(t);
				l_bracket++;
			}
			else if(buf[index] == ')')
			{
				if(l_bracket)
				{
					l_bracket--;
					while(tmp.top() != "(")
					{
						postfix.push(tmp.top());
						tmp.pop();
					}
					tmp.pop();
				}
				else
				{
					return 1;	//lose left bracket;
				}
			}
			else if(!tmp.empty())
			{
				//maybe have problem.......................................
				if( tmp.top() == "*" | tmp.top() == "/" | tmp.top() == "^")
				{
					postfix.push(tmp.top());
					tmp.pop();
				}
				if(buf[index] != 0)tmp.push(t);
			}
			else
			{
				if(buf[index] != 0)tmp.push(t);
			}

		}
		else
		{
			if(buf[index] != 0)return 2;
		}
		if(buf[index] == 0)
		{
			if(l_bracket != 0)	//lose right bracket
			{
				return 1;
			}
			while(!tmp.empty())
			{
				postfix.push(tmp.top());
				tmp.pop();
			}
		}
	}

/***********test**************
	cout << postfix.size() << endl;
	while(!postfix.empty())
	{
		cout << postfix.top() << endl;
		postfix.pop();
	}

	while(!tmp.empty())
	{
		cout << tmp.top() ;
		tmp.pop();
	}
	cout << endl;
/***********/	

	return 0;
}

//USE postfix to calculate answer
int mCalCore::getAnswer()
{
	double lv , rv;
	//swap
	while(!postfix.empty())
	{
		tmp.push(postfix.top());
		postfix.pop();
	}
	//cal
	int x=0,y=0;
	//calculate
	while(!tmp.empty())
	{	
		if(tmp.top() == "+" | tmp.top() == "-" | tmp.top() == "*" | tmp.top() == "/" | tmp.top() == "^")
		{
			if(postfix.size() < 2)return 3;
			x++;
			lv = atof(postfix.top().c_str());
			postfix.pop();
			rv = atof(postfix.top().c_str());
			postfix.pop();
			if(tmp.top() == "+")res = rv + lv;
			if(tmp.top() == "-")res = rv - lv;
			if(tmp.top() == "*")res = rv * lv;
			if(tmp.top() == "/")
			{
				if(lv == 0)return 2;
				res = rv / lv;
			}
			if(tmp.top() == "^")res = pow(rv,lv);
			char str[256];
			sprintf(str, "%lf", res);
			string str1 = str;
			postfix.push(str1);
		}
		else if(tmp.top() >= "0" )
		{
			y++;
			postfix.push(tmp.top());
		}
		else
		{
			return 2;
		}
		tmp.pop();
	}

	return 0;
}

void mCalCore::init()
{
	flag = false;
	l_bracket = 0;
	while(!tmp.empty())
	{
		tmp.pop();
	}
	while(!postfix.empty())
	{
		postfix.pop();
	}
	res = 0;
	err = 0;
}


/*
char * mCalCore ::errInfo()
{
	switch(err)
	{
	case 0:errstr = "" ;break ;
	case 1:errstr = "ERROR_1:lose bracket";break;
	case 2:errstr = "ERROR_2:illegal input";break;
	case 3:errstr = "ERROR_3:symbol error"
	default:errstr = "ERROR_X:UNKNOW ERROR";break;
	}
	return errstr;
}
*/