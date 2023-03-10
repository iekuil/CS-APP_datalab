/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  int not_y = ~y;
  int not_x = ~x;
  int a1 = x&not_y;
  int a2 = not_x & y;
  int not_a1 = ~a1;
  int not_a2 = ~a2;
  int a3 = not_a1 & not_a2;
  return ~a3;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1<<31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	int rev_x = ~x;
	volatile int tmp = rev_x;
	volatile int tmp1 = tmp + rev_x;
	int tmp2 = x + 1;
	int a1 = !tmp2;
	int a2 = !a1;
	int tmp3 = (!tmp1) & a2;
	//printf("x=%x,tmp=%x,tmp1=%x,res=%x\n\n",x,tmp,tmp1,tmp3);
	//printf("1\n");
	//printf("x=%x,res=%x\n\n",x,tmp3);
	return tmp3;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int x1 = x >> 16;
  int x2 = x & x1;
  int x3 = x2 >> 8;
  int x4 = x2 & x3 ;
  int x5 = x4 >> 4;
  int x6 = x4 & x5;
  int x7 = x6 >> 2;
  int x8 = x6 & x7;
  int x9 = x8 >> 1;
  return x9 & 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  int x1 = x >> 3;
  int x2 = x1 ^ 0x06;
  int x3 = x1 ^ 0x07;
  int x4 = x & 0x06;
  int not_x2 = !x2;
  int not_x3 = !x3;
  int not_x4 = !x4;
  int x5 = not_x3 & not_x4;
  return not_x2 | x5;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int a1 = !x;
  int a2 = ~a1;
  int a3 = a2+1;
  int a4 = ~ a3;
  int a5 = a4 & y;
  int a6 = ~ a4;
  int a7 = a6 & z;
  return a5 | a7;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int i = x >> 31;
  int j = y >> 31;
  int not_j = !j;
  int k = i & not_j;
  int l = i ^ j;
  int y_minus = ~y+1;
  int m = x + y_minus;
  int n = m >> 31;
  int not_l = !l;
  int not_m = !m;
  int tmp = not_m | n;
  int o = not_l & tmp;
  return k | o;
}

