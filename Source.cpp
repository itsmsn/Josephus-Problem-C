#include <iostream>
#include "myconsole.h"
#include "mygraphics.h"
#include <ctime>
using namespace std;

class queue
{
	int* arr;
	int front;
	int rear;
	int size;

public:
	queue(int size = 0)
	{
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = -2;
		}
		front = -1;
		rear = -1;
		this->size = size;
	}

	bool is_Full()
	{
		if (front == 0 && rear == size - 1)
		{
			cout << "\nITS FULL\n";
			return true;
		}
		else if (front == rear + 1)
		{
			return true;
		}
		else
			return 0;
	}

	bool is_emptY()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
			return 0;
	}

	void enqueue(int val)
	{
		if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;
			arr[rear] = val;
		}
		else if(!is_Full())
		{
			rear = (rear + 1) % (size);
			arr[rear] = val;
		}


	}

	int dequeue()
	{
		int element = 0;
		if(is_emptY())
		{
			cout << "ITS EMPTY";
			return -1;
		}
		else
		element = arr[front];

		if (front == rear) 
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % size;
		}
		return (element);
	}

	void show()
	{
		if (is_emptY())
		{
			cout << "LIST IS EMPTY";
		}
		else
		{

			if (rear > front)
			{
				for (int i = front; i <= rear ; i++)
				{
					cout << arr[i] << " ";
				}
			}
			else
			{
				for (int i = front; i < size; i++)
				{
					cout << arr[i] << " ";
				}
			}
		}
	}

	void kill(int o)
	{
		int s = 1;
		int k = 0;
		cout << "\n";
		Sleep(1000);
		//ClearScreen();
		drawboard(arr, size,s,k);
		k = k + 30;
		srand(time(0));
		front = rand() % (size - 1);
		cout << "\nFRONT IS : " << front << endl;
		int kill = front;
		for (int i = 0; i < size - 1 ; i++)
		{
			kill = (kill + o ) % size;
			if (arr[kill] == 0)
			{
				//cout << "To";
				l2:
				while (arr[kill] == 0)
				{
					kill++;
					if (kill >= size)
					{
						kill = kill % size;
						if (arr[kill] == 0)
							goto l2;
					}
				}
				if (arr[kill] != 0)
				{
					arr[kill] = 0;
				}
			}
			else
			{
				arr[kill] = 0;
				l:
				while (arr[kill] == 0)
				{
					cout << "To00";
					kill++;
					if (kill >= size)
					{
						kill = (kill % size);
						if (arr[kill] == 0)
							goto l;

					}
				}
			}
			/*if (arr[i] == -1)
			{
				cout << " ";
			}
			else
			{
				cout << arr[i];
			}*/
			cout << "\n";
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			Sleep(1000);
			//ClearScreen();
			//s++;
			drawboard(arr, size, s,k);
			k = k + 30;
		}


	}

	int kill_it(int o)
	{
		int s = 1;
		int k = 0;
		cout << "\n";
		Sleep(1000);
		//ClearScreen();
		drawboard(arr, size, s, k);
		k = k + 30;
		srand(time(0));
		front = rand() % (size - 1);
		cout << "\nFRONT IS : " << front << endl;
		int kill = 0, cut = front, num = 1;
		while ( kill < (size - 1))
		{
			while (num <= o) 
			{
				cut++;
				cut = cut % size; 
				if (arr[cut] == 1) {
					num++;
				}
			}
			num = 1;
			arr[cut] = 0;
			kill++;
			cut++;
			cut = cut % size;
			while (arr[cut] == 0)
			{
				cut++;
				cut = cut % size; 
			}
			cout << "\n";
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			Sleep(1000);
			drawboard(arr, size, s, k);
			k = k + 30;
		}
		return cut + 1; 
	}

	/*~queue()
	{
		delete arr;
		front = -1;
		rear = -1;
	}*/
};




int main()
{
	maximized();
	cout << "ENTER EXECUTIONERS SIZE : ";
	int size = 0;
	cin >> size;

	cout << "LETS BEGIN NOW ENTER THE NUMBER TO SKIP : ";
	int k = 0;
	cin >> k;


	queue q(size);
	for (int i = 0; i < size; i++)
	{
		q.enqueue(1);
	}

	q.show();

	//q.kill(k);
	cout << "\n";
	cout <<"----------->"<< q.kill_it(k);






	return 0;
}