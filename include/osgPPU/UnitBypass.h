/***************************************************************************
 *   Copyright (c) 2008   Art Tevs                                         *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 3 of        *
 *   the License, or (at your option) any later version.                   *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Lesse General Public License for more details.                    *
 *                                                                         *
 *   The full license is in LICENSE file included with this distribution.  *
 ***************************************************************************/

#ifndef _C_UNIT_BYPASS_H_
#define _C_UNIT_BYPASS_H_


//-------------------------------------------------------------------------
// Includes
//-------------------------------------------------------------------------
#include <osgPPU/Export.h>
#include <osgPPU/Unit.h>

namespace osgPPU
{
    //! Unit which do simply bypass input to the output
    /**
    **/
    class OSGPPU_EXPORT UnitBypass : public Unit {
        public:
            META_Object(osgPPU,UnitBypass);
        
            UnitBypass(osg::State* state) : Unit(state) {}
            UnitBypass() : Unit() {}
            UnitBypass(const UnitBypass& u, const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY) : Unit(u, copyop) {}
            
            ~UnitBypass(){}
            
            void init() { Unit::init(); mOutputTex = mInputTex; }
            
        protected:
            void render(int mipmapLevel = 0) { mOutputTex = mInputTex; }
    };
};

#endif
