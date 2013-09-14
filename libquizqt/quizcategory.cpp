/**
 * libquizqtbase - Part of quizqt
 * 
 * Copyright (C) 2013 Dominik Wagenfuehr <dee@deesaster.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <quizcategory.hh>

#include <QObject>

// Constructor
QuizCategory::QuizCategory( const QString& cat, const QString& sub, const int id )
: mCategory(cat), mSubcategory(sub), mIndex(id)
{ }

// Comparison operator.
bool QuizCategory::operator<( const QuizCategory& other ) const
{
    // Random categories are "bigger" than specific categories.
    
    bool retVal = false;

    if ( mCategory == QObject::tr("Random") )
    {
        // no matter what the other category is (even if it's random too)
        // this one is bigger.
        retVal = false;
    }
    else if ( other.mCategory == QObject::tr("Random") )
    {
        // so the other category is bigger
        retVal = true;
    }
    else if ( mSubcategory == QObject::tr("Random") )
    {
        // no matter what the other subcategory is (even if it's random too)
        // this one is bigger.
        retVal = false;
    }
    else
    {
        retVal = true;
    }
    
    return retVal;
}
