//4.30.2021

#include <iostream>

 

using namespace std;

 

int** multiply(int** a1, int dimension, int count)
{
    //Create result array
    int** ax = new int* [dimension];
    for (int i = 0; i < dimension; i++)
    {
        ax[i] = new int[dimension];
    }
    //Initialize to zero values
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            ax[i][j] = a1[i][j];
        }
    }
    //Mulitply a1 count number of times against self
    int** temp = new int* [dimension];
    for (int i = 0; i < dimension; i++)
    {
        temp[i] = new int[dimension];
    }
    for (int i = 0; i < count; i++)
    {    
        for (int row =  0; row < dimension; row++)
        {        
            for (int col = 0; col < dimension; col++)
            {    
                int result = 0;
                //loop to end of row to calculate
                for (int pos = 0; pos < dimension; pos++)
                {
                    result += ax[row][pos] * a1[pos][col];
                }
                temp[row][col] = result;
            }
        }
        //Loop through ax and assign it temp's values
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                ax[i][j] = temp[i][j];
            }
        }
    }
    
    return ax;
}
int main()
{

 

    int** input_matrix;
    int** reachability_matrix;
    bool loop = true;
    int input;
    do
    {
        cout << "Enter 2 for two nodes :\nEnter 3 for three nodes:\nEnter 4 for four nodes:\nEnter 5 for five nodes:\nEnter 0 to quit\n";
        cin >> input;
        //Create initial array(A1)
        input_matrix = new int* [input];
        for (int i = 0; i < input; i++)
        {
            input_matrix[i] = new int[input];
        }
        //Fill A1
        cout << "Enter values for array :" << endl;
        for (int i = 0; i < input; i++)
        {
            for (int j = 0; j < input; j++)
            {
                cin >> input_matrix[i][j];
            }
        }
        cout << endl;

 

        //Initialize A arrays(A2, A3, etc)
        int*** arrays = new int**[input];
        for (int i = 0; i < input; i++)
        {
            arrays[i] = new int* [input];
            for (int j = 0; j < input; j++)
            {
                arrays[i][j] = new int[input];
            }
        }

 

        //Assign A1 manually(user input)
        arrays[0] = input_matrix;
        //Determine A2, A3, etc
        for (int i = 1; i < input; i++)
        {
            arrays[i] = multiply(arrays[0], input, i);
        }

 

        //Determine reachability matrix
        reachability_matrix = new int*[input];
        for (int i = 0; i < input; i++)
        {
            reachability_matrix[i] = new int[input];    
        }
        for (int i = 0; i < input; i++)
        {
            for (int j = 0; j < input; j++)
            {
                reachability_matrix[i][j] = 0;
                for (int k = 0; k < input; k++)
                {
                    reachability_matrix[i][j] += arrays[k][i][j];
                }
            }
        }
        //Display Arrays
        for (int i = 0; i < input; i++)
        {
            cout << "A" << (i + 1) << " : " << endl;
            for (int j = 0; j < input; j++)
            {
                for (int k = 0; k < input; k++)
                {
                    cout << arrays[i][j][k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        //Display reachability matrix
        cout << "Reachability Matrix : " << endl;
        for (int i = 0; i < input; i++)
        {
            for (int j = 0; j < input; j++)
            {
                cout << reachability_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } while (input != 0);
}