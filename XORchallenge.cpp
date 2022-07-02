/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

ll main() {
	ll num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#define ll long long int

using namespace std;

int main()
{
	ll c;
	cin>>c;
	ll num=1;
	ll n1=0,n2=0;
	while(num<=c)
	{
		if(c&num){
			n2+=num;
		}
		else{
			n2+=num;
			n1+=num;
		}
		num*=2;
	}
	if(c!=num)num/=2;
	n1+=num;
	n2-=num;
	cout<<n1*n2<<"\n";
	return 0;
}