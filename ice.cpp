// A C program for ice cream management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store ice cream data
struct ice_cream {
    char name[20]; // name of the ice cream
    int price; // price of the ice cream
    int stock; // stock of the ice cream
};

// A global array to store ice creams
struct ice_cream ice_creams[100];
int n = 0; // number of ice creams

// A function to display the menu
void display_menu() {
    printf("Welcome to Ice Cream Management System\n");
    printf("Please choose an option:\n");
    printf("1. Display ice creams list\n");
    printf("2. Add new ice cream data\n");
    printf("3. Update the record of the ice cream\n");
    printf("4. Search any ice cream\n");
    printf("5. Delete any ice cream record\n");
    printf("6. Exit\n\n");
}

// A function to display the ice creams list
void display_ice_creams() {
    printf("Ice Creams List:\n");
    printf("Name\tPrice\tStock\n\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\n", ice_creams[i].name, ice_creams[i].price, ice_creams[i].stock);
    }
}

// A function to add new ice cream data
void add_ice_cream() {
    char name[20];
    int price;
    int stock;
    printf("Enter the name of the new ice cream: ");
    scanf("%s", name);
    printf("Enter the price of the new ice cream: ");
    scanf("%d", &price);
    printf("Enter the stock of the new ice cream: ");
    scanf("%d", &stock);
    
    // Check if the name already exists
    for (int i = 0; i < n; i++) {
        if (strcmp(ice_creams[i].name, name) == 0) {
            printf("The name already exists. Please choose another name.\n");
            return;
        }
    }
    
    // Add the new ice cream to the array
    strcpy(ice_creams[n].name, name);
    ice_creams[n].price = price;
    ice_creams[n].stock = stock;
    n++;
    
    // Save the data to a file
    FILE *fp = fopen("ice_creams.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fprintf(fp, "%s %d %d\n", name, price, stock);
    
    fclose(fp);
    
    printf("The new ice cream data has been added successfully.\n");
}

// A function to update the record of the ice cream
void update_ice_cream() {
    char name[20];
    int price;
    int stock;
    
    // Ask for the name of the ice cream to update
    printf("Enter the name of the ice cream to update: ");
    scanf("%s", name);
    
    // Search for the ice cream in the array
    int index = -1;
    
for (int i = 0; i < n; i++) {
        if (strcmp(ice_creams[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    
    // If not found, print an error message
    if (index == -1) {
        printf("The name does not exist. Please enter a valid name.\n");
        return;
    }
    
    // Ask for the new price and stock
    printf("Enter the new price of the ice cream: ");
    scanf("%d", &price);
    
     printf("Enter the new stock of the ice cream: ");
     scanf("%d", &stock);
     
// Update the array with the new data
ice_creams[index].price = price;
ice_creams[index].stock = stock;

// Save the data to a file
FILE *fp = fopen("ice_creams.txt", "w");
if (fp == NULL) {
    printf("Error opening file.\n");
    return;
}

for (int i = 0; i < n; i++) {
    fprintf(fp, "%s %d %d\n", ice_creams[i].name, ice_creams[i].price, ice_creams[i].stock);
}

fclose(fp);

printf("The ice cream record has been updated successfully.\n");
}

// A function to search any ice cream
void search_ice_cream() {
char name[20];

// Ask for the name of the ice cream to search
printf("Enter the name of the ice cream to search: ");
scanf("%s", name);

// Search for the ice cream in the array
int index = -1;

for (int i = 0; i < n; i++) {
    if (strcmp(ice_creams[i].name, name) == 0) {
        index = i;
        break;
    }
}

// If not found, print an error message
if (index == -1) {
    printf("The name does not exist. Please enter a valid name.\n");
    return;
}

// If found, print the details of the ice cream
printf("Ice Cream Details:\n");
printf("Name\tPrice\tStock\n");
printf("%s\t%d\t%d\n", ice_creams[index].name, ice_creams[index].price, ice_creams[index].stock);
}

// A function to delete any ice cream record
void delete_ice_cream() {
char name[20];

// Ask for the name of the ice cream to delete
printf("Enter the name of the ice cream to delete: ");
scanf("%s", name);

// Search for the ice cream in the array
int index = -1;

for (int i = 0; i < n; i++) {
    if (strcmp(ice_creams[i].name, name) == 0) {
        index = i;
        break;
    }
}

// If not found, print an error message
if (index == -1) {
    printf("The name does not exist. Please enter a valid name.\n");
    return;
}

// If found, delete the ice cream from the array
for (int i = index; i < n - 1; i++) {
    strcpy(ice_creams[i].name, ice_creams[i + 1].name);
    ice_creams[i].price = ice_creams[i + 1].price;
    ice_creams[i].stock = ice_creams[i + 1].stock;
}

n--;

// Save the data to a file
FILE *fp = fopen("ice_creams.txt", "w");
if (fp == NULL) {
    printf("Error opening file.\n");
    return;
}

for (int i = 0; i < n; i++) {
    fprintf(fp, "%s %d %d\n", ice_creams[i].name, ice_creams[i].price, ice_creams[i].stock);
}

fclose(fp);

printf("The ice cream record has been deleted successfully.\n");
}

// A function to load the data from a file
void load_data() {
FILE *fp = fopen("ice_creams.txt", "r");
if (fp == NULL) {
    printf("Error opening file.\n");
    return;
}

char name[20];
int price;
int stock;

while (fscanf(fp, "%s %d %d\n", name, &price, &stock) != EOF) {
    strcpy(ice_creams[n].name, name);
    ice_creams[n].price = price;
    ice_creams[n].stock = stock;
    n++;
}

fclose(fp);
}

// The main function
int main() {

// Load the data from a file
load_data();

// Display the menu and ask for user choice
int choice;

do {
    display_menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

// Perform the corresponding action based on the user choice
    switch (choice) {
        case 1:
            display_ice_creams();
            break;
        case 2:
            add_ice_cream();
            break;
        case 3:
            update_ice_cream();
            break;
        case 4:
            search_ice_cream();
            break;
        case 5:
            delete_ice_cream();
            break;
        case 6:
            printf("Thank you for using Ice Cream Management System.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
    }
} while (choice != 6);

return 0;
}
