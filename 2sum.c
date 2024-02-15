//316147016
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 10000
/**
 * @brief Structure to represent a value with its index.
 */
struct value_with_index
{
	/* data */
	int value;
	int index;
};
/**
 * @brief Comparison function for qsort.
 * This function is designed to be used as a comparison function for the qsort
 * function.
 * @param a Pointer to the first element.
 * @param b Pointer to the second element.
 * @return Negative value if the value of a is less than the value of b,
 * 0 if the values are equal, and positive value if the value of 
 * a is greater than the value of b.
 */
int compare_values(const void *a, const void *b);
/**
 * @brief Finds two numbers in an array that add up to a target value.
 * This function takes an array of integers and a target value as input,
 * and it prints the indices of two numbers in the array whose sum equals
 *  the target value.
 * @param nums The array of integers.
 * @param nums_size The size of the array.
 * @param target The target value.
 */
void twoSum(int nums[], int nums_size, int target);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;
	// Input target value
	scanf("%d", &target);
	// Input array values until the end of input
	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;
	// Find and print indices of two numbers in the array that add up to the 
	// target value
	twoSum(nums, array_size, target);

	return (0);
}

void twoSum(int nums[], int nums_size, int target) {
	/* YOUR CODE HERE */
	struct value_with_index nums_with_i[nums_size]; 
	int left = 0;
	int right = nums_size - 1;
	int current_sum;
	// Initialize nums_with_i array with values and indices
	for(int i=0;i<nums_size;i++) {
		nums_with_i[i].value = nums[i];
		nums_with_i[i].index = i;
	}
	// Sort nums_with_i array based on values
	qsort(nums_with_i, nums_size, sizeof(struct value_with_index), 
	compare_values);
	// Find two numbers in the sorted array that add up to the target value
	while (left < right){
		current_sum = nums_with_i[left].value + nums_with_i[right].value;
		if (current_sum == target) {
			printf ("(%d, %d)",nums_with_i[left].index
			,nums_with_i[right].index);
			return;
		}
		else if (current_sum < target) {
			left++;
		}
		else {
			right--;
		}

	}
}

int compare_values(const void *a, const void *b) {
    return ((struct value_with_index *)a)->value - 
	((struct value_with_index *)b)->value;
}
