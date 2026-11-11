#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawiera definicję klasy Interp4Move ...
 */

/*!
 * \brief Modeluje iInterpreterCommandnterpreter polecenia Move
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego ruch.
 */
class Interp4Move: public AbstractInterp4Command {

 public:  /*!
   * \brief Wyświetla postać bi
  /*!
   * \brief
   */
  Interp4Move();  

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
  * \brief Zczytuje parametry polecenia Move
  */
  virtual bool ReadParameters(std::istream &argStream) override;

  /*!
  * \brief Wykonuje polecenie Move
  */
  virtual bool ExecuteCmd(Scene *scene) override;

 };

#endif
