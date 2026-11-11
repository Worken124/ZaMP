#include <iostream>
#include "Interp4Set.hh"


using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
  const char* GetCmdName(void) {return "Set";};
}




/*!
 * \brief Tworzy obiekt klasy Interp4Set.
 *
 * Tworzy obiekt klasy Interp4Set.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Set.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Set();
}


/*!
 *
 */
Interp4Set::Interp4Set()
{}

const char* Interp4Set::GetCmdName() const
{
  return "Set";
}

/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set  NazwaObiektu  Wsp_X[m]  Wsp_Y[m]  Wsp_Z[m]  Kat_OX[st]  Kat_OY[st]  Kat_OZ[st]" << endl;
}

bool Interp4Set::ReadParameters(std::istream &argStream)
{
  argStream >> _objName >> _wsp[0] >> _wsp[1] >> _wsp[2] >> _kat[0] >> _kat[1] >> _kat[2];
  cout << _wsp[2] << endl;
  return !argStream.fail();
}

bool Interp4Set::ExecuteCmd(Scene *scene)
{
    return false;
}
