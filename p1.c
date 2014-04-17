/* Name : Dilan Samarasinghe
   Lab : Firday 11:30
*/

#include <stdio.h>
int main(void)
{
  #define BINARY_DEVISOR 2
  #define SIZE 31 //size of the array
  int number, remainder; // store the input and the remainder
  int maxBlockLength, numberOfOnes; // stores the maximum length of blocks and the number of ones
  int i,j,count,flag; // temp variables
  int binaryArray[SIZE]; // stores the 31 bit binary
  // intialize the array storing binary values to all zeroes
  for(i = 0; i <SIZE;i++)
    {
      binaryArray[i]= 0;
    }
  printf("Please enter the interger number: ");
  fflush(stdout);
  scanf("%i",&number);
  if(number < 0) // checks to see if the input is negative and ends if it is
    {
      printf("Input value is negative. \n");
      fflush(stdout);
	return 0;
    }
  else
    {
      int index = SIZE-1;
      /* As long as the value being devided is greater than zero, keep deviding it by 2 to get the remainder and store the new divided number as the value, if the value is 1 then set the remainder to 1 and the value to zero thus ending the loop.Store the remainder value in the array starting from the last index, which is SIZE -1.
       */

      while(number >0)
	{
	  
	  if( number == 1)
	    {
	      remainder = 1;
	      number = 0;
	    }
	  else
	    {
	      remainder = number % BINARY_DEVISOR;
	      number = number /BINARY_DEVISOR;
	    }
	  binaryArray[index] = remainder;
	  index--;
	}
     
    }//Iterate the index by one until a non zero number is found.This is used in all for loops after this.  
  while(binaryArray[j] != 1)
    {
      j++;
    }
  numberOfOnes = 0;
  //calculate number of ones by searching for ones and adding one to numberOfOnes each time.
  for(i = j; i < SIZE;i++)
    {
      if(binaryArray[i] == 1)
	{
	  numberOfOnes++;
	}
     
    }
  maxBlockLength = 0;
  flag = 0; // a flag of 0 indicates there are no ones
  // This for loop will make flag equal to 1 as well as increment count each time a 1 is found in the array.
  for(i = j; i <SIZE; i++)
    {
      if(binaryArray[i] == 1)
	  {
	    flag = 1;
	    count++;
	  }
	 // this else means we have reached a border of a 1 and a 0, now we check if the count weve been increasing is higher than the block length we already have
	 else
	  {
	    if(flag == 1)
	      {
		if(count > maxBlockLength)
		  {
		    maxBlockLength = count;
		  }
	      }
	    count = 0;
	    flag = 0;
	  }
     
    }
  // this nested if statement is there incase the last digit in the array is a 1, if it is we do the same thing as the previous if statement as long as the flag is a 1 this indicates the array doesnt contain all zeroes. If the flag is zero then the array has no 1s.
  if(count > 0 && flag == 1)
    {
      if(count > maxBlockLength)
	{
	  maxBlockLength = count;
	  count = 0;
	  flag =0;
	}
    }
  printf("The binary representation of the given value is: ");
  fflush(stdout);
  // print the array starting with the first non zero number with the help of the variable j we calculated earlier.
  for(i = j;i < SIZE;i++){
    printf("%i", binaryArray[i]);
    fflush(stdout);
  }
  printf("\nThe number of ones in the binary representation is:  ");
  fflush(stdout);
  printf("%i \n", numberOfOnes);
  fflush(stdout);
  printf("Maximum block length is: ");
  fflush(stdout);
  printf("%i \n", maxBlockLength);
  fflush(stdout);
  return 0;
}

