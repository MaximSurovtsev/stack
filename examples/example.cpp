#include "stack.h"
#include <cstdlib>
#include <string>
int main()
{
	stack<int> MOSSIV;
	string arg;
	cout << "Add an element: + {element}\nShow the stack: =\nPop the element: -\nShow the last element: ?\nExit the programm: E\n";
	while (arg != "E")
	{
		getline(cin, arg);
		switch (arg[0])
		{
		case '+':
			try
			{
				if (arg[1] != ' ')
				{
					throw 1;
				}
				for (int i = 2; i < arg.length(); i++)
				if (!(arg[i] >= '0' && arg[i] <= '9')) {
					throw 1;

				}
				MOSSIV.push(stoi(arg.substr(2, arg.length() - 2)));


			}
			catch (int i)
			{
				cout << "An error has occurred while reading arguments\n";
			}
			break;
		case '?':
			try
			{
				if (arg[1])
				{
					throw 1;
				}
				MOSSIV.last();
				
			}
			catch (int i)
			{
				cout << "An error has occurred while reading arguments\n";
			}
			
			break;
		case '=':
			try
			{
				if (arg[1])
				{
					throw 1;
				}
				MOSSIV.print();
			}
			catch (int i)
			{
				cout << "An error has occurred while reading arguments\n";
			}
			
			break;
		case '-':
			try
			{
				if (arg[1])
				{
					throw 1;
				}
				MOSSIV.pop();
			}
			catch (int i)
			{
				cout << "An error has occurred while reading arguments\n";
			}
		

			break;
		}
	}


	system("pause");
	return 0;
}
