#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "AbstractInterp4Command.hh"

#define FPS 60

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawiera definicję klasy Interp4Rotate ...
 */

/*!
 * \brief Modeluje interpreter polecenia Rotate
 *
 *  Klasa modeluje interpreter polecenie dla modelu obiektu fizycznego,
 *  które wymusza jego obrót wokół wybranej osi.
 */
class Interp4Rotate: public AbstractInterp4Command {

  private:

    std::string _objName;
    std::string _axisName;
    double _szybkoscKatowa;  // stopnie na sekundę
    double _katObrotu;       // stopnie

 public:
  /*!
   * \brief Konstruktor
   */
  Interp4Rotate();  

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
  * \brief Zczytuje parametry polecenia Rotate
  */
  virtual bool ReadParameters(std::istream &argStream) override;

  /*!
  * \brief Wykonuje polecenie Rotate
  */
  virtual bool ExecuteCmd(Scene &scene, ComChannel *channel) override;

 };

#endif
