/**
 *   SFCGAL
 *
 *   Copyright (C) 2012-2013 Oslandia <infos@oslandia.com>
 *   Copyright (C) 2012-2013 IGN (http://www.ign.fr)
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Library General Public
 *   License as published by the Free Software Foundation; either
 *   version 2 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Library General Public License for more details.

 *   You should have received a copy of the GNU Library General Public
 *   License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include <SFCGAL/Exception.h>


namespace SFCGAL {

///
///
///
Exception::Exception() throw():
    _message( "unknown exception" )
{

}


///
///
///
Exception::Exception( std::string const& message ) throw():
    _message( message )
{

}

///
///
///
Exception::~Exception() throw()
{

}

///
///
///
const char* Exception::what() const throw()
{
    return _message.c_str() ;
}

///
///
///
std::string Exception::diagnostic() const throw()
{
    return boost::diagnostic_information( *this ) ;
}


}//SFCGAL



