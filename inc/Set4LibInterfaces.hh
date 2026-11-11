#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <memory>
#include <iostream>

#include "LibInterface.hh"


/*!
 * \brief Klasa zarzadzajaca dostepem do kluczy
 *
 *  Klasa podaje podstawowe operacje na wczytywaniu wtyczek,
 */
class Set4LibInterfaces : public std::map<std::string, std::shared_ptr<LibInterface>> {
    public:
        /*
         * \brief Funkcja dodajaca do zbioru znacznik na biblioteke i jej nazwe.
         *
         * \param[in] libName NAZWA BIBLIOTEKI np. "libInterp4Move.so"
         * 
         * \return Zwraca true jeśli poprawnie załaduje biblioteke. 
         */
        bool addPlugin(const std::string &libName);

        /*
         * \brief Funkcja przzeszukujaca zbior w celu znalezienia uchwytu wtyczki.
         * 
         * \param[in] cmdName komenda, np. "Move"
         * \return Zwraca wskaźnik współdzielony do interfejsu wtyczki. 
         */
        std::shared_ptr<LibInterface> findPlugin(const std::string &cmdName);
};

#endif