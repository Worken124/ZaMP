#include <iostream>
#include "Interp4Pause.hh"

using std::cout;
using std::endl;


extern "C" {
  AbstractInterp4Command* CreateCmdInterp(void);
  const char* GetCmdName(void) {return "Pause";};
}




/*!
 * \brief Tworzy obiekt klasy Interp4Pause.
 *
 * Tworzy obiekt klasy Interp4Pause.
 * \return Zwraca wskaźnik na obiekt klasy bazowej utworzonego
 *         obiektu klas Inter4Pause.
 */
AbstractInterp4Command* CreateCmdInterp(void)
{
  return new Interp4Pause();
}


/*!
 *
 */
Interp4Pause::Interp4Pause()
{}

const char* Interp4Pause::GetCmdName() const
{
  return "Pause";
}

/*!
 * Wyświetla składnię polecenia.
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "   Pause  NazwaObiektu  CzasWMilisekundach" << endl;
}

bool Interp4Pause::ReadParameters(std::istream &argStream)
{
  argStream >> _czas;

  return !argStream.fail();
}

bool Interp4Pause::ExecuteCmd(Scene &scene, ComChannel *channel)
{
  std::this_thread::sleep_for(std::chrono::microseconds(1000 * _czas));
  return true;
}
