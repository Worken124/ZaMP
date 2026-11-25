#include <iostream>
#include "Interp4Dev.hh"

using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
  const char* GetCmdName(void) {return "Dev";};
}


/*!
 * \brief Tworzy obiekt klasy Interp4Dev.
 *
 * Tworzy obiekt klasy Interp4Dev.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Dev.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Dev();
}


/*!
 *
 */
Interp4Dev::Interp4Dev()
{}

const char* Interp4Dev::GetCmdName() const
{
  return "Dev";
}

/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Dev::PrintSyntax() const
{
  cout << "   Dev" << endl;
}

bool Interp4Dev::ReadParameters(std::istream &argStream)
{
  return true;
}

bool Interp4Dev::ExecuteCmd(Scene &scene, ComChannel *channel)
{
  cout << "===== Lista obiektow w scenie =====" << endl;

  for (auto &pair : scene) {
    std::shared_ptr<GeomObject> obj = pair.second;

    std::unique_lock<std::mutex> lk = obj->lock();

    vec3d pos = obj->getPos_m();
    vec3d rot = obj->getRot_deg();

    cout << "Obiekt: " << obj->getName() << endl;
    cout << "  Polozenie: " << pos << endl;
    cout << "  Rotacja:   " << rot << endl;
    cout << endl;
  }

  cout << "===================================" << endl;
  return true;
}
