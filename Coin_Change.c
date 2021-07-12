// A Dynamic Programming based C++ program to find minimum of coins 
// to make a given change V 
#include<stdio.h> 
#define INT_MAX 9999

// m is size of coins array (number of different coins) 
int minCoins(int coins[], int m, int V) 
{ 
	// table[i] will be storing the minimum number of coins 
	// required for i value. So table[V] will have result 
	int table[V+1],i,j; 

	// Base case (If given value V is 0) 
	table[0] = 0; 

	// Initialize all table values as Infinite 
	for ( i=1; i<=V; i++) 
		table[i] = INT_MAX; 

	// Compute minimum coins required for all 
	// values from 1 to V 
	for (i=1; i<=V; i++) 
	{ 
		// Go through all coins smaller than i 
		for ( j=0; j<m; j++) 
		if (coins[j] <= i) 
		{ 
			int sub_res = table[i-coins[j]]; 
			if (sub_res != INT_MAX && sub_res + 1 < table[i]) 
				table[i] = sub_res + 1; 
		} 
	} 
	return table[V]; 
} 

// Driver program to test above function 
int main() 
{ 
    int ans;
    int V,m,coins[10],k,num;
    printf("Enter total number coins: ");
    scanf("%d",&num);
    printf("Enter values of %d coins: ",num);
    for(k=0;k<num;k++){
        scanf("%d",&coins[k]);
    }
    printf("Coins: {");
	for(k=0;k<num;k++){
        printf("%d,",coins[k]);
    }	
	printf("}");
	// int coins[] = {9, 6, 5, 1}; 
	m = sizeof(coins)/sizeof(coins[0]); 
    printf("\nTotal change that you want: ");
    scanf("%d",&V);
	// int V = 11; 
    ans=minCoins(coins,m,V);
    printf("Minimum coins requires is %d",ans);

	return 0; 
} 
