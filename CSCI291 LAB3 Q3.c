// Including library headers needed for the working of the code
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Defined constants for number of teams and squad size
#define NUM_TEAMS 5
#define SQUAD_SIZE 4

// Struct age_t to store age of the player
typedef struct {
    int day;
    int month;
    int year;
} age_t;

// Struct player_t to store player details 
typedef struct {
    char name[25];
    int KitNumber;
    char club[30];
    age_t DOB;
    char role[20];
} player_t;

// Struct team_t to store team details
typedef struct {
    char name[20];
    player_t players[SQUAD_SIZE];
    int size;
} team_t;

team_t leagues[NUM_TEAMS];
int team = 0;

// Specifications stored as void for each function
void display_menu();
void enroll_club();
void add_player();
void search_update();
void display_club_statistics();
void handle_error();

// Initialising main program
int main() 
{
    // Initialising user input
    int input;
    // Using while(1) for an infinite loop
    while (1) 
    {
        // Function for display menu
        display_menu();
        // Reads user input 
        scanf("%d", &input);
        // Switch case syntax
        switch (input) {
            case 1: enroll_club(); 
            break;
            case 2: add_player(); 
            break;
            case 3: search_update(); 
            break;
            case 4: display_club_statistics(); 
            break;
            case 5: printf("Exiting the program.\n"); 
            return 0;
            default: handle_error("Invalid choice. Exiting the program."); 
            return 0;
        }
    }
}