//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int i = x >> 16 | x;
  int j = i >> 8 | i;
  int k = j >> 4 | j;
  int l = k >> 2 | k;
  int m = l >> 1 | l;
  int n = m+1;
  return n&1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int mov = 0;
  int current = 16;

  int x1 = x >> current;
  int test = (!x1) | !(x1+1);
  int new = 8 ;
  int flag = test + ~1 + 1;
  //current = current + (~flag & new) | (flag& (~new+1));
  int tmp = (flag & new) | (~flag &(~new + 1));
  int tmp1 = current + tmp ;
  current = tmp1;

  x1 = x >> current;
  test = (!x1) | !(x1+1);
  new = 4 ; 
  flag = test + ~1 + 1;
  //current = current + (~flag & new) | (flag & (~new+1));
  tmp = (flag & new) | (~flag &(~new + 1));
  tmp1 = current + tmp ;
  current = tmp1;


  x1 = x >> current;
  test = (!x1) | !(x1+1);
  new = 2 ;
  flag = test + ~1 + 1 ;
  //current = current + (~flag & new) | (flag & (~new+1));
  tmp = (flag & new) | (~flag &(~new + 1));
  tmp1 = current + tmp ;
  current = tmp1;
  
  x1 = x >> current;
  test = (!x1) | !(x1+1);
  new = 1 ;
  flag = test + ~1 + 1;
  //current = current + (~flag & new) | (flag & (~new+1));
  tmp = (flag & new) | (~flag &(~new + 1));
  tmp1 = current + tmp ;
  current = tmp1;

  x1 = x >> current;
  //printf("final-current-value = %d\n",current);
  int test2 = (!x1) | !(x1+1);
  //new = 1 ;
  int flag2 = test2 + ~1 + 1;
  //printf("test2=%d,flag2=%d\n",test2,flag2);
  //current = current + (flag & (~new + 1));
  //tmp = (~flag & new); 
  //tmp1 = current + tmp ;
  //current = tmp1;
  
  tmp = flag2 & 1; 
  //printf("0/-1 flag = %d\n",tmp);
  int all_bit_same_flag = !((!x) | !(x+1));
  int res = current + tmp + (1 & all_bit_same_flag); 
  //tmp = res;
  //int i = ~(~!tmp+1);
  //int j = i & tmp;
  //int k = ~i & 1;
  //res = j | k;

  //printf("x=%d,res=%d\n\n",x,res);
  return res;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  unsigned int i = (uf&(~(1<<31)))>>23;
  unsigned int j = !(i^0xFF);

  if (j)
  {
    //printf("1.uf = %0x, res = %0x\n\n",uf,uf);
    return uf;
  }
  
  if (!i)
  {
    unsigned int k = uf << 1;
    unsigned int l = !k;
    if (l)
    {
      
      //printf("2.uf = %0x, res = %0x\n\n",uf,uf);
      return uf;
    }
    //printf("3.uf = %0x, res = %0x\n\n",uf,k+(uf&(1<<31)));
    return k + (uf & (1<<31));
  }
  i = i + 1;
  unsigned int m = !(i^0xFF);

  if (m)
  {
    //printf("4.uf = %0x, res = %0x\n\n",uf,(i<<23)+uf&(1<<31));
    return (i << 23) + (uf & (1<<31));
  }


  //printf("5.uf = %0x, res = %0x\n\n",uf,uf+(1<<23));
  return uf + (1<<23);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	unsigned sig_mask = 1 << 31;
	unsigned sig = (sig_mask) & uf;
	unsigned minus_bias = (~127)+1;
	unsigned exp = (uf & ~(sig_mask)) >> 23;
	unsigned E = exp + minus_bias ;
	if (E >> 31)
	{
	//	printf("1.uf=%x,res=0\n\n",uf);
		return 0;
	}
	unsigned minus_thirty = (~30) + 1;
	if ( !((E + minus_thirty) >> 31))
	{
	//	printf("2.uf=%x,res=0x80000000\n\n",uf);
		return 0x80000000u;
	}

	unsigned minus_23 = (~23) + 1;

	unsigned mask = ~((sig_mask) + (0xFF << 23));
	unsigned frac = (1<<23) + (uf & mask);
	unsigned res;
	unsigned E_less_than_23 = E + minus_23;
	if ( (E_less_than_23) >> 31)
	{
		unsigned dist = (~E_less_than_23)+1;
		res = frac >> dist;
	}
	else
	{
		unsigned dist = E_less_than_23;
		res = frac << dist;
	}
	if ( sig )
		res = (~res) + 1;
	//printf("3.uf=%x,res=%x\n\n",uf,res);	
	return res;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	int sig_x = x >> 31;
	
	if (!sig_x)
	{
		int range_x = x + (~127) ;
		if ( range_x >> 31 )
		{
			int res = ( x + 127 ) << 23 ;
			//printf("1.x=%d,res=%x\n\n",x,res);
			return res;
		}
		else
		{
			//printf("2.x=%d,res=%x\n\n",x,0xFF << 23);
			return 0xFF << 23;
		}
	}
	else
	{
		int abs_x = (~x) + 1;
		int comp_149 = 149 + (~abs_x) + 1;
		if (comp_149 >> 31)
		{
			//printf("3.x=%d,res=0\n\n",x);
			return 0;
		}
		int comp_126 = abs_x + (~126) + 1;
		if (comp_126 >> 31)
		{
			int E = 127 + x;
			//printf("4.x=%d,res=%x\n\n",x,E<<23);
			return E << 23;
		}
		else
		{
			int exp = 1 << 23;
			//printf("5.x=%d,res=%x\n\n",x,exp>>comp_126);
			return exp >> comp_126;
		}

	}


}
