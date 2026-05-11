/**
 * @file Note.cpp
 * 
 * @brief Note class to learn dynamic memory in C++
 */

#include <iostream>
#include <string>

/**
 * @class Note
 * @brief Holds string in dynamic memory
 */
class Note
{
private:
    std::string* text;

public:
    /**
     * @brief Creates object to store string dynamically
     * @param p_text text to store in Notes
     */
    Note(const std::string& p_text)
    {
        text = new std::string(p_text); // Is this faster or slower than the solution?
    }

    /**
     * @brief Copy constructor to fix double free bug
     * @param to_copy reference to the object to copy
     */
    Note(const Note& to_copy)
    {
        text = new std::string(*to_copy.text);
    }

    /**
     * @brief Releases memory for text and prints confirmation
     */
    ~Note()
    {
        delete text;
        text = nullptr;
        std::cout << "Memory released" << std::endl;
    }

    /**
     * @brief prints stored text to console
     */
    void display() const
    {
        std::cout << "Stored text: '" << *text << "'\n" << std::flush;
    }
};

int main()
{
    Note note1("The moon is made of green cheese!");
    Note note2 = note1;

    note1.display();
    note2.display();

    /**
     * An exception occurs when note2 tries to free it's memory.
     * The standard copy constructor allows to create a new note from an other note
     * this however makes the second node reference the same memory as the first.
     * Both dextructors are automatically called when the Program exits (more specifically the main() function)
     * Calling delete on nullptr causes an exception.
     */
    // The exception is relosved using a custom copy constructor

    return 0;
}