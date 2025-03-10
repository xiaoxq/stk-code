//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2014-2015  SuperTuxKart Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_PROPERTY_ANIMATOR_HPP
#define HEADER_PROPERTY_ANIMATOR_HPP

#include "utils/no_copy.hpp"
#include "utils/ptr_vector.hpp"

enum AnimatablePropery
{
    AP_LIGHT_ENERGY,
    FOG_RANGE,
    FOG_MAX,
    FOG_COLOR
};

class AnimatedProperty : NoCopy
{
    AnimatablePropery m_property;
    int m_values_count;
    double* m_values_from;
    double* m_values_to;
    double* m_new_values;
    double m_total_time;
    double m_remaining_time;
    void* m_data;

public:
    AnimatedProperty(AnimatablePropery property, int values_count,
        double* values_from, double* values_to,
        double duration, void* data);

    ~AnimatedProperty()
    {
        delete[] m_values_from;
        delete[] m_values_to;
        delete[] m_new_values;
    }

    bool update(double dt);
};


class PropertyAnimator
{
    PtrVector<AnimatedProperty> m_properties;
    static PropertyAnimator* s_instance;
public:

    static PropertyAnimator* get();

    void add(AnimatedProperty* prop);
    void update(double dt);
    void clear();
};


#endif
