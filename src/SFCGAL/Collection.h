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
#ifndef _SFCGAL_COLLECTION_H_
#define _SFCGAL_COLLECTION_H_

#include <vector>
#include <SFCGAL/Point.h>

namespace SFCGAL {
        
    /**
     * A geometry collection
     */
    template < typename GeometryType > 
    class Collection : public Geometry<typename GeometryType::Kernel>, public std::vector< GeometryType > {
        using Container = std::vector< GeometryType > ;
    public:
        using Kernel = typename GeometryType::Kernel ;

        // forward Container's ctor's
        using Container::Container;

        virtual ~Collection(){}

        /**
         * Get n'th geometry
         * @deprecated use g.size()
         */        
        int numGeometries() const {
            return this->size() ;
        }
        /**
         * Get n'th geometry
         * @deprecated use g[i] or g.at(i)
         */
        GeometryType & geometryN( const size_t & n ) {
            BOOST_ASSERT( n < this->size() );
            return (*this)[n] ;
        }
        /**
         * Get n'th geometry
         * @deprecated use g[i] or g.at(i)
         */
        const GeometryType & geometryN( const size_t & n ) const {
            BOOST_ASSERT( n < this->size() );
            return (*this)[n] ;
        }

        //-- IGeometry
        virtual bool isEmpty() const {
            return this->empty() ;
        }
        //-- IGeometry
        virtual bool is3D() const {
            return (! isEmpty()) && this->front().is3D();
        }
        //-- IGeometry
        virtual bool isMeasured() const {
            return (! isEmpty()) && this->front().isMeasured();
        }

    } ;

}

#endif
