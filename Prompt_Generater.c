#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMPLATES 100
#define MAX_LINE_LENGTH 500
#define MAX_WORD_LENGTH 100

// Word lists for different placeholder types
char *adjectives[] = {"mysterious", "futuristic", "funny", "epic", "magical", "dark", "bright", "ancient", "modern", "whimsical"};
char *animals[] = {"cat", "fox", "dragon", "penguin", "owl", "wolf", "elephant", "rabbit", "tiger", "dolphin"};
char *actions[] = {"learns to code", "travels to Mars", "starts a band", "opens a restaurant", "writes a book", "becomes a detective", "builds a robot", "learns magic", "explores caves", "saves the world"};
char *business_types[] = {"coffee shop", "tech startup", "bookstore", "bakery", "art gallery", "fitness center", "music store", "pet shop", "restaurant", "game studio"};
char *concepts[] = {"quantum physics", "blockchain", "AI ethics", "climate change", "space exploration", "genetic engineering", "renewable energy", "virtual reality", "machine learning", "cybersecurity"};
char *audiences[] = {"10-year-old", "grandparent", "college student", "professional", "teenager", "scientist", "artist", "engineer", "teacher", "business owner"};

// Array sizes
int adjectives_count = sizeof(adjectives) / sizeof(adjectives[0]);
int animals_count = sizeof(animals) / sizeof(animals[0]);
int actions_count = sizeof(actions) / sizeof(actions[0]);
int business_types_count = sizeof(business_types) / sizeof(business_types[0]);
int concepts_count = sizeof(concepts) / sizeof(concepts[0]);
int audiences_count = sizeof(audiences) / sizeof(audiences[0]);

// Function to get a random word based on placeholder type
char* get_random_word(const char* placeholder) {
    if (strcmp(placeholder, "adjective") == 0) {
        return adjectives[rand() % adjectives_count];
    } else if (strcmp(placeholder, "animal") == 0) {
        return animals[rand() % animals_count];
    } else if (strcmp(placeholder, "action") == 0) {
        return actions[rand() % actions_count];
    } else if (strcmp(placeholder, "business_type") == 0) {
        return business_types[rand() % business_types_count];
    } else if (strcmp(placeholder, "concept") == 0) {
        return concepts[rand() % concepts_count];
    } else if (strcmp(placeholder, "audience") == 0) {
        return audiences[rand() % audiences_count];
    }
    return "UNKNOWN";
}

// Function to replace placeholders in a template
void replace_placeholders(char* template, char* result) {
    char temp[MAX_LINE_LENGTH];
    strcpy(temp, template);
    result[0] = '\0';
    
    char* pos = temp;
    char* start_brace;
    char* end_brace;
    
    while ((start_brace = strchr(pos, '{')) != NULL) {
        // Copy text before the placeholder
        *start_brace = '\0';
        strcat(result, pos);
        
        // Find the end brace
        end_brace = strchr(start_brace + 1, '}');
        if (end_brace == NULL) {
            // Malformed placeholder, just copy the rest
            strcat(result, start_brace);
            break;
        }
        
        // Extract placeholder name
        *end_brace = '\0';
        char* placeholder = start_brace + 1;
        
        // Get random word and append to result
        char* replacement = get_random_word(placeholder);
        strcat(result, replacement);
        
        // Move position after the closing brace
        pos = end_brace + 1;
    }
    
    // Append any remaining text
    strcat(result, pos);
}

// Function to read templates from file
int read_templates(char templates[][MAX_LINE_LENGTH]) {
    FILE *file = fopen("templates.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open templates.txt\n");
        printf("Creating a default templates.txt file...\n");
        
        // Create default templates file
        file = fopen("templates.txt", "w");
        if (file != NULL) {
            fprintf(file, "Write a {adjective} story about a {animal} who {action}.\n");
            fprintf(file, "Design a {adjective} logo for a {business_type}.\n");
            fprintf(file, "Explain {concept} to a {audience}.\n");
            fprintf(file, "Create a {adjective} marketing campaign for a {business_type}.\n");
            fprintf(file, "Write a {adjective} poem about a {animal}.\n");
            fprintf(file, "Develop a {adjective} app for {audience}.\n");
            fprintf(file, "Teach {concept} using {adjective} examples.\n");
            fprintf(file, "Create a {adjective} character who is a {animal} that {action}.\n");
            fclose(file);
            printf("Default templates.txt created successfully!\n\n");
        }
        
        // Reopen for reading
        file = fopen("templates.txt", "r");
        if (file == NULL) {
            return 0;
        }
    }
    
    int count = 0;
    while (fgets(templates[count], MAX_LINE_LENGTH, file) != NULL && count < MAX_TEMPLATES) {
        // Remove newline character
        templates[count][strcspn(templates[count], "\n")] = 0;
        // Skip empty lines
        if (strlen(templates[count]) > 0) {
            count++;
        }
    }
    
    fclose(file);
    return count;
}

// Function to save generated prompt to file
void save_prompt_to_file(const char* prompt) {
    FILE *file = fopen("generated_prompts.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s\n", prompt);
        fclose(file);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    char templates[MAX_TEMPLATES][MAX_LINE_LENGTH];
    char generated_prompt[MAX_LINE_LENGTH];
    
    printf("🤖 AI Prompt Generator\n");
    printf("=====================\n\n");
    
    // Read templates from file
    int template_count = read_templates(templates);
    if (template_count == 0) {
        printf("Error: No templates found or could not read templates.txt\n");
        return 1;
    }
    
    printf("Loaded %d templates from templates.txt\n\n", template_count);
    
    char choice;
    do {
        // Select random template
        int random_template_index = rand() % template_count;
        char* selected_template = templates[random_template_index];
        
        // Replace placeholders
        replace_placeholders(selected_template, generated_prompt);
        
        // Display result
        printf("Generated Prompt: %s\n\n", generated_prompt);
        
        // Save to file
        save_prompt_to_file(generated_prompt);
        
        printf("Generate another prompt? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("Generated prompts have been saved to 'generated_prompts.txt'\n");
    printf("Thank you for using the AI Prompt Generator! 🎉\n");
    
    return 0;
}