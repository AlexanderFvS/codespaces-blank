#ifndef DISPLAY_OUTPUT_H
#define DISPLAY_OUTPUT_H

#ifndef ANGLE_H
#define ANGLE_H


/*
 ****************************************************************************************
 *  @brief      Einmalige initialisierung vor dem Superloop von Texten auf dem Bildschirm.
 *
 *  @return     void
 ****************************************************************************************/
 
void printLabels();

/*
 ****************************************************************************************
 *  @brief      Druckt die Error Message.
 *
 *  @return     void
 ****************************************************************************************/

void printError();

/*
 ****************************************************************************************
 *  @brief      Entfernt die Error Message.
 *
 *  @return     void
 ****************************************************************************************/

void clearError();

/*
 ****************************************************************************************
 *  @brief      Druckt den Winkel auf dem Bildschirm.
 *
 *  @return     void
 ****************************************************************************************/

void printWinkel(double winkel);

/*
 ****************************************************************************************
 *  @brief      Druckt die Geschwindigkeit auf dem Bildschirm.
 *
 *  @return     void
 ****************************************************************************************/

void printGeschw(double geschw);


#endif
