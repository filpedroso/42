# Number-to-Word Converter developed during 42 School's Piscine

This tool takes a numeric input (e.g., "40") and returns its textual form (e.g., "forty"). It uses a dictionary file to map numbers to their word equivalents and handles various number formats, from single digits to large numbers.

## Files and Main Functionality

- **Main Functionality**:
    - Converts a number string into its word representation based on mappings provided in a dictionary file.
    - Handles numbers from single digits to large scales (e.g., "one hundred", "thousand").

### Files and Functions

1. **Dictionary Management**:
    - `t_dict` struct: A linked list structure holding key-value pairs for number-word mappings.
    - **`parse_dict`**: Loads the dictionary from a file, parsing it into key-value pairs in the `t_dict` structure.
    - **`process_buffer`**: Processes chunks of data from the dictionary file.
    - **`process_line`**: Processes each line of the dictionary file to extract a number-word pair.
    - **`add_to_dict`**: Adds a new key-value pair to the dictionary.
    - **`free_dict`**: Frees all memory allocated for the dictionary.

2. **Conversion Functions**:
    - **`convert_and_print`**: Main function that converts the number string and prints its word representation.
    - **`print_number`**: Processes numbers to be printed based on their length.
    - **`print_two_digits`**: Handles the conversion of two-digit numbers.
    - **`print_three_digits`**: Converts three-digit numbers.
    - **`print_large_number`**: Converts numbers larger than three digits, handling scaling (e.g., "thousand", "million").

3. **Helper Functions**:
    - **`ft_atoi`**: Converts a string to an integer.
    - **`ft_strncpy`**: Copies a specified number of characters from one string to another.
    - **`ft_strcat`**: Concatenates two strings.
    - **`ft_strcmp`**: Compares two strings.
    - **`ft_strchr`**: Finds the first occurrence of a character in a string.
    - **`ft_strdup`**: Duplicates a string.
    - **`ft_strlen`**: Calculates the length of a string.
    - **`ft_trim`**: Trims whitespace or extraneous characters from a string.
    - **`is_valid_number`**: Checks if the input is a valid numeric string.

4. **Printing Functions**:
    - **`print_word`**: Prints a word based on a dictionary lookup.
    - **`create_and_print_scale`**: Prints large-scale numbers like "thousand" and "million".

### Usage

To use the tool, compile the code and run it with the number string and optional dictionary file path. If a dictionary file is provided, the tool will parse and use it to convert numbers to words.

```bash
./num2word <number> [dictionary_file]
