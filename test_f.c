#include <stdio.h>

void reverse(char *p, char *q)
{
	char c;

	while (p++ < q--)
	{
		c = *p;
		*p = *q;
		*q = c;
	}
}

char* inc(char* s, char* e)
{
	int co = 1;
	char* t = e;

	while (t >= s)
	{
		if (*t == '.')
			continue;
		*t += co;
		if (*t > '9')
		{
			*t = '0';
			co = 1;
		}
		else
		{
			co = 0;
			break;
		}
		t--;
	}	
	if (co)
	{
		t = ++e;
		while (t > s)
		{
			*t = *(t - 1);
			*s = '1';
			t--;
		}
	}
	return e;
}
char* ftoa(char* dest, long double n, int precision, int sign)
{
	char *p;
	long long integer;
	long double decimal;
	int save_pres = precision;
	char *q; 

	integer = (long long)n;
	decimal = n - integer;
	p = dest;
	//parse sign
	if (sign && n > 0)
		*p++ = '+';
	if (n < 0)
	{
		*p++ = '-';
		integer = -integer;
		decimal = -decimal;
	}
	//parse integer
	if (integer)
	{
		q = p;
		while (integer)
		{
			*q++ = '0' + integer % 10;
			integer /= 10;
		}
		reverse(p, q - 1);
		p = q;
	}
	else
		*p++ ='0';
	//parse decimal
	//void decimal(int precision)
	//{
	//	if (precision > 0)
	//		*p++ = '.';
	//	while (precision)
	//	
	//}
	if(precision > 0)
	{
		*p++ = '.';

		while (precision)
		{
			decimal *= 10;
			*p++ = '0' + (int)decimal;
			decimal -= (int)decimal;
			precision--;
		}
		if ((long long)(decimal + 0.5))
			p = inc(dest, p - 1) + 1;
	}
//	if (((int)n % 2 == 1) && save_pres == 0 && decimal >= 0.5)
//		p = inc(dest, p - 1) + 1;
//	if (n < 1 && save_pres == 0 && decimal > 0.5)
//		p = inc(dest, p - 1) + 1;
	*p = '\0';
	return dest;
}

int main(void) {
	char s[50];
	long double n = 99999999.6485;

	sprintf(s, "%.Lf", n);
	puts(s);
	puts(ftoa(s, n, 0, 0));

	return 0;
}
