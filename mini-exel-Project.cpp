#include <iostream>
#include <vector>
using namespace std;

class Cell
{
public:
    int data;
    Cell *Up;
    Cell *Down;
    Cell *Right;
    Cell *Left;

    Cell(int val)
    {
        data = val;
        Up = nullptr;
        Down = nullptr;
        Left = nullptr;
        Right = nullptr;
    }
};

class Excel
{
private:
    int rows;
    int cols;
    Cell *current_ptr;
    vector<vector<Cell *>> gridContainer;

public:
    Excel(int numRows, int numCols)
    {
        rows = numRows;
        cols = numCols;
        current_ptr = nullptr;
        initialize_Grid(numRows, numCols);
    }

    void initialize_Grid(int &rows, int &cols)
    {
        // initaize the grid with empty
        for (int i = 0; i < rows; i++)
        {
            vector<Cell *> grid;
            for (int j = 0; j < cols; j++)
            {
                grid.push_back(nullptr);
            }
            gridContainer.push_back(grid);
        }
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {
                Cell *cell = new Cell(0); // Assign unique values.
                gridContainer[i][j] = cell;

                if (i > 0)
                {
                    cell->Up = gridContainer[i - 1][j];
                    gridContainer[i - 1][j]->Down = cell;
                }
                if (j > 0)
                {
                    cell->Left = gridContainer[i][j - 1];
                    gridContainer[i][j - 1]->Right = cell;
                }
            }
        }
        current_ptr = gridContainer[4][4];
    }

     void display2()
{
    Cell *temp = current_ptr;
    int flag = 0; // 0 means moving toward left

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";

        if (flag == 0)
        {
            if (temp->Left == nullptr)
            {
                temp = temp->Up; // Move right if possible
                flag = 1; 
            }
            else
            {
                temp = temp->Left; // Move up when no right movement is possible
            
            }
        }
        else
        {
            if (temp->Right == nullptr)
            {
                temp = temp->Up; // Move left if possible
                flag=0;
            }
            else
            {
                temp = temp->Right; // Move up when no left movement is possible
                 
            }
        }
    }
}

        // void insertRowAtAbove()
        // {
        //     if (gridContainer.size() == 0)
        //     {
        //         return; // Do nothing if the grid is empty.
        //     }

        //     if (current_ptr == nullptr)
        //     {
        //         // If current_ptr is not set, insert the new row as the first row.
        //         vector<Cell *> newRow(cols);
        //         for (int idx = 0; idx < cols; idx++)
        //         {
        //             Cell *cell = new Cell(1);
        //             newRow[idx] = cell;

        //             if (idx > 0)
        //             {
        //                 cell->Left = newRow[idx - 1];
        //                 newRow[idx - 1]->Right = cell;
        //             }
        //         }
        //         gridContainer.insert(gridContainer.begin(), newRow);
        //         current_ptr = newRow[0];
        //     }
        //     if(current_ptr == nullptr)
        //     {
        //         // Insert a new row above the current row.
        //         vector<Cell *> newRow(cols);
        //         for (int idx = 0; idx < cols; idx++)
        //         {
        //             Cell *cell = new Cell(0);
        //             newRow[idx] = cell;

        //             if (idx > 0)
        //             {
        //                 cell->Left = newRow[idx - 1];
        //                 newRow[idx - 1]->Right = cell;
        //             }

        //             cell->Down = current_ptr;
        //             current_ptr->Up = cell;
        //         }

        //         // Update the current_ptr to the newly inserted row.
        //         current_ptr = newRow[0];
        //         gridContainer.insert(gridContainer.begin() + 1, newRow);
        //     }
        // }

        void display()
        {
            for (int i = 0; i < gridContainer.size(); i++)
            {
                for (int j = 0; j < gridContainer[i].size(); j++) // Change gridContainer.size() to gridContainer[i].size()
                {
                    cout << gridContainer[i][j]->data << "-->";
                }
                cout << "NULL" << endl;
            }
        }
    };

    int main()
    {
        Excel excel(5, 5);
        excel.display2();
        return 0;
    }
