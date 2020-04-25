/***************************************/
// 	Project name :	Quine–McCluskey algorithm
// 	Programmer :	Poorya Mohammadi Nasab
// 	Email :			Poorya.m.n.b@gmail.com
// 	Github Page:	github.com/pooryamn
/***************************************/

#include <iostream>
using namespace std;

void check_bit(unsigned int[], unsigned int[]);

// minterms structures : 

struct minterm{
	unsigned int a[6];
	int n;
	int are;
	int tedad=0;
	void to_bin(){
		are = 0;
		for (int i = 0; i < 6; i++)
		{
			a[i] = 0;
		}
		int temp;
		temp = n;
		int m = 5;
		while (temp!=0)
		{
			a[m] = temp % 2;
			m--;
			temp = temp / 2;
		}
	}
	void print(){
		
		if (a[0]==1)// A 
		{
			cout << "A";
		}
		else if(a[0]==0)// A'
		{
			cout << "A'";
		}
		if (a[1] == 1)// B
		{
			cout << "B";
		}
		else if (a[1] == 0)// B'
		{
			cout << "B'";
		}
		if (a[2] == 1)// C
		{
			cout << "C";
		}
		else if (a[2] == 0)// C'
		{
			cout << "C'";
		}
		if (a[3] == 1)// D
		{
			cout << "D";
		}
		else if (a[3] == 0)// D'
		{
			cout << "D'";
		}
		if (a[4] == 1)// E
		{
			cout << "E";
		}
		else if (a[4] == 0)// E'
		{
			cout << "E'";
		}
		if (a[5] == 1)// F
		{
			cout << "F";
		}
		else if (a[5] == 0)// F'
		{
			cout << "F'";
		}
	}

	void checkt(){
		int f = 0;
		for (int i = 0; i < 6; i++)
		{
			if (a[i] == 1)
			{
				f++;
			}
		}
		tedad = f;
	}
};


int main()
{
	minterm m[256];
	int t,y,count;
	cout << "how many Minterms : ";
	cin >> t;
	count = t;

	if (t==0)
	{
		cout << "0\n";
	}

	else if (t==64)
	{
		cout << "1\n";
	}

	else {
		cout << "Enter your minterms : \n";
		for (int i = 0; i < t; i++)
		{
			cin >> y;
			m[i].n = y;
			m[i].to_bin();
			m[i].checkt();
		}
		
		for (int i = 0; i < count; i++)
		{
			for (int j = i; j < count / 2; j++)
			{
				if (m[j].tedad - m[i].tedad == 1)
				{
					int f = 0;
					for (int z = 0; z < 6; z++)
					{
						if (m[j].a[z] != m[i].a[z])
						{
							f++;
						}
					}
					if (f == 1)
					{
						m[j].are = 1;
						m[i].are = 1;
						count++;
						for (int z = 0; z < 6; z++)
						{
							m[count].are = 0;
							if (m[j].a[z] != m[i].a[z])
							{
								m[count].a[z] = 10;
							}
							else if (m[j].a[z] == m[i].a[z])
							{
								m[count].a[z] = m[j].a[z];
							}
						}
					}
				}
			}
		}

		int print_flag = 0;
		for (int i = 0; i < count; i++) {
			if (m[i].are == 0)
			{
				if(print_flag == 1){
				cout << " + ";
				}
				m[i].print();
				print_flag = 1;
			}

		}
		cout << '\n';
	}
	return 0;
}