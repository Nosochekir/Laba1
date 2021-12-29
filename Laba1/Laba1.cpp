
#include <locale.h>
#include <ctime>
#include "windows.h"
#include <iostream>
#include <cstdlib>

using namespace std;
struct st
{
	unsigned long long int N_op = 0;
}n;

struct Node
{
	Node* next;
	int value;
};
class Ochered
{
private:
	int size;
public:
	Node* head;
	Node* tail;

	void Init()		//.2
	{
		head = NULL; n.N_op++;	//1
		tail = NULL; n.N_op++;	//1
	}
	bool Isempty()		//.1
	{
		return tail == NULL; n.N_op++;	//1
	}
	void Add(int x)		//3+2+1+1+2+2+2+2+1+2+2+2=22
	{
		Node* node = new Node; n.N_op += 3;	//3

		if (Isempty() == 1)		//2
		{
			n.N_op++;
			head = node; n.N_op++;	//1
			tail = node; n.N_op++;	//1
			node->next = NULL; n.N_op += 2;	//2
			node->value = x; n.N_op += 2;	//2
			size++;	n.N_op++;	//1
		}
		else
		{
			n.N_op++;
			head->next = node; n.N_op += 2;		// 2
			head = node; n.N_op++;		//1
			head->value = x; n.N_op += 2;		//2
			node->next = NULL; n.N_op += 2;		//2
			size++;	n.N_op++;	//1
		}
	}

	void Del()		//.2+1+2=5

	{
		if (Isempty() != 1)		//2
		{
			n.N_op++;
			Node* tmp;
			tmp = tail; n.N_op++;		//1
			tail = tail->next; n.N_op += 2;		//2
			delete tmp;
		}
	}
	int Value()		//.2+1=3
	{
		if (Isempty() != 1)		//2
		{
			n.N_op++;
			return tail->value;	n.N_op++;	//1
		}
		return 0;
	}
};
void sort(int N)
{
	Node* perc;

	Ochered och1;
	Ochered och2;

	och1.Init(); 	//3
	och2.Init();	//3

	int example;

	int i = N;		//1
	int a;

	cout << "Origin:\n";

	for (; i > 0; i--)		//1+N(2+23)=23N+1
	{
		a = rand() % (1000 - 0 + 1);
		cout << " [ " << a << " ] \n";
		och1.Add(a);
	}
	cout << "\n---------------\n";

	for (int k = 0; k < N - 1; k++)		//3+(N-1)((3+5+6+2+96N)+(36N+3))=3+16N+96N^2-16-96N+36N^2+3N-36N-3=-16-113N+132N^2
	{
		example = och1.Value();	//5
		och1.Del();		//6
		for (int j = 0; j < N; j++)		//2+N(2+2+23+5+23+5+27+6)=2+96N
		{

			if (och1.Isempty())		//2
			{
				och2.Add(example);		//23
			}
			else
			{
				if (example <= och1.Value())		//5
				{
					och2.Add(example);		//23
					example = och1.Value();		//5
				}
				else
				{
					och2.Add(och1.Value());		//27
				}
				och1.Del();		//6
			}

		}
		while (och2.Isempty() != 1)		//3+N(3+27+6)=36N+3
		{
			och1.Add(och2.Value());		//27
			och2.Del();		//6

		}

	}

	while (och1.Isempty() != 1)		//3+N(3+6)=3+9N
	{
		cout << "\n [ " << och1.Value() << " ]" << endl;
		och1.Del();
	}

}
int main()

{
	sort(10);
	cout << n.N_op << endl;
	return 0;

}
