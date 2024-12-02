/*---------/ Information:

Author: Joel Stephan and Pietro Vannucchi
Version: 0

/------------------------*/
/*---------/ Text:
Store management system:
Create a management system for a store that uses a linked list to keep track of items in stock. Each node of the list should represent a product and contain information such as code, description, price, and available quantity. Implement functions to add new products, update quantities in stock, and generate invoices for purchases.
/---------*/


//---------/*	Libraries:

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

//-------------------------/

//---------/*	Defines:
#define MAX_NAME 20+1 // assume 20 characters as the maximum length of the array (+1 for the null terminator)
#define MAX_CODE 13+1 // assume 13 characters as the maximum length for the code (+1..)
#define MAX_DESCRIPTION 100+1 // choose 100 characters as the maximum length of the description (+1..)
#define NAME_FILE "products.txt"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
//----------------------------------/

//---------/*	Structs:
typedef struct node{
	char name[MAX_NAME];
	char code[MAX_CODE];
	char description[MAX_DESCRIPTION];
	float price;
	int quantity;
	struct node *next;
} Product;

//----------------------------------/

//---------/*	Functions:
FILE *open_file (FILE *file, char *fileName, char *mode){
	file=fopen(fileName, mode);
    if (file==NULL){					    
        printf("ERROR: Invalid file opening.\n");
        exit(-1);
    }
	return file;
}

void close_file(FILE *file){
	if(fclose(file)!=0) {
        printf("ERROR: Invalid file closing.\n");
        exit(-2);
    }
    return;
}

void startup_input(char *fileName, Product** list){
    FILE* file = open_file(NULL, fileName, "r");

    int flag = 0; // Use a variable to manage the exit condition

    while (!flag) {
        Product* newProduct = (Product*)malloc(sizeof(Product));

        if (newProduct == NULL) {
            printf("ERROR: Invalid memory allocation.\n");
            fclose(file);
            exit(-1);
        }

        if (fscanf(file, "%s %s %s %f %d", newProduct->name, newProduct->code, newProduct->description, &newProduct->price, &newProduct->quantity) == EOF) {
            free(newProduct);
            flag = 1; // Set to 1 to exit the loop
        }
        else {
            newProduct->next = NULL; // Initialize the 'next' field of the new product

            if (*list == NULL) {
                // If the list is empty, the new product becomes the first element
                *list = newProduct;
            } else {
                // Otherwise, find the last element and add the new product at the end
                Product* last = *list;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = newProduct;
            }
        }
    }

    return;
}


void print_product(Product *product){
	
    // Print product information
    printf("Name: %s\n", product->name);
    printf("Code: %s\n", product->code);
    printf("Description: %s\n", product->description);
    printf("Price: %.2f\n", product->price);
    printf("Quantity: %d\n", product->quantity);
    printf("-------------------------\n");
    
    return;
}

void print_list(Product *list){
    // Check if the list is empty
    if (list == NULL){
        printf("The list is empty.\n");
        exit(-2);
    }

    // Iterate through the list and print each product
    Product *current = list;
    while (list != NULL){
        print_product(list);
        // Move to the next item in the list
        list = list->next;
    }
    
    system("PAUSE");
	system("CLS");
    return;
}

// Function to check if a code is already present in the list
int code_present(Product *list, char *code){
	int flag = 0; // Code not present
	
    while (list != NULL) {
        if (strcmp(list->code, code) == 0) {
            flag = 1; // Code already present
        }
        list = list->next;
    }
    return flag; 
}

// Function to get a valid price (greater than or equal to zero)
float valid_price_input(){
    float price;
    do {
        printf("Enter the price of the new product (must be greater than or equal to zero): ");
        scanf("%f", &price);
        if (price < 0) {
            printf("ERROR: Price must be greater than or equal to zero.\n");
        }
    } while (price < 0);
    return price;
}

// Function to get a valid quantity (greater than or equal to zero)
int valid_quantity_input(){
    int quantity;
    do {
        printf("Enter the quantity of the new product (must be greater than or equal to zero): ");
        scanf("%d", &quantity);
        if (quantity < 0) {
            printf("ERROR: Quantity must be greater than or equal to zero.\n");
        }
    } while (quantity < 0);
    return quantity;
}

