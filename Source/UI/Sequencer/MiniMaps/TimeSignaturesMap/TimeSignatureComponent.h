/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

class TimeSignaturesProjectMap;

#include "TimeSignatureEvent.h"

class TimeSignatureComponent : public Component
{
public:

    TimeSignatureComponent(TimeSignaturesProjectMap &parent, const TimeSignatureEvent &event) :
        editor(parent), event(event) {}

    const TimeSignatureEvent &getEvent() const noexcept
    {
        return this->event;
    }

    float getBeat() const noexcept
    {
        return this->event.getBeat();
    }

    virtual void updateContent() = 0;
    virtual void setRealBounds(const Rectangle<float> bounds) = 0;

    static int compareElements(const TimeSignatureComponent *first,
                               const TimeSignatureComponent *second)
    {
        if (first == second) { return 0; }

        const float diff = first->event.getBeat() - second->event.getBeat();
        const int diffResult = (diff > 0.f) - (diff < 0.f);
        if (diffResult != 0) { return diffResult; }

        return first->event.getId().compare(second->event.getId());
    }

protected:

    const TimeSignatureEvent &event;
    TimeSignaturesProjectMap &editor;

};
