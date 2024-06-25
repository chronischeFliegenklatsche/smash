#ifndef _TEXT_DISPLAY_HPP
#define _TEXT_DISPLAY_HPP

#include "Integers.hpp"

namespace smash {

    /**
     * @brief The TextDisplay class is an abstract base class for text display devices.
     * 
     * This class provides a common interface for displaying text and setting the cursor position
     * on different text display devices.
     */
    class TextDisplay {

        public:
            /**
             * @brief Constructs a new TextDisplay object.
             */
            TextDisplay();

            /**
             * @brief Displays the specified text on the text display device.
             * 
             * @param inputText The text to be displayed.
             */
            virtual void displayText(char* inputText) = 0;

            /**
             * @brief Sets the cursor position on the text display device.
             * 
             * @param col The column position of the cursor.
             * @param row The row position of the cursor.
             */
            virtual void setCursor(uint8_t col, uint8_t row) = 0;
    };
}

#endif