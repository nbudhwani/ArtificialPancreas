#include <string>
/** \brief Generate latex strings
 *  \author Thomas
 * 
 *  Generate latex strings for use with writing latex code automatically.
 * */
namespace LatexHelper
{
      /**
       * \brief Environemnt
       * \param environment the environment
       * \param text the string to use
       * \return string of environemnt
       *
       * Sets up environment
       */
    std::string environment(std::string environment, std::string text);

      /**
       * \brief Returns end portion of string
       * \param environment the environment
       * \return the end portion
       *
       * tag to end a latex environment
       */
    std::string end(std::string environment);

     /**
       * \brief Returns beginning portion of string
       * \param environment the environment
       * \return the starting portion
       *
       * tag to begin a latex environment
       */
    std::string begin(std::string environment);


     /**
       * \brief Returns header for latex
       * \return the header, "\documentclass{article}"
       *
       * writes out the string "\documentclass{article}". 
       * Has use in generating latex file manually.
       */
    std::string header();

      /**
       * \brief returns a latex \input command
       * \return the string "\input{[inputFile]}"
       * 
       * Returns the string "\input{[inputFile]}".
       * This is a command to the tex compiler to include.
       * 
       */
    std::string input(std::string inputFile);
    
    /** 
     * \brief Returns a string for a latex command.
     * 
     * \return a string for a latex command in the form 
     *      \newcommand{\[command]}{\[definition]}
     * where [command] and [definition] are replaced with the respective arguments.
     * */
    std::string newCommand(
        /// Command to create
        std::string command,
        /// Definition of the command
        std::string definition);
}