void add_product(Product **list){
    // Memory allocation for a new product
    Product* newProduct = (Product*)malloc(sizeof(Product));

    if (newProduct == NULL) {
        printf("ERROR: Invalid memory allocation.\n");
        exit(-1);
    }

    // Input data for the new product
    printf("Enter the name of the new product: ");
    scanf("%s", newProduct->name);

    // Input of the code of the new product with control on the presence
    do {
        printf("Enter the code of the new product: ");
        scanf("%s", newProduct->code);
        
        if (code_present(*list, newProduct->code)) {
            printf("ERROR: The entered code is already present. Enter a new one.\n");
        }
        
    } while (code_present(*list, newProduct->code));

    printf("Enter the description of the new product: ");
    scanf("%s", newProduct->description);

    // Input of the price of the new product with control on validity
    newProduct->price = valid_price_input();

    // Input of the quantity of the new product with control on validity
    newProduct->quantity = valid_quantity_input();

    // Initialization of the 'next' field of the new product
    newProduct->next = NULL;

    // Add the new product to the list
    if (*list == NULL) {
        // If the list is empty, the new product becomes the first element
        *list = newProduct;
    } else {
        // Otherwise, find the last element and add the new product at the end
        Product* last = *list;
        while (last->next != NULL) {
           

 last = last->next;
        }
        last->next = newProduct;
    }

    printf("Product added successfully!\n");
    
    system("PAUSE");
	system("CLS");
	return;
}

void save_to_file(char *fileName, Product *list){
    FILE* file = open_file(NULL, fileName, "w");

    // Write each product to the file
    while (list != NULL) {
        fprintf(file, "%s %s %s %.2f %d\n", list->name, list->code, list->description, list->price, list->quantity);
        list = list->next;
    }

    // Close the file after writing all the products
    close_file(file);
    
    return;
}

void update_quantity(Product *list) {
    char code[MAX_CODE];
    int new_quantity;
    int product_found = 0;  // Flag indicating whether the product has been found

    // Check if the list is empty
    if (list == NULL) {
        printf("The list is empty.\n");
        exit(-2);
    }

    // Input the code of the product to update
    printf("Enter the code of the product to update: ");
    scanf("%s", code);

    // Search for the product with the corresponding code in the list
    Product* product = list;
    while (product != NULL) {
        if (strcmp(product->code, code) == 0) {
            // Found the product, ask for the new quantity
            printf("Enter the new quantity for product %s: ", code);
            scanf("%d", &new_quantity);

            // Update the quantity
            product->quantity = new_quantity;

            printf("Quantity updated successfully!\n");
            product_found = 1;  // Set the flag to true
        }

        // Move to the next item in the list
        product = product->next;
    }

    // If no product has been found, print an error message
    if (!product_found) {
        printf("Product not found.\n");
    }
 
    system("PAUSE");
	system("CLS");
    return;
}

void search_product(Product *list) {
	char code_to_search[MAX_CODE];	
	int found = 0;  // Flag indicating whether the product has been found
	
    // Check if the list is empty
    if (list == NULL) {
        printf("The list is empty.\n");
        exit(-2);
    }

    // Input the code of the product to search for
    printf("Enter the code of the product to search for: ");
    scanf("%s", code_to_search);

    // Search for the product with the corresponding code in the list
    Product* found_product = list;

    while (found_product != NULL) {
        if (strcmp(found_product->code, code_to_search) == 0) {
        	
            // Found the product, print the information
            printf("Product found:\n");
            print_product(found_product);
            found = 1;  // Set the flag to true
        }

        // Move to the next item in the list
        found_product = found_product->next;
    }

    // If no product has been found, print an error message
    if (!found) {
        printf("No product found with code %s.\n", code_to_search);
	}
	
    system("PAUSE");
    system("CLS");
    return;
}

