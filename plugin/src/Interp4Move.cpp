#include <iostream>
#include "Interp4Move.hh"


using std::cout;
using std::endl;


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
  return true;
}

bool Interp4Move::ExecuteCmd(Scene *scene)
{
    return false;
}
