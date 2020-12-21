/****************************
 * button.cpp
 *
 *  Created on: 2010-04-19
 *      Author: DK
 ****************************/

#include "button.h"

//------------------------------------------------------------------------------
CButton::CButton()
//------------------------------------------------------------------------------
{
}

//------------------------------------------------------------------------------
void CButton::init(GPIO_TypeDef *port, uint16_t pin, bool reversed)
//------------------------------------------------------------------------------
{
    m_port = port;
    m_pin = pin;
    GPIO_InitTypeDef GPIO_InitStructure = GPIO_InitTypeDef();
    GPIO_InitStructure.Pin = pin;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(m_port, &GPIO_InitStructure);
    m_buttonDown = false;
    m_akceptedState = TAS_RELEASED;
    m_reveresed = reversed;
}

//------------------------------------------------------------------------------
void CButton::update()//wywolywane 100 razy na sekunde
//------------------------------------------------------------------------------
{
    if (m_beeperCounter >= 0)
    {
        --m_beeperCounter;
        if (m_beeperCounter == 0 && m_buzzerFunction != NULL)
        {
            m_buzzerFunction(false);
        }
    }

    if (m_counterOfPulse > 0)
    {
        --m_counterOfPulse;
    }

    if (m_vibrationCounter > 0)
    {
        --m_vibrationCounter;
    }

    switch (m_buttonState)
    {
        case TBS_RELEASED:
        {
            if (isKeyDown())
            {
                m_buttonState = TBS_TEST_PRESS;
                m_vibrationCounter = 4;
            }

            m_buttonUp = true;

            break;
        }

        case TBS_TEST_PRESS:
        {
            if (m_vibrationCounter == 0)
            {
                if (isKeyDown())
                {
                    m_buttonState = TBS_PRESSED;
                    m_beeperCounter = 1;
                    m_counterOfPulse = 60;
                    m_bPulseActive = true;

                    if (m_buzzerFunction != NULL)
                    {
                        m_buzzerFunction(true);
                    }
                }
                else
                {
                    m_buttonState = TBS_RELEASED;
                }
            }

            break;
        }

        case TBS_PRESSED:
        {
            if (!isKeyDown())
            {
                m_buttonState = TBS_TEST_RELEASE;
                m_vibrationCounter = 4;
            }
            else
            {
                if (m_counterOfPulse == 0)
                {
                    m_bPulseActive = true;
                    m_counterOfPulse = 10;
                }
            }

            m_buttonDown = true;

            break;
        }

        case TBS_TEST_RELEASE:
        {
            if (m_vibrationCounter == 0)
            {
                if (isKeyDown())
                {
                    m_buttonState = TBS_PRESSED;
                }
                else
                {
                    m_buttonState = TBS_RELEASED;
                }
            }

            break;
        }
    }
}

//------------------------------------------------------------------------------
void CButton::loopStartRegister()
//------------------------------------------------------------------------------
{
    switch (m_akceptedState)
    {
        case TAS_RELEASED:
        {
            if (m_buttonDown)
            {
                m_buttonUp = false;
                m_akceptedState = TAS_PRESSED;
            }

            break;
        }

        case TAS_PRESSED:
        case TAS_IMPULSE:
        {
            if (m_buttonUp)
            {
                m_buttonDown = false;
                m_akceptedState = TAS_RELEASED;
            }

            break;
        }
    }
}

//------------------------------------------------------------------------------
bool CButton::getImpulse(bool clearEvent)
//------------------------------------------------------------------------------
{
    bool bImpulse = false;
    if (m_bPulseActive && m_akceptedState != TAS_RELEASED)
    {
        m_akceptedState = TAS_IMPULSE;
        bImpulse = m_bPulseActive;
        if(clearEvent)
        {
        	m_bPulseActive = false;
        }
    }
    return bImpulse;
}

//------------------------------------------------------------------------------
bool CButton::getKeyPressed()
//------------------------------------------------------------------------------
{
    bool bPressed = false;
    if (m_bPulseActive && m_akceptedState == TAS_PRESSED)
    {
        m_akceptedState = TAS_IMPULSE;
        bPressed = true;
        m_bPulseActive = false;
    }
    return bPressed;
}
