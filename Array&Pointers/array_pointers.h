#ifndef  __ARRAY_POINTERS_H__
#define __ARRAY_POINTERS_H__

//recieves a matrix and calculates the sum of each row, sums of rows should be saved in result array, passed by user, return 0 if successful.
int MtxSum(int row, int col, const int matrix [row][col], int arr[row]);
//calculate last man standing position in josephus game.
int Lucky(int num);
//prints to stdout sizes of all data types
int DTypeNames();
//copies all the envirnoment variables into char** buffer in lower case, and prints them
//int PrintEnv();

#endif
