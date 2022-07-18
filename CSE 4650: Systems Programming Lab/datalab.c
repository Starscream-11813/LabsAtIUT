/* 
 * Courtesy of CMU ICS Course and CS:APP authors
 * 
 * Syed Rifat Raiyan 180041205
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 */


#endif
//1. Bit Manipulations
/*
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	/*
	Derivation:
	x&y 
	= ~(~(x&y)) 
	= ~(~x|~y) [De Morgan's Law]
	*/
	int res = ~((~x) | (~y));
    return res;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	/*
	1) Shift 0b11111111 by 8*n bit positions to the left. [Since, n<<3 == n*pow(2,3) == n*8]
	2) Perform AND with x. This will filter out the 8 bits of the nth byte from the left.
	3) Shift the filtered value 8*n bit positions to the right.
	4) Now, due to arithmetic right shifting, if MSB is 1, it is preserved. To truncate these leading 1s in the 1st 24 bits, perform AND with 0b11111111 again.
	*/
	int res = ((x & (0xff << (n << 3))) >> (n << 3)) & 0xff;
    return res;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	/*
	The goal here is to remove any leading 1s that might manifest due to arithmetic right shifting.
	1) At first, take 1 and shift it to the leftmost(31st) bit position to make 0b1000...0000.
	2) Now, shift it to the right by n bit positions. This will make the 1st n bits 1 and the rest 32-n bits 0.
	3) Perform NOT to flip all the bits. This will make the 1st n bits 0 and the rest 32-n bits 1.
	4) Now, perform right shift on x by n bit positions.
	5) Perform AND operation between this value and the mask created after Step-3. This will remove all the leading 1s that might appear in the 1st n bit positions.
	*/
	int res = (x >> n) & (~(((1 << 31) >> n) << 1));
    return res;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	/*
	The goal here is to bring check if x is zero or non-zero.
	For any value x != 0, x | (-x) will always yield 1 in the MSB. Contrarily, if x == 0, then, the MSB will be 0 due to overflow of 1.
	We can capitalize on this property of 0.
	1) Determine the 2s complement of x. This can be interpreted as -x.
	2) Perform OR operation between x and -x.
	3) Shift the result by 31 bit positions to the right. Due to arithmetic shifting, the MSB will be preserved. 
	   In case of non-zero values if x, all bits will be 1 and if x == 0, then all the bits will be 0.
	4) Now, add 1 to this result. We know, if all the bits are 1, then the value is -1.
	   So, for non-zero values, (-1) + 1 = 0. And for x == 0, 0 + 1 = 1.
	*/
	int res = ((x | ((~x) + 1)) >> 31) + 1;
    return res;
}

//2. Two’s Complement Arithmetic
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	/*
	The lowest value that can be represented in 32-bit signed integer format is -2147483648 when the MSB or sign-bit is set to 1 and the rest of the bits are 0.
	1) Take 1 and shift it 31 bit positions to the left thus setting the MSB to 1.
	*/
	int res = 1 << 31;
    return res;
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	/*
	The negative of a number in signed binary representation is the 2s complement of that number.
	1) Perform NOT operation on x to invert its bits.
	2) Add 1 to the result.
	*/
	int res = (~x) + 1;
    return res;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	/*
	The goal here is to check if the MSB of x is set to 1, which implies that x is negative, or if x == 0.
	1) At first, take 1 and shift it 31 bit positions to the left.
	2) Perform AND operation with x.
	3) Then, shift the result 31 bit positions to the right thus bringing the MSB to the LSB's position.
	4) Then, perform AND operation with 1 to remove any leading 1s.
	   If the result is 1, we can be sure that x's MSB is set to 1, which means it is a negative number.
	5) Perform NOT on x to check if x == 0. It will return 0 if x>0 or if x<0.
	6) Perform OR between !x and the value obtained after Step-4. This will return 1 if x <= 0.
	7) Perform NOT on the result to get the desired opposite output.
	A simplified expression can be written as, res = !(a | !b), where a = bool(x < 0), and b = bool(x != 0).
	Overall, if x == 0 then the 1st portion of the OR operation will yield 0 and the 2nd portion will yield 1, and !(0 | 1) = 0.
	If x < 0, the 1st portion of the OR operation will yield 1 and the 2nd portion will yield 0, and !(1 | 0) = 0.
	If x > 0, the 1st portion of the OR operation will yield 0 and the 2nd portion will also yield 0, and !(0 | 0) = 0.
	*/
	int res = !(((((x & (1 << 31)) >> 31) & 1)) | (!x));
    return res;
}
