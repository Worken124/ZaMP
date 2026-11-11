#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Set ...
 */

/*!
 * \brief Modeluje iInterpreterCommandnterpreter polecenia Set
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego zmiane pozycji i rotacji.
 */
class Interp4Set: public AbstractInterp4Command {

  private:

    std::string _objName ;
    double _wsp[3];
    double _kat[3];

  public:  

    /*!
     * \brief Wyświetla postać bi
    /*!
     * \brief
     */
  Interp4Set(); 
  
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
  * \brief Zczytuje parametry polecenia Set
  */
  virtual bool ReadParameters(std::istream &argStream) override;

  /*!
  * \brief Wykonuje polecenie Set
  */
  virtual bool ExecuteCmd(Scene *scene) override;
 };

#endif
