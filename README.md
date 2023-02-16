# PUSH_SWAP

### Objectives : 
	* You have to sort in ascending order (lower at the top of A) a list of number with certain type of instruction
	* With the less instruction as possible

### Overview :
	* You have two stacks (A and B)
	* You can push the top of each one to the other one
	* You can rotate up (first become last) each elem of A or B
	* You can rotate down (last become first) each elem of A or B

### Method :
	* So i check all elems to find the median value
	* Then pushing all elem lower than the median value
	* Then all elem greater than the median value
	* So in A, max, min and median
	* And in B, half top greater than median value half bottom lower than median value
	* The ideas of sorting is the insert sort
	* I will check how many instructions to each elems of B to be moved to the right place in A
	* Then moving the lower cost elems in B to A
	* Again Again and Again

