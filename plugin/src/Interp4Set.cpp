#include <iostream>
#include "Interp4Set.hh"


using std::cout;
using std::endl;
using std::cerr;

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
  argStream >> _objName >> _wsp >> _rot;
  //cout << _wsp[2] << endl;
  return !argStream.fail();
}

bool Interp4Set::ExecuteCmd(Scene &scene, ComChannel *channel)
{
  std::shared_ptr<GeomObject> obj = scene.findGeomObject(_objName);
  if (obj == nullptr) {
    cerr << "Nie znaleziono obiektu" << endl;
    return false;
  }

  {
    std::unique_lock<std::mutex> lk = obj->lock();
    *obj->usePos_m() = _wsp;
    *obj->useRot_deg() = _rot;
  }

  return true;
}
