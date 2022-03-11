/*
Name: Mian Aizaz Tahir
SID: 1662795
CCID: matahir
CMPUT 275, Winter 2022

Weekly exersise #2: idols
*/

#include <iostream>
using namespace std;

/*
Description : Swaps the values contained inside of two pointers. 

Arguments :
begin: integer pointer that points to the first element of the array you want to swap.
end: integer pointer that points to the later element of the array you want to swap.
*/
void swap(int* begin, int* end) {

    int temp = *begin;
    *begin = *end;
    *end = temp;
}

/*
Description : Reverses the order of a given array

Arguments :
begin: integer pointer that points to the start of the array you want to reverse.
end: integer pointer that points to the end of the array you want to reverse.
*/
void reverse(int* begin, int* end) {

    while (begin < end) {
        swap(begin, end);
        begin++;
        end--;
    }
}

/*
Description : Determines the maximum value of a given array.

Arguments :
start: integer pointer that points to the start of the array you want to find the maximum of.
end: integer pointer that points to the end of the array you want to find the maximum of.

Returns :
maxIndex: A pointer that points to the maximum value of the array.
*/
int *maxVal(int* start, int* end) {

    int current_max = 0, length, *maxIndex;
    length = end - start;
    for (int i = 0; i < length; i++) {
        if (*(start + i) >= current_max) {
            current_max = *(start + i);
            maxIndex = (start + i);
        }  
    }  
    return maxIndex;
}

int main() {
    // Taking in the input from the user
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Start of process to find the idols
    int i = 0, idol_num = 0, *idolPtr;
    int idols[n], indicies[n];
    
    while (i < n) {
        idolPtr = maxVal(array + i, array + n);
        i = idolPtr - array; 
        indicies[idol_num] = i;
        i++;
        idols[idol_num] = *idolPtr;
        idol_num++;
    }
    // End of process to find idols

    // Printing the idols out to stdout
    for (int i = 0; i < (idol_num - 1); i++) {
        cout << idols[i] << " "; 
    }
    cout << idols[idol_num - 1];
    cout << endl;

    // Reversing the first group
    if (indicies[0] > 1) {
        reverse(array, array + indicies[0] - 1);
    }
    
    // Reversing all groups formed between idols
    for (int i = 0; i < (idol_num - 1); i++) {
        if ((indicies[i+1] - indicies[i]) > 2) {
            reverse(array + indicies[i] + 1, array + (indicies[i+1] - 1));
        }
    }
    // Printing the partially reveresed array 
    for (int i = 0; i < (n-1); i++) {
        cout << array[i] << " "; 
    }
    cout << array[n-1];
    cout << endl;
    
    return 0;
}