// Name: Alex Ingram
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 11

#include <cctype>   // Provides toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream> // Provides cout and cin

using namespace std;

void print_menu();
// Postcondition: The menu has been written to cout.

char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.

void HF1(int key, int table[][2]);
// Precondition: key is value from keys array, table is the hashtable
// Postcondition: adds key values to table by using division method and linear probing

void HF2(int key, int table[][2]);
// Precondition: key is value from keys array, table is the hashtable
// Postcondition: adds key values to table by using division method and quadratic probing

void HF3(int key, int table[][2]);
// Precondition: key is value from keys array, table is the hashtable
// Postcondition: adds key values to table by using division method and double hashing

int H2(int key);
// Precondition: key is value from keys array
// Postcondition: returns int of the key double hashed

int sumProbes(int table[][2]);
// Precondition: table is the hashtable
// Postcondition: returns a int of the number of probes


int main() {
    char command;
    int keys [50] = {1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299,
                  5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412,
                  5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589,
                  5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871,
                  5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523};


    do {
        print_menu();
        command = toupper(get_command());

        int table [50][2];
        for(int i = 0; i < 50; i++)
        {
            table[i][0] = -1;
        }

        for(int i = 0; i < 50; i++)
        {
            table[i][1] = 0;
        }

        cout << endl;

        switch(command) {
            case '0': // Do nothing..
                break;

            case '1':
                for(int i = 0; i < 50; i++)
                {
                    HF1(keys[i], table);
                }
                cout << "Index\t";
                cout << " Key\t";
                cout << " Probes\t" << endl;
                cout << "--------------------------" << endl;
                for(int j = 0; j < 50; j++)
                {
                    cout << "  " << j << "\t";
                    cout << table[j][0] << "\t";
                    cout << "  " << table[j][1] << "\t" << endl;
                }
                cout << "--------------------------" << endl;
                cout << endl;
                cout << "Sum of probe values = " << sumProbes(table) << " probes." << endl;
                cout << endl;
                break;

            case '2':
                for(int i = 0; i < 50; i++)
                {
                    HF2(keys[i], table);
                }
                cout << "Index\t";
                cout << " Key\t";
                cout << " Probes\t" << endl;
                cout << "--------------------------" << endl;
                for(int j = 0; j < 50; j++)
                {
                    cout << "  " << j << "\t";
                    cout << table[j][0] << "\t";
                    cout << "  " << table[j][1] << "\t" << endl;
                }
                cout << "--------------------------" << endl;
                cout << endl;
                cout << "Sum of probe values = " << sumProbes(table) << " probes." << endl;
                cout << endl;
                break;

            case '3':
                for(int i = 0; i < 50; i++)
                {
                    HF3(keys[i], table);
                }
                cout << endl;
                cout << "Index\t";
                cout << " Key\t";
                cout << " Probes\t" << endl;
                cout << "--------------------------" << endl;
                for(int j = 0; j < 50; j++)
                {
                    cout << "  " << j << "\t";
                    cout << table[j][0] << "\t";
                    cout << "  " << table[j][1] << "\t" << endl;
                }
                cout << "--------------------------" << endl;
                cout << endl;
                cout << "Sum of probe values = " << sumProbes(table) << " probes." << endl;
                cout << endl;
                break;

            default:
                cout << "Invalid command." << endl;
                break;
        }
    } while(command != '0');

    return (EXIT_SUCCESS);
}

void print_menu()
{
    cout << "----------------- MAIN MENU -----------------" << endl;
    cout << "0 - Exit Program" << endl;
    cout << "1 - Run HF1 (Division method with Linear Probing)" << endl;
    cout << "2 - Run HF2 (Division method with Quadratic Probing)" << endl;
    cout << "3 - Run HF3 (Division method with Double Hashing)" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

void HF1(int key, int table[][2])
{
    int placeFound = 0;

    int index = key % 50;

    if(table[index][0] == -1)
    {
        table[index][0] = key;
        table[index][1] = 0;
    }

    else
    {
        int check = ++index;
        int probe = 1;
        do {
            if(check == 50)
            {
                check = 0;
            }

            if(table[check][0] == -1)
            {
                table[check][0] = key;
                table[check][1] = probe;
                placeFound = 1;
            }
            else
            {
                check++;
                probe++;
            }
        }while(placeFound == 0);
    }
}

void HF2(int key, int table[][2])
{

    int index = key % 50;

    if(table[index][0] == -1)
    {
        table[index][0] = key;
        table[index][1] = 0;
    }

    else
    {
        int check;
        int probe = 1;

        for(int i = 1; i < 50; i++)
        {
            check = (index + (i*i)) % 50;
            if(table[check][0] == -1)
            {
                table[check][0] = key;
                table[check][1] = probe;
                break;
            }
            else
            {
                probe++;
            }
        }
    }
}

void HF3(int key, int table[][2])
{

    int index = key % 50;

    if(table[index][0] == -1)
    {
        table[index][0] = key;
        table[index][1] = 0;
    }

    else
    {
        int check;
        int probe = 0;
        int j = 0;
        int h = H2(key);
        for(int i = 0; i < 50; i++)
        {
            check = (index + i * h) % 50;

            if(table[check][0] == -1)
            {
                table[check][0] = key;
                table[check][1] = probe;
                j = 1;
                break;
            }
            else
            {
                probe++;
            }

        }

        if(j == 0)
        {
            cout << "Unable to hash key " << key << " to the table." << endl;
        }
    }
}

int H2(int key)
{
    return 30 - key % 25;
}

int sumProbes(int table[][2])
{
    int total = 0;
    for(int i = 0; i < 50; i++)
    {
        total += table[i][1];
    }
    return total;
}