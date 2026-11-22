#ifndef  COMMAND4Pause_HH
#define  COMMAND4Pause_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Pause ...
 */

/*!
 * \brief Modeluje iInterpreterCommandnterpreter polecenia Pause
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które ... nic nie robi tylko czeka.
 */
class Interp4Pause: public AbstractInterp4Command {

  private:

    int _czas;

  public:  

    /*!
     * \brief Wyświetla postać bi
    /*!
     * \brief
     */
  Interp4Pause(); 
  
  /*!
   * \brief Pokazuje nazwę polecenia.
   * \return Zwraca nazwę polecenia.
   */
  virtual const char* GetCmdName() const override;

  /*!
   * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
   */
  virtual void PrintSyntax() const override;

  
  /*!
  * \brief Zczytuje parametry polecenia Pause
  */
  virtual bool ReadParameters(std::istream &argStream) override;

  /*!
  * \brief Wykonuje polecenie Pause
  */
  virtual bool ExecuteCmd(Scene *scene, ComChannel *channel) override;
 };

#endif
