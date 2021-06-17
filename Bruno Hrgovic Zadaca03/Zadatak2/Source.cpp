#include<iostream>
#include<chrono>
#include<thread>


using namespace std;
using namespace chrono;

void search_obst(char field[20][40], int ax, int ay, int bx, int by, int xx, int xy) {
	system("cls");

	duration<int, std::milli> timespan(100);
	this_thread::sleep_for(timespan);


	for (unsigned i = 0; i < 20; i++)
	{
		for (unsigned j = 0; j < 40; j++) {

			if (i < 10 && j == 13)
			{
				field[i][j] = '#';
			}

			else if (i == ay - 1 && j == ax - 1)
			{
				if (xx == ax && xy == ay)
				{
					field[i][j] = 'X';
				}
				else
				{
					field[i][j] = 'A';
				}
			}

			else if (i == by - 1 && j == bx - 1)
			{
				if (xx == bx && xy == by)
				{
					field[i][j] = 'X';
				}
				else
				{
					field[i][j] = 'B';
				}
			}

			else if (i == xy - 1 && j == xx - 1)
			{
				field[i][j] = 'X';
			}

			else
			{
				field[i][j] = '-';
			}
		}
	}
	for (unsigned i = 0; i < 20; i++)
	{
		for (unsigned j = 0; j < 40; j++) {

			cout << field[i][j];
		}
		cout << endl;
	}


	if (xx == bx && xy == by)
	{
		throw exception(":O");
	}



	if (bx > xx)
	{
		if (xy <= 10 && xx == 13)
		{
			search_obst(field, ax, ay, bx, by, xx, xy + 1);
		}
		else
		{
			search_obst(field, ax, ay, bx, by, xx + 1, xy);
		}
	}
	if (bx < xx)
	{
		if (xy <= 10 && xx == 15)
		{
			search_obst(field, ax, ay, bx, by, xx, xy + 1);
		}
		else
		{
			search_obst(field, ax, ay, bx, by, xx - 1, xy);
		}
	}
	if (by < xy)
	{
		search_obst(field, ax, ay, bx, by, xx, xy - 1);
	}
	if (by > xy)
	{
		search_obst(field, ax, ay, bx, by, xx, xy + 1);
	}

}

int main() {

	char field[20][40];
	int ax, ay, bx, by;
	bool wrong = true;

	do
	{
		system("cls");


		cout << "COUNTER STRIKE C++" << endl << endl;
		cout
			<< "You are playing the role of Terrorists in Counter Strike, your job is to set the bomb on coordinates and see if Counter Terrorists will find it " << endl << endl
			<< "This is the test course you are going to fail we can't do anything about that but it's different this time there is an obstacle " << endl << endl
			<< "RULE: Coordinates of points 'A' and 'B' have to be inside field 20(width)X40(height) " << endl
			<< "ATTENTION:" << endl
			<< "This time you cannot put X as the value of 14 on both point A or B because there is a wall there " << endl
			<< "*****************************************************" << endl << endl;

		if (!wrong)
		{
			cout << "You entered the wrong coordinates, please try again" << endl;
		}

		cout << "Enter coordinates for Counter Terrorists " << endl
		<< "X coordinate for  A= ";
		cin >> ax;
		cout << endl << "Y coordinate for A= ";
		cin >> ay;
		cout << endl;
		cout << "Enter coordinates for your bomb " << endl 
		<< "X coordinate for B= ";
		cin >> bx;
		cout << endl << "Y coordinate for B= ";
		cin >> by;

		if (ax == 14 || bx == 14 || ax <= 0 || bx <= 0 || ay <= 0 || by <= 0)
		{
			wrong = false;
		}
		else
		{
			wrong = true;
		}
	} while (!wrong);

	int xx = ax, xy = ay;

	try
	{
		search_obst(field, ax, ay, bx, by, xx, xy);
	}
	catch (const exception& e)
	{
		cout << "Bomb has been defused! " << e.what() << endl;
	}

	return 0;
}