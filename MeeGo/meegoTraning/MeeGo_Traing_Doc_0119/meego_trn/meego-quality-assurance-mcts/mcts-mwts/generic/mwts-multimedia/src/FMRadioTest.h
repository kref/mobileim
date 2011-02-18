/* FMRadioTest.h
 *
 * This file is part of MCTS
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: Tommi Toropainen; tommi.toropainen@nokia.com;
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef _INCLUDED_FM_RADIO_TEST_H
#define _INCLUDED_FM_RADIO_TEST_H

#include <MwtsCommon>
#include <qradiotuner.h>

#ifdef MWTS_MULTIMEDIA_DEBUG
    #define MWTS_FM_RADIO_DEBUG
#endif

class FMRadioTest : public QObject
{
    Q_OBJECT

public:

    /**
     * Constructor for FMRadioTest class
     */
    FMRadioTest();

    /**
     * Destructor for FMRadioTest class
     */
    virtual ~FMRadioTest();

    /**
     * Function for MultiMediaTest class
     * OnInitialize is called before test execution
     */
    void OnInitialize();

    /**
     * Function for MultiMediaTest class
     * OnUninitialize is called after test execution
     */
    void OnUninitialize();

    /**
     * Sets the frequency in Hertz.
     * @param frequency Hz
     */
    void SetFrequency(int freq);

    /**
     * Starts a foreward scan for a signal, starting from the current frequency
     */
    void ScanUp();

    /**
     * Starts a backward scan for a signal, starting from the current frequency
     */
    void ScanDown();


    /**
     * Set the radio volume percentage.
     * @param volume  as 0 <= integer number <= 100)
     */
    void SetVolume(int volume);

    /**
     * Starts to play the radio on the set frequency for a certain time
     */
    void PlayRadio();

    /**
     * Sets the duration of the radio playing
     * @param radio playing duration in milliseconds
     */
    void SetRadioDuration(int millisecond);

private:
    //The main object used for radio playing
    QRadioTuner* radio;
    //Integer holds the the initial, later set volume value
    int vol;
    //Integer holds the the initial, later set frequency value
    int freq;
    //Integer holds the the initial, later set frequency value
    int duration;

private slots:
    /**
     * Outputs the current frequency in kHz
     */
    void freqChanged(int);
    /**
     * Based on signal strength, outputs if signal exists or not
     */
    void signalChanged(int);
    /**
    * Displays the emited error
    * @param error
    */
    void error(QRadioTuner::Error error);
    /**
    * Displays the current QRadioTuner state
    * @param state
    */
    void stateChanged(QRadioTuner::State state);
};


#endif //#ifndef _INCLUDED_FM_RADIO_TEST_H
