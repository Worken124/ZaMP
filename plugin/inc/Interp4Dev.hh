#ifndef  COMMAND4DEV_HH
#define  COMMAND4DEV_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Dev
 *
 * Plik zawiera definicję klasy Interp4Dev ...
 */

/*!
 * \brief Modeluje interpreter polecenia Dev
 *
 *  Klasa modeluje interpreter polecenie diagnostyczne,
 *  które wyświetla wszystkie obiekty i ich parametry.
 */
class Interp4Dev: public AbstractInterp4Command {

 public:
  /*!
   * \brief Konstruktor
   */
  Interp4Dev();  

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
  * \brief Zczytuje parametry polecenia Dev
  */
  virtual bool ReadParameters(std::istream &argStream) override;

  /*!
  * \brief Wykonuje polecenie Dev
  */
  virtual bool ExecuteCmd(Scene &scene, ComChannel *channel) override;

 };

#endif
