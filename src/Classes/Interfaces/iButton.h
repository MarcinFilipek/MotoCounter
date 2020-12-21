/****************************
 * iButton.h
 *
 *  Created on: 2010-06-25
 *      Author: DK
 ****************************/

#ifndef IBUTTON_H_
#define IBUTTON_H_

/**
 * \brief Klasa interfejsowa dla klasy button
 */
class IButton
{
    public:

        /**
         * Definicja typu dla funkcji sterujacej buzzerem
         */
        typedef void (*TEventKeyPressedBuzzer)(bool buzzerOn);
};

#endif /* IBUTTON_H_ */
