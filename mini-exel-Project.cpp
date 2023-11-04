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
    Cell *head;
    Cell *tail;
    Cell *current_ptr;
    vector<vector<Cell*>> gridContainer ;//holding all rows in one container
    vector<Cell*> grid;//holding one row

public:
    Excel(int numRows, int numCols)
    {
        rows = numRows;
        cols = numCols;
        head = nullptr;
        tail = nullptr;
        current_ptr = nullptr;
        initialize_Grid();
    }

    void initialize_Grid()
    {
        for (int i = 0; i < rows; i++)
        {
            Cell *cell = new Cell(0);
            if (head == nullptr && tail == nullptr)
            {
                head = cell;
                tail = cell;
                current_ptr = cell;
                grid.push_back(head);
            }
            else
            {
                tail->Right = cell;
                cell->Left = tail;
                tail = cell;
                grid.push_back(tail);
            }
            gridContainer.push_back(grid);
        }
    }

    void display()
    {
        Cell *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->Right;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Excel excel(5, 5);
    excel.display();

    return 0;
}