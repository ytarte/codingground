#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// Program to generate all alphabet combinations for a given phone number.
// Ex. number "234" can generate ADG, AEG, AEF, etc.

// alphabets corresponding to each digit on the dialpad
char * dialpad[] = {"+", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", 
                    "TUV", "WXYZ"};
static int count = 0;

char get_alpha(int num, int i) {
    char alpha = '\0';
    if(num >= 0 && num <= 9 && i < strlen(dialpad[num])) {
        alpha = dialpad[num][i];
    }
    return alpha;
}

// Recursively generate different alphabets for each digit in the phone number
void print_combo_r(int * nums, int len, char * str, int index) {
    if(len == 1) {
        for(int i = 0; i < strlen(dialpad[nums[0]]); i++) {
            str[index] = get_alpha(nums[0], i);
            printf("%s\n", str);
            count++;
        }
        return;
    }
    
    for(int i = 0; i < strlen(dialpad[nums[0]]); i++) {
        str[index] = get_alpha(nums[0], i);
        print_combo_r(nums+1, len - 1, str, index + 1);
    }
}

void print_combo(int * nums, int len) {
    char str[len] = {0};
    
    print_combo_r(nums, len, str, 0);
}

int main()
{
   int ph[] = {2, 3, 4, 5, 5, 6, 9}; // phone number
   print_combo(ph, 7); 
   printf("count: %d\n", count); // number of combinations generated
   return 0;
}

