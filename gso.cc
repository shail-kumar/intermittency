/*
* This program returns the orthonormal vectors using the Gram-Schmidth Orthogonalization procedure.
* The input is the basis vectors of the vector space.

Author: Shail Kumar
Created on : Thu Mar 29 17:32:39 2018
*/
#include <iostream>
#include <blitz/array.h>

using namespace blitz;
typedef TinyVector<double,3> vect;
vect subtrand(Array<vect,1>, Array<vect,1>, int );


int main(int argc, char const *argv[])
{
	int num_row = 3;
	int num_col = 3;
	Array<vect,1> A(num_row,num_col);
	Array<vect,1> E(num_row,num_col);
	E = 0.0;
	cout<<" Put the entry of a vector in the form e.g. [2,3,4] "<<endl;
	for (int i = 0; i < num_col; ++i)
	{
		cout<<"Elements of vector "<<i+1<<" : ";
		cin>>A(i);
	}
/*	// Sample input basis vectors 
	vect a(1,0,0);	cout<<a<<endl;
	vect b(2,0,3);	cout<<b<<endl;
	vect c(4,5,6);	cout<<c<<endl;
	A = a,b,c;*/

	cout<<A<<endl;

	E(0)=A(0)/sqrt(dot(A(0),A(0)));
	for (int i = 1; i < num_col; ++i)
	{
		vect e(0,0,0);
		e = A(i) - subtrand(A,E,i);
		E(i) = e/sqrt(dot(e,e));
	}
	cout<<E<<endl;
	return 0;
}

vect subtrand(Array<vect,1> A, Array<vect,1> E, int num_col)
{
	vect s(0,0,0);
	for (int i = 0; i < num_col; ++i)
	{
		s+=dot(E(i), A(num_col)) * E(i);
	}
	return s;
}
