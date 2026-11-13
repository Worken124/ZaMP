#ifndef ABSTRACTINTERP4COMMAND_HH
#define ABSTRACTINTERP4COMMAND_HH

#include <iostream>
#include "Scene.hh"
#include "ComChannel.hh"

/*!
 * \file 
 * \brief Zawiera definicję klasy abstrakcyjnej AbstractInterp4Command
 *
 *  Zawiera definicję klasy abstrakcyjnej AbstractInterp4Command.
 *  Wyznacza ona niezbędny interfejs klas pochodnych.
 */

 /*!
  * \brief Definiuje interfejs interpretera polecenia.
  *
  * Definiuje interfejs interpretera polecenia udostępnianego
  * przez daną wtyczkę.
  */
  class AbstractInterp4Command {
   public:

    virtual ~AbstractInterp4Command() {}

    /*!
    * \brief Pokazuje nazwę polecenia.
    * \return Zwraca nazwę polecenia.
    */
    virtual const char* GetCmdName() const = 0; 

    /*!
     * \brief Wyświetla składnię polecenia
     */
    virtual void PrintSyntax() const = 0;

    /*!
     * \brief Wykonuje polecenie
     */
    virtual bool ReadParameters(std::istream &argStream) = 0;

    virtual bool ExecuteCmd(Scene *scene, ComChannel *channel) = 0;

  };


#endif
