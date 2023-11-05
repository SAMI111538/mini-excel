#include <iostream>
using namespace std;

class Cell {
public:
    int data;
    Cell* Up;
    Cell* Down;
    Cell* Right;
    Cell* Left;

    Cell(int val) {
        data = val;
        Up = nullptr;
        Down = nullptr;
        Left = nullptr;
        Right = nullptr;
    }
};

class Excel {
private:
    int rows;
    int cols;
    Cell* current_ptr;
    Cell* head;

public:
    Excel(int numRows, int numCols) {
        rows = numRows;
        cols = numCols;
        current_ptr = nullptr;
        head = nullptr;

        // Call a method to initialize the grid
        InitializeGrid();
    }

    void InitializeGrid() {
        head = new Cell(0);
        current_ptr = head;

        for (int i = 0; i < rows; ++i) {
            Cell* current_row = current_ptr;
            for (int j = 0; j < cols; ++j) {
                if (j < cols - 1) {
                    Cell* new_cell = new Cell(0);
                    current_row->Right = new_cell;
                    new_cell->Left = current_row;
                    current_row = new_cell;
                }
            }

            if (i < rows - 1) {
                Cell* new_row = new Cell(0);
                current_ptr->Down = new_row;
                new_row->Up = current_ptr;
                current_ptr = new_row;
            }
        }
    }

    friend void DisplayGrid(const Excel& excel);
};

void DisplayGrid(const Excel& excel) {
    Cell* current_row = excel.head;
    while (current_row != nullptr) {
        Cell* current_cell = current_row;
        while (current_cell != nullptr) {
            cout << current_cell->data << "-->";
            current_cell = current_cell->Right;
        }
        cout<<"NULL";
        cout << endl;
        current_row = current_row->Down;
    }
}

int main() {
    Excel excel(5, 5);  // Create a 3x3 grid
    DisplayGrid(excel); // Display the grid
    return 0;
}
