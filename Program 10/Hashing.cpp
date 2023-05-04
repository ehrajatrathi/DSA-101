#include<stdio.h>
#include<stdlib.h>

int table[10];

void insert_val(int val){
	int mod_val = val % 10;
	if(table[mod_val] == -1){
		table[mod_val] = val;
		printf("%d inserted at index %d", val, mod_val);
	}
	else{
		int size = 1, flag = 0;
		while(size < 10){
			int x = (mod_val + size) % 10;
			if(table [x] == -1){
				printf("%d inserted at index %d", val, x);
				table[x] = val;
				flag = 1;
				break;
			}
			size++;
		}
		if( flag == 0)
			printf("Table at capacity!!");
	}
}

void search_val(int val){
	int mod_val = val % 10;
	if(table[mod_val] == val)
		printf("Value found at index %d", mod_val);
	else{
		int size = 1, flag = 0;
		while(size<10){
			int x = (mod_val + size) % 10;
			if(table[x] == val){
				printf("Value found at index %d", x);
				flag = 1;
				break;
			}
			size++;				
		}
		if(flag == 0)
			printf("Value not found!!");
	}
}

int main(){
	int i, choice, val;
	
	for(i = 0; i<10; i++){
		table[i] = -1;
	}
	
	printf("----------Hash Program-----------\n\n");
	
	while(1){
		printf("\n1. Insert \t 2.Search\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:		printf("Enter value to Insert: ");
						scanf("%d", &val);
						insert_val(val);
						break;
							
			case 2: 	printf("Etner value to Search: ");
						scanf("%d", &val);
						search_val(val);
						break;
						
			case 3:		for(i = 0 ;i<10; i++)
							printf("%d-",table[i]);
						
			default:	printf("Wrong Input! ");
						break;
		}
	}
}
