#include<stdio.h>
#include<stdlib.h>

void printset(int a[], int size);
void createbitstring();
void generatebit(int a[], int size, int bit[]);
int search(int a[], int size, int element);
void setunion(int a1[], int a2[]);
void setinter(int a1[], int a2[]);
void setdiff(int a1[], int a2[]);

int u[50], u_size = 0, A[20], A_size = 0, B[20], B_size = 0;
int bitA[50], bitB[50], bitunion[50], bitinter[50], bitdiff[50];

int main()
{
    int choice;

    printf("Enter the size of universal set:");
    scanf("%d", &u_size);

    printf("Enter the elements of universal set:");
    for (int i = 0; i < u_size; i++)
    {
        scanf("%d", &u[i]);
    }

    printf("Enter the size of set A:");
    scanf("%d", &A_size);

    printf("Enter the elements of set A:");
    for (int i = 0; i < A_size; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter the size of set B:");
    scanf("%d", &B_size);

    printf("Enter the elements of set B:");
    for (int i = 0; i < B_size; i++)
    {
        scanf("%d", &B[i]);
    }

    do
    {
        printf("\n1. Generate bit string");
        printf("\n2. Union");
        printf("\n3. Intersection");
        printf("\n4. Difference");
        printf("\n5. Print sets");
        printf("\n6. Exit");
        printf("\nEnter your choice:");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nGenerate bit string");
            createbitstring();
            break;

        case 2:
            printf("\nUnion");
            setunion(bitA, bitB);
            break;

        case 3:
            printf("\nIntersection");
            setinter(bitA, bitB);
            break;

        case 4:
            printf("\nDifference");
            setdiff(bitA, bitB);
            break;

        case 5:
            printf("\nPrint sets");
            printf("\nUniversal Set: ");
            printset(u, u_size);
            printf("\nSet A: ");
            printset(A, A_size);
            printf("\nSet B: ");
            printset(B, B_size);
            break;

        case 6:
            printf("\nExit");
            break;

        default:
            printf("\nEnter valid choice");
            break;
        }
    } while (choice != 6);

    return 0;
}

void printset(int a[], int size)
{
    printf("{");
    for (int i = 0; i < size; i++)
    {
        printf("%d", a[i]);
        if (i != size - 1)
        {
            printf(",");
        }
    }
    printf("}");
}

void createbitstring()
{
    for (int i = 0; i < u_size; i++)
    {
        bitA[i] = 0;
        bitB[i] = 0;
        bitunion[i] = 0;
        bitinter[i] = 0;
        bitdiff[i] = 0;
    }

    generatebit(A, A_size, bitA);
    generatebit(B, B_size, bitB);

    printf("BITSTRING REPRESENTATION OF A: ");
    printset(bitA, u_size);

    printf("BITSTRING REPRESENTATION OF B: ");
    printset(bitB, u_size);
}

    void generatebit(int a[], int size, int bit[])
{
    for (int i = 0; i < size; i++)
    {
        int pos = search(u, u_size, a[i]);
        if (pos >= 0)
        {
            bit[pos] = 1;
        }
    }
}

void setunion(int a1[], int a2[])
{
    for (int i = 0; i < u_size; i++)
    {
        bitunion[i] = a1[i] | a2[i];
        printf("%d", bitunion[i]);
    }
}
void setinter(int a1[], int a2[]) {
    for (int i = 0; i < u_size; i++) {
        bitinter[i] = a1[i] & a2[i];
        printf("%d", bitinter[i]);
    }
}

void setdiff(int a1[], int a2[])
{
    int i;
    for (i = 0; i < u_size; i++)
    {
        bitdiff[i] = a1[i] & (!a2[i]);
        printf("%d", bitdiff[i]);
    }
}
int search(int a[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            return i;
        }
    }
    return -1;
}



//      ---------------------------------ALGORITHM------------------------------------------------------------------------------------------------------------------------------
// This program implements set operations (union, intersection, and difference) using bit strings. The algorithm of this program is as follows:

// Declare and initialize necessary variables, including the universal set (u) and its size (u_size), sets A and B, their sizes (A_size and B_size), and bit strings for A, B, the union, intersection, and difference (bitA, bitB, bitunion, bitinter, and bitdiff).

// Read in the values for u, A, and B from the user.

// Enter a do-while loop that displays a menu of options for the user to choose from: generate bit string, union, intersection, difference, print sets, and exit.

// If the user selects "Generate bit string" (option 1), the program initializes the bit strings to all zeros and generates a bit string for sets A and B using the function generatebit. The bit strings are then printed.

// If the user selects "Union" (option 2), the program performs the union operation on the bit strings for sets A and B using the function setunion. The resulting bit string for the union is printed.

// If the user selects "Intersection" (option 3), the program performs the intersection operation on the bit strings for sets A and B using the function setinter. The resulting bit string for the intersection is printed.

// If the user selects "Difference" (option 4), the program performs the difference operation on the bit strings for sets A and B using the function setdiff. The resulting bit string for the difference is printed.

// If the user selects "Print sets" (option 5), the program prints out the values of the universal set, set A, and set B.

// If the user selects "Exit" (option 6), the program terminates.

// Functions used in this program include:

// printset: prints the contents of a set
// createbitstring: initializes the bit strings to all zeros and generates a bit string for a set using generatebit
// generatebit: generates a bit string for a set by setting the corresponding bits to 1
// setunion: performs the union operation on two bit strings and prints the resulting bit string
// setinter: performs the intersection operation on two bit strings and prints the resulting bit string
// setdiff: performs the difference operation on two bit strings and prints the resulting bit string
// search: searches for an element in a set and returns its position in the array.





//----------------    OUTPUT   -----------------------------------------------------------------------------------------------

// Enter the size of universal set:6
// Enter the elements of universal set:0 1 2 3 4 5
// Enter the size of set A:2
// Enter the elements of set A:4
// 5
// Enter the size of set B:3
// Enter the elements of set B:4
// 5
// 2

// 1. Generate bit string
// 2. Union
// 3. Intersection
// 4. Difference
// 5. Print sets
// 6. Exit
// Enter your choice:1

// Generate bit stringBITSTRING REPRESENTATION OF A: {0,0,0,0,1,1}BITSTRING REPRESENTATION OF B: {0,0,1,0,1,1}       
// 1. Generate bit string
// 2. Union
// 3. Intersection
// 4. Difference
// 5. Print sets
// 6. Exit
// Enter your choice:2 

// Union001011
// 1. Generate bit string
// 2. Union
// 3. Intersection
// 4. Difference
// 5. Print sets
// 6. Exit
// Enter your choice:3

// Intersection000011
// 1. Generate bit string
// 2. Union
// 3. Intersection
// 4. Difference
// 5. Print sets
// 6. Exit
// Enter your choice:4
// Enter your choice:5

// Print sets
// Universal Set: {0,1,2,3,4,5}
// Set A: {4,5}
// Set B: {4,5,2}
// 1. Generate bit string
// 2. Union
// 3. Intersection
// 4. Difference
// 5. Print sets
// 6. Exit
// Enter your choice:6

// Exit
