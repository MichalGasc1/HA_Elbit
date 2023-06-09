// Question 1 - functions
//
//	you are given the following missing implementation:
//	float applyF(float a, float b, ??????)
//	{
//		return f(a, b);
//	}
//
//	1) list at least 3 different ways to replace the qustion marks (??????)
//		1. func f (using typedef float func(float, float))
//		2. std::function<float(float, float)>
//		3. float (*f)(float, float)
//
//	2) replace the qustion marks in the following implementations with the solutions you listed
//
//	3) using one of those options create an add operation and a multiply operation and implement the following computation:
//		(2 * 3) + (4 * 5) + 6
//
//	you may not change the functions' implementation, only complete the signature
#include <functional>
typedef float func(float, float);




float applyF1(float a, float b, func f)
{
	return f(a, b);

}

float applyF2(float a, float b, std::function<float(float, float)> f)
{
	return f(a, b);
}

float applyF3(float a, float b, float (*f)(float, float) )
{
	return f(a, b);
}

float add(float a, float b)
{
    return a+b;
}

float multiply (float a, float b)
{
    return a*b;
}

int main(int argc, char *argv[])
{
	float fNum = 0;
	// calculate fNum = (2 * 3) + (4 * 5) + 6
	float mul1 = applyF1(2,3,&multiply);
	float mul2 = applyF1(4,5,&multiply);
    float add1 = applyF1(mul1,mul2,&add);
    fNum = applyF1(add1,6,&add);

    return 0;
}


