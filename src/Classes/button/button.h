/****************************
 * button.h
 *
 *  Created on: 2010-04-19
 *      Author: DK
 ****************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdlib.h>
#include "iButton.h"
#include "hal.h"

/**
 * Klasa służąca do obsługi pojedyńczego przycisku
 */
class CButton : public IButton
{
    public:

        /**
         * Aktualny stan klawisza w badaniu. Jest to stan jeszcze nie zaakceptowany.
         */
        enum TButtonState
        {
            TBS_RELEASED,///klawisz opuszczony
            TBS_TEST_PRESS,///testowanie klawisza, czy napewno jest nacisniety
            TBS_PRESSED,///klawisz nacisniety
            TBS_TEST_RELEASE,///testowanie klawisza, czy napewno jest opuszczony
        };

        /**
         * Stan klawisza zaakceptowany, gotowy do odczytu przez program
         */
        enum TAkceptedState
        {
            TAS_RELEASED,///klawisz puszczony
            TAS_PRESSED,///klawisz nacisniety - odnotowanie pierwszego zbocz
            TAS_IMPULSE,///klawisz nacisniety - odliczanie impulsow
        };

        /**
         * Funkcja majaca za zadanie zainicjalizowanie sprzetu dla konkretnego przycisku.
         * \param port - rejestr PORT dla przycisku
         * \param pin -  bit wskazujacy na nozke portu do ktorej przylaczony jest przycisk
         * \param reversed - odwrócona interpretacja poziomu wejsciowego na nóżce.
         */
        void init(GPIO_TypeDef *port, uint16_t pin, bool reversed = false);
        /**
         * Funckja, ktora musi byc wykonywana 100 razy na sekunde. Najlepiej wywolywac
         * z przerwania timera
         */
        void update();
        /**
         * Funkcja, ktora zajmuje sie akceptowaniem stanu przycisku. Nalezy ja wywolywac
         * na poczatku petli programu oraz we wszystkich petlach w ktorych badamy stan przycisku.
         * Jesli funkcja nie bedzie wywolywana, to stan przycisku bedzie caly czas
         * taki sam jaki zostal nadany podczas ostatniego wywolania tej funckji.
         */
        void loopStartRegister();//two increments means program loop complete //zaakceptowanie stanu lub anulowanie stanu - kazdy nowy stan czeka na akceptacje na poczatku petli

        /**
         * Funckja dajaca impulsy klawisza podczas jego stalego nacisniecia.
         * Pierwszy impuls trwa ok. 0,4 sekundy a nastepne ok 0,1 sekundy
         * \param clearEvent - czy ma skasowac event przycisku (jesli przekazemy false,
         *  mozna testowac przycisk drugi raz w tej samej petli)
         * \return true jesli nastapil impuls
         */
        bool getImpulse(bool clearEvent = true);
        /**
         * Funckja podczas pojedynczego nacisniecia klawisza zwraca true tylko raz
         * niezaleznie od czasu trwania nacisniecia klawisza.
         * \return true jesli nacisnieto klawisz
         */
        bool getKeyPressed();
        /**
         * Funckja informuje o nacisnieciu klawisza
         * \return true gdy klawisz jest wcisniety
         */
        bool getKeyDown() { return m_akceptedState != TAS_RELEASED; }

        /**
         * Ustawia funkcje do obslugi buzzera
         * \param value - funkcja do obslugi buzzera
         */
        void setBuzzerFunction(TEventKeyPressedBuzzer value) { m_buzzerFunction = value; }

        CButton();

    private:

        GPIO_TypeDef *m_port;
        uint16_t m_pin;
        TButtonState m_buttonState;
        volatile TAkceptedState m_akceptedState;
        volatile bool m_buttonDown;
        volatile bool m_buttonUp;
        volatile bool m_bPulseActive;
        bool m_reveresed;
        IButton::TEventKeyPressedBuzzer m_buzzerFunction;


        int8_t m_vibrationCounter;
        int8_t m_beeperCounter;
        int8_t m_counterOfPulse;

        bool isKeyDown() { return HAL_GPIO_ReadPin(m_port, m_pin) == m_reveresed ? GPIO_PIN_SET : GPIO_PIN_RESET; }

};

#endif /* BUTTON_H_ */
