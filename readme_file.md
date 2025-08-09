# 🤖 AI Prompt Generator

A fun and interactive C program that generates creative AI prompts by randomly combining templates with word lists. Perfect for writers, content creators, and anyone looking for creative inspiration!

## ✨ Features

- 📝 Template-based prompt generation using `{placeholder}` syntax
- 🎲 Random word selection from curated lists
- 📁 Automatic file creation and management
- 💾 Saves all generated prompts to a log file
- 🔄 Interactive mode for generating multiple prompts
- 🛡️ Error handling and graceful fallbacks

## 🚀 Quick Start

### Prerequisites
- GCC compiler (or any C compiler)
- Text editor (optional, for customizing templates)

### Installation & Usage

1. **Clone or download the files:**
   ```bash
   # You need these files:
   # - prompt_generator.c
   # - templates.txt
   ```

2. **Compile the program:**
   ```bash
   gcc -o prompt_generator prompt_generator.c
   ```

3. **Run the program:**
   ```bash
   ./prompt_generator
   ```

4. **Follow the interactive prompts:**
   ```
   🤖 AI Prompt Generator
   =====================

   Loaded 15 templates from templates.txt

   Generated Prompt: Write a mysterious story about a fox who learns to code.

   Generate another prompt? (y/n): y

   Generated Prompt: Design a futuristic logo for a coffee shop.

   Generate another prompt? (y/n): n

   Generated prompts have been saved to 'generated_prompts.txt'
   Thank you for using the AI Prompt Generator! 🎉
   ```

## 📂 Project Structure

```
ai-prompt-generator/
├── prompt_generator.c      # Main C source code
├── templates.txt          # Template file with {placeholder} patterns
├── generated_prompts.txt  # Output file (auto-created)
└── README.md             # This file
```

## 🎯 How It Works

### 1. Templates
The program reads templates from `templates.txt`. Each template contains placeholders in `{placeholder}` format:

```
Write a {adjective} story about a {animal} who {action}.
Design a {adjective} logo for a {business_type}.
Explain {concept} to a {audience}.
```

### 2. Word Lists
The program contains predefined arrays for each placeholder type:

- **Adjectives**: mysterious, futuristic, funny, epic, magical...
- **Animals**: cat, fox, dragon, penguin, owl...
- **Actions**: learns to code, travels to Mars, starts a band...
- **Business Types**: coffee shop, tech startup, bookstore...
- **Concepts**: quantum physics, blockchain, AI ethics...
- **Audiences**: 10-year-old, grandparent, college student...

### 3. Generation Process
1. Randomly selects a template
2. Finds all `{placeholder}` patterns
3. Replaces each with a random word from the matching array
4. Displays the final prompt
5. Saves it to `generated_prompts.txt`

## 🎨 Example Outputs

- "Write a mysterious story about a fox who learns to code."
- "Design a futuristic logo for a coffee shop."
- "Explain quantum physics to a 10-year-old."
- "Create an epic character who is a dragon that builds a robot."
- "Develop a whimsical app for teenagers."

## ⚙️ Customization

### Adding New Templates
Edit `templates.txt` and add your own templates:
```
Create a {adjective} website about {concept}.
Write a {adjective} song about a {animal}.
```

### Adding New Word Categories
1. Add a new array in the C code:
   ```c
   char *colors[] = {"red", "blue", "green", "purple"};
   ```

2. Update the array count:
   ```c
   int colors_count = sizeof(colors) / sizeof(colors[0]);
   ```

3. Add a case in `get_random_word()`:
   ```c
   else if (strcmp(placeholder, "color") == 0) {
       return colors[rand() % colors_count];
   }
   ```

### Adding More Words
Simply expand the existing arrays with more options:
```c
char *adjectives[] = {"mysterious", "futuristic", "funny", "epic", "YOUR_NEW_WORD"};
```

## 🔧 Compilation Options

### Standard compilation:
```bash
gcc -o prompt_generator prompt_generator.c
```

### With debugging symbols:
```bash
gcc -g -o prompt_generator prompt_generator.c
```

### With optimization:
```bash
gcc -O2 -o prompt_generator prompt_generator.c
```

## 📋 File Details

### `templates.txt`
- Contains prompt templates with `{placeholder}` patterns
- One template per line
- Empty lines are ignored
- Auto-created with defaults if missing

### `generated_prompts.txt`
- Auto-created output file
- Contains all generated prompts from your session
- Appends new prompts (doesn't overwrite)

## 🚨 Error Handling

- **Missing templates.txt**: Auto-creates with default templates
- **Malformed placeholders**: Handles gracefully, copies as-is
- **File permissions**: Shows clear error messages
- **Memory safety**: Proper string handling and bounds checking

## 🤝 Contributing

Want to improve the AI Prompt Generator? Here are some ideas:

- Add more word categories (emotions, locations, professions)
- Implement nested placeholders
- Add command-line arguments for batch generation
- Create a GUI version
- Add configuration file support

## 📄 License

This project is open source. Feel free to use, modify, and distribute as needed.

## 🙋 Support

If you encounter issues:
1. Check that `templates.txt` exists and has proper format
2. Ensure you have write permissions in the directory
3. Verify your compiler supports C99 standard

## 🎉 Have Fun!

This generator is perfect for:
- Creative writing prompts
- Content ideation
- Brainstorming sessions
- Educational exercises
- Breaking writer's block

Happy prompt generating! 🚀