************************************************
Gia Vinh Lam             0925571
CIS3490                  A3
07/03/2017               glam01@mail.uoguelph.ca
************************************************

***********
Compilation
***********
Assuming that you are in the main folder's directory in the terminal:
make

******************
Running and Usage
******************
Assuming that you are in the main folder's directory in the terminal:
./main data_4.txt data_5.txt
(second and third part are the input files (arguments) for the program)

************************
How the Program(s) Works
************************
After running the main file, you will be given a menu where you have three choices.
If you enter 1, the program will prompt for a string and find any anagrams of it in the first data file using
both a brute force method (P11.c) and a presort method (P12.c). 
It'll list the anagrams found, the number of anagrams found, and the execution times of each method in milliseconds.

If 2 is entered, the program will prompt for a pattern (string to search for) in the second data file. It'll calculate this using three different methods: brute force, Horspool's algorithm, and Boyer Moore's algorithm. It'll return the total number of string matches in the text, number of pattern shifts, and the execution times of each method in milliseconds.

*********************************************
Comments on Execution Times + Analysis Stuff
**********************************************
You will notice that the execution time of the brute force approach for obtaining anagrams is faster than that of the presort. I feel like the reason why is because the brute force approach I implemented was quite efficient despite being brute force. It only had one big for loop where the upper bound was n and then other smaller for loops; so it's certainly better than O(n^2). In addition, even though I used efficient sorting algorithms for the presort (quicksort -> nlogn average case and binary search to find the values in the sorted array), I believe the number of steps that had to be taken to prepare the sorted array is what ultimately made it take longer to execute than the brute force. Though they are both still very fast algorithms, when searching for anagrams of 1214790563, the brute force method computes it in 7 ms and the presort method computes it in 21 ms.

Comparison and Analysis:
I was unable to finish the bonus Boyer Moore's code, but in regards to comparing at least Horspool's and the Brute Force goes as follows:
Ten different search patterns:
1. characteristics
2. ifo
3. training
4. student
5. forth
6. qt
7. Training
8. booperbop
9. statistical
10. randomsuperduperlongstring

Define performance ratio as: Execution time of Brute Force / Execution time of Horspool. Thus, if the performance ratio is > 1, Horspool's Algorithm was faster.

Results of search pattern 1:
Brute Force: 12ms
Horspool: 7ms
Performance ratio: 1.714


Results of search pattern 2:
Brute Force: 16ms
Horspool: 29ms
Performance ratio: 0.552


Results of search pattern 3:
Brute Force: 31ms
Horspool: 12ms
Performance ratio: 2.583


Results of search pattern 4:
Brute Force: 15ms
Horspool: 15ms
Performance ratio: 1.000


Results of search pattern 5:
Brute Force: 13ms
Horspool: 18ms
Performance ratio: 0.722


Results of search pattern 6:
Brute Force: 13ms
Horspool: 40ms
Performance ratio: 0.325


Results of search pattern 7:
Brute Force: 32ms
Horspool: 12ms
Performance ratio: 2.667


Results of search pattern 8:
Brute Force: 37ms
Horspool: 22ms
Performance ratio: 1.682


Results of search pattern 9:
Brute Force: 13ms
Horspool: 9ms
Performance ratio: 1.444


Results of search pattern 10:
Brute Force: 16ms
Horspool: 7ms
Performance ratio: 2.286

Average ratio (summation of all performance ratios divided by 10): (1.714 + 0.552 + 2.583 + 1.000 + 0.722 + 0.325 + 2.667 + 1.682 + 1.444 + 2.286)/10
Average ratio: 1.5

What this ratio tells us is that on average, Horspool's algorithm performs better then brute force, as expected.
However from some of the results above, where the ratios are < 1, we can see that this is not always the case and that Horspool's method is sometimes longer.

For small cases like the word "ifo", the Brute Force method executes faster (ex. ~16 ms vs. ~29 ms of the Horspool Method).
But for bigger words like the word "characteristics", the Horspool Method is faster (~7ms for Horspool, ~12ms for Brute Force).
It makes sense that for a word such as "characteristics" Horspool would faster as the longer the pattern, the more pattern shifts we can effectively
skip using Horspool's Algorithm. On the other hand, the word "ifo" would not be as big of a difference in pattern shifts b/n Horspool and Brute Force and due to the preprocessing of the Horspool Algorithm, the overall time is longer in this case. 
If the file was bigger as well, we would see better efficiency in the Horspool algorithm as the difference b/n pattern shifts of the brute force and Horspool method would be larger.

*********************************
Known Limitations or Assumptions
*********************************
My array sizes will limit certain data files if they're very large (ex. in the first problem, if the data file contained 200000 integers).
Defensive programming is not implemented, therefore the program will not work as intended if the user enters a string instead of an integer at the beginning of the program.
Assumes format from each data file will remain the same and the general sizes are the same (otherwise, amount of memory allocated will not be enough if it's bigger).
