//
// Created by Tyler Franklin on 11/21/24.
//
#include <iostream>
#include <sys/time.h>

using namespace std;

//Function to calculate GCD and count number of modulus operations
int Gcd(int a, int b, int& count){
    //Set count to 0
    count = 0;
    //Initialize variable for remainder
    int r;
    //Loop until remainder is 0
    while((a % b) > 0){
        r = a % b;
        a = b;
        b = r;
        count++;
    }
    return b;
}

int main() {

    //Initialize n and get input for value of n
    int n;
    cout << "Set integer n larger than 8: ";
    //Read int n and ensure n is greater than 8
    while(!(cin >> n) || n <= 8) {
        cout << "\nNot larger than 8, try again: ";
    }
    //starting time
    struct timeval start, end;
    gettimeofday(&start, NULL);

    //From each i from 8 until n
    for(int i = 8; i <= n; i++){


        //Initialize variables to hold the value of a and b that needed the most operations
        int max_modulus = 0;
        int max_a = 0, max_b = 0;
        int max_gcd = 0;
        //For each b from 8 until i
        for(int b = 1; b <= i; b++){
            //For each a from 1 until b
            for(int a = 1; a <= b; a++){
                int count;
                //Calculate GCD for a and b, count number of modulus operations
                int curr_gcd = Gcd(a, b, count);
                //
                if(count > max_modulus){
                    max_modulus = count;
                    max_a = a;
                    max_b = b;
                    max_gcd = curr_gcd;
                }
            }
        }
        //end time
        gettimeofday(&end, NULL);
        double duration = (end.tv_usec - start.tv_usec);

        //Print each maximum modulus operations at corresponding a and b for each i
        cout << "At i=" << i << "; gcd(" << max_a << ", " << max_b << ") = " << max_gcd << " took " << max_modulus << " modulus operations. Elapsed time: " << duration << "ms" << endl;
    }
    return 0;
}
