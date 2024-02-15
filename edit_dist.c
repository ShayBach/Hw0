#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100
/**
 * @brief Calculates the minimum of three integers.
 *
 * @param a First integer.
 * @param b Second integer.
 * @param c Third integer.
 * @return Minimum of the three integers.
 */
int min3(int a, int b, int c);
/**
 * @brief Calculates the minimum edit distance between two words.
 *
 * @param word1 First word.
 * @param word2 Second word.
 * @return Minimum edit distance between the two words.
 */
int edit_dist(char word1[], char word2[]);

int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));

	return (0);
}

int edit_dist(char word1[], char word2[]) {
	/* YOUR CODE HERE */
	int word1_len = strlen(word1);
	int word2_len = strlen(word2);
	int dist_arr[word1_len+1][word2_len+1];
	int last_char_dist;
	//if one of the strings is empty return the other's length
	if (word1_len == 0){
		return word2_len;
	}
	else if (word2_len == 0){
		return word1_len;
	}
	//initialize the array
	for (int i=0; i<=word1_len; i++){
		for (int j=0; j<=word2_len; j++){
			if (i == 0) {
				dist_arr[i][j] = j;
			}
			else if (j == 0) {
				dist_arr[i][j] = i;
			}
			else {
				dist_arr[i][j] = 0;
			}
		}
	}
	// Fill the array with minimum edit distance values
	for (int i=1; i<=word1_len; i++){
		for (int j=1; j<=word2_len; j++){
			//no addition to the distance since the chars are identical
			if (word1[i-1] == word2[j-1]) {
				dist_arr[i][j]	= dist_arr[i-1][j-1];
			}
			else {
				dist_arr[i][j] = 1 + min3(dist_arr[i-1][j], dist_arr[i][j-1],
				dist_arr[i-1][j-1]);
			}
		}
	}
	return dist_arr[word1_len][word2_len];
}

int min3(int a, int b, int c){
	if ((a <= b) && (a <= c)){
		return a;
	}
	else if ((b <= a) && (b <= c)){
		return b;
	}
	else {
		return c;
	}
}
