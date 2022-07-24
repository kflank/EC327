#include "View.h"



View::View() 
{
size = 11;

scale = 2;

origin.x = 0;
origin.y = 0;
}


void View::Clear()
{
	for (int i = 0; i< size; i++)
	{
		for (int j=0; j<size; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = '.';
		}
	}


}


bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
{
	out_x = (int) ((location.x - origin.x)/scale);
	out_y = (int) ((location.y - origin.y)/scale);

if (out_x <= size && out_y <= size)
{
	return true; 
}
else
{
	cout<<"object is outsdie the display "<<endl;
	return false;
} 

}



void View::Draw()
{
	for (int j = size-1; j>= -1; j--)
	{

		for (int i = -1; i<= size-1; i++)
		{

			if ( i == -1 && j%2 == 0)
			{

				cout << j*2;
				if (j/5 == 0)
				{
					cout<< " ";
				}


			}
			else if (i == -1 && j%2 !=0)
			{
				cout<<" ";
			}

			else if (j == -1 && i%2 == 0)
			{
				cout<<i*2;
				if (i/5 == 0)
				{
					cout<<" ";
				}
				cout<<" ";
			}
			//draw objects
			if (i >= 0 && j>= 0)
			{
				cout<< grid[i][j][0] << grid[i][j][1];
			}
		}
		cout<<endl;

	} 
}

void View::Plot(GameObject *ptr)
{
	if (ptr->ShouldBeVisible())
	{
		Point2D loc = ptr->GetLocation();
		int x,y;
		char *objectptr = new char;
		if (GetSubscripts(x,y,loc))
		{
			//ptr->DrawSlef(objectptr);
			if (grid[x][y][0] == '.')
			{
				grid[x][y][0] = objectptr[0];
				grid[x][y][1] = objectptr[1];
			}
			else 
			{
				grid[x][y][0] = '*';
				grid[x][y][1] = ' ';
			}
		}
	}
}