void generate_invoice(Product *list) {
    char purchase_code[MAX_CODE];
    int purchase_quantity;
    float total;

    // Check if the list is empty
    if (list == NULL) {
        printf("The list of products is empty. Unable to generate the invoice.\n");
        exit(-2);
    }

    // Print the list of available products
    printf("Available products:\n");
    print_list(list);

    // Input the code of the product to purchase
    printf("Enter the code of the product you want to purchase: ");
    scanf("%s", purchase_code);

    // Search for the product in the list
    Product* purchased_product = list;
    while (purchased_product != NULL && strcmp(purchased_product->code, purchase_code) != 0) {
        purchased_product = purchased_product->next;
    }

    // Check if the product has been found
    if (purchased_product == NULL){
        printf("The product with code %s is not available.\n", purchase_code);
        
    } else {
        // Input the quantity to purchase
        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &purchase_quantity);

        // Check if the available quantity is sufficient
        if (purchase_quantity > purchased_product->quantity){
        	
            printf("Insufficient quantity available for purchase.\n");
            
        } else {
            // Calculate the total and update the available quantity
            total = purchase_quantity * purchased_product->price;
            purchased_product->quantity -= purchase_quantity;

            // Open the receipt file in append mode
            FILE* receipt_file = open_file(NULL, "receipts.txt", "a");

            // Write the receipt to the file
            fprintf(receipt_file, "Product purchased:\n");
            fprintf(receipt_file, "Name: %s\n", purchased_product->name);
            fprintf(receipt_file, "Code: %s\n", purchased_product->code);
            fprintf(receipt_file, "Description: %s\n", purchased_product->description);
            fprintf(receipt_file, "Unit price: %.2f\n", purchased_product->price);
            fprintf(receipt_file, "Quantity purchased: %d\n", purchase_quantity);
            fprintf(receipt_file, "Total: %.2f\n", total);
            fprintf(receipt_file, "-------------------------\n");

            // Close the receipt file
            close_file(receipt_file);

            printf("Purchase completed. Receipt generated and saved in the file 'receipts.txt'.\n");
        }
    }

	system("PAUSE");
    system("CLS");
    return;
}

//----------------------------------/

//----/* Main Function:
int main(){
	//---------/ Variables:
	int choice;
	Product *list = NULL;
	//----------------------/
	
	//---------/ Resolution Algorithm:
	
	//Loading products from file to the list.	
	startup_input("products.txt", &list);
	
	do {
        printf("--- Welcome to the Menu ---\n");
        
		printf(GREEN " 1. Print " RESET " - Show the complete list of available products.\n");
		printf(GREEN " 2. Search " RESET " - Find and display information for a specific product by its code.\n");
		printf(YELLOW " 3. Add" RESET " - Insert new products into the warehouse.\n");
		printf(YELLOW " 4. Update Quantity" RESET " - Modify the available quantities of products.\n");
		printf(CYAN " 5. Generate Invoice" RESET " - Create invoices for purchase transactions.\n");
		printf(RED " 6. Exit " RESET " - Close the application.\n");
		
		printf("Enter the number corresponding to your choice: ");
		scanf("%d", &choice);


        switch (choice) {
            case 1:
            	system("CLS");
            	
			    // Print products
    			print_list(list);
    			
                break;
                
            case 2:
            	system("CLS");
            	
				// Search for a product


                search_product(list);
                
                break;
                
            case 3:
            	system("CLS");
					
            	// Add new products
			    add_product(&list);
			    
			    // Save the updated list to the file
			    save_to_file(NAME_FILE, list);

                break;
            
            case 4:
            	system("CLS");
            	
				// Update the quantities in stock
    			update_quantity(list);
    			
    			// Save the updated list to the file
    			save_to_file(NAME_FILE, list);
    			
                break;
            
            case 5:
            	system("CLS");
            	
				// Generate invoices for purchases
                generate_invoice(list);
                
                // Save the updated list to the file
                save_to_file(NAME_FILE, list);
                
                break;  
                
            case 6:
            	system("CLS");
            	
                printf(RED "Exiting completed, goodbye!\n" RESET);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}