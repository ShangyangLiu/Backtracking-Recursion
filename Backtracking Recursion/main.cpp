/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"
using namespace std;

Vector<int> dr1 = {-2,-2,-1,-1,1,1,2,2};
Vector<int> dr2 = {-1,1,-2,2,-2,2,-1,1};

void knightTourHelper(Grid<bool> &grid, GridLocation current,
                      Vector<GridLocation> temp,Vector<GridLocation> &result)
{
    if(temp.size() == 25)
    {
        result = temp;
        return;
    }
    else
    {
        grid[current] = false;
        GridLocation nextLoc;
        for(int i = 0;i<8;i++)
        {
            nextLoc = {current.row+dr1[i],current.col+dr2[i]};
            if(grid.inBounds(nextLoc) && grid[nextLoc] == true)
            {

                knightTourHelper(grid,nextLoc,temp + nextLoc,result);

            }
        }
        grid[current] = true;
    }
}

void knightTour(Grid<bool> grid)
{

    Vector<GridLocation> result;
    Vector<GridLocation> temp;
    GridLocation current = {0,0};
    temp.add(current);
    knightTourHelper(grid,current,temp,result);
    if(result.isEmpty())
    {
        cout<<"ERROR"<<endl;
    }
    else
    {
        cout<<result<<endl;
    }

}


int main()
{
    Grid<bool> grid(5,5,true);
    knightTour(grid);

    return 0;
}