// Displaying main menu to the user using printf
void display_menu() {
    printf(".............................\n");
    printf("   League Team Application\n");
    printf(".............................\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

// Function for enroll club
void enroll_club() 
{
    // Initialising number of clubs 
    int numClubs;
    printf("How many clubs would you like to enroll (up to %d)? ", NUM_TEAMS - team);
    // Reads user input
    scanf("%d", &numClubs);

    // if statement
    if (numClubs <= 0) 
    {
        // Handles error if invalid input is entered
        handle_error("Invalid number of clubs.");
        return;
    }

    if (team + numClubs > NUM_TEAMS) 
    {
        // Handles error if user enrolls more number of clubs ignoring the condition
        handle_error("Exceeding maximum number of teams. Please enroll fewer clubs.");
        return;
    }

    // Clears the input buffer after reading user input
    getchar();
    // Using for loop
    for (int i = 0; i < numClubs; i++) {
        printf("Enter the name of club %d: ", team + 1);
        // Reads specific number of characters
        fgets(leagues[team].name, sizeof(leagues[team].name), stdin);

        leagues[team].name[strcspn(leagues[team].name, "\n")] = 0;

        leagues[team].size = 0;
        // Increments
        team++;
        printf("Club enrolled successfully.\n");
    }
}

// Function to add player
void add_player() 
{
    // Initialising necessary variables
    int clubs, numPlayers, i, j, k;
    player_t NewPlayer;

    printf("Choose a club to add players to:\n");
    // Using for loop
    for (i = 0; i < team; i++) 
    {
        printf("%d. %s\n", i + 1, leagues[i].name);
    }
    scanf("%d", &clubs);
    // Decrements
    clubs--;
    
    // if statement
    if (clubs < 0 || clubs >= team) 
    {
        handle_error("Invalid club selection.");
        return;
    }

    printf("How many players would you like to add? ");
    // Reads user input for number of players
    scanf("%d", &numPlayers);

    if (leagues[clubs].size + numPlayers > SQUAD_SIZE) 
    {
        handle_error("Adding these players would exceed the maximum squad size.");
        return;
    }

    for (k = 0; k < numPlayers; k++) {
        printf("Enter player name: ");
        scanf(" %[^\n]", NewPlayer.name);
        
        // Validates kit number
        while (1) 
        {
            printf("Enter kit number (1-99): ");
            scanf("%d", &NewPlayer.KitNumber);
            if (NewPlayer.KitNumber >= 1 && NewPlayer.KitNumber <= 99) 
            {
                break; 
            } else {
                printf("Invalid kit number! Please enter a number between 1 and 99.\n");
            }
        }

        printf("Enter position: ");
        // Adds new line in array 
        scanf(" %[^\n]", NewPlayer.role);
        printf("Enter date of birth (dd mm yyyy): ");
        scanf("%d %d %d", &NewPlayer.DOB.day, &NewPlayer.DOB.month, &NewPlayer.DOB.year);

        // Check for duplicates in all clubs
        int duplicateFound = 0;
        for (i = 0; i < team; i++) {
            for (j = 0; j < leagues[i].size; j++) {
                if (strcasecmp(leagues[i].players[j].name, NewPlayer.name) == 0 ||
                    leagues[i].players[j].KitNumber == NewPlayer.KitNumber) {
                    if (!duplicateFound) {
                        printf("Duplicate detected! Existing players with similar details:\n");
                    }
                    printf("Club: %s, Player: %s, Kit Number: %d\n",
                           leagues[i].name, leagues[i].players[j].name, leagues[i].players[j].KitNumber);
                    duplicateFound = 1;
                }
            }
        }

        if (duplicateFound) {
            printf("Please re-enter valid details for this player.\n");
            k--;
            continue;
        }

        leagues[clubs].players[leagues[clubs].size++] = NewPlayer;
        printf("Player added successfully.\n");
    }
}

// Function to search update
void search_update() 
{
    char search_name[25];
    // Initialsing necessary variables
    int KitNumber, i, j;
    printf("Search by:\n1. Name\n2. Kit number\n");
    int search;
    // Reads user input
    scanf("%d", &search);

    if (search == 1) {
        printf("Enter player name to search: "); // Searches by name
        scanf(" %[^\n]", search_name);
        // Nested for loop
        for (i = 0; i < team; i++) {
            for (j = 0; j < leagues[i].size; j++) {
                if (strcasecmp(leagues[i].players[j].name, search_name) == 0) {
                    printf("Player found: %s, Kit Number: %d, Position: %s\n", leagues[i].players[j].name, leagues[i].players[j].KitNumber, leagues[i].players[j].role);
                    printf("Enter new details:\n");
                    printf("Enter new position: ");
                    scanf(" %[^\n]", leagues[i].players[j].role);
                    printf("Player details updated successfully.\n"); // Displays updated details entered by the user
                    return;
                }
            }
        }
        printf("Player not found. Please enter a valid name.\n"); // Prompts the user to enter a valid name 
    } 
    else if (search == 2) 
    {
        printf("Enter kit number to search: "); // Searches by kit number
        scanf("%d", &KitNumber);
        for (i = 0; i < team; i++) {
            for (j = 0; j < leagues[i].size; j++) {
                if (leagues[i].players[j].KitNumber == KitNumber) {
                    printf("Player found: %s, Kit Number: %d, Position: %s\n", leagues[i].players[j].name, leagues[i].players[j].KitNumber, leagues[i].players[j].role);
                    printf("Enter new details:\n");
                    printf("Enter new position: ");
                    scanf(" %[^\n]", leagues[i].players[j].role);
                    printf("Player details updated successfully.\n"); // Displays updated details entered by the user
                    return;
                }
            }
        }
        printf("Player not found. Please enter a valid kit number");
    } 
    else 
    {
        handle_error("Invalid search option.");
    }
}

// Function for club statistics
void display_club_statistics() {
    // Initialsing required variables 
    int i, j, age_sum, count;
    for (i = 0; i < team; i++) {
        printf("Club: %s\n", leagues[i].name);
        printf("Number of players: %d\n", leagues[i].size);
        age_sum = 0;
        count = leagues[i].size;
        for (j = 0; j < count; j++) {
            int age = 2024 - leagues[i].players[j].DOB.year;
            age_sum += age;
            printf("Player: %s, Kit Number: %d, Age: %d, Position: %s\n",
                leagues[i].players[j].name, leagues[i].players[j].KitNumber,
                age, leagues[i].players[j].role);
        }
        if (count > 0) {
            printf("Average Age: %.2f\n", (float) age_sum / count); // Displays age of the player after calculation
        }
    }
}

// Function to handle error and display error messages
void handle_error(char *message) {
    
    printf("Error: %s\n", message);
}
