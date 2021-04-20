// Name: Landon Brown
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include <iostream>
#include <stdlib.h>

// prompt user for commands for program
char get_command();

// prints meaningful menu
void printMenu();

// clear hash table
void clearTable(int Table[50][2]);

// print hash table
void printTable(int Table[50][2]);

// sum probes
int sumProbes(int Table[50][2]);

// linear probing hash
void HF1(int arr[], int Table[50][2]);

// quadratic probing hash
void HF2(int arr[], int Table[50][2]);

// double hashing
void HF3(int arr[], int Table[50][2]);

int main()
{

    int keys[] = {1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299, 5078, 8239, 1208, 5098, 5195, 5329, 4543, 3344, 7698, 5412, 5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589, 5439, 8907, 4097, 3096, 4310, 5298, 9156, 3895, 6673, 7871, 5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523};
    
    char command;
    int Table1[50][2];
    int Table2[50][2];
    int Table3[50][2];

    do {
        printMenu(); 
        command = toupper(get_command());

        switch(command) {
            case '1':
                std::cout << std::endl;
                HF1(keys, Table1);
                std::cout << "\nSum of probe values = " << sumProbes(Table1) << " probes." << std::endl;
            break;
            case '2':
                std::cout << std::endl;
                HF2(keys, Table2);
                std::cout << "\nSum of probe values = " << sumProbes(Table2) << " probes." << std::endl;
            break;
            case '3':
                std::cout << std::endl;
                HF3(keys, Table3);
                std::cout << "\nSum of probe values = " << sumProbes(Table3) << " probes." <<std::endl;
            break;
        }

    } while(command != 'Q');


    return 0;
}


void HF1(int arr[], int Table[50][2]) 
{
    int hash_val;
    int num_probes;

    // clear the table
    clearTable(Table);

    for(int i=0; i<50; i++) {
        num_probes = 0;
        hash_val = arr[i] % 50;
        while(Table[hash_val][0] != 0) {
            num_probes++;
            hash_val = (hash_val + 1) % 50;
        }

        Table[hash_val][0] = arr[i];
        Table[hash_val][1] = num_probes;
    }
    printTable(Table);
}

void HF2(int arr[], int Table[50][2])
{
    int hash_val;
    int num_probes;

    clearTable(Table);

    for(int i=0; i<50; i++) {
        num_probes = 0;
        hash_val = arr[i] % 50;
        while(Table[hash_val][0] != 0) {
            num_probes++;
            hash_val = (arr[i]%50 + (num_probes*num_probes)) % 50;
        }

        Table[hash_val][0] = arr[i];
        Table[hash_val][1] = num_probes;
    }
    printTable(Table);
}

void HF3(int arr[], int Table[50][2])
{
    int hash_val;
    int h2; // second hash
    int j;  // probe counter

    clearTable(Table);

    for(int i=0; i<50; i++) {
        hash_val = arr[i] % 50;
        if(Table[hash_val][0] == 0) {
            Table[hash_val][0] = arr[i];
        } else {
            // collision orrcured -> find second hash
            h2 = 30 - (arr[i]%25);
            for(j=0; j<=50; j++) {
                // double hashing
                hash_val = ((arr[i]%50) + (j*h2)) % 50;
                if(Table[hash_val][0] == 0) {
                    Table[hash_val][0] = arr[i];
                    Table[hash_val][1] = j;
                    break;
                } else if(j >= 50) {
                    std::cout <<"Uanble to hash key " << arr[i] << " to the table." << std::endl;
                }
            }
        }
    }
    std::cout << std::endl;
    printTable(Table);
}

void clearTable(int Table[50][2])
{
    for(int i=0; i<50; i++) {
        Table[i][0] = 0;
        Table[i][1] = 0;
    }
}

void printTable(int Table[50][2])
{
    std::cout << "  Index     Key     Probes  " << std::endl;
    std::cout << "---------------------------" << std::endl;
    for(int i=0; i<50; i++) {
        if(i < 10) {
        std::cout << "   " << i << "        " << Table[i][0] << "       " << Table[i][1] << std::endl;
        }
        else
            std::cout << "   " << i << "       " << Table[i][0] << "       " << Table[i][1] << std::endl;
    }
    std::cout << "---------------------------" << std::endl;
}

int sumProbes(int Table[50][2])
{
    int sum = 0;
    for(int i=0; i<50; i++) {
        sum += Table[i][1];
    }
    return sum;
}

// get command from user
char get_command()
{
    char command;

    std::cout << ">";
    std::cin >> command;
    std::cin.ignore();
    return toupper(command);
}

// menu of functions
void printMenu()
{
    std::cout << std::endl;
    std::cout << "-----MAIN MENU-----" << std::endl;
    std::cout << "1 - Run HF1 (Division method with Linear Probing" << std::endl; 
    std::cout << "2 - Run HF2 (Division method with Quadratic Probing" << std::endl; 
    std::cout << "3 - Run HF3 (Division method with Double Hashing" << std::endl; 
    std::cout << "Q - Quit program" << std::endl;
}

#if 0
void HF2(int arr[], int Table[50][2])
{
    int hash_val;
    int num_probes;
    int t;
    int j;

    clearTable(Table);

    for(int i=0; i<50; i++) {
        hash_val = arr[i] % 50;

        if(Table[hash_val][0] == 0) {
            Table[hash_val][0] = arr[i];
        } else {
            for(j=0; j<50; j++) {
                t = (hash_val + j*j)%50;
                if(Table[t][0] == 0) {
                    Table[t][0] = arr[i];
                    Table[t][1] = j;
                    break;
                }
            }
        }
    }
    printTable(Table);
}
#endif
#if 0
void HF3(int arr[], int Table[50][2])
{
    int hash_val;
    int h2; // second hash
    int probes;  // probe counter
    int t;

    clearTable(Table);

    for(int i=0; i<50; i++) {
        probes = 0;
        hash_val = arr[i] % 50;
        h2 = 30 - (arr[i]%25);
        while(Table[hash_val][0] != 0 && probes < 50) {
            probes++;
            hash_val = (arr[i]%50 + (probes*h2)) % 50;
        }
        if(probes >= 50) {
            std::cout <<"Uanble to hash key " << arr[i] << " to the table" << std::endl;
        } else {
            Table[hash_val][0] = arr[i];
            Table[hash_val][1] = probes;;
        }
    }
    printTable(Table);
}
#endif
