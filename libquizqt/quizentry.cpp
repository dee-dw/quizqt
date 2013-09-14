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

#include "quizentry.hh"

#include <iostream>

// This constructor sets all necessary values.
QuizEntry::QuizEntry( const QStringList& categories,
                      const QString& subcategory,
                      const QString& question, 
                      const QString& answer,
                      const int points )
  : mCategories(categories), mSubCategory(subcategory),
    mQuestion(question), mAnswer(answer),
    mPoints(points), mUsed(false), mSelected(false), mValid(false)
{
    // There must be at least one category.
    if ( mCategories.isEmpty() )
    {
        return;
    }

    // No category is allowed to be empty.
    for ( int ii = 0; ii < mCategories.size(); ii++ )
    {
        if ( mCategories[ii].isEmpty() )
        {
             return;
        }
    }
    
    // The question must not be empty.
    if ( mQuestion.isEmpty() )
    {
        return;
    }

    // The answer must not be empty.
    if ( mAnswer.isEmpty() )
    {
        return;
    }
    
    // The points must be one of 100,200,300 or 400.
    if ( 100 != mPoints && 200 != mPoints && 300 != mPoints && 400 != mPoints)
    {
        return;
    }
    
    // Everything seems to be okay
    mValid = true;
}

// Default constructor.
QuizEntryPointers::QuizEntryPointers()
{
    for ( int ii = 0; ii < QuizEntry::numQuestionsPerCategory; ii++ )
    {
        entriesP[ii] = 0;
    }
}
