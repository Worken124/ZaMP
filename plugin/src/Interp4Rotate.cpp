#include <iostream>
#include <cmath>
#include "Interp4Rotate.hh"

using std::cout;
using std::endl;
using std::cerr;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
    const char* GetCmdName(void) {return "Rotate";};
}


/*!
 * \brief Tworzy obiekt klasy Interp4Rotate.
 *
 * Tworzy obiekt klasy Interp4Rotate.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Rotate.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Rotate();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate()
{}

const char* Interp4Rotate::GetCmdName() const
{
  return "Rotate";
}

/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  NazwaOsi  SzybkoscKatowa[st/s]  KatObrotu[st]" << endl;
}

bool Interp4Rotate::ReadParameters(std::istream &argStream)
{
  argStream >> _objName >> _axisName >> _szybkoscKatowa >> _katObrotu;
  if (argStream.fail()) return false;

  if (_katObrotu < 0.0) {
    cerr << "Kat obrotu musi byc wartoscia nieujemna (podano: " << _katObrotu << ")" << endl;
    return false;
  }
  return true;
}

bool Interp4Rotate::ExecuteCmd(Scene &scene, ComChannel *channel)
{
  std::shared_ptr<GeomObject> obj = scene.findGeomObject(_objName);
  if (obj == nullptr) {
    cerr << "Nie znaleziono obiektu" << endl;
    return false;
  }

  if (_szybkoscKatowa == 0.0 || _katObrotu == 0.0) {
    return true;
  }

  // OX=0, OY=1, OZ=2
  int axisIdx = -1;
  if (_axisName == "OX" || _axisName == "ox" || _axisName == "X" || _axisName == "x")
    axisIdx = 0;
  else if (_axisName == "OY" || _axisName == "oy" || _axisName == "Y" || _axisName == "y")
    axisIdx = 1;
  else if (_axisName == "OZ" || _axisName == "oz" || _axisName == "Z" || _axisName == "z")
    axisIdx = 2;
  else {
    cerr << "Nieznana os: " << _axisName << " (dozwolone: OX, OY, OZ)" << endl;
    return false;
  }

  const double sign = (_szybkoscKatowa > 0) ? 1.0 : -1.0; // kierunek +-
  const double absSpeed = std::abs(_szybkoscKatowa);

  const double stepDeg = absSpeed / FPS;  
  double remaining = _katObrotu;

  while (remaining > 0) {
    const double delta = std::min(stepDeg, remaining);
    remaining -= stepDeg;

    {
      std::unique_lock<std::mutex> lk = obj->lock();
      vec3d *rot = obj->useRot_deg();

      (*rot)[axisIdx] += sign * delta;
    }

    std::this_thread::sleep_for(std::chrono::microseconds(1000000 / FPS));
  }

  return true;
}
