/*
  Copyright (c) 2015 Lester Hedges <lester.hedges+vmmc@gmail.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BOX_H
#define _BOX_H

#include <cstdlib>
#include <iostream>
#include <vector>

/*! \file Box.h
*/

//! Class for the simulation box.
/*! Contains attributes and functionality for the rectangular two or three
    dimensional simulation box.
 */
class Box
{
public:
    //! Constructor: Initialise a fully periodic simulation box.
    /*! \param boxSize_
            Vector containing x,y,z size of box.
     */
    Box(const std::vector<double>&);

    //! Constructor: Initialise a simulation box with defined periodicity.
    /*! \param boxSize_
            Vector containing x,y,z size of box.

        \param isPeriodic_
            Vector containing x,y,z periodicity of box.
     */
    Box(const std::vector<double>&, const std::vector<bool>&);

    //! Apply periodic boundary conditions.
    /* \param coord
            x,y,z coordinate vector.
     */
    void periodicBoundaries(std::vector<double>&);

    //! Compute minimum image separation.
    /*! \param separation
            x,y,z separation vector.
     */
    void minimumImage(std::vector<double>&);

    std::vector<double> boxSize;        //!< size of the box in x,y,z directions
    unsigned int dimension;             //!< dimensionality of the simulation box

private:
    std::vector<bool> isPeriodic;       //!< whether the box is periodic across each boundary
    std::vector<double> posMinImage;    //!< minimum image condition in each dimension
    std::vector<double> negMinImage;    //!< negative minimum image condition in each dimension
};

#endif  /* _BOX_H */
