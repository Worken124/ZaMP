#include <iostream>
#include "Interp4Move.hh"

using std::cout;
using std::endl;
using std::cerr;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
    const char* GetCmdName(void) {return "Move";};
}


/*!
 * \brief Tworzy obiekt klasy Interp4Move.
 *
 * Tworzy obiekt klasy Interp4Move.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Move.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Move();
}


/*!
 *
 */
Interp4Move::Interp4Move()
{}

const char* Interp4Move::GetCmdName() const
{
  return "Move";
}

/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

bool Interp4Move::ReadParameters(std::istream &argStream)
{
  argStream >> _objName >> _szybkosc >> _dlugosc;
  return !argStream.fail();}

bool Interp4Move::ExecuteCmd(Scene &scene, ComChannel *channel)
{
  std::shared_ptr<GeomObject> obj = scene.findGeomObject(_objName);
  if (obj == nullptr) {
    cerr << "Nie znaleziono obiektu" << endl;
    return false;
  }

  if (_szybkosc <= 0.0 || _dlugosc <= 0.0) { // szybkość jest tylko dodatnia
    return true;
  }

  vec3d *current_position;

  vec3d vstep(0,0,0);
  vec3d rstep(0,0,0);
  const double vel = _szybkosc/FPS;


  while (_dlugosc > 0) {

    const double step = std::min(vel, _dlugosc);
    vstep.x = step;
    _dlugosc -= vel;

    {
      std::unique_lock<std::mutex> lk = obj->lock();
      current_position = obj->usePos_m();
      rstep = obj->getRot_deg();
      *current_position += vstep.rotRPY(rstep);
    }

    std::this_thread::sleep_for(std::chrono::microseconds(1000000 / FPS));
  }
    cout << current_position << endl;
    return true;
}